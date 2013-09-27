

/* MEX function for Matlab */

#include "mex.h"
#include "ariac.h"


void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    double *p;
	if(nrhs != 1) {
		mexErrMsgIdAndTxt("arrobot_move", "One input required.");
		return;
	}
    p = mxGetPr(prhs[0]);
    arrobot_move(*p);
}
	
