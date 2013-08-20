//---------------------------------------------------------------------------
#ifndef polynomH
#define polynomH
//---------------------------------------------------------------------------
#include <math.h>
#include <complex.h>

#include "compl.h"
//---------------------------------------------------------------------------
#define EPSS 1.0e-8
#define MR 8
#define MT 10
#define MAXIT (MT*MR)
#define EPS 2.0e-7
#define MAXM 100
//---------------------------------------------------------------------------
static float maxarg1, maxarg2;
#define FMAX(a,b) (maxarg1=(a),maxarg2=(b),(maxarg1) > (maxarg2) ?\
(maxarg1) : (maxarg2))
//---------------------------------------------------------------------------
void laguer(fcomplex a[], int m, fcomplex *x, int *its);
//---------------------------------------------------------------------------
void zroots(fcomplex a[], int m, fcomplex roots[], int polish);
//---------------------------------------------------------------------------
#endif
