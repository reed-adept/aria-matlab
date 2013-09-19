
% initialize with default arguments: (connect to robot connected to this
% computer via COM1 serial port)
aria_init

% initialize aria to connect to a remote computer (e.g. a robot with a wifi
% interface instead of onboard computer, or a simulator running on another
% computer):
%aria_init -rh 10.0.200.42

% connect to the robot:
arrobot_connect

% make the robot drive in a small circle:
arrobot_setvel(300)
arrobot_setrotvel(35)

disp 'Running. Call arrobot_stop to stop robot motion. Call arrobot_disconnect to disconnect from robot.'