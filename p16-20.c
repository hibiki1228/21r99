#include <stdio.h>
#include "p11-15.c"

// 16. 時刻 h1:m1:s1 と 時刻 h2:m2:s2 の間の秒数を整数で返す関数 int sec_between(int h1, int m1, int s1, int h2, int m2, int s2). 
int sec_between(int h1, int m1, int s1, int h2, int m2, int s2) {
  return time_to_int(h1, m1, s1) - time_to_int(h2, m2, s2);
}

// 17. 平年の 1 月 1 日から同年 mm 月 dd 日までの日数を返す関数 int days(int mm, int dd). days(1,1) の戻り値は 1. 
int days(int mm, int dd) {
  int m_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int day = 0;

  for (int i = 0; i < mm - 1; i++) {
    day += m_days[i];
  }

  return day + dd -1;
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

    if (is_leap(y1) && m1 < 3) {
      day++;
    }

    if (is_leap(y2) && m2 > 2) {
      day++;
    }
  }

  return day;
}

// 19. [問題変更] 元日からの通算日数を引数 n で取り、文字列 "月の英名, 日" で返す関数 char * to_date(int n). 例えば、 to_date(1) の戻り値は "January, 1", to_date(345) の戻り値は "December, 31" だ。 

// 20. 整数 x, y を引数にとり、大きい方の整数を戻り値とする関数 int max2(int x, int y).
