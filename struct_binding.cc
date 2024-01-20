#include <iostream>
auto divide(int dividend, int divisor) {
  struct result {
    int quotient;
    int remainder;
  };
  return result{dividend / divisor, dividend % divisor};
}

int main() {
  auto result = divide(14, 3);
  std::cout << result.quotient << ", " << result.remainder << std::endl;
  auto [quotient, remainder] = divide(14, 3);
  std::cout << quotient << ", " << remainder << std::endl;
}