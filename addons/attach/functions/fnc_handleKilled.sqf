/*
 * Author: PabstMirror
 * Handles when vehicle or man is killed. 
 * Note: Runs where unit is local.
 *
 * Arguments:
 * 0: DeadVehicle <OBJECT>
 *
 * Return Value:
 * None
 *
 * Example:
 * [bob1] call ACE_attach_fnc_handleKilled
 *
 * Public: No
 */
#include "script_component.hpp"

params ["_deadUnit"];
TRACE_1("params",_deadUnit);

private ["_attachedList"];

_attachedList = _deadUnit getVariable [QGVAR(attached), []];

if ((count _attachedList) == 0) exitWith {};

{
    _x params ["_xObject"];
    TRACE_2("detaching",_xObject,_deadUnit);
    detach _xObject;
} forEach _attachedList;

_deadUnit setVariable [QGVAR(attached), nil, true];
