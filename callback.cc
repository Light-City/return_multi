#include <functional>
#include <iostream>

void divide(int dividend, int divisor, std::function<void(int, int)> callback) {
  callback(dividend / divisor, dividend % divisor);
}

int main() {
  divide(14, 3, [&](int quotient, int remainder) {
    std::cout << quotient << ", " << remainder << std::endl;
  });

  return 0;
}
