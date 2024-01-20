#include <iostream>

template <typename T1, typename T2>
struct many {
  T1 quotient;
  T2 remainder;
};

template <class T1, class T2>
many(T1, T2) -> many<T1, T2>;

many<int, int> divide(int dividend, int divisor) {
  return many{
      dividend / divisor,
      dividend % divisor,
  };
}

int main() {
  auto result = divide(14, 3);
  auto [quotient, remainder] = result;
  std::cout << "Quotient: " << quotient << ", Remainder: " << remainder << std::endl;

  return 0;
}
