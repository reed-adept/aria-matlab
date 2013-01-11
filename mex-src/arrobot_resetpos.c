

/* MEX function for Matlab */

#include "mex.h"
#include "ariac.h"


void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
	if(nrhs > 0) {
		mexErrMsgIdAndTxt("arrobot_resetpos", "No input parameters.");
		return;
	}
    arrobot_resetpos();
}
	