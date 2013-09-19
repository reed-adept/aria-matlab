

/* MEX function for Matlab */

#include "mex.h"
#include "ariac.h"


void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
	if ( nrhs != 0 ) 
    {
        mexErrMsgIdAndTxt("arrobot_getpose","This function takes no input arguments.");
        return;
    }
    
    if (nlhs < 1 || nlhs > 3)
    {
        mexErrMsgIdAndTxt("arrobot_getpose", "Output must be assigned to one matrix, two values [x, y] or three values [x, y, th]");
        return;
    }
      
    if(nlhs == 1)
    {
        double *op;
        arpose rp;
        plhs[0] = mxCreateDoubleMatrix(1, 3, mxREAL);
        op = mxGetPr(plhs[0]);
        rp = arrobot_getpose();
        op[0] = rp.x;
        op[1] = rp.y;
        op[2] = rp.th;
        return;
    }
    
    if(nlhs >= 2)
    {
         arpose rp = arrobot_getpose();
         plhs[0] = mxCreateDoubleScalar(rp.x);
         plhs[1] = mxCreateDoubleScalar(rp.y);
         if(nlhs > 2)
             plhs[2] = mxCreateDoubleScalar(rp.th);
    }
}
	
