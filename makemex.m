echo on

funcs = {
    'aria_init',  
    'arrobot_connect', 
    'arrobot_disconnect', 
    'arloginfo', 
    'arrobot_setvel', 
    'arrobot_setrotvel', 
    'arrobot_getx', 
    'arrobot_gety', 
    'arrobot_getth', 
    'arrobot_stop',
    'arrobot_length',
    'arrobot_width',
    'arrobot_radius',
    'arrobot_getsonarrange',
    'arrobot_getnumsonar',
    'arrobot_getdigin',
    'arrobot_setlatvel',
    'arrobot_getbatteryvoltage',
    'arrobot_getvel',
    'arrobot_getrotvel',
    'arrobot_getlatvel',
    'arrobot_setdeltaheading',
    'arrobot_resetpos',
	  'arrobot_isstalled',
	  'arrobot_isleftstalled',
  	'arrobot_isrightstalled',
    'arrobot_setwheelvels'
}

% Unload old mex functions etc.  Note, if you add a new mex function above that
% does not match these patterns, add it to this list or a pattern that
% matches it.
clear aria_* arloginfo arrobot_*

 
% Set filenames and options depending on current platform
def = ''
switch computer
    case 'PCWIN'
		ariainstdir = 'C:/Program Files/MobileRobots/Aria'
        ariaclink = '-L. -lariac_vc10_i386'
        arialink = '-L../lib -L../bin -lAriaVC10'
        def = '-DWIN32 -win32'
        ariadll = '../bin/AriaVC10.dll'
		disp 'You are on Windows 32 bit. Will attempt to use AriaVC10.dll and ariac_vc10_i386.lib, built in Release configuration for win32 platform with Visual C++ 2010.'
    case 'PCWIN64'
		ariainstdir = 'C:/Program Files/MobileRobots/Aria'
        ariaclink = '-L. -lariac_vc10_x64'
        def = '-DWIN32'
        arialink = '-L../lib64 -L../bin64 -lAriaVC10'
        ariadll = '../bin64/AriaVC10.dll'
		disp 'You are on Windows 64 bit. Will attempt to use AriaVC10.dll and ariac_vc10_x64.lib, built in Release configuration for x64 platform with Visual C++ 2010.'
    case 'GLNX86'
		ariainstdir = '/usr/local/Aria'
        ariaclink = '-L. -lariac'
        arialink = '-L../lib -lAria'
        ariadll = '../lib/libAria.so'
		disp 'You are on Linux 32 bit. Will attempt to use libAria.so and libariac.so.
    case 'GLNXA64'
		ariainstdir = '/usr/local/Aria'
        ariaclink = '-L. -lariac'
        arialink = '-L../lib -lAria'
        ariadll = '../lib/libAria.so'
		disp 'You are on Linux 64 bit. Will attempt to use libAria.so and libariac.so.
	case 'MACI64'
	    disp 'Sorry, not set up for Mac yet. You will need to get ARIA and ariac built on Mac, then edit makemex.m to set the appropriate mex compilation flags under the MACI64 computer type case instead of displaying this message..'
        return
    otherwise
        disp 'error, unrecognized system type. (what kind of computer and OS are you on?)'
        computer
		return
end

% Put a copy of the ARIA runtime library into the current directory
disp 'Copying ARIA DLL into current directory so Matlab can easily find it...'
eval(['copyfile ' ariadll ' .'])

% Compile all the mex functions listed above:

for i = 1:length(funcs)
  cmd = sprintf('mex -g -v %s -DMATLAB -I. %s %s mex-src/%s.c', def, ariaclink, arialink, funcs{i});
  cmd
  eval(cmd)
end

