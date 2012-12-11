

/* MEX function for Matlab */

#include "mex.h"
#include "ariac.h"


void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
	if(nlhs != 1) {
		mexErrMsgIdAndTxt("arrobot_isstalled", "One output required.");
		return;
	}
	plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32CLASS, mxREAL);
    *((int32_T*)mxGetData(plhs[0])) = arrobot_isstalled();
}
	