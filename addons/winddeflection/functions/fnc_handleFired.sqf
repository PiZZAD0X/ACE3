/**
 * fnc HandleFired.
 * Handles wind deflection for projectiles.
 * Is expected to be triggered by the fired eventhandler from BI.
 *
 * Params:
 *   1. unit: Object - Object the event handler is assigned to
 *   2. weapon: String - Fired weapon
 *   3. muzzle: String - Muzzle that was used
 *   4. mode: String - Current mode of the fired weapon
 *   5. ammo: String - Ammo used
 *   6. magazine: String - magazine name which was used
 *   7. projectile: Object - Object of the projectile that was shot (Arma 2: OA and onwards)
 *
 * Author: Glowbal, Ruthberg
 *
 */

#include "script_component.hpp"

if (isNil QGVAR(EnableForAI)) exitWith {false}; // means that the module has not yet initialized

private ["_unit", "_weapon", "_ammo", "_bullet", "_airFriction", "_index"];
_unit = _this select 0;

if (_unit distance ACE_player > 3000) exitWith {false}; // Large enough distance to not simulate any wind deflection.
if (!GVAR(EnableForAI) && !(isPlayer _unit)) exitWith {false};
_bullet = _this select 6;

if (_bullet isKindOf "BulletBase") then {
    _weapon = _this select 1;
    _ammo   = _this select 4;

    _airFriction = getNumber(configFile >> "cfgAmmo" >> _ammo >> "airFriction");

    _index = count GVAR(bulletDatabaseLastFrame);
    if (count GVAR(bulletDatabaseLastFrameFreeIndices) > 0) then {
        _index = GVAR(bulletDatabaseLastFrameFreeIndices) select 0;
        GVAR(bulletDatabaseLastFrameFreeIndices) = GVAR(bulletDatabaseLastFrameFreeIndices) - [_index];
    };

    GVAR(bulletDatabaseLastFrame)          set[_index, [_bullet, _airFriction, _index]];
    GVAR(bulletDatabaseLastFrameLastFrame) set[_index, time];

    GVAR(bulletDatabaseLastFrameOccupiedIndices) pushBack _index;

    if (count GVAR(bulletDatabaseLastFrameOccupiedIndices) == 1) then {
        [{
            private ["_bullet", "_airFriction", "_index", "_deltaT", "_bulletVelocity", "_bulletSpeed", "_trueVelocity", "_trueVelocity", "_dragRef", "_drag", "_accelRef", "_accel"];

            {
                _bullet = (GVAR(bulletDatabaseLastFrame) select _x) select 0;
                _index  = (GVAR(bulletDatabaseLastFrame) select _x) select 2;
                if (!alive _bullet) then {
                    GVAR(bulletDatabaseLastFrameOccupiedIndices) = GVAR(bulletDatabaseLastFrameOccupiedIndices) - [_index];
                    GVAR(bulletDatabaseLastFrameFreeIndices) pushBack _index;
                };
            } forEach GVAR(bulletDatabaseLastFrameOccupiedIndices);

            if (count GVAR(bulletDatabaseLastFrameOccupiedIndices) == 0) exitWith {
                /// Resetting all the variables.
                GVAR(bulletDatabaseLastFrame) = [];
                GVAR(bulletDatabaseLastFrameLastFrame) = [];
                GVAR(bulletDatabaseLastFrameOccupiedIndices) = [];
                GVAR(bulletDatabaseLastFrameFreeIndices) = [];
                [_this select 1] call cba_fnc_removePerFrameHandler;
            };

            {
                _bullet      = (GVAR(bulletDatabaseLastFrame) select _x) select 0;
                _airFriction = (GVAR(bulletDatabaseLastFrame) select _x) select 1;
                _index       = (GVAR(bulletDatabaseLastFrame) select _x) select 2;

                _deltaT = time - (GVAR(bulletDatabaseLastFrameLastFrame) select _index);
                GVAR(bulletDatabaseLastFrameLastFrame) set[_index, time];

                _bulletVelocity = velocity _bullet;
                _bulletSpeed = vectorMagnitude _bulletVelocity;

                if (vectorMagnitude ACE_wind > 0) then {
                    _trueVelocity = _bulletVelocity vectorDiff ACE_wind;
                    _trueSpeed = vectorMagnitude _trueVelocity;

                    _dragRef = _deltaT * _airFriction * _bulletSpeed * _bulletSpeed;
                    _accelRef = (vectorNormalized _bulletVelocity) vectorMultiply (_dragRef);
                    _bulletVelocity = _bulletVelocity vectorDiff _accelRef;

                    _drag = _deltaT * _airFriction * _trueSpeed * _trueSpeed;
                    _accel = (vectorNormalized _trueVelocity) vectorMultiply (_drag);
                    _bulletVelocity = _bulletVelocity vectorAdd _accel;
                };

                // TODO expand with advanced ballistics functionality.

                _bullet setVelocity _bulletVelocity;
            }forEach GVAR(bulletDatabaseLastFrameOccupiedIndices);
        }, 0, []] call CBA_fnc_addPerFrameHandler;
    };
};
true;