_vehicle=vehicle (_this select 0);
_loopexit = false;
_brakechute = "sr71a_brakechute" CreateVehicle (getPos _vehicle);
_brakechute attachTo [_vehicle,[0,0,0],"brakechute_point"];
_brakechute enableSimulation false;

while {!(_loopexit)} do  
{
	_speed = speed _vehicle;
	_alt=(getPos _vehicle) select 2;
	_GearDown=(_vehicle animationPhase "fgear")<0.1;
	
	player vehicleChat "Brake Chute Deployed";
	if ((_speed>40) and (_alt<1) and _GearDown) then 
	{
		_vel=velocity _vehicle; 
		_vehicle setvelocity[(_vel select 0) * 0.95,(_vel select 1) * 0.95,(_vel select 2) * 0.95];
		sleep 0.5;
	}
	else
	{  
		if (_speed<40) then 
		{
			detach _brakechute;
			_brakechute enableSimulation true;
			deleteVehicle _brakechute;
			player vehicleChat "Brake Chute Detached!";
			_loopexit = true;   
		};
	};
};