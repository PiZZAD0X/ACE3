class CfgMovesBasic {
    class Default;    // External class reference
    class NoActions; // External class reference
    class Actions {
        class CivilStandActions;    // External class reference
        class CivilProneActions : CivilStandActions {
            SecondaryWeapon = "ACE_LauncherProne";
            weaponOn = "ACE_LauncherProne";
        };
        class PistolStandActions;    // External class reference
        class PistolProneActions : PistolStandActions {
            SecondaryWeapon = "ACE_LauncherProne";
            weaponOn = "ACE_LauncherProne";
        };
        class RifleBaseStandActions;    // External class reference
        class RifleProneActions : RifleBaseStandActions {
            SecondaryWeapon = "ACE_LauncherProne";
            weaponOn = "ACE_LauncherProne";
            weaponOff = "AmovPpneMstpSrasWrflDnon";
        };
        class LauncherKneelActions: NoActions {
            Lying = "AmovPknlMstpSrasWlnrDnon";
            PlayerProne = "AmovPknlMstpSrasWlnrDnon";
            Down = "AmovPknlMstpSrasWlnrDnon";
        };
        class LauncherStandActions: LauncherKneelActions {
            Default = "AmovPercMstpSrasWlnrDnon";
            PlayerStand = "AmovPercMstpSrasWlnrDnon";
            Stand = "AmovPercMstpSrasWlnrDnon";
            Up = "AmovPknlMstpSrasWlnrDnon";
            Lying = "AmovPercMstpSrasWlnrDnon";
            PlayerProne = "AmovPercMstpSrasWlnrDnon";
            Down = "AmovPercMstpSrasWlnrDnon";
        };
        class ACE_LauncherProneActions: LauncherKneelActions {
            StopRelaxed = "ACE_LauncherProne";
            Default = "ACE_LauncherProne";
            Up = "ACE_LauncherProne";
            Crouch = "ACE_LauncherProne";
            PlayerCrouch = "ACE_LauncherProne";
            Down = "ACE_LauncherProne";
            Stand = "ACE_LauncherProne";
            PlayerStand = "ACE_LauncherProne";
            TurnL = "AmovPpneMrunSrasWlnr_turnL";
            TurnLRelaxed = "AmovPpneMrunSrasWlnr_turnL";
            TurnR = "AmovPpneMrunSrasWlnr_turnR";
            TurnRRelaxed = "AmovPpneMrunSrasWlnr_turnR";
            Stop = "ACE_LauncherProne";
            Civil = "AmovPpneMstpSnonWnonDnon";
            CivilLying = "AmovPpneMstpSnonWnonDnon";
            BinocOff = "ACE_LauncherProne";
            Gear = "AinvPpneMstpSnonWnonDnon";
            BinocOn = "AwopPpneMstpSoptWbinDnon_Lnr";
            HandGunOn = "AmovPpneMstpSrasWpstDnon";
            stance = "ManStanceProne";
            ReloadRPG = "LauncherProne_Reload_Start";
            //GestureReloadRPG7[] = {"GestureReloadRPG7Kneel", "Gesture"};
            weaponOn = "ACE_LauncherProne";
            WeaponOff = "AmovPpneMstpSrasWrflDnon";
            WalkB = "AmovPpneMrunSrasWlnrDb";
            WalkRB = "AmovPpneMrunSrasWlnrDbr";
            WalkLB = "AmovPpneMrunSrasWlnrDbl";
            WalkR = "AmovPpneMrunSrasWlnrDr";
            WalkL = "AmovPpneMrunSrasWlnrDl";
            WalkRF = "AmovPpneMrunSrasWlnrDfr";
            WalkLF = "AmovPpneMrunSrasWlnrDfl";
            WalkF = "AmovPpneMrunSrasWlnrDf";
            PlayerWalkB = "AmovPpneMrunSrasWlnrDb";
            PlayerWalkRB = "AmovPpneMrunSrasWlnrDbr";
            PlayerWalkLB = "AmovPpneMrunSrasWlnrDbl";
            PlayerWalkR = "AmovPpneMrunSrasWlnrDr";
            PlayerWalkL = "AmovPpneMrunSrasWlnrDl";
            PlayerWalkRF = "AmovPpneMrunSrasWlnrDfr";
            PlayerWalkLF = "AmovPpneMrunSrasWlnrDfl";
            PlayerWalkF = "AmovPpneMrunSrasWlnrDf";
            SlowF = "AmovPpneMrunSrasWlnrDf";
            SlowLF = "AmovPpneMrunSrasWlnrDfl";
            SlowRF = "AmovPpneMrunSrasWlnrDfr";
            SlowL = "AmovPpneMrunSrasWlnrDl";
            SlowR = "AmovPpneMrunSrasWlnrDr";
            SlowLB = "AmovPpneMrunSrasWlnrDbl";
            SlowRB = "AmovPpneMrunSrasWlnrDbr";
            SlowB = "AmovPpneMrunSrasWlnrDb";
            PlayerSlowF = "AmovPpneMrunSrasWlnrDf";
            PlayerSlowLF = "AmovPpneMrunSrasWlnrDfl";
            PlayerSlowRF = "AmovPpneMrunSrasWlnrDfr";
            PlayerSlowL = "AmovPpneMrunSrasWlnrDl";
            PlayerSlowR = "AmovPpneMrunSrasWlnrDr";
            PlayerSlowLB = "AmovPpneMrunSrasWlnrDbl";
            PlayerSlowRB = "AmovPpneMrunSrasWlnrDbr";
            PlayerSlowB = "AmovPpneMrunSrasWlnrDb";
            FastF = "AmovPpneMrunSrasWlnrDf";
            FastLF = "AmovPpneMrunSrasWlnrDfl";
            FastRF = "AmovPpneMrunSrasWlnrDfr";
            FastL = "AmovPpneMrunSrasWlnrDl";
            FastR = "AmovPpneMrunSrasWlnrDr";
            FastLB = "AmovPpneMrunSrasWlnrDbl";
            FastRB = "AmovPpneMrunSrasWlnrDr";
            FastB = "AmovPpneMrunSrasWlnrDb";
            TactB = "AmovPpneMrunSrasWlnrDb";
            TactRB = "AmovPpneMrunSrasWlnrDbr";
            TactLB = "AmovPpneMrunSrasWlnrDbl";
            TactR = "AmovPpneMrunSrasWlnrDr";
            TactL = "AmovPpneMrunSrasWlnrDl";
            TactRF = "AmovPpneMrunSrasWlnrDfr";
            TactLF = "AmovPpneMrunSrasWlnrDfl";
            TactF = "AmovPpneMrunSrasWlnrDf";
            PlayerTactB = "AmovPpneMrunSrasWlnrDb";
            PlayerTactRB = "AmovPpneMrunSrasWlnrDbr";
            PlayerTactLB = "AmovPpneMrunSrasWlnrDbl";
            PlayerTactR = "AmovPpneMrunSrasWlnrDr";
            PlayerTactL = "AmovPpneMrunSrasWlnrDl";
            PlayerTactRF = "AmovPpneMrunSrasWlnrDfr";
            PlayerTactLF = "AmovPpneMrunSrasWlnrDfl";
            PlayerTactF = "AmovPpneMrunSrasWlnrDf";
        };
        class BinocProneLnrActions: LauncherKneelActions {
            BinocOff = "ACE_LauncherProne";
            SecondaryWeapon = "ACE_LauncherProne";
            weaponOn = "ACE_LauncherProne";
        };
    };
};
