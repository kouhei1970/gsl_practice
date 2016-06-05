//3x3の行列の固有値と固有ベクトルを
//gslを用いて計算するサンプル
//2016.6.5 Copyright Kouhei Ito
//
#include <stdio.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_eigen.h>
int main (void)
{
  double data[][3] = { 
    2.0, -3.0, 3.0,
    1.0, -2.0, 3.0,
    1.0, -1.0, 2.0
  };
  gsl_eigen_nonsymmv_alloc(3);



}
