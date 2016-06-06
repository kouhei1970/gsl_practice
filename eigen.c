//3x3の行列の固有値と固有ベクトルを
//gslを用いて計算するサンプル
//マニュアルのサンプルをコメントを入れ3x3バージョンに変更
//2016.6.5 Copyright Kouhei Ito
//
#include <stdio.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_eigen.h>
int main (void)
{
  //3x3の行列データを用意します
  double data[] = { 
    2.0, -3.0, 3.0,
    1.0, -2.0, 3.0,
    1.0, -1.0, 2.0
  };
  //用意した行列データを行列構造体にセットします
  gsl_matrix_view m = gsl_matrix_view_array(data, 3, 3);
  //計算用のワークスペースを用意します
  gsl_eigen_nonsymmv_workspace* w = gsl_eigen_nonsymmv_alloc(3);
  //固有値を格納するベクトル構造体を用意します
  gsl_vector_complex * eval = gsl_vector_complex_alloc(3);
  //固有ベクトルを格納する行列構造体を用意します
  gsl_matrix_complex * evec = gsl_matrix_complex_alloc(3, 3);
  
  //行列mの固有値と対応する固有ベクトルを求めます
  gsl_eigen_nonsymmv(&m.matrix, eval, evec, w);
  
  //確保したワークスペースメモリの開放
  gsl_eigen_nonsymmv_free(w);
  //求められた固有値を昇順にソート
  gsl_eigen_nonsymmv_sort(eval, evec, GSL_EIGEN_SORT_ABS_ASC);

  //結果の表示
  {
    int i, j;
    for (i = 0; i < 3; i++) {
      gsl_complex eval_i = gsl_vector_complex_get(eval, i);
      gsl_vector_complex_view evec_i
        = gsl_matrix_complex_column(evec, i);
      printf("eigenvalue = %g + %gi\n",
          GSL_REAL(eval_i), GSL_IMAG(eval_i));
      printf("eigenvector = \n");
      for (j = 0; j < 3; ++j) {
        gsl_complex z = gsl_vector_complex_get(&evec_i.vector, j);
        printf("%g + %gi\n", GSL_REAL(z), GSL_IMAG(z));
      }
    }
  }
  //確保した各構造体のメモリを開放
  gsl_vector_complex_free(eval);
  gsl_matrix_complex_free(evec);
  return 0;
}
