#include <stdio.h>

// 41. 600851475143 の素因数のうち最大のものを求めよ。 
int p41(long long int n) {
  int i;

  for (i = 2; i < n; i++) {
    if (n % i == 0) {
      n /= i;
    }
  }

  return n;
}

// test code
int p41_test(void) {
  return p41(30) == 5 &&
    p41(150) == 5 &&
    p41(1234) == 617 &&
    p41(36789) == 12263 &&
    p41(600851475143) == 6857;
}


// 42. 10 までの整数をその約数の数で分類すると、1-(1), 2-(2,3,5,7),3-(4,9), 4-(6,8,10) となってグループ 2 が最もたくさんのメンバーを持ち、そのメンバーの和は 17 になる。同様に 1000までの整数を分類し、もっともたくさんのメンバーを持つグループを特定し、総和せよ。多分その数は 143*** くらいになる。

// こいつまだ
void count_divisors(int n) {
  int cnt_num = 0;
  int sum_div = 0;

  for (int i = 1; i <= n; i++) {
    if (n % i == 0) {
      cnt_num++;
      sum_div += i;
    }
  }
}

int p42(void) {
  int i;
  int max_cnt = 0;

  for (i = 0; i <= 1000; i++) {

  }
}

// 43. n を整数とする。factorial(n) + 2 が立方数となるような n を全て求めよ。 

// 44. 整数一つを引数とし、その数が完全数かどうかを判定する関数 int is_perfect(int n). 
int is_perfect(int n) {
  int sum = 0;

  for (int i = 1; i < n; i++) {
    if (n % i == 0) {
      sum += i;
    }
  }

  return sum == n;
}

int is_perfect_test(void) {
  return is_perfect(6) &&
        ! is_perfect(8) &&
        is_perfect(28) &&
        ! is_perfect(30);
}

// 45. n よりも大きい完全数はなにか？を求める関数 int next_perfect(int n).next_perfect(28) はきっと 496。 
int next_perfect(int n) {
  for (int i = n + 1; i > n; i++) {
    if (is_perfect(i)) {
      return i;
    }
  }
}

int next_perfect_test(void) {
  return next_perfect(3) == 6 &&
    next_perfect(6) == 28 &&
    next_perfect(20) == 28 &&
    next_perfect(28) == 496 &&
    next_perfect(496) == 8128;
  //    next_perfect(8128) == 33550336 &&
  //    next_perfect(33550336) == -1;
}

int main(void) {
  long long int a = 600851475143;
  printf("Problem 41\n");
  printf("%d\n", p41_test());
  
  printf("Problem 42\n");
  
  printf("Problem 43\n");
  
  printf("Problem 44\n");
  printf("%d\n", is_perfect_test());
  
  printf("Problem 45\n");
  printf("%d\n", next_perfect_test());
  
  return 0;
}
