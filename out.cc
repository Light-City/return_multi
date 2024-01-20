#include <functional>
#include <iostream>
#include <optional>
#include <tuple>

template <class T>
struct out {
  std::function<void(T)> target;

  out(T* t)
      : target([t](T&& in) {
          if (t) *t = std::move(in);
        }) {}

  template <class... Args>
  void emplace(Args&&... args) {
    target(T(std::forward<Args>(args)...));
  }

  template <class X>
  void operator=(X&& x) {
    emplace(std::forward<X>(x));
  }

  template <class... Args>
  void operator()(Args&&... args) {
    emplace(std::forward<Args>(args)...);
  }
};

void divide(int dividend, int divisor, out<int>& quotient_out, out<int>& remainder_out) {
  quotient_out.emplace(dividend / divisor);
  remainder_out.emplace(dividend % divisor);
}

int main() {
  int quotient = 0, remainder = 0;
  out<int> quotient_out(&quotient), remainder_out(&remainder);

  divide(14, 3, quotient_out, remainder_out);
  std::cout << quotient << ", " << remainder << std::endl;

  return 0;
}
