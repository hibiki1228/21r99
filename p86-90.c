#include <stdio.h>

// 86. 文字列 s1 を文字列 s2 にコピーする関数void str_copy(char* s1, char* s2).s2 は s1 をコピーするに十分な長さがあると仮定してよい。以下同様。str_copy(s1,s2) の実行後、str_sql(s1, s2) が真になること。 

// 87. 文字列 s1 の後ろに文字列 s2 を連結する関数char* str_append(char* s1, char* s2).str_append("abc", "def") の実行後、str_eql(s1, "abcdef")は真になる。s1 を破壊しないバージョンも作ってみよう。s1 と s2 を連結した文字列を返すように。 

// 88. 文字列 s1 中に文字列 s2 が出現するかどうかを判定する関数int str_search(char* s1, char* s2).s2 が s1 の何文字目から出現しているかを返す。見つからなかった時は -1 を返せ。戻り値 が 0 の時は「s1 の先頭に s2 は見つかる」の意味になる。 

// 89. 文字列 s1 の n 文字目からの m 文字を削除するchar* str_remove(char* s1, int n, int m). 戻り値は s1.s1="0123456789" として、str_remove(s1, 5,3) の後、s1 は "0123489" になる。s1 を書き換えない、安全なバージョンにも挑戦しよう。 

// 90. 文字列 s1 の n 文字目に文字列 s2 を挿入するchar* str_insert(char* s1, int n, char* s2).戻り値は挿入後の文字列（ポインタ）。printf("%s\n", str_insert("012345", 3, "abc")) は0123abc45 を印字する。 


int main(void) {
  printf("Problem 86\n");

  printf("Problem 87\n");
  
  printf("Problem 88\n");
  
  printf("Problem 89\n");
  
  printf("Problem 90\n");
  
  return 0;
}
