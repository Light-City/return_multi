#include <iostream>
#include <tuple>

void divideWithReferences(int dividend, int divisor, int& quotient, int& remainder) {
  quotient = dividend / divisor;
  remainder = dividend % divisor;
}

void divideWithPointers(int dividend, int divisor, int* quotient, int* remainder) {
  if (quotient) *quotient = dividend / divisor;
  if (remainder) *remainder = dividend % divisor;
}

int main() {
  int quotient_ref, remainder_ref;
  int quotient_ptr, remainder_ptr;

  divideWithReferences(14, 3, quotient_ref, remainder_ref);
  std::cout << "Reference Parameters: " << quotient_ref << ", " << remainder_ref
            << std::endl;

  divideWithPointers(14, 3, &quotient_ptr, &remainder_ptr);
  std::cout << "Pointer Parameters: " << quotient_ptr << ", " << remainder_ptr
            << std::endl;

  return 0;
}
