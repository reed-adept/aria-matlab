

/* MEX function for Matlab */

#include "mex.h"
#include "ariac.h"


void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
   //mexPrintf("arrobot_connect mexFunction start\n");
   arrobot_connect();
  // mexPrintf("arrobot_connect mexFunction end\n");
}
	