/*  tfft2.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  fft2
*/
#include "ccmath.h"
#include <math.h>
#define MPT 64
void main(void)
{ Cpx *f,*p,ft[MPT];
  double tpi=6.283185307179586,ang,ann;
  int n=MPT,i,j,m=6;
  printf(" Test of Radix 2 Complex FFT\n");
  printf("     F(k)=cos(2pi*5*k/n),cos(2pi*3*k/n)\n");
  ang=5.*tpi/n; ann=3.*tpi/n;
  for(i=0,f=ft; i<n ;++i){ f->re=cos(ang*i); (f++)->im=cos(ann*i);}
  printf("      m= %d\n",n);
  fft2(ft,m,'d');
  for(f=ft,p=ft+n/2,i=0,j=n/2; i<n/2 ;++p,++f){
    printf("%3d %9.6f %9.6f  ",i++,f->re,f->im);
    printf("  %3d %9.6f %9.6f\n",j++,p->re,p->im);
   }
}
/* Test output

 Test of Radix 2 Complex FFT
     F(k)=cos(2pi*5*k/n),cos(2pi*3*k/n)
      m= 64
  0 -0.000000 -0.000000     32 -0.000000 -0.000000
  1  0.000000 -0.000000     33 -0.000000  0.000000
  2 -0.000000  0.000000     34  0.000000 -0.000000
  3  0.000000  0.500000     35 -0.000000 -0.000000
  4 -0.000000  0.000000     36  0.000000 -0.000000
  5  0.500000 -0.000000     37 -0.000000 -0.000000
  6  0.000000  0.000000     38  0.000000 -0.000000
  7  0.000000 -0.000000     39  0.000000  0.000000
  8 -0.000000  0.000000     40 -0.000000  0.000000
  9  0.000000 -0.000000     41 -0.000000 -0.000000
 10  0.000000 -0.000000     42 -0.000000 -0.000000
 11  0.000000  0.000000     43  0.000000 -0.000000
 12 -0.000000  0.000000     44  0.000000 -0.000000
 13  0.000000 -0.000000     45  0.000000  0.000000
 14  0.000000  0.000000     46  0.000000  0.000000
 15 -0.000000  0.000000     47  0.000000  0.000000
 16 -0.000000  0.000000     48 -0.000000  0.000000
 17 -0.000000  0.000000     49  0.000000  0.000000
 18 -0.000000  0.000000     50  0.000000  0.000000
 19 -0.000000 -0.000000     51 -0.000000  0.000000
 20 -0.000000 -0.000000     52  0.000000  0.000000
 21  0.000000 -0.000000     53  0.000000 -0.000000
 22  0.000000  0.000000     54 -0.000000  0.000000
 23  0.000000  0.000000     55  0.000000  0.000000
 24 -0.000000 -0.000000     56 -0.000000 -0.000000
 25  0.000000 -0.000000     57  0.000000  0.000000
 26  0.000000  0.000000     58  0.000000 -0.000000
 27 -0.000000  0.000000     59  0.500000  0.000000
 28 -0.000000  0.000000     60 -0.000000  0.000000
 29 -0.000000 -0.000000     61 -0.000000  0.500000
 30  0.000000 -0.000000     62 -0.000000 -0.000000
 31 -0.000000  0.000000     63 -0.000000  0.000000
*/