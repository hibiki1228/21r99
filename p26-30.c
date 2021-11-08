#include <stdio.h>

// 26. 正の整数 n から m までの整数の積を求める関数 int product(int n, int m). 
int product(int n, int m) {
  int pro = 1;

  for (int i = n; i <= m; i++) {
    pro *= i;
  }

  return pro;
}

// test code
int product_test(void) {
  return product(0,10) == 0 &&
    product(1,10) == 3628800 &&
    product(10,20) == -18221056; // surprise!
}


// 27. 整数 n の各桁の総和を返す関数 int sum_of_digits(int n). 
int sum_of_digits(int n) {
  int sum = 0;
  int d_num;

  for (int i = 10; n * 10 / i != 0; i *= 10) {
    d_num = n % i;
    sum += d_num * 10 / i;
    n -= d_num;
  }

  return sum;
}

// test code
int sum_of_digits_test(void) {
  return sum_of_digits(0)==0 &&
    sum_of_digits(10)==1 &&
    sum_of_digits(1010101) == 4 &&
    sum_of_digits(12345) == 15 &&
    sum_of_digits(54321) == 15;
}


// 28. 正の整数 n を引数とし、それが 3 の倍数だったら 1、5 の倍数だったら 2、3 の倍数でもあり、かつ、5 の倍数でもあったら 3、いずれでもなかったら 0 を返す関数 int fz(int n). 
int fz(int n) {
  if (n % 3 == 0 && n % 5 == 0) {
    return 3;
  } else if (n % 5 == 0) {
    return 2;
  } else if (n % 3 == 0) {
    return 1;
  } else {
    return 0;
  }
}

// test code
int fz_test(void) {
  return fz(1)==0 &&
    fz(2)==0 &&
    fz(3)==1 &&
    fz(4)==0 &&
    fz(5)==2 &&
    fz(9)==1 &&
    fz(15)==3 &&
    fz(16)==0;
}


// 29. 3 で割って1余り、5 で割って2余り、7 で割って 3 余る正の整数の最小のものはなにか？（孫子の問題） 
int son(void) {
  for (int i = 0; i < 2147483647; i++) {
    if (i % 3 == 1 && i % 5 == 2 && i % 7 == 3) {
      return i;
    }
  }
}

// test code
int son_test() {
  return son()==52;
}


// 30. 整数一つを引数とし、その約数を全てプリントする関数 void divisors_p(int n). 
void divisors_p(int n) {
  for (int i = 1; i <= n; i++) {
    if (n % i == 0) {
      printf("%d is devisor\n", i);
    }
  }
}


int main(void) {
  printf("Problem 26\n");
  printf("%d\n", product_test());

  printf("Problem 27\n");
  printf("%d\n", sum_of_digits_test());
  
  printf("Problem 28\n");
  printf("%d\n", fz_test());
  
  printf("Problem 29\n");
  printf("%d\n", son_test());
  
  printf("Problem 30\n");
  divisors_p(20);
  divisors_p(6);
  
  return 0;
}
