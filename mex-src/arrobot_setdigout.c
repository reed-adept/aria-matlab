

/* MEX function for Matlab */

#include "mex.h"
#include "ariac.h"


void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    uint8_T *p;
	if(nrhs != 1) {
		mexErrMsgIdAndTxt("arrobot_setdigout", "One input required.");
		return;
	}
    p = (uint8_T*)mxGetData(prhs[0]);
    arrobot_setdigout(*p);
}
	