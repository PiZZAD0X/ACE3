/*
 * Author: KoffeinFlummi, commy2
 * Initializes unit variables.
 *
 * Arguments:
 * 0: The Unit <OBJECT>
 *
 * ReturnValue:
 * nil
 *
 * Public: No
 */
#include "script_component.hpp"

params ["_unit"];

_unit setVariable [QGVAR(pain), 0, true];
_unit setVariable [QGVAR(bloodVolume), 100, true];
_unit setVariable ["ACE_isUnconscious", false, true]; // TODO this is done based on state

// tourniquets
_unit setVariable [QGVAR(tourniquets), [0,0,0,0,0,0], true];
_unit setVariable [QGVAR(occludedMedications), nil, true]; //Delayed Medications (from tourniquets)

// wounds and injuries
_unit setVariable [QGVAR(openWounds), [], true];
_unit setVariable [QGVAR(bandagedWounds), [], true];
_unit setVariable [QGVAR(internalWounds), [], true];

// vitals
_unit setVariable [QGVAR(heartRate), 80];
_unit setVariable [QGVAR(heartRateAdjustments), []];
_unit setVariable [QGVAR(bloodPressure), [80, 120]];
_unit setVariable [QGVAR(peripheralResistance), 100];

// fractures
_unit setVariable [QGVAR(fractures), [], true];

// triage card and logs
// TODO move to treatment
//_unit setVariable [QGVAR(triageLevel), 0, true];
//_unit setVariable [QGVAR(triageCard), [], true];

// IVs
_unit setVariable [QGVAR(salineIVVolume), 0, true];
_unit setVariable [QGVAR(plasmaIVVolume), 0, true];
_unit setVariable [QGVAR(bloodIVVolume), 0, true];

// damage storage
_unit setVariable [QGVAR(bodyPartStatus), [0,0,0,0,0,0], true];

// airway
_unit setVariable [QGVAR(airwayStatus), 100];
_unit setVariable [QGVAR(airwayOccluded), false];
_unit setVariable [QGVAR(airwayCollapsed), false];

// generic medical admin
_unit setVariable [QGVAR(addedToUnitLoop), false, true]; // TODO this is replaced by unit state
_unit setVariable [QGVAR(inCardiacArrest), false, true]; // TODO this is no longer present
_unit setVariable [QGVAR(hasLostBlood), 0, true];
_unit setVariable [QGVAR(isBleeding), false, true];
_unit setVariable [QGVAR(hasPain), false, true];
_unit setVariable [QGVAR(amountOfReviveLives), GVAR(amountOfReviveLives), true];
_unit setVariable [QGVAR(painSuppress), 0, true];

private ["_allUsedMedication", "_logs"];

// medication
_allUsedMedication = _unit getVariable [QGVAR(allUsedMedication), []];
{
   _unit setVariable [_x select 0, nil];
} forEach _allUsedMedication;
_unit setVariable [QGVAR(allUsedMedication), [], true];

// TODO move to treatment
_logs = _unit getVariable [QGVAR(allLogs), []];
{
    _unit setVariable [_x, nil];
} forEach _logs;
_unit setVariable [QGVAR(allLogs), [], true];

// TODO move to treatment
// items
[{
    _this call FUNC(itemCheck);
}, [_unit], 0.5, 0.1] call CBA_fnc_waitAndExecute;