#include <stdio.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_matrix.h>

int main(void){
  short i,j;
  double mat[][3]={1.0, 1.0, -1.0, 1.0, 1.0, 1.0, -1.0, 1.0, 1.0};

  //行列の確保
  gsl_matrix* a=gsl_matrix_alloc(3,3);
  gsl_matrix* v=gsl_matrix_alloc(3,3);
  //ベクトルの確保
  gsl_vector* s=gsl_vector_alloc(3);
  gsl_vector* w=gsl_vector_alloc(3);

  //確保した行列に値をセットし表示
  printf("a=\n");
  for (i=0;i<3;i++){
    for (j=0;j<3;j++){
      gsl_matrix_set(a,i,j,mat[i][j]);  //値をセット
      printf("%8.5f ",gsl_matrix_get(a,i,j));
    }
    printf("\n");
  }
  printf("\n");
  

  gsl_linalg_SV_decomp(a,v,s,w);  //特異値分解
  //特異値分解ライブラリは上の例では
  //
  //  a=u*s*v'
  //
  //で示す分解を行う
  //ただし分解結果のu行列については元のa行列に収められる
  //また，sは行列であるが対角行列になるため，各対角成分を要素に持つ
  //ベクトルに格納される
  //またvは転置されていない結果が入る．

  //結果を表示
  //u
  printf("u=\n");
  for (i=0;i<3;i++){
    for (j=0;j<3;j++){
      printf("%8.5f ",gsl_matrix_get(a,i,j));
    }
    printf("\n");
  }
  printf("\n");
 
  //s
  printf("s=\n");
  for (i=0;i<3;i++){
    printf("%8.5f\n",gsl_vector_get(s,i));
  }
  printf("\n");
 
  //v
  printf("v=\n");
  for (i=0;i<3;i++){
    for (j=0;j<3;j++){
      printf("%8.5f ",gsl_matrix_get(v,i,j));
    }
    printf("\n");
  }
  return 0;
}
