#ifndef JULIANDATES_HPP_
#define JULIANDATES_HPP_

#include <cstdint>
#include <ctime>

namespace juliandates {

std::uint8_t CalcDayFromDate(const struct tm &stTime);

std::int32_t CalcJDN(const struct tm &stTime);

struct tm CalcGregorianDateFromJDN(int32_t lJDN);

} // namespace juliandates

#endif // JULIANDATES_HPP_
