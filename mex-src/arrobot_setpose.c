

/* MEX function for Matlab */

#include "mex.h"
#include "ariac.h"


void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
  arpose p;
	if(nrhs == 1) {
    double *arr = mxGetPr(prhs[0]);
    p.x = arr[0];
    p.y = arr[1];
    p.th = arr[2];
  } else if(nrhs == 3) {
    p.x = *mxGetPr(prhs[0]);
    p.y = *mxGetPr(prhs[1]);
    p.th = *mxGetPr(prhs[2]);
  } else {
		mexErrMsgIdAndTxt("arrobot_movepose", "One 3-element array (vector) input {x, y, th}, or three inputs (x, y, th), of floating point numbers (doubles) required.");
    return;
	}
  arrobot_setpose_p(p);
}
	
