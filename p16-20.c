#include <stdio.h>
#include <string.h>

// previous functions
int time_to_int(int h, int m, int s) {
  return h * 60 * 60 + m * 60 + s;
}

int is_leap(int year) {
  if (year % 4 == 0 || year % 400 == 0) {
    return 1;
  } else if(year % 100 == 0) {
    return 0;
  } else {
    return 0;
  }
}

// 16. 時刻 h1:m1:s1 と 時刻 h2:m2:s2 の間の秒数を整数で返す関数 int sec_between(int h1, int m1, int s1, int h2, int m2, int s2). 
int sec_between(int h1, int m1, int s1, int h2, int m2, int s2) {
  return time_to_int(h2, m2, s2) - time_to_int(h1, m1, s1);
}

// test code
int sec_between_test(void) {
  return sec_between(1, 2, 3, 1, 2, 3) == 0 &&
    sec_between(2, 0, 0, 1, 0, 0) == -3600 &&
    sec_between(1, 0, 0, 2, 0, 0) == 3600 &&
    sec_between(1, 2, 3, 3, 2, 1) == - sec_between(3, 2, 1, 1, 2, 3);
}


// 17. 平年の 1 月 1 日から同年 mm 月 dd 日までの日数を返す関数 int days(int mm, int dd). days(1,1) の戻り値は 1. 
int days(int mm, int dd) {
  int m_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int day = 0;

  for (int i = 0; i < mm - 1; i++) {
    
    day += m_days[i];
  }
  return day + dd;
}

// test code
int days_test() {
  return days(1,1) == 1 &&
    days(1,30) == 30 &&
    days(5,2) == 122 &&
    days(12,31) == 365;
}


// 18. y1 年 m1 月 d1 日から y2 年 m2 月 d2 月までの日数を返す関数int days_between(int y1, int m1, int d1, int y2, int m2, int d2). 自分は今日まで何日生きてきましたか？
int days_between(int y1, int m1, int d1, int y2, int m2, int d2) {
  int day = 0;
  int i;

  for (i = y1 + 1; i < y2; i++) {
    day += 365 + is_leap(i);
  }

  if (y1 == y2) {
    day += days(m2, d2) - days(m1, d1);
  } else {
    day += 364 - days(m1, d1) + days(m2, d2);

    if (is_leap(y1) == 1 && (m1 < 3)) {
      day++;
    }

    if (is_leap(y2) == 1 && (m2 > 2)) {
      day++;
    }
  }

  return day;
}

// test code
int days_between_test() {
  return days_between(2000,1,1, 2021,10,29) == 7972 &&
    days_between(2021,10,29, 2021,10,29) == 0 &&
    days_between(2021,10,29, 2022,2,14) == 108 &&
    days_between(2024, 2,28, 2024, 3,1) == 2;
}


// 19. [問題変更] 元日からの通算日数を引数 n で取り、文字列 "月の英名, 日" で返す関数 char * to_date(int n). 例えば、 to_date(1) の戻り値は "January, 1", to_date(345) の戻り値は "December, 31" だ。 
char to_date(int n) {
  int i=0;
  char m_name[12][10] = {"January", "February", "March", "April", "May", "June", "Jury", "August", "September", "October", "November", "December"};
  int m_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  for (i; i < 12; i++) {
    if (n > m_days[i]) {
      n -= m_days[i];
    } else {
      break;
    }
  }

  return ("%s, %d", m_name[i], n);
}

// test code
// int to_date_test() {
//   return \
//     strcmp("January, 1",   to_date(days( 1, 1))) == 0 &&
//     strcmp("August, 8",    to_date(days( 8, 8))) == 0 &&
//     strcmp("October, 10",  to_date(days(10,10))) == 0 &&
//     strcmp("December, 31", to_date(days(12,31))) == 0;
// }

// 20. 整数 x, y を引数にとり、大きい方の整数を戻り値とする関数 int max2(int x, int y).
int max2(int x, int y) {
  return x > y? x : y;
}

//test code
int max2_test(void) {
  return max2(1,2) == 2 &&
    max2(2,1) == 2 &&
    max2(3,3) == 3 &&
    max2(-10,-20)== -10;
}


int main(void) {
  printf("Problem 16\n");
  printf("%d\n", sec_between_test());

  printf("Problem 17\n");
  printf("%d\n", days_test());
  printf("%d, %d, %d, %d\n", days(1,1), days(1,30), days(5,2), days(12,31));
  
  printf("Problem 18\n");
  printf("%d\n", days_between_test());
  printf("%d, %d, %d, %d\n", days_between(2000,1,1, 2021,10,29), days_between(2021,10,29, 2021,10,29), days_between(2021,10,29, 2022,2,14), days_between(2024, 2,28, 2024, 3,1));
  
  printf("Problem 19\n");
  // printf("%d\n", to_date_test());
  // printf("%s\n", to_date(days(1 ,1)));
  // printf("%s\n", to_date(days(8 ,8)));
  // printf("%s\n", to_date(days(10 ,10)));
  // printf("%s\n", to_date(days(12 ,31)));
  
  printf("Problem 20\n");
  printf("%d\n", max2_test());
  
  return 0;
}
