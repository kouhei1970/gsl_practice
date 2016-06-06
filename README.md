# gsl_practice
C言語の数値計算ライブラリのgslの練習です．

####次の場所からgslの最新版
gsl-latest.tar.gzをダウンロードする。
http://public.p-knowledge.co.jp/gnu-mirror/gsl/

####コンパイル
ダウンロードしたファイルを解凍して
回答されたディレクトリの中に入って
```
./configure
make
```

管理者権限でmake install
ubuntuなら
```
sudo make install
```

####環境変数の設定
```
export LIBRARY_PATH=/usr/local/lib:$LD_LIBRARY_PATH
```
####作ったコードのコンパイル

ubuntuならば
ソースコードをsample.cで保存していたならば。
```
gcc sample.c -lgsl -lgslcblas -lm
```
####サンプルファイル

githubに置いておきます。
