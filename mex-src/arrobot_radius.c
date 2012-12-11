

/* MEX function for Matlab */

#include "mex.h"
#include "ariac.h"


void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    double n;
	if(nlhs != 1) {
		mexErrMsgIdAndTxt("arrobot_genumsonar", "One output required.");
		return;
	}
	plhs[0] = mxCreateDoubleMatrix(1, 1, mxREAL);
    n = arrobot_radius();
    *(mxGetPr(plhs[0])) = n;
}
	