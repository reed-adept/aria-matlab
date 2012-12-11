

/* MEX function for Matlab */

#include "mex.h"
#include "ariac.h"


void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    int8_T c;
	if(nlhs != 1) {
		mexErrMsgIdAndTxt("arrobot_getdigin", "One output required.");
		return;
	}
	plhs[0] = mxCreateNumericMatrix(1, 1, mxINT8_CLASS, mxREAL);
    c = arrobot_getdigin();
    *((int8_T*)mxGetData(plhs[0])) = c;
}
	