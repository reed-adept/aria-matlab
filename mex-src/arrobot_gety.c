

/* MEX function for Matlab */

#include "mex.h"
#include "ariac.h"


void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    double y;
    //mexPrintf("arrobot_gety mex function start\n");
	if(nlhs != 1) {
		mexErrMsgIdAndTxt("arrobot_gety", "One output required.");
		return;
	}
    //mexPrintf("arrobot_gety mex function create double m\n");
	plhs[0] = mxCreateDoubleMatrix(1, 1, mxREAL);
    //mexPrintf("arrobot_gety mex function calling arrobot_gety...\n");
    y = arrobot_gety();
    //mexPrintf("arrobot_gety mex function set plhs[0] to %f...\n", y);
    *(mxGetPr(plhs[0])) = y;
    //mexPrintf("arrobot_gety mex function end\n");
}
	