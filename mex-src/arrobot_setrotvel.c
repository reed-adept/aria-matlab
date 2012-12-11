

/* MEX function for Matlab */

#include "mex.h"
#include "ariac.h"


void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    double *p;
    //mexPrintf("arrobot_setrotvel mex function start\n");
	if(nrhs != 1) {
		mexErrMsgIdAndTxt("arrobot_setrotvel", "One input required.");
		return;
	}
    p = mxGetPr(prhs[0]);
    //mexPrintf("arrobot_setrotvelx mex function got double %f\n", *p);
    arrobot_setrotvel(*p);
}
	