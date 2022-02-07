#include <stdio.h>
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

void str_copy(char *s1, char *s2) {
  int i;
  for (i = 0; s1[i] != '\0'; i++) {
    s2[i] = s1[i];
  }
  s2[i] = '\0';
}

int str_len(char *s) {
  int i;
  for (i = 0; s[i] != '\0'; i++) {
    ;
  }

  return i;
}

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

// 91. 文字列 s1 中に現れる文字列 s2 を文字列 s3 で置き換えるchar* str_subst(char* s1, char* s2, char* s3).戻り値は置き換え後の文字列（ポインタ）。 
// char *str_subst(char *s1, char *s2, char *s3) {
//   int s_len = str_len(s1) + str_len(s3);
//   char *strp = NULL;
//   strp = (char*)malloc(sizeof(char) * s_len);

//   str_copy(s1, strp);
//   int s_index = str_search(strp, s2);
//   strp = str_remove_str(strp, s2);
//   strp = str_insert(strp, s_index, s3);

//   return strp;
// }

// int str_subst_test(void) {
//   char s1[100] = "He is nice.";
//   char s2[100] = "aaa bbb ccc abc";
//   char s3[100] = "zzz bbb ccc zbc";

//   return \
//     str_eql(str_subst(s1, "are", "are not"), "He is nice.") &&
//     str_eql(str_subst(s1, "is", "is not"), "He is not nice.") &&
//     str_eql(str_subst(s2, "a", "z"), "zzz bbb ccc zbc") &&
//     str_eql(str_subst(s3, "z", "123"), "123123123 bbb ccc 123bc");
// }

// 92. 文字列 s を全て大文字にして返す char *toUpper(char* s).printf("%s\n", toUpper("I am small letters, ain't I?")) はI AM SMALL LETTERS, AIN'T I? を印字する。 


char* toUpper(char* s){
  int i;
  for(i=0; i<str_len(s); i++){
    s[i] -= 32;
  }
  return s;
}

int toUpper_test(void) {
  char s[] = "it's a small world";
  return str_eql(toUpper("I am small letters, ain't I?"), "I AM SMALL LETTERS, AIN'T I?") &&
    str_eql(toUpper("I AM SMALL LETTERS, AIN'T I?"), "I AM SMALL LETTERS, AIN'T I?") &&
    str_eql(toUpper(""), "") &&
    str_eql(toUpper("abcd123"), "ABCD123");
}

// 93. 文字列 s1 を整数に変換して返す関数 int str_to_int(char* s1).str_to_int("314")の戻り値は 314 になる。atoi( ) 使わずに行ってみよう。 
int power(int n, int m) {
  int ans = 1;
  int i;

  for (i = 0; i < m; i++) {
    ans *= n;
  }

  return ans;
}

int str_to_int(char *s1) {
  int ret_num = 0;
  int i;

  for (i = 0; s1[i] != '\0'; i++) {
    ret_num += (s1[i] - 48) * power(10, str_len(s1) - i - 1);
  }

  return ret_num;
}

int str_to_int_test(void) {
  return str_to_int("") == 0 &&
    str_to_int("123") == 123 &&
    str_to_int("1024") == 1024 &&
    str_to_int("9999") == 9999 &&
    str_to_int("-314") == -314 &&
    str_to_int("-100200")== -100200;
}

// 94. 文字列 *s を逆にした文字列を返す関数 char* str_reverse(char* s).printf("%s\n", str_reverse("abcdef")) がプリントするのは"fedcba\n" 

// solved

/*
  sの大きさ分のメモリを確保して、作ったものにsをコピーした。
  次に、forで長さの半分だけ回して、sp[i]をsp[s_len - 1 -i]を入れ替えた。
*/

char *str_reverse(char *s) {
  int s_len = str_len(s);
  char *sp = NULL;
  sp = (char*)malloc(sizeof(char) * s_len);

  str_copy(s, sp);

  int i;
  char tmp;
  for (i = 0; i < s_len / 2; i++) {
    tmp = sp[i];
    sp[i] = sp[s_len - 1 - i];
    sp[s_len - 1 - i] = tmp;
  }

  return sp;
}

int str_reverse_test(void) {
  char s1[]= "abcdef";
  char s2[]= "123456";
  char *cp = str_reverse(s1);

  return str_eql(str_reverse(""), "") &&
    str_eql(str_reverse(s1), "fedcba") &&
    str_eql(str_reverse(str_reverse(s1)), "abcdef") &&
    str_eql(str_reverse(s2), "654321") &&
    str_eql(cp, "fedcba");
}

// 95. 文字列 *s1 が日本語文字列の場合、s1 を逆順にした文字列を返す関数char *jstr_reverse(char* s1)).printf("%s\n", jstr_reverse("おはようございます。")) がプリントするのは"。すまいざごうよはお\n" solved
char *jstr_reverse(char *s1) {
  int s_len = str_len(s1);
  char *sp1 = NULL;
  sp1 = (char*)malloc(sizeof(char) * (s_len + 1));

  int i;
  for (i = 0; s1[i] != '\0'; i += 3) {
    sp1[i] = s1[s_len - i - 3];
    sp1[i + 1] = s1[s_len - i - 2];
    sp1[i + 2] = s1[s_len - i - 1];
  }
  sp1[i] = '\0';

  return sp1;
}

int jstr_reverse_test(void) {
  return str_eql(jstr_reverse(""),"") &&
    str_eql(jstr_reverse("おはようございます。"), "。すまいざごうよはお") &&
    str_eql(jstr_reverse(jstr_reverse("おはようございます。")), "おはようございます。");
}

int main(void) {
  printf("Problem 91\n");
  // printf("%d\n", str_subst_test());

  printf("Problem 92\n");
  // printf("%d\n", toUpper_test());
  
  printf("Problem 93\n");
  printf("%d\n", str_to_int_test());
  
  printf("Problem 94\n");
  printf("%d\n", str_reverse_test());
  
  printf("Problem 95\n");
  printf("%d\n", jstr_reverse_test());
  
  return 0;
}
