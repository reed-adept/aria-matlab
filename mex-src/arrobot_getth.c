

/* MEX function for Matlab */

#include "mex.h"
#include "ariac.h"


void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
	if(nlhs != 1) {
		mexErrMsgIdAndTxt("arrobot_getth", "One output required.");
		return;
	}
	plhs[0] = mxCreateDoubleMatrix(1, 1, mxREAL);
    *(mxGetPr(plhs[0])) = arrobot_getth();
}
	