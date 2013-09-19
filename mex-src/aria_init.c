

/* MEX function for Matlab */

#include <string.h>
#include "mex.h"
#define MATLAB 1
#include "ariac.h"


void mexLog(const char *s)
{
    mexPrintf("aria: %s\n", s);
}


void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{

   int pi;
   int ai;
   char **arg;
   char **argv;
   const char *scriptname;
   size_t n;
   size_t snlen;
   char buf[256];
   
   aria_setloghandler(&mexLog);
   
   argv = (char**)malloc((1+nrhs) * sizeof(char*));
   scriptname = mexFunctionName();
   snlen = strlen(scriptname);
   argv[0] = (char*)malloc(snlen+1);
   strncpy(argv[0], scriptname, snlen);
   mexPrintf("nrhs=%d, argv[0]=%s\n", nrhs, argv[0]);
   for(ai = 1, pi = 0; pi < nrhs; ++pi, ++ai)
   {
       memset(buf, 0, 256);
       if(mxGetString(prhs[pi], buf, 255) != 0)
       {
           mexPrintf("aria_init: error copying argument %d from matlab. not a string or too long. aborting without initializing aria.");
           return;
       }
       mexPrintf("prhs[%d]=%s\n", pi, buf);
       n = strlen(buf);
       argv[ai] = (char*)malloc(n+1);
       strncpy(argv[ai], buf, n+1);
       mexPrintf("argv[%d]=%s\n", ai, argv[ai]);
   }
   
   aria_init(nrhs+1, argv);
}
	
