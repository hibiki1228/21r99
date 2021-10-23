#include <stdio.h>

// 1. 整数ひとつをキーボードから入力、それに 1 を足した数をプリントする関数 void add1_p(void).
void add1_p(void) {
  int n;
  printf("Enter a number: ");
  scanf("%d", &n);

  printf("added number is %d.\n", n+1);
}

// 2. 整数 x, y を引数にとり、それらを足した数を戻り値とする関数 int add2(int x, int y).
int add2(int x, int y) {
  return x + y;
}

// 3. 整数 x, y を引数にとり、それらを足した数をプリントする関数 void add2_p(int x, int y).
void add2_p(int x, int y) {
  printf("sum number is %d.\n", x + y);
}

// 4. 円の半径（整数）を引数にとり、その円の面積（浮動小数点数）を戻り値とする関数 float en(int r).
float en(int r) {
  return r * r * 3.14;
}

// 5. 円の半径（整数）をキーボードから読み、その円の面積（浮動小数点数）をプリントする関数 void en_p(void).
void en_p(void) {
  int r;
  printf("Enter a radius: ");
  scanf("%d", &r);

  printf("Round area is %f.\n", r * r * 3.14);
}

int main(void) {
  printf("Problem 1\n");
  add1_p();
  printf("Problem 2\n");
  printf("%d\n", add2(3, 5));
  printf("Problem 3\n");
  add2_p(5, 7);
  printf("Problem 4\n");
  printf("%f\n", en(4));
  printf("Problem 5\n");
  en_p();

  return 0;
}
