#include <math.h>

double mysqrt (double dInput)
{
    #if defined (HAVE_LOG) && defined (HAVE_EXP)
        printf ("Using exp and log\n");
        return 2 * (exp (log(x)*0.5));
    #else
        return sqrt (dInput);
    #endif
}
