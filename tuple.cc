#include <iostream>
#include <tuple>

std::tuple<int, int> divide(int dividend, int divisor) {
  return std::make_tuple(dividend / divisor, dividend % divisor);
}

int main() {
  int quotient, remainder;

  std::tie(quotient, remainder) = divide(14, 3);

  std::cout << quotient << ", " << remainder << std::endl;
}