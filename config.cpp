#define TEast 0
#define TWest 1
#define TGuerrila 2
#define TCivilian 3
#define TSideUnknown 4
#define TEnemy 5
#define TFriendly 6
#define TLogic 7

#define true 1
#define false 0

#define private 0
#define protected 1
#define public 2

enum {
	DESTRUCTENGINE = 2,
	DESTRUCTDEFAULT = 6,
	DESTRUCTWRECK = 7,
	DESTRUCTTREE = 3,
	DESTRUCTTENT = 4,
	STABILIZEDINAXISX = 1,
	STABILIZEDINAXISY = 2,
	STABILIZEDINAXESBOTH = 3,
	DESTRUCTNO = 0,
	STABILIZEDINAXESNONE = 0,
	DESTRUCTMAN = 5,
	DESTRUCTBUILDING = 1,
};

class CfgPatches
{
	class sr71a
        {
		units[] = {};
		weapons[] = {};
	};
};

class CfgSounds
{
	class sr71a_gear_up
 	{
		sound[]={"\sr71a\sound\gearup.wav",10,1};
		name = "sr71a_gear_up";
		titles[] = {};
 	};

	class sr71a_gear_down
 	{
		sound[]={"\sr71a\sound\GEARDOWN.wav",10,1};
		name = "sr71a_gear_down";
		titles[] = {};
 	};
};

class CfgVehicles
{
	class All {};
	class AllVehicles: All {};
	class Air: AllVehicles {};
	class Helicopter : Air {};

	class ParachuteBase : Helicopter {};

	class sr71a_brakechute : ParachuteBase {
		scope = protected;
		faction = "BLU_F";
		vehicleClass = "Air";
		accuracy = 0.5;	// accuracy needed to recognize type of this target
		side = TWest;
		displayName = "SR-71 Brake Parachute";
		model = "\sr71a\sr71_chute";
		crew = "B_Pilot_F";
		castDriverShadow = false;
		typicalCargo[] = {"B_Pilot_F"};
		Icon = "\sr71a\icon.paa";
		mapSize = 5;
	};
	class Plane: Air {
	      class HitPoints;
	      class AnimationSources;
	      class NewTurret;
	      class ViewPilot;
		};
	class sr71a: Plane
	{
		scope=public;
		destrType = "DestructWreck";
		model="\sr71a\sr71a";
		displayName="$STR_sr71a_NAME";
		extCameraPosition[] = {0, 4, -35};
		side=TWest;
		faction = "BLU_F";
		vehicleclass = "Air";
		crew = "B_Pilot_F";
		driverAction="Pilot";
		hasGunner=1;
		insideSoundCoef=0.85000;
		driverIsCommander = 1;
		gunnerAction = "Pilot"
		gunnerOpticsColor[] = {1, 1, 1, 1};
		gunnerOpticsModel = "\a3\Weapons_f\optika_empty";
		driverOpticsModel = "\a3\Weapons_f\optika_empty";
		opticsPPEffects[] = {"OpticsCHAbera1", "OpticsBlur1"};
		opticsFlare = true;
		opticsDisablePeripherialVision = true;
		optics = true;

		simulation="airplane";
		animated=1;
		_generalMacro="Plane";

		opticsZoomMin = 0.01;
		opticsZoomMax = 0.9;
		distanceZoomMin = 300;
		distanceZoomMax = 300;
		weapons[]={};
		magazines[]={};
		hiddenselections[]= {};
		memoryPointDriverOptics = "gunnerview";
		memoryPointGunnerOptics = "gunnerview";
		picture = "\sr71a\picture.paa";
		icon = "\sr71a\icon.paa";
		mapSize = 40;
		gearRetracting = true;
		nameSound="aircraft";
		soundEngine[]={"\sr71a\sound\X_A_sr71_3.wav",4,1.2};
		soundEnviron[]={"\sr71a\sound\A_EFSC.wav",db-60,1.0};			// Cessna sound
		soundServo[]={"\sr71a\sound\FLAPS.wav",db-10,1};		// Cessna sound
		soundEngineOnInt[] = {"\sr71a\sound\X_T_COMB_START.wav", 0.562341, 1.000000};
		soundEngineOnExt[] = {"\sr71a\sound\X_T_COMB_START.wav", 0.562341, 1.000000, 900};
		soundEngineOffInt[] = {"\sr71a\sound\X_T_sr71_SHUT.wav", 0.562341, 1.000000};
		soundEngineOffExt[] = {"\sr71a\sound\X_T_sr71_SHUT.wav", 0.562341, 1.000000, 900};
		camouflage = 25;
		audible = 10;
		accuracy = 0.300000;
        commanderCanSee = 31;
		gunnerCanSee = "1+16+4+8";
        landingSpeed = 350;
		acceleration = 450;
		maxSpeed = 3250;
		armor = 70;
		armorStructured = 1;
		wheelSteeringSensitivity = 9.000000;
		irScanRangeMin = 125;
		irScanRangeMax = 40000;
		irScanToEyeFactor = 7;
		aileronSensitivity = 0.3;
		elevatorSensitivity = 7.7;
		brakeDistance=300;
		flapsFrictionCoef = 0.300000;
		noseDownCoef = 1.5;	// how much goes nose down during turns
		envelope[]=
		{
		// speed relative to max. speed -> lift
		//      0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0 1.1 // rel. speed
			0.0,0.5,1.0,2.0,4.0,4.5,5.0,5.3,5.6,6.0,6.2,6.5,6.7,0 // lift
		};
		laserScanner = 1;
		gunAimDown = 0.045000;
		leftDustEffect = "LDustEffects";
		rightDustEffect = "RDustEffects";
		minFireTime = 30;
		landingAoa="rad 10";

		class Library {
			libTextDesc = "$STR_sr71a_DESCR";
		};

		class Sounds {
			class EngineLowOut {
				sound[] = {"ca\sounds\Air\AV8\ext\ext-jetair-engine-low1", db8, 1.0, 1200};
				frequency = "1.0 min (rpm + 0.5)";
				volume = "engineOn*camPos*(rpm factor[0.85, 0])";
			};

			class EngineHighOut {
				sound[] = {"ca\sounds\Air\AV8\ext\ext-jetair-engine-high3", db8, 1.3, 1800};
				frequency = "1";
				volume = "engineOn*camPos*(rpm factor[0.55, 1.0])";
			};

			class ForsageOut {
				sound[] = {"ca\sounds\Air\AV8\ext\ext-jetair-forsage1", db5, 0.8, 2000};
				frequency = "1";
				volume = "engineOn*camPos*(thrust factor[0.5, 1.0])";
				cone[] = {3.0, 3.92, 1.9, 0.5};
			};

			class WindNoiseOut {
				sound[] = {"ca\sounds\Air\AV8\ext\ext-jetair-wind1", db-5, 1.0, 150};
				frequency = "(0.1+(1.2*(speed factor[1, 150])))";
				volume = "camPos*(speed factor[1, 150])";
			};

			class EngineLowIn {
				sound[] = {"ca\sounds\Air\AV8\int\int-av8b-engine-low", db0, 1.0};
				frequency = "1.0 min (rpm + 0.5)";
				volume = "(1-camPos)*(engineOn*(rpm factor[0.85, 0]))";
			};

			class EngineHighIn {
				sound[] = {"ca\sounds\Air\AV8\int\int-av8b-engine", db0, 1.0};
				frequency = "1";
				volume = "(1-camPos)*(engineOn*(rpm factor[0.55, 1.0]))";
			};

			class ForsageIn {
				sound[] = {"ca\sounds\Air\AV8\int\int-av8b-forsage-1", db-10, 1.0};
				frequency = "1";
				volume = "(1-camPos)*(engineOn*(thrust factor[0.5, 1.0]))";
			};

			class WindNoiseIn {
				sound[] = {"ca\sounds\Air\AV8\int\int-jetair-wind1", db-10, 1.0};
				frequency = "(0.1+(1.2*(speed factor[1, 150])))";
				volume = "(1-camPos)*(speed factor[1, 150])";
			};
		};

		class ViewPilot: ViewPilot
		{
			initFov = 0.8; minFov = 0.3; maxFov = 1.2;
			initAngleX = 0; minAngleX = -40; maxAngleX = +100;
			initAngleY = 0; minAngleY = -180; maxAngleY = 180;
		};

		class Turrets
		{
			class MainTurret : NewTurret
			{
				body = "";
      			gun = "";
				commanding = -1;
				memoryPointsGetInGunner= "pos gunner";
				memoryPointsGetInGunnerDir= "pos gunner dir";
				weapons[]={"Laserdesignator","NVGoggles","Binocular"};
				magazines[]={"Laserbatteries"};
				castGunnerShadow = 1;
				viewGunnerShadow = 1;
				gunnerAction = "Pilot";
				gunnerInAction = "Pilot";
			};
		};

		class ViewOptics
		{
			initAngleX = 0;
			minAngleX = -360;
			maxAngleX = 360;
			initAngleY = 0;
			minAngleY = -360;
			maxAngleY = 360;
			initFov = 0.99;
			minFov = 0.01;
			maxFov = 0.99;
		};

		steerAheadSimul=1.0;
		steerAheadPlan=2.0;

		class EventHandlers
        {
            Init = "_this execVM ""\sr71a\scr\common_init.sqf""; [_this select 0] exec ""\sr71a\scr\common_init.sqs"";_this execVM ""\sr71a\scr\gear_trigger.sqf"";";
            //engine="if (_this select 1) then {(_this select 0) setobjecttexture[0, ""\sr71a\efa_glass_ca.paa""];} else {(_this select 0) setobjecttexture[0, ""];}";
			fired = "_this call BIS_Effects_EH_Fired;";
			killed = "_this call BIS_Effects_EH_Killed;";
        };

		class DestructionEffects {};
		cost = 20000000;
		type = 2;
		threat[] = {1, 1, 0.700000};

		class Reflectors {

			class Left {
				color[] = {0.5, 0.8, 1.0, 1.0};
				ambient[] = {0.07, 0.07, 0.07, 1.0};
				position = "L svetlo";
				direction = "konec L svetla";
				hitpoint = "L svetlo";
				selection = "L svetlo";
				size = 1;
				brightness = 0.7;
			};

			class Right {
				color[] = {0.5, 0.8, 1.0, 1.0};
				ambient[] = {0.07, 0.07, 0.07, 1.0};
				position = "P svetlo";
				direction = "konec P svetla";
				hitpoint = "P svetlo";
				selection = "P svetlo";
				size = 1;
				brightness = 0.7;
			};
		};

		class MarkerLights {
			class RedStill {
				color[] = {0.2, 0.02, 0.02, 1};
				ambient[] = {0.3, 0.03, 0.03, 1};
				name = "cerveny pozicni";
				brightness = 0.1;
				blinking = false;
			};

			class GreenStill {
				color[] = {0.02, 0.2, 0.15, 1};
				ambient[] = {0.03, 0.3, 0.03, 1};
				name = "zeleny pozicni";
				brightness = 0.1;
				blinking = false;
			};
			class WhiteStill {
				color[] = {0.2, 0.2, 0.2, 1};
				ambient[] = {0.3, 0.3, 0.3, 1};
				name = "bily pozicni";
				brightness = 0.1;
				blinking = false;
			};

			class WhiteBlinking {
				color[] = {1, 1, 1, 1};
				ambient[] = {0.2, 0.2, 0.2, 1};
				name = "bily pozicni blik";
				brightness = 0.1;
				blinking = true;
			};

			class RedBlinking {
				color[] = {1, 0.05, 0.05, 1};
				ambient[] = {0.2, 0.02, 0.02, 1};
				name = "cerveny pozicni blik";
				brightness = 0.1;
				blinking = true;
			};
		};

		// Radar stuff
		irTarget=true;
		irScanRange = 2000;
		irScanGround = true;

		class AnimationSources {
			class fgear
			{
				source = "user";
				initPhase = 0;
				animPeriod =4;
			};
			class fgear2
			{
				source = "user";
				initPhase = 0;
				animPeriod =4;
			};
			class fgear3
			{
				source = "user";
				initPhase = 0;
				animPeriod =4;
			};
			class fgear4
			{
				source = "user";
				initPhase = 0;
				animPeriod =4;
			};
			class rgear
			{
				source = "user";
				initPhase = 0;
				animPeriod =4;
			};
			class rgear2
			{
				source = "user";
				initPhase = 0;
				animPeriod =4;
			};
			class rgear3
			{
				source = "user";
				initPhase = 0;
				animPeriod =4;
			};
			class rgear4
			{
				source = "user";
				initPhase = 0;
				animPeriod =4;
			};
			class lgear
			{
				source = "user";
				initPhase = 0;
				animPeriod =4;
			};
			class lgear2
			{
				source = "user";
				initPhase = 0;
				animPeriod =4;
			};
			class lgear3
			{
				source = "user";
				initPhase = 0;
				animPeriod =4;
			};
			class lgear4
			{
				source = "user";
				initPhase = 0;
				animPeriod =4;
			};
		};
		class UserActions
		{
			class Afterburner
			{
				displayName ="$STR_sr71a_BON";
				position = "doorarea";
				radius =100;
				showWindow = 0;
				condition = "speed this > 100 and player in this and speed this >0 and this animationPhase ""ABSwitch"" <= 0.1";
				statement = "this execvm ""\sr71a\Afterburner.sqf"";";
				onlyforplayer = false;
			};

			class Afterburner_1
			{
				displayName ="$STR_sr71a_BOFF";
				position = "doorarea";
				radius =100;
				showWindow = 0;
				condition = "player in this and this animationPhase ""ABSwitch"" >= 0.9";
				statement = "this animate [""ABSwitch"",0]";
				onlyforplayer = false;
			};

			class parchuchute {
				displayName = "$STR_sr71a_para";
				position = "doorarea";
				onlyforplayer = 1;
				showWindow = 0;
				radius = 100;
				condition = "this animationphase ""fgear"" < 0.5 AND (player in this) AND speed (this) > 100 AND speed (this) < 450 AND Alive(this)";
				statement = "[this,player] execVM ""\sr71a\scr\chute.sqf"";";
			};
 		};

		class Exhausts
		{
		   class Exhaust1
		   {
			   position = "exhaust1";
			   direction = "exhaust1_dir";
			   effect = "ExhaustsEffectPlane";
		   };

		   class Exhaust2
		   {
			   position = "exhaust2";
			   direction = "exhaust2_dir";
			   effect = "ExhaustsEffectPlane";
		   };
		};
	};
};
