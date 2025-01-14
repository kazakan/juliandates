#include "juliandates.hpp"

#include <cstdint>
#include <ctime>

namespace juliandates {

/// @brief 년도, 월, 일 값을 받아 요일 정보를 반환
/// @param date 년도, 월, 일 값이 들어있는 tm
/// @return 그레고리력 기분으로 계산한 요일정보 (월,화,...,토,일 = 1,2,... 7)
/// @see https://en.wikipedia.org/wiki/Zeller%27s_congruence
uint8_t CalcDayFromDate(const struct tm &date) {
  uint32_t day_of_month = date.tm_mday;
  uint32_t month = date.tm_mon + 1;
  uint32_t year =
      (month < 3) ? (date.tm_year + 1900 - 1) : (date.tm_year + 1900);
  uint32_t year_of_century = year % 100;
  uint32_t zero_base_century = year / 100;

  uint32_t ret_day_of_week = 0;

  if (month < 3) {
    month += 12;
  }

  month = month < 3 ? month + 12 : month;

  ret_day_of_week = (day_of_month + ((13 * (month + 1)) / 5) + year_of_century +
                     (year_of_century / 4) + (zero_base_century / 4) -
                     (2 * zero_base_century)) %
                    7;

  ret_day_of_week = (ret_day_of_week + 5) % 7 + 1;

  return ret_day_of_week;
}

/// @brief 그레고리력 날짜를 받아 율리우스 적일을 계산함.
/// @param date 그레고리력 기준 날짜
/// @return 율리우스 적일 (JDN)
/// @see
/// https://en.wikipedia.org/wiki/Julian_day#Converting_Gregorian_calendar_date_to_Julian_Day_Number
int32_t CalcJDN(const struct tm &date) {
  int32_t year = date.tm_year + 1900;
  int32_t month = date.tm_mon + 1;
  int32_t day_of_month = date.tm_mday;

  int32_t jdn = (1461 * (year + 4800 + (month - 14) / 12)) / 4 +
                (367 * (month - 2 - 12 * ((month - 14) / 12))) / 12 -
                (3 * ((year + 4900 + (month - 14) / 12) / 100)) / 4 +
                day_of_month - 32075;
  return jdn;
}

/// @brief 율리우스력 적일을 받아 그레고리력 날짜를 계산함
/// @param jdn 율리우스력 적일
/// @return 그레고리력 기준 날짜
/// @see
/// https://en.wikipedia.org/wiki/Julian_day#Julian_or_Gregorian_calendar_from_Julian_day_number
struct tm CalcGregorianDateFromJDN(int32_t jdn) {
  const int32_t ly = 4716;
  const int32_t lj = 1401;
  const int32_t lm = 2;
  const int32_t ln = 12;
  const int32_t lr = 4;
  const int32_t lp = 1461;
  const int32_t lv = 3;
  const int32_t lu = 5;
  const int32_t ls = 153;
  const int32_t lw = 2;
  const int32_t lB = 274277;
  const int32_t lC = -38;

  int32_t lf = jdn + lj + (((4 * jdn + lB) / 146097) * 3) / 4 + lC;
  int32_t le = lr * lf + lv;
  int32_t lg = (le % lp) / lr;
  int32_t lh = lu * lg + lw;

  int32_t day_of_month = (lh % ls) / lu + 1;
  int32_t month = ((lh / ls + lm) % ln) + 1;
  int32_t year = (le / lp) - ly + (ln + lm - month) / ln;

  struct tm ret_date;
  ret_date.tm_mday = (day_of_month);
  ret_date.tm_mon = (month - 1);
  ret_date.tm_year = (year - 1900);
  ret_date.tm_hour = 0;
  ret_date.tm_min = 0;
  ret_date.tm_sec = 0;

  return ret_date;
}

} // namespace juliandates
