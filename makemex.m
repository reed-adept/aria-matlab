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
    'arrobot_getlatvel'
}

% Unload mex functions etc.  Note, if you add a new mex function below that
% does not match these patterns, add it to this list or a pattern that
% matches it.
clear aria_* arloginfo arrobot_*

 
% Set filenames and options depending on current platform
def = ''
switch computer
    case 'PCWIN'
        ariaclink = '-L. -lariac_vc10'
        arialink = '-L../lib -lAriaVC10'
        def = '-DWIN32'
        ariadll = '../bin/AriaVC10.dll'
    case 'PCWIN64'
        ariaclink = '-L. -lariac_vc10_x64'
        def = '-DWIN32'
        arialink = '-L../lib64 -lAriaVC10'
        ariadll = '../bin64/AriaVC10.dll'
    case 'GLNX86'
        ariaclink = '-L. -lariac'
        arialink = '-L../lib -lAria'
        ariadll = '../lib/libAria.so'
    case 'GLNXA64'
        ariaclink = '-L. -lariac'
        arialink = '-L../lib -lAria'
        ariadll = '../lib/libAria.so'
    otherwise
        disp 'what kind of computer are you on?'
        computer
end

% Get ARIA runtime library
eval(['copyfile ' ariadll '.'])

% Compile all the mex functions:

for i = 1:length(funcs)
  cmd = sprintf('mex -g %s -DMATLAB -I. %s %s mex-src/%s.c', def, ariaclink, arialink, funcs{i});
  cmd
  eval(cmd)
end

%{

eval( ['mex -g ' def '-DWIN32 -DMATLAB -I. -L. -lariac_vc10_x64 -L../lib64 -lAriaVC10 mex-src/aria_init.c'] )
mex -g -DWIN32 -DMATLAB -I. -L. -lariac_vc10_x64 -L../lib64 -lAriaVC10 mex-src/arrobot_connect.c
mex -g -DWIN32 -DMATLAB -I. -L. -lariac_vc10_x64 -L../lib64 -lAriaVC10 mex-src/arrobot_disconnect.c
mex -g -DWIN32 -DMATLAB -I. -L. -lariac_vc10_x64 -L../lib64 -lAriaVC10 mex-src/arloginfo.c
mex -g -DWIN32 -DMATLAB -I. -L. -lariac_vc10_x64 -L../lib64 -lAriaVC10 mex-src/arrobot_setvel.c
mex -g -DWIN32 -DMATLAB -I. -L. -lariac_vc10_x64 -L../lib64 -lAriaVC10 mex-src/arrobot_setrotvel.c
mex -g -DWIN32 -DMATLAB -I. -L. -lariac_vc10_x64 -L../lib64 -lAriaVC10 mex-src/arrobot_getx.c
mex -g -DWIN32 -DMATLAB -I. -L. -lariac_vc10_x64 -L../lib64 -lAriaVC10 mex-src/arrobot_gety.c
mex -g -DWIN32 -DMATLAB -I. -L. -lariac_vc10_x64 -L../lib64 -lAriaVC10 mex-src/arrobot_getth.c
mex -g -DWIN32 -DMATLAB -I. -L. -lariac_vc10_x64 -L../lib64 -lAriaVC10 mex-src/arrobot_stop.c

%}
