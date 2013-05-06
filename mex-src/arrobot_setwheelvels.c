

/* MEX function for Matlab */

#include "mex.h"
#include "ariac.h"


void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    double *p;
  	if(nrhs != 2) {
		  mexErrMsgIdAndTxt("arrobot_setwheelvels", "Two inputs required.");
		  return;
	  }
    arrobot_setwheelvels(*(mxGetPr(prhs[0])), *(mxGetPr(prhs[1])));
}
	
