#include <stdio.h>
#include <time.h>

// 31. n 以下の整数のうち、もっとも約数の多い数を返す関数 int most_divisors(int n). 前問に同じ。 
int count_divisors(int n) {
  int cnt = 0;

  for (int i = 1; i <= n; i++) {
    if (n % i == 0) {
      cnt++;
    }
  }

  return cnt;
}

int most_divisors(int n) {
  int most_div;
  int max_cnt = 0;

  for (int i = 1; i <= n; i++) {
    if (count_divisors(i) > max_cnt) {
      max_cnt = count_divisors(i);
      most_div = i;
    }
  }
  return most_div;
}

// test code
int most_divisors_test(void) {
  return most_divisors(10) == 6 &&
    most_divisors(100) == 60 &&
    most_divisors(1000) == 840;
}


// 32. 整数一つを引数とし、その約数の合計を戻り値とする関数 int sum_of_divisors(int n). 
int sum_of_divisors(int n) {
  int sum = 0;

  for (int i = 1; i <= n; i++) {
    if (n % i == 0) {
      sum += i;
    }
  }

  return sum;
}

// test code
int sum_of_divisors_test(void) {
  return sum_of_divisors(1) == 1 &&
        sum_of_divisors(10) == 18 &&
        sum_of_divisors(100) == 217 &&
        sum_of_divisors(1000) == 2340;
}


// 33. n 以下の素数(nは整数)は何個あるかを戻り値とする関数 int primes(int n). primes(10000) の戻り値はおそらく 1229。 
int check_p(int n) {
  for (int i = 2; i < n; i++) {
    if (n % i == 0) {
      // not prime
      return 0;
    }
  }

  // prime
  return 1;
}

int primes(int n) {
  int count = 0;

  for (int i = 2; i <= n; i++) {
    if (check_p(i)) {
      count++;
      
    }
  }

  return count;
}

// test code
int primes_test(void) {
  return primes(10) == 4 &&
        primes(100) == 25 &&
        primes(1000) == 168 &&
        primes(10000) == 1229;
}


// 34. 整数一つを引数とし、その数が素数だったら1、素数でなかったら 0 を返す関数int is_prime(int n).約数が何個あるかを数えて素数判定するのは遅い。速い素数判定を望む。repl.it で is_prime(2147483549) が3秒以内で 1 を返せば速いと認める。回答には次で得られる計算時間を入れること。
// > time ./main1real    0m1.020suser    0m0.511ssys 0m0.009s
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

// test code
int is_prime_test(void) {
  return ! is_prime(2147483541) &&
          is_prime(2147483543) &&
        ! is_prime(2147483545) &&
        ! is_prime(2147483547) &&
          is_prime(2147483549);
}


// 35. n 未満の素数の和を求める関数int sum_primes_under(int n).sum_primes_under(1000) は 76127 のはず。 
int sum_primes_under(int n) {
  int sum = 0;
  
  for (int i = 2; i < n; i++) {
    if (is_prime(i)) {
      sum += i;
    }
  }

  return sum;
}

// test code
int sum_primes_under_test(void) {
  return sum_primes_under(2) == 0 &&
        sum_primes_under(3) == 2 && 
        sum_primes_under(10) == 17 &&
        sum_primes_under(100) == 1060 &&
        sum_primes_under(1000) == 76127;
}


int main(void) {
  printf("Problem 31\n");
  printf("%d\n", most_divisors_test());

  printf("Problem 32\n");
  printf("%d\n", sum_of_divisors_test());
  
  printf("Problem 33\n");
  printf("%d\n", primes_test());
  
  printf("Problem 34\n");
  clock_t start_clock, end_clock;
  start_clock = clock();  // count time start
  
  printf("%d\n", is_prime_test());

  end_clock = clock();  // count time end

  printf("clock:%f\n", (double)(end_clock - start_clock) / CLOCKS_PER_SEC);
  
  printf("Problem 35\n");
  printf("%d\n", sum_primes_under_test());
  
  return 0;
}
