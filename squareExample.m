
try

    % simple example that drives robot to a series of positions
    
    arrobot_disconnect
    clear all

    points = {{3000, 0}, {3000, 3000}, {0, 3000}, {0, 0}}
    velMult = 0.5
    distThresh = 350 % mm
    angleThresh = 0.5 % deg

    aria_init -rh 10.0.151.11
    arrobot_connect()
    arrobot_resetpos()
    curPoint = 1


    xpositions = []
    ypositions = []
    %fig = figure('NextPlot', 'add')
    %ph = newplot

    disp 'press control-c to stop. then maybe arrobot_stop to stop the robot.'
    while (true)
      % get current robot position from aria
      rx = arrobot_getx
      ry = arrobot_gety
      xpositions = [xpositions rx]
      ypositions = [ypositions ry]
     % plot(xpositions, ypositions)

      % Check if we've reached goal point
      p = points{curPoint}
      px = p{1}
      py = p{2}
      d = sqrt( (px - rx)^2 + (py - ry)^2 )
      disp(sprintf(' distance remaining: %f', d))
      if d <= distThresh
        disp 'reached point'
        arrobot_stop

        % choose next point in list
        curPoint = curPoint + 1
        if curPoint > length(points)
          curPoint = 1
        end
        p = points{curPoint} 
        px = p{1}
        py = p{2}

        % determine how far to rotate to face this next point
        rt = arrobot_getth
        dt =  (atan2(py - ry, px - rx) * (180/3.14159)) - rt
        dt = mod((dt + 180), 360) - 180 % restrict to (-180,180)


        % restrict to (-180,180)
    %     if (dt >= 360)
    %         dt = dt - 360.0 * (dt / 360)
    %     end
    %     if (dt < -360)
    %         dt = dt + 360.0 * (dt / -360)
    %     end
    %     if (dt <= -180)
    %         dt = + 180.0 + (dt + 180.0)
    %     end
    %     if (dt > 180)
    %         dt = - 180.0 + (dt - 180.0)
    %     end

        % request robot to turn
        disp(sprintf('Turning by %d deg.', dt))
        arrobot_setdeltaheading(dt)

        % wait until heading change is achieved within specified threshold
        target = rt + dt
        target = mod((target + 180), 360) - 180 % restrict to (-180,180)
        while abs(arrobot_getth - target) > angleThresh  % note, get newest robot theta from aria each time
          disp(sprintf(' angle remaining %f', abs(arrobot_getth - target)))
          pause(0.08)
        end
        disp 'Heading done.'
      else
        % request robot velocity proportionally to distance remaining
        arrobot_setvel(d*velMult)
        % Could also set delta heading or rotational velocity here to continuously
        % correct angle as well.
      end
      pause(0.08)
    end

catch err
    disp 'error or cancelled'
    arrobot_stop
end


