#include <iostream>

// constexpr function
constexpr double square(int x) { return x * x; }

int main() {
  // Constexpr
  constexpr int maxPlayer{16};
  constexpr double area = square(5);

  std::cout << "=== Constexpr ===" << '\n';
  std::cout << "Max player = " << maxPlayer << '\n';
  std::cout << "Area = " << area << '\n';

  // Const
  const double pi{3.14159};
  std::cout << "=== Const ===" << '\n';
  std::cout << "pi: " << pi << '\n';

  // Runtime input
  double radius{0};
  std::cout << "Input radius: ";
  std::cin >> radius;

  // runtime calculation
  const double circle_area = pi * square(radius);
  std::cout << "Circle area: " << circle_area << '\n';

  // kenapa constexpr di runtime gagal?
  // constexpr double error = square(radius);
  // std::cout << error << '\n';

  return 0;
}
