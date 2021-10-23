#include <stdio.h>

// 11. 整数 x, y を引数にとり、それらの和、差、積、整数商をプリントする関数 void arithmetic_p(int x, int y). 
void arithmetic_p(int x, int y) {
  printf("sum: %d\n", x + y);
  printf("diff: %d\n", x - y);
  printf("prod: %d\n", x * y);
  printf("com: %d\n", x / y);
}

// 12. 彼・彼女の年齢を y とする。彼・彼女がティーンエイジャーだったら真、そうでなければ偽を返す関数 int is_teenage(int y). 
int is_teenage(int y) {
  if (y >=10 && y <20) {
    return 1;
  } else {
    return 0;
  }
}

// 13. 西暦 year を引数にとり昭和、平成、令和の和暦をプリントする関数 void era_p(int year). era_p(2020)は "令和2年" をプリントする。 
void era_p(int year) {
  int y;
  if (year >= 2019) {
    y = year - 2019 + 1;
    printf("令和%d年\n", y);
  } else if (year >= 1989) {
    y = year - 1989 + 1;
    printf("平成%d年\n", y);
  } else if (year >= 1926) {
    y = year - 1926 + 1;
    printf("昭和%d年\n", y);
  }
}

// 14. 西暦 year を引数にとり、閏年であれば 1、そうでなければ 0 を返す関数 int is_leap(int year). 西暦が 4 で割り切れれば閏年。ただし、100 で割り切れる時は平年。ただし、400 で割り切れる時は閏年。 
int is_leap(int year) {
  if (year % 4 == 0 || year % 400 == 0) {
    return 1;
  } else if(year % 100 == 0) {
    return 0;
  } else {
    return 0;
  }
}

// 15. hh 時 mm 分 ss 秒の hh, mm, ss を引数にとり、0 時 0 分 0 秒からの通算秒に変換した整数を戻り値とする関数 int time_to_int(int h, int m, int s).
int time_to_int(int h, int m, int s) {
  return h * 60 * 60 + m * 60 + s;
}

int main(void) {
  printf("Problem 11\n");
  arithmetic_p(9, 4);

  printf("Problem 12\n");
  printf("%d\n", is_teenage(18));
  printf("%d\n", is_teenage(8));
  printf("%d\n", is_teenage(20));

  printf("Problem 13\n");
  era_p(2021);
  era_p(1999);
  era_p(1950);

  printf("Problem 14\n");
  printf("%d\n", is_leap(2020));
  printf("%d\n", is_leap(2001));

  printf("Problem 15\n");
  printf("%d\n", time_to_int(15, 20, 40));

  return 0;
}