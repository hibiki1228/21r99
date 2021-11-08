#include <stdio.h>

// 41. 600851475143 の素因数のうち最大のものを求めよ。 
int p41(int n) {
  int i;

  for (i = 2; i <= n; i++) {
    if (n % i == 0) {
      n /= i;
    }
  }

  return i;
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

// 43. n を整数とする。factorial(n) + 2 が立方数となるような n を全て求めよ。 

// 44. 整数一つを引数とし、その数が完全数かどうかを判定する関数 int is_perfect(int n). 

// 45. n よりも大きい完全数はなにか？を求める関数 int next_perfect(int n).next_perfect(28) はきっと 496。 


int main(void) {
  printf("Problem 41\n");
  printf("%d\n", p41_test());

  printf("Problem 42\n");
  
  printf("Problem 43\n");
  
  printf("Problem 44\n");
  
  printf("Problem 45\n");
  
  return 0;
}
