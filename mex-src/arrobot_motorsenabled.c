

/* MEX function for Matlab */

#include "mex.h"
#include "ariac.h"


void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
	if(nlhs != 1) {
		mexErrMsgIdAndTxt("arrobot_motorsenabled", "One output required.");
		return;
	}
	plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *((int32_T*)mxGetData(plhs[0])) = arrobot_motors_enabled();
}
	
