

/* MEX function for Matlab */

#include "mex.h"
#include "ariac.h"


void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    double t;
    //mexPrintf("arrobot_getth mex function start\n");
	if(nlhs != 1) {
		mexErrMsgIdAndTxt("arrobot_getth", "One output required.");
		return;
	}
    //mexPrintf("arrobot_getth mex function create double m\n");
	plhs[0] = mxCreateDoubleMatrix(1, 1, mxREAL);
    //mexPrintf("arrobot_getth mex function calling arrobot_getth...\n");
    t = arrobot_getth();
   // mexPrintf("arrobot_getth mex function set plhs[0] to %f...\n", t);
    *(mxGetPr(plhs[0])) = t;
    //mexPrintf("arrobot_getth mex function end\n");
}
	