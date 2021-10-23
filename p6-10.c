#include <stdio.h>

// 6. 整数 x を引数にとり、それが偶数だったら 1、奇数だったら 0 を返す関数 int is_even(int x). 
int is_even(int x) {
  if (x & 1) {
    return 0;
  } else {
    return 1;
  }
}

// 7. キーボードから整数ひとつを入力し、それが偶数だったら "偶数です"、奇数だったら "奇数です" とプリントする関数 void parity_p(void). 
void parity_p(void) {
  int n;
  printf("Enter a number: ");
  scanf("%d", &n);

  if (n & 1) {
    printf("This is a odd num.\n");
  } else {
    printf("This is a even num.\n");
  }
}

// 8. 整数 n の絶対値を返す関数 int abs(int n). 
int abs(int n) {
  if (n > 0) {
    return n;
  } else {
    return -n;
  }
}

// 9. 整数 n の 2 乗を戻り値とする関数 int square(int n). 
int square(int n) {
  return n * n;
}

// 10. n,m を正の整数とする。 n の m 乗を返す関数 int power(int n, int m). C言語では nm を n^m では計算できない。
int power(int n, int m) {
  int multiple;
  multiple = n;
  for (int i=1; i < m; i++) {
    multiple *= n;
  }
  return multiple;
}

int main(void) {
  printf("Problem 6\n");
  printf("%d\n", is_even(3));
  printf("%d\n", is_even(4));

  printf("Problem 7\n");
  parity_p();
  printf("Problem 8\n");
  printf("%d\n", abs(34));
  printf("%d\n", abs(-12));

  printf("Problem 9\n");
  printf("%d\n", square(4));
  printf("%d\n", square(-3));

  printf("Problem 10\n");
  printf("%d\n", power(2, 3));
  printf("%d\n", power(2, 2));

  return 0;
}