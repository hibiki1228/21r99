#include <stdio.h>

// 56. 関数 long random(void) を呼ぶとすごく大きい正の整数乱数が返ってくる。random( ) を利用し、0 以上 n 未満の正の整数乱数を返す関数int my_rand(int n).
// * 注意1, R99 は #include <stdlib.h> が前提です。
// * 注意2, #include <unistd.h> を加えた後、プログラムでmy_rand( ) 呼ぶ前のどこかで一度（だいたいは main( )の最初で） 、
// srandom(getpid( ));
// ってやると、乱数がバラバラになります（変な日本語だけど、これやらないといつも同じ順で乱数が出てくる） 

// 57. 0.0 ≤ r < 1.0 の浮動小数点数乱数 r を返す関数float randf(void). 

// 58. n ≤ r < m の整数乱数 r を返す関数int rand_int(int n, int m). 

// 59. 上の randf( ) を呼び出して、2次元乱数 [x, y](0.0 ≤ x < 1.0, 0.0 ≤ y < 1.0)を n 個プリントする関数void randf_p(int n). 

// 60. 上の randf( ) を応用し、円周率 pi を求める関数float pi(int n).2次元乱数 [x,y]、(0.0 ≤ x < 1.0, 0.0 ≤ y < 1.0)を n = 1,000 個発生し、x^2 + y^2 ≤ 1 となるものを数える。多分それは 785 近辺の数になる。とすると円周率 pi は (785/1000)*4 と推定できる。n を増やすと pi の精度は上がるはず。 


int main(void) {
  printf("Problem 56\n");

  printf("Problem 57\n");
  
  printf("Problem 58\n");
  
  printf("Problem 59\n");
  
  printf("Problem 60\n");
  
  return 0;
}
