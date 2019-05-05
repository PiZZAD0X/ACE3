class CfgWeapons {
    class Binocular;
    class ACE_Vector: Binocular {
        author = ECSTRING(common,ACETeam);
        displayName = CSTRING(VectorName);
        descriptionShort = CSTRING(VectorDescription);
        model = QPATHTOF(ace_vector.p3d);
        picture = QPATHTOF(UI\ace_vector_x_ca.paa);
        visionMode[] = {"Normal","NVG"};
        opticsZoomMax = 0.25/7;
        opticsZoomMin = 0.25/7;
        modelOptics = "\x\cba\addons\optics\cba_optic_big_100.p3d";
        //weaponInfoType = "ACE_RscOptics_vector";

        class CBA_ScriptedOptic {
            minMagnificationReticleScale[] = {5,1.026};
            maxMagnificationReticleScale[] = {25,25*1.026};

            reticleDetailTextures[] = {
                // start at > this magnification, reticleTexture, reticleTextureSize, reticleTextureNight (optional)
                {0,  PATHTOF(data\reticles\ace_vector_reticle_1_ca.paa), 1},
                {9,  PATHTOF(data\reticles\ace_vector_reticle_2_ca.paa), 1/2}
            };

            bodyTexture = QPATHTOF(data\reticles\ace_vector_body_co.paa);
            //bodyTextureNight = QPATHTOF(data\reticles\ace_vector_body_co.paa);
            bodyTextureSize = 1.15;
        };
        weaponInfoType = "CBA_ScriptedOptic_zooming";
    };

    class ACE_VectorDay: ACE_Vector {
        author = ECSTRING(common,ACETeam);
        displayName = CSTRING(VectorDayName);
        visionMode[] = {"Normal"};
    };
};
