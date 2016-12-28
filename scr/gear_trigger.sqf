_blackbird = _this select 0;

while {(alive _blackbird)} do
{
	if (((_blackbird animationPhase "gear_trigger")==1) and ((_blackbird animationPhase "fgear")==0)) then
	{
		_blackbird say "sr71a_gear_up";
		_blackbird animate["fgear",1]; 
		_blackbird animate["fgear2",1]; 
		_blackbird animate["rgear",1];
		_blackbird animate["rgear4",1];
		_blackbird animate["rgear2",1];		
		_blackbird animate["lgear",1];
		_blackbird animate["lgear4",1];
		_blackbird animate["lgear2",1];
		sleep(4);		
		_blackbird animate["fgear3",1]; 
		_blackbird animate["fgear4",1];
		_blackbird animate["rgear3",1];
		_blackbird animate["lgear3",1];
	};
	if (((_blackbird animationPhase "gear_trigger")==0) and ((_blackbird animationPhase "fgear")==1)) then
	{
		_blackbird say "sr71a_gear_down";
		_blackbird animate["fgear3",0]; 
		_blackbird animate["fgear4",0];
		_blackbird animate["rgear3",0];
		_blackbird animate["lgear3",0];
		sleep(4);
		_blackbird animate["fgear",0]; 
		_blackbird animate["fgear2",0]; 
		_blackbird animate["rgear",0];
		_blackbird animate["rgear4",0];
		_blackbird animate["rgear2",0];		
		_blackbird animate["lgear",0];
		_blackbird animate["lgear4",0];
		_blackbird animate["lgear2",0];
	};
	sleep(0.1);
};