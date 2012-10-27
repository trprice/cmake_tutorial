#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "TutorialConfig.h"

#ifdef USE_MYMATH
#include "MathFunctions.h"
#endif

int main (int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf (stdout, "%s Version %d.%d\n",
                 argv[0],
                 Tutorial_VERSION_MAJOR,
                 Tutorial_VERSION_MINOR);

        fprintf (stdout, "Usage: %s number\n", argv[0]);
        
        return 1;
    }

    double dInputValue = atof (argv[1]);

#ifdef USE_MYMATH
    double dOutputValue = mysqrt (dInputValue);
#else
    double dOutputValue = sqrt (dInputValue);
#endif

    fprintf (stdout, "The square root of %g is %g\n", dInputValue,
                    dOutputValue);
}
