

/* MEX function for Matlab */

#include "mex.h"
#include "ariac.h"


void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    double x;
    mexPrintf("arrobot_setvel mex function start\n");
	if(nrhs != 1) {
		mexErrMsgIdAndTxt("arrobot_setvel", "One input required.");
		return;
	}
    x = prhs[0];
    mexPrintf("arrobot_setvelx mex function got double %f\n", x);
    arrobot_setvel(x);
}
	