

/* MEX function for Matlab */

#include "mex.h"
#include "ariac.h"


void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
	if(nrhs == 1) {
        arrobot_command( * (int*)mxGetData(prhs[0]) );
	} else if(nrhs == 2) {
        arrobot_command_int( * (int*)mxGetData(prhs[0]), * (int*)mxGetData(prhs[1]) );
	} else if(nrhs == 3) {
        arrobot_command_2bytes( * (int*)mxGetData(prhs[0]), * (int*)mxGetData(prhs[1]),  * (int*)mxGetData(prhs[2]) );
	} else {
		mexErrMsgIdAndTxt("arrobot_command", "Command and optional additional arguments required");
	}
}
	
