#include <stdio.h>

// 61. サイズ n の整数配列 a[ ] に 0~99 の乱数をセットする関数void init_randoms_99(int a[ ] , int n). 

// 62. 上で作った乱数配列 a[ ] 中にみつからない 0~99 の数をプリントする関数void find_not(int a[ ], int n). 

// 63. 上で作った乱数配列 a[ ] ( サイズは n) 中に一番たくさん重複して現れる数を返す関数int find_max_dupli(int a[ ], int n). 

// 64. 上で作った乱数配列 a[ ] を要素の大きさ順に並べ替えた配列を b[ ] とする関数void sort(int a[ ], int b[ ], int n).(2021-01-16 [追記] hkimura の書き方悪かったか。b[0] には配列 a の一番小さい要素が来るように。2021-02-01 問題文修正、みんな誤解している。a[ ]を破壊してb[ ] にコピーを取るんじゃないよ。) 

// 65. 上で並べ替えた配列 b[ ] が正しく要素順になっているかを確認する関数int is_sorted(int b[ ], int n). 


int main(void) {
  printf("Problem 61\n");

  printf("Problem 62\n");
  
  printf("Problem 63\n");
  
  printf("Problem 64\n");
  
  printf("Problem 65\n");
  
  return 0;
}
