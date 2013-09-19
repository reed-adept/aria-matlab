

/* MEX function for Matlab */

#include "mex.h"
#include "ariac.h"


void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    double *p;
	if(nrhs != 1) {
		mexErrMsgIdAndTxt("arrobot_setvel", "One input required.");
		return;
	}
    arrobot_setvel(*(mxGetPr(prhs[0])));
}
	