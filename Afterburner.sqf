private ["_MaxIntensity","_Boost","_leftengine","_rightengine","_emitters","_Intensity","_looptime", "_plane"];

_MaxIntensity = 0.15;
_Boost = 0.030;
_Intensity = 0.12;
//_this setvariable ["afterburner",false];

_maxspeed = 3250;
_plane = _this;
_plane animate ["ABSwitch",1];
sleep 0.5;

_leftengine = "#particlesource" createVehicle position _this;
_rightengine = "#particlesource" createVehicle position _this;
_emitters = [_leftengine,_rightengine];
{_x setParticleRandom [0.05,[0.05,0.05,0.05],[0.05,0.05,0.05],0,0.8,[0.1,0.1,0.1,0],0,0]} foreach _emitters;
{_x setDropInterval 0} foreach _emitters;
_looptime = 0.1;
_runtime = 200;
while {(alive _plane) and (_plane animationphase "ABSwitch" >= 0.1)} do {
if (isengineon _plane) then 
{
if (_Intensity < _MaxIntensity) then {_Intensity = _Intensity + 0.1*(15*_looptime)};
if ((speed _this) < _maxspeed) then {_this setVelocity [(velocity _this select 0)+((vectordir _this) select 0)*((_Boost*_Intensity/2)*(15*_looptime)),(velocity _this select 1)+((vectordir _this) select 1)*((_Boost*_Intensity/2)*(15*_looptime)),(velocity _this select 2)+((vectordir _this) select 2)*((_Boost*_Intensity/2)*(10*_looptime))]};
if (fuel _this > 0) then {_this setFuel ((fuel _this)-((0.002/5000)*(3*_looptime)))};
} 
else {if (_Intensity > 0) then {_Intensity = _Intensity - 0.2*(15*_looptime)}};
_leftengine setParticleParams ["\Ca\data\cl_exp","","Billboard",1,0.07,(_plane selectionposition "osa vrtule 1"),[(velocity _this select 0) - ((vectordir _this) select 0)*30,(velocity _this select 1) - ((vectordir _this) select 1)*30,(velocity _this select 2) - ((vectordir _this) select 2)*30],1,1.2745,1,0,[0.6+(2*(speed _this/_maxspeed)),0.5+(10*(speed _this/_maxspeed))],[[0.040,0.100,0.900,0.1500*_Intensity],[0.200,0.200,0.800,0.1000*_Intensity],[0.500,0.200,0.000,0.0250*_Intensity],[0.000,0.000,0.000,0.0000*_Intensity]],[0],0,0,"","",_this];
_rightengine setParticleParams ["\Ca\data\cl_exp","","Billboard",1,0.07,(_plane selectionposition "osa vrtule 2"),[(velocity _this select 0) - ((vectordir _this) select 0)*30,(velocity _this select 1) - ((vectordir _this) select 1)*30,(velocity _this select 2) - ((vectordir _this) select 2)*30],1,1.2745,1,0,[0.6+(2*(speed _this/_maxspeed)),0.5+(10*(speed _this/_maxspeed))],[[0.040,0.100,0.900,0.1500*_Intensity],[0.200,0.200,0.800,0.1000*_Intensity],[0.500,0.200,0.000,0.0250*_Intensity],[0.000,0.000,0.000,0.0000*_Intensity]],[0],0,0,"","",_this];

{_x setpos (getpos _this)} foreach _emitters;
if (_Intensity > 0) then {{_x setDropInterval 0.001} foreach _emitters} else {{_x setDropInterval 0} foreach _emitters};

_looptime = time;

sleep 0.05; // mod by Crowe

_runtime = _runtime - 1;
};
deleteVehicle _leftengine;
deleteVehicle _rightengine;
sleep 3;
