

/* MEX function for Matlab */

#include "mex.h"
#include "ariac.h"


void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
  arpose p;
  if(nrhs == 1)
  {
    p.x = mxGetPr(prhs[0])[0];
    p.y = mxGetPr(prhs[0])[1];
    p.th = mxGetPr(prhs[0])[2];
  }
  else if(nrhs == 2)
  {
    p.x = *mxGetPr(prhs[0]);
    p.y = 0.0;
    p.th = *mxGetPr(prhs[1]);
  } 
  else if(nrhs == 3)
  {
    p.x = *mxGetPr(prhs[0]);
    p.y = *mxGetPr(prhs[1]);
    p.th = *mxGetPr(prhs[2]);
  }
	else
  {
		mexErrMsgIdAndTxt("arrobot_setvels", "One vector input {x, y, th}, or two inputs (x, th), or three inputs (x, y, th) required.");
		return;
	}
  arrobot_setvels(p);
}
	
