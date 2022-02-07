#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int str_eql(char* s1, char* s2) {
  int i; 
  int j = 0;
  for (i=0; s1[i]!='\0'; i++) {
    if (s1[i] == s2[i]) {
      j++;
    }
  }
  return s1[j] == '\0' && s2[j] == '\0';
}

// 86. 文字列 s1 を文字列 s2 にコピーする関数void str_copy(char* s1, char* s2).s2 は s1 をコピーするに十分な長さがあると仮定してよい。以下同様。str_copy(s1,s2) の実行後、str_sql(s1, s2) が真になること。 
char * str_copy(char* s1, char* s2) {
  int i;
  
  for (i=0; s1[i]!='\0'||s2[i]!='\0'; i++) {
    s1[i] = s2[i];
  }
  return s1;
}

int str_copy_test(void) {
  char s1[] = "nice to meet you";
  char s2[BUFSIZ];
  str_copy(s2, s1);
  return str_eql(s2, "nice to meet you") &&
    str_eql(str_copy(s2, "hello"), "hello") &&
    str_eql(str_copy(s2, s1), s1) &&
    str_eql(str_copy(s2, s2), s2) &&
    str_eql(str_copy(s2,""), "") &&
    str_eql(s1, str_copy(s2, s1));
}

// 87. 文字列 s1 の後ろに文字列 s2 を連結する関数char* str_append(char* s1, char* s2).str_append("abc", "def") の実行後、str_eql(s1, "abcdef")は真になる。s1 を破壊しないバージョンも作ってみよう。s1 と s2 を連結した文字列を返すように。 
char* str_append(char* s1, char* s2) {
  int count;
  for (count=0; s1[count]!='\0'; count++) {
    ;
  }
  for (int i=0; s2[i]!='\0'; i++) {
    s1[count + i] = s2[i];
  }
  return s1;
}

int str_append_test(void) {
  char s1[100] = "abc";
  char s2[100];
  s2[0] = '\0';

  str_append(s1, "def");
  return str_eql(s1, "abcdef") &&
    str_eql(str_append(s1, "012"),"abcdef012") &&
    str_eql(str_append(s2, "xyz"), "xyz") &&
    str_eql(str_append(s2, ""), "xyz");
}

// 88. 文字列 s1 中に文字列 s2 が出現するかどうかを判定する関数int str_search(char* s1, char* s2).s2 が s1 の何文字目から出現しているかを返す。見つからなかった時は -1 を返せ。戻り値 が 0 の時は「s1 の先頭に s2 は見つかる」の意味になる。 
int str_len(char s[]) {
  int i;

  for (i = 0; s[i] != '\0'; i++) {
    ;
  }
  return i;
}

// int str_search(char* s1, char* s2) {
//   int i, j;
//   int cnt = 0;
//   int s2_len;

//   s2_len = str_len(s2);
//   printf("s2_len == %d\n", s2_len);

//   for(i=0; s2[i]!='\0'; i++) {
//     for(j=0; s1[j]!='\0'; j++) {
//       if(s2[i] == s1[j]) {
//         cnt++;
//       }
//     }
//     if (s2_len == cnt) {
//       return i + j;
//     }
//     cnt = 0;
//   }
//   return - 1;
// }

// int str_search(char* s1,char* s2){
// 	int i,j,count=0;
// 	for (i=0;s1[i]!='\0';i++) {
// 		if(s1[i]==s2[0]){//s1のi文字目がs2の0文字目と等しい
// 			for(j=0;s2[j]!='\0';j++){
// 				if(s1[i+j]==s2[j]){
// 					count++;
// 				}
// 			}
// 			if(count==str_len(s2)){
// 				return i+1;
// 			}
// 			else return -1;
// 		}


// 	}

// }

// int str_search(char* s1, char* s2) {
//   const char *p1 = s1;
//   const char *p2 = s2;

//   while (*p1 && *p2) {
//     if (*p1 == *p2) {p1++;
//       p2++;
//     } else {
//       p1 -= p2 - s2 - 1;
//       p2 = s2;
//     }
//   }
//     return - 1;
// }

int str_search(char *s1, char *s2) {
  int i, j;
  int tf = 0;
  int s1_len = str_len(s1);
  int s2_len = str_len(s2);
  
  if (s1_len < s2_len) {
    return -1;
  } else if (s2_len == 0) {
    return 0;
  }
  
  for (i = 0; i <= s1_len - s2_len; i++) {
    if (s1[i] == s2[0]) {
      for (j = 1; s2[j] != '\0'; j++) {
        if (s1[i + j] == s2[j]) {
          tf = 1;
        } else {
          tf = 0;
          break;
        }
      }
      if (tf) {
        return i;
      }
    }
  }
  
  return -1;
}

int str_search_test(void) {
  char s1[]="The long and winding road";

  return str_search(s1, "") == 0 &&
    str_search(s1, "The") == 0 &&
    str_search(s1, "long") == 4 &&
    str_search(s1, "love") == -1 &&
    str_search(s1, "advance") == -1  &&
    str_search(s1, "road") == 21 &&
    str_search(s1, "long long long long long string") == -1;
}

// 89. 文字列 s1 の n 文字目からの m 文字を削除するchar* str_remove(char* s1, int n, int m). 戻り値は s1.s1="0123456789" として、str_remove(s1, 5,3) の後、s1 は "0123489" になる。s1 を書き換えない、安全なバージョンにも挑戦しよう。
char* str_remove(char* s1, int n, int m) {
  int i;

  for (i=n; s1[i]!='\0' ; i++) {
    s1[i] = s1[i+m];
  }
  s1[i + m]  = '\0';
  return s1;
} 

int str_remove_test(void) {
  char s1[] = "0123456789";
  return str_eql(str_remove(s1, 5,3), "0123489");
}

// 90. 文字列 s1 の n 文字目に文字列 s2 を挿入するchar* str_insert(char* s1, int n, char* s2).戻り値は挿入後の文字列（ポインタ）。printf("%s\n", str_insert("012345", 3, "abc")) は0123abc45 を印字する。 
char* str_insert(char* s1, int n, char* s2){
  int total_len = str_len(s1) + str_len(s2);
  char* ans_str = (char*)malloc(sizeof(char) * total_len);

  int i;
  for(i=0; i<n; i++){
    ans_str[i] = s1[i];
  }
  for(i=0; s2[i]!='\0'; i++){
    ans_str[n + i] = s2[i];
  }
  for(i=n; s1[i]!='\0'; i++){
    ans_str[str_len(s2) + i - 1] = s1[i];
  }
  ans_str[total_len - 1] = '\0';
  return ans_str;
}


int str_insert_test(void) {
  char s1[100] = "012345";
  return str_eql(str_insert(s1, 3, "abc"), "012abc345") &&
    str_copy(s1, "012345") &&
    str_eql(str_insert(s1, 0, "!"), "!012345") &&
    str_copy(s1, "012345") &&
    str_eql(str_insert(s1, 6, "zzz"), "012345zzz") &&
    str_copy(s1, "012345") &&
    str_eql(str_insert(s1, 100, "xyz"), s1);
}


int main(void) {
  printf("Problem 86\n");
  printf("%d\n", str_copy_test());

  printf("Problem 87\n");
  printf("%d\n", str_append_test());

  printf("Problem 88\n");
  char s1[]="The long and winding road";
  printf("%d %d %d %d %d %d %d\n", str_search(s1, ""), str_search(s1, "The"), str_search(s1, "long"), str_search(s1, "love"), str_search(s1, "advance"), str_search(s1, "road"), str_search(s1, "long long long long long string"));
  printf("%d\n", str_search_test());

  printf("Problem 89\n");
  printf("%d\n", str_remove_test());

  printf("Problem 90\n");
  printf("%d\n", str_insert_test());

  return 0;
}
