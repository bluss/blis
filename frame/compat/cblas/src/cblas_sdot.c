#include "bli_config.h"
#include "bli_config_macro_defs.h"
#include "bli_system.h"
#include "bli_type_defs.h"
#include "bli_cblas.h"
#ifdef BLIS_ENABLE_CBLAS
/*
 * cblas_sdot.c
 *
 * The program is a C interface to sdot.
 * It calls the fortran wrapper before calling sdot.
 *
 * Written by Keita Teranishi.  2/11/1998
 *
 */
#include "cblas.h"
#include "cblas_f77.h"
float cblas_sdot( const int N, const float *X,
                      const int incX, const float *Y, const int incY)
{
   float dot;
#ifdef F77_INT
   F77_INT F77_N=N, F77_incX=incX, F77_incY=incY;
#else 
   #define F77_N N
   #define F77_incX incX
   #define F77_incY incY
#endif
   F77_sdot_sub( &F77_N, X, &F77_incX, Y, &F77_incY, &dot);
   return dot;
}   
#endif
