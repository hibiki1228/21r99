#include <stdio.h>

// previous func
int max2(int x, int y) {
  return x > y? x : y;
}

int square(int n) {
  return n * n;
}

// 21. 整数三つを引数にとり、もっとも大きい整数を戻り値とする関数 int max3(int x, int y, int z). 
int max3(int x, int y, int z) {
  return max2(max2(x, y), z);
}

// test code
int max3_test(void) {
  return max3(1,2,3) == 3 &&
    max3(2,3,1) == 3 &&
    max3(3,2,1) == 3 &&
    max3(0,0,0) == 0;
}


// 22. 整数 4 つを引数にとり、もっとも大きい整数を戻り値とする関数 int max4(int x, int y, int z, int w). 
int max4(int x, int y, int z, int w) {
  return max2(max3(x, y, z), w);
}

// test code
int max4_test(void) {
  return max4(1,2,3,4) == 4 &&
    max4(2,3,4,1) == 4 &&
    max4(3,4,1,2) == 4 &&
    max4(4,1,2,3) == 4;
}


// 23. 3つの整数を引数とし、それらの長さを各辺とする三角形がありうるかどうかを判定する関数 int triangle(int x, int y, int z). 
int triangle(int x, int y, int z) {
  return max3(x, y, z) < x + y + z - max3(x, y, z);
}

// test code
int triangle_test(void) {
  return triangle(-3, -4,-10) == 0 &&
    triangle(1,1,0) == 0 &&
    triangle(1,1,1) == 1 &&
    triangle(1,1,2) == 0;
}


// 24. 3つの整数を引数とし、それらの長さを各辺とする直角三角形がありうるかどうかを判定する関数 int right_angle(int x, int y, int z). 
int right_angle(int x, int y, int z) {
  return 2 * square(max3(x, y, z)) == square(x) + square(y) + square(z);
}

// test code
int right_angle_test(void) {
  return right_angle(3,4,5)== 1 &&
    right_angle(10,6,8) == 1 &&
    right_angle(1,1,1) == 0;
}


// 25. 整数 n から m までの総和を求める関数 int sum(int n, int m).
int sum(int n, int m) {
  int sum = 0;
  
  for (int i = n; i <= m; i++) {
    sum += i;
  }

  return sum;
}

// test code
int sum_test(void) {
  return sum(0,10) == 55 &&
    sum(0,-10) == 0 &&
    sum(-100,200) == 15050 &&
    sum(0,1000) == 500500 &&
    sum(2000,3000) == 2502500;
}


int main(void) {
  printf("Problem 21\n");
  printf("%d\n", max3_test());

  printf("Problem 22\n");
  printf("%d\n", max4_test());
  
  printf("Problem 23\n");
  printf("%d\n", triangle_test());
  
  printf("Problem 24\n");
  printf("%d\n", right_angle_test());
  
  printf("Problem 25\n");
  printf("%d\n", sum_test());
  
  return 0;
}
