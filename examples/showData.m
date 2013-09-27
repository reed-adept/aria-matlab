

% This example just displays data from the robot, does not cause it to move.
% You can use the joystick to move the robot, or call arrobot_ functions in
% the Matlab command window.

% TODO: show examples of plotting data.


%aria_init -rh 10.0.200.42 -ris
aria_init
arrobot_connect

disp(sprintf('Connected to robot. Radius=%d, Length=%d, Width=%d, NumSonar=%d.', arrobot_getradius, arrobot_getlength, arrobot_getwidth, arrobot_getnumsonar))

arloginfo


while (true)

  disp(sprintf('x:%f y:%f th:%f vel:%f rotvel:%f stall:%d battv:%f', arrobot_getx, arrobot_gety, arrobot_getth, arrobot_getvel, arrobot_getrotvel, arrobot_isstalled, arrobot_getbatteryvoltage))

  pause(2)
 
end


