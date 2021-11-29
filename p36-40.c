#include <stdio.h>

// previous code
int is_prime(int n) {
  int fast_num = n;
  if (n == 0 || n == 1) {
    return 0;
  } else if (n == 2) {
    return 1;
  } else {
    for (int i = 2; i < fast_num; i++) {
      if (n % i == 0) {
        return 0;
      }
      fast_num = n / i;
    }
  }

  return 1;
}

int power(int n, int m) {
  int multiple;
  multiple = n;
  for (int i=1; i < m; i++) {
    multiple *= n;
  }
  return multiple;
}

// 36. 216を超えない最大の素数は何か？
int max_prime_under(int n) {
  int prime;

  for (int i = 1; i <= n; i++) {
    if (is_prime(i)) {
      prime = i;
    }
  }

  return prime;
}

// test code
int p36_test(void) {
  return max_prime_under(10) == 7 &&
    max_prime_under(1000) == 997 &&
    max_prime_under(power(2,16)) == 65521;
}


// 37. [問題変更] 230を超えない2番目に大きい素数は何か？
int p37(int n) {
  int prime = 0, prime2;

  for (int i = 1; i < n; i++) {
    prime2 = prime;
    if (is_prime(i)) {
      prime = i;
    }
  }

  return prime2;
}

// test code
// added 2021-11-21
int p37_test(void) {
  return  p37(10) == 5 &&
    p37(power(2,10)) == 1019 &&
    p37(power(2,20)) == 1048571 &&
    p37(power(2,30)) == 1073741783;
}

// 38. 4 番目までの素数を足すと 2 + 3 + 5 + 7 = 17.1000 番目までの素数の和を求めなさい。それはたぶん 3682913. 
int p38(int n) {
  int sum = 0;
  int count = 0;
  for (int i = 1; i <= 2147483647; i++) {
    if (count < n) {
      if (is_prime(i)) {
        sum += i;
        count++;
      }
    } else {
      break;
    }
  }

  return sum;
}

// test code
int p38_test(void) {
  return p38(10) == 129 &&
        p38(100) == 24133 &&
        p38(1000) == 3682913;
}


// 39. 10000 未満の素数 p1, p2, p3 で、p12 + p22 = p32を満たすものを探せ。
int p39(void) {
  
}

// 40. 2520 は 1 から 10 の数字のすべての整数で割り切れる最小の整数である。1 から 20 までの整数すべてで割り切れる最小の整数は何か？ 
int div_1to20(int n) {
  for (int i = 1; i <= 20; i++){
    if (n % i != 0) {
      return 0;
    }
  }
  return 1;
}

int p40(void) {
  for (int i = 20; i < 2147483647; i++) {
    if (div_1to20(i)) {
      return i;
    }
  }
}

// test code
int p40_test(void) {
  int i;
  int lcm = p40();

  for (i=2; i<=20; i++) {
    if (lcm%i != 0) {
      return 0;
    }
  }
  return 1;
}

int main(void) {
  printf("Problem 36\n");
  printf("%d\n", p36_test());

  printf("Problem 37\n");
  printf("%d\n", p37_test());
  printf("%d\n", p37(10));
  printf("%d\n", p37(power(2,10)));
  printf("%d\n", p37(power(2,20)));
  printf("%d\n", p37(power(2,30)));
  
  printf("Problem 38\n");
  printf("%d\n", p38_test());
  printf("%d, %d, %d\n", p38(10), p38(100), p38(1000));
  
  printf("Problem 39\n");
  
  printf("Problem 40\n");
  printf("%d\n", p40_test());
  
  return 0;
}
