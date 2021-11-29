#include <stdio.h>

// 46. 整数 n が平方数であるかどうかを判定する関数 int is_square(int n). 237169 は平方数である。 
int is_square(int n) {
  int i;
  
  for (i = 0; i * i < n; i++) {
    ;
  }

  return i * i == n;
}

int is_square_test(void) {
  return is_square(0) &&
    is_square(1) &&
    ! is_square(2) &&
    ! is_square(3) &&
    is_square(4) &&
    ! is_square(5) &&
    ! is_square(6) &&
    ! is_square(7) &&
    ! is_square(8) &&
    is_square(9) &&
    is_square(100) &&
    is_square(237169) &&
    ! is_square(-1) &&
    ! is_square(-4) &&
    ! is_square(1000);
}

// 47. 整数 n が立方数であるかどうかを判定する関数 int is_cubic(int n). 9663597 は立方数である。 
int is_cubic(int n) {
  int i;

  if (n >= 0) {
    for (i = 0; i * i * i <= n; i++) {
      if (i * i * i == n) {
        return 1;
      }
    }
  } else if (n < 0) {
    for (i = 0; i * i * i >= n; i--) {
      if (i * i * i == n) {
        return 1;
      }
    }
  }

  return 0;
}

int is_cubic_test(void) {
  return is_cubic(0) &&
    is_cubic(-1) &&
    is_cubic(1000) &&
    is_cubic(9663597) &&
    ! is_cubic(-3) &&
    ! is_cubic(-4) &&
    is_cubic(-1000);
}

// 48. 整数 n が 二つの整数の2乗の和として表されるかどうかを判定する関数int is_squeare_sum(int n). is_square_sum(30505) は 1 を返す。30505 = 1232+1242. 
int is_square_sum(int n) {
  for (int i = 1; i * i < n; i++) {
    if (is_square(n - i * i)) {
      return 1;
    }
  }

  return 0;
}

int is_square_sum_test(void) {
  return ! is_square_sum(1) &&
    is_square_sum(2) &&
    ! is_square_sum(4) &&
    is_square_sum(10) &&
    is_square_sum(90) &&
    is_square_sum(30505) &&
    ! is_square_sum(15) &&
    ! is_square_sum(21) &&
    ! is_square_sum(31414);
}

// 49. 整数 n のルートを超えない最大の整数を返す関数int sqrt_int(int n). sqrt_int(24) の戻り値は4, sqrt_int(25)の戻り値は5 を期待している。ヒントは前問。ライブラリ sqrt を使うことは反則とする。 
int sqrt_int(int n) {
  int i;

  for (i = 0; i * i <= n; i++) {
    ;
  }

  return i - 1;
}

int sqrt_int_test(void) {
  return sqrt_int(0) == 0 &&
    sqrt_int(10) == 3 &&
    sqrt_int(24) == 4 &&
    sqrt_int(25) == 5 &&
    sqrt_int(100) == 10;
}

// 50. 1000000 未満の整数で、平方数かつ立方数でもある最大の数を探す関数。int square_cubic(int n).square_cubic(1000000) の戻り値はきっと、531***. 
int square_cubic(int n) {
  int i;

  for (i = n - 1; i > 0; i--) {
    if (is_square(i) && is_cubic(i)) {
      return i;
    }
  }
}

int square_cubic_test(void) {
  return square_cubic(10) == 1 &&
    square_cubic(100) == 64 &&
    square_cubic(1000) == 729 &&
    square_cubic(10000) == 4096 &&
    square_cubic(100000) == 46656 &&
    square_cubic(1000000) == 531441;
}

int main(void) {
  printf("Problem 46\n");
  printf("%d\n", is_square_test());

  printf("Problem 47\n");
  printf("%d\n", is_cubic_test());
  
  printf("Problem 48\n");
  printf("%d\n", is_square_sum_test());
  
  printf("Problem 49\n");
  printf("%d\n", sqrt_int_test());
  
  printf("Problem 50\n");
  printf("%d\n", square_cubic_test());
  
  return 0;
}
