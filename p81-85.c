#include <stdio.h>
#include <string.h>


// 81. 文字列 s が空文字列 "" かどうかを判定する関数int is_empty(char* s). 
int is_empty(char* s) {
  return s[0] == '\0';
}

int is_empty_test(void) {
  char s[] = "I am not empty";

  return is_empty("") &&
    ! is_empty(" ") &&
    ! is_empty(s);
}

// 82. 文字列 s の長さを返す関数int str_len(char* s). 
int str_len(char* s) {
  int i;
  
  for (i=0; s[i] != '\0'; i++) {
    ;
  }

  return i;
}

int str_len_test(void) {
  char s1[] = "I am a string.";
  char *s2 = "I am a pointer to a string.";

  return str_len("") == strlen("") &&
    str_len(s1) == 14 &&
    str_len(s2) == 27 &&
    str_len(s1) == strlen(s1) &&
    str_len(s2) == strlen(s2);
}

// 83. 文字列 s に含まれる文字 c の数を返す関数 int count_chars(char* s, char c). 
int count_chars(char* s, char c) {
  int i;
  int count = 0;

  for (i=0; s[i] != '\0'; i++) {
    if (s[i] == c) {
      count++;
    }
  }
  return count;
}

int count_chars_test(void) {
  return count_chars("", 'a') == 0 &&
    count_chars("aaa", 'a') == 3 &&
    count_chars("a a a", 'b') == 0 &&
    count_chars("a a a", 'a') == 3 &&
    count_chars("a a a", ' ') == 2;
}

// 84. 二つの文字列 s1, s2 の先頭の n 文字が等しいかどうかを判定する関数int str_eql_n(char* s1, char* s2, int n). 
int str_eql_n(char* s1, char* s2, int n){
  int i; 
  
  for (i=0; i < n; i++) {
    if (s1[i] != s2[i]) {
      return 0;
    } else if (s1[i] == '\0' ) {
      return 0;
    }
  }
  return 1;
}

int str_eql_n_test(void) {
  char* s  = "I am a string. equal to myself";
  char* s1 = "12345 same first 6";
  char* s2 = "12345 differ after 6";

  return str_eql_n("", "", 0) &&
    ! str_eql_n("a",   "b",   1) &&
      str_eql_n("abc", "abc", 3) &&
      str_eql_n(s,  s, 10) &&
    ! str_eql_n(s,  s, 100) &&
      str_eql_n(s1, s2, 6) &&
    ! str_eql_n(s1, s2, 10);
}

// 85. 文字列 s1 と文字列 s2 が完全に等しいかどうかを判定する関数int str_eql(char* s1, char* s2). 
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


int str_eql_test(void) {
  char s0[] = "I am a string.";
  char s1[] = "I am a string.";
  char s2[] = "I am a string, too.";

  return str_eql("", "") &&
    ! str_eql("", "abc") &&
    ! str_eql("abc","") &&
    str_eql("abc", "abc") &&
    ! str_eql("abc", "abcdef") &&
    ! str_eql("abcdef", "abc") &&
    str_eql(s0, s1) &&
    str_eql(s1, s1) &&
    str_eql(s2, s2) &&
    ! str_eql(s1, s2) &&
    ! str_eql(s2, s1);
}


int main(void) {
  printf("Problem 81\n");
  printf("%d\n", is_empty_test());

  printf("Problem 82\n");
  printf("%d\n", str_len_test());
  
  printf("Problem 83\n");
  printf("%d\n", count_chars_test());
  
  printf("Problem 84\n");
  printf("%d\n", str_eql_n_test());
  
  printf("Problem 85\n");
  printf("%d\n", str_eql_test());
  
  return 0;
}
