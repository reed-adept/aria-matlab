

/* MEX function for Matlab */

#include "mex.h"
#include "ariac.h"


void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
	if(nrhs != 1) {
		mexErrMsgIdAndTxt("arrobot_setdeltaheading", "One input required.");
		return;
	}
    arrobot_setdeltaheading(*(mxGetPr(prhs[0])));
}
	