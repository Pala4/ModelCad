//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "polynom.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
void laguer(fcomplex a[], int m, fcomplex *x, int *its)
{
int iter,j;
double abx,abp,abm,err;
fcomplex dx,x1,b,d,f,g,h,sq,gp,gm,g2;
static double frac[MR+1] = {0.0,0.5,0.25,0.75,0.13,0.38,0.62,0.88,1.0};

for (iter=1;iter<=MAXIT;iter++) {
*its=iter;
b=a[m];
err=Cabs(b);
d=f=Complex(0.0,0.0);
abx=Cabs(*x);
for (j=m-1;j>=0;j--) {
f=Cadd(Cmul(*x,f),d);
d=Cadd(Cmul(*x,d),b);
b=Cadd(Cmul(*x,b),a[j]);
err=Cabs(b)+abx*err;
}
err *= EPSS;
if (Cabs(b) <= err) return;
g=Cdiv(d,b);
g2=Cmul(g,g);
h=Csub(g2,RCmul(2.0,Cdiv(f,b)));
sq=Csqrt(RCmul((double) (m-1),Csub(RCmul((double) m,h),g2)));
gp=Cadd(g,sq);
gm=Csub(g,sq);
abp=Cabs(gp);
abm=Cabs(gm);
if (abp < abm) gp=gm;
dx=((FMAX(abp,abm) > 0.0 ? Cdiv(Complex((double) m,0.0),gp)
: RCmul(1+abx,Complex(cos((double)iter),sin((double)iter)))));
x1=Csub(*x,dx);
if (x->r == x1.r && x->i == x1.i) return;
if (iter % MT) *x=x1;
else *x=Csub(*x,RCmul(frac[iter/MT],dx));
}
//nrerror(
// nrerror("too many iterations in laguer");

return;
}

void zroots(fcomplex a[], int m, fcomplex roots[], int polish)
{
//void laguer(fcomplex a[], int m, fcomplex *x, int *its);
int i,its,j,jj;
fcomplex x,b,c,ad[MAXM];
for (j=0;j<=m;j++) ad[j]=a[j];
for (j=m;j>=1;j--) {
     x=Complex(0.0,0.0);
     laguer(ad,j,&x,&its);
     if (fabs(x.i) <= 2.0*EPS*fabs(x.r)) x.i=0.0;
     roots[j]=x;
     b=ad[j];
     for (jj=j-1;jj>=0;jj--) {
     c=ad[jj];
     ad[jj]=b;
     b=Cadd(Cmul(x,b),c);
   }
}
if (polish)
   for (j=1;j<=m;j++)
   laguer(a,m,&roots[j],&its);
   for (j=2;j<=m;j++) {
      x=roots[j];
      for (i=j-1;i>=1;i--) {
        if (roots[i].r <= x.r) break;
        roots[i+1]=roots[i];
      }
      roots[i+1]=x;
   }
}
