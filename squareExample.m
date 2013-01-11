
points = {{3000, 0}, {3000, 3000}, {0, 3000}, {0, 0}}
velMult = 0.5
distThresh = 300 % mm
angleThresh = 0.5 % deg

aria_init
arrobot_connect
curPoint = 0

while (true)
  % get current robot position from aria
  rx = arrobot_getx
  ry = arrobot_gety

  % Check if we've reached goal point
  p = points{curPoint}
  d = pdist({p, {rx, ry}})
  disp sprintf(' distance remaining: %f', d)
  if d <= distThresh:
    disp 'reached point'
    arrobot_stop

    % choose next point in list
    curPoint += 1
    if curPoint > length(points)
      curPoint = 0
    end
    p = points{curPoint} 
    px = p{1}
    py = p{2}

    % determine how far to rotate to face this next point
    rt = arrobot_getth
    dt = radtodeg(atan2(py - ry, px - rx)) - rt
    dt = ((dt + 180) mod 360) - 180 % restrict to (-180,180)

    % request robot to turn
    disp(sprintf('Turning by %d deg.', dt))
    arrobot_setdeltaheading(dt)

    % wait until heading change is achieved within specified threshold
    target = rt + dt
    while abs(arrobot_getth - target) > angleThresh  % note, get newest robot theta from aria each time
      disp(sprintf(' angle remaining %f', abs(arrobot_getth - target)))
      pause(100)
    end
    disp 'Heading done.'
  else
    % request robot velocity proportionally to distance remaining
    arrobot_setvel(d*velMult)
    % Could also set delta heading or rotational velocity here to continuously
    % correct angle as well.
  end
  pause(100)
end


