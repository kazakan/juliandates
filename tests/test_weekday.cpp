#include "juliandates.hpp"

#include <cassert>
#include <cstdint>
#include <iostream>

int main(void) {

  // Arrange
  struct tm st_date;
  st_date.tm_year = 2025 - 1900;
  st_date.tm_mon = 1 - 1;
  st_date.tm_mday = 15;
  const int32_t kExpectedweekDay = 3; // 1 = mon, .. , 6 = sat, 7 = sun

  // Act
  int32_t calculated_week_day = juliandates::CalcDayFromDate(st_date);

  // Assert
  std::cout << "Expected : " << kExpectedweekDay
            << ", Actual : " << calculated_week_day << "\n";
  assert(calculated_week_day == kExpectedweekDay);
  return 0;
}