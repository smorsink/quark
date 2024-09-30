/***************************************************************************
 * consts.h 
 *
 * This file contains definitions of constants used in the procedures.
 *
 **************************************************************************/

#define DM (1.0/(MDIV-1.0))          /* spacing in mu direction */ 
#define RDIV 900                     /* grid point in RK integration */ 
#define SMAX 0.99999                  /* maximum value of s-coordinate */  
#define DS (SMAX/(SDIV-1.0))         /* spacing in s-direction */
#define LMAX 10                      /* max. term in Legendre poly. */

/*#define C 2.9979e10*/              /* speed of light in vacuum (cm/s) */
#define C 2.99792458e10
/*#define G 6.6732e-8*/              /* gravitational constant (cm^3/g/s^2) */
#define G 6.67259e-8
#define H 6.626069e-27               /* Planck's constant (erg*s) */
#define K_B 1.3807e-16               /* Boltzmann's constant (erg/K) */
#define STEFAN 5.6705e-5             /* Stefan-Boltzmann (erg/cm^2/s/K^4) */

#define KAPPA (1.0e-15*C*C/G)        /* scaling factor */
#define KSCALE (KAPPA*G/(C*C*C*C))   /* another scaling factor */
/*#define MSUN 1.987e33*/            /* Mass of Sun */
#define MSUN 1.989e33
#define SQ(x) ((x)*(x))              /* square macro */
#define MB 1.66e-24                  /* baryon mass */
#define RMIN 1.0e-15                 /* use approximate TOV equations when
                                        computing spherical star and r<RMIN */
#define UNUSED (-1.11e30)            /* Used in the Ridder zero-finder */ 
#ifndef PI
#define PI 3.141592653589793              /* what else */
#endif

#define M_MAX 6         /* Maximum l=m mode considered */
#define BOUND 1         /* Excludes last grid point, since we set everything
                           to zero there */
#define MAXIT 30        /* Maximum number of iterations in rtsec_G */ 
#include <float.h>
#include <limits.h>

#define EPSILON 1.0e-5  /* This number is used in several places.  If it is
                           insufficient for some application, make a new 
                           constant rather than change this one. */

#ifndef DBL_EPSILON
#define DBL_EPSILON 1e-15
#endif

/*#define DEBUG 0*/
#define TESTTHETA 1
#define N_THETA 100
#define N_ALTITUDE 100
#define N_HORIZON 50
#define THETAMIN 0 /*Can be set to small positive value to avoid possible 
		    *difficulties with poles*/



