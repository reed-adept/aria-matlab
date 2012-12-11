

/* MEX function for Matlab */

#include "mex.h"
#include "ariac.h"


void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    double *ip;
	if(nrhs != 1) {
		mexErrMsgIdAndTxt("arrobot_getsonarrange", "One input required.");
		return;
	}
	if(nlhs != 1) {
		mexErrMsgIdAndTxt("arrobot_getsonarrange", "One output required.");
		return;
	}
    ip = mxGetPr(prhs[0]);
	plhs[0] = mxCreateDoubleMatrix(1, 1, mxREAL);
    *(mxGetPr(plhs[0])) = arrobot_getsonarrange(*ip);
}
	