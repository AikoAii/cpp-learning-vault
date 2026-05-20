#include <cmath>
#include <iostream>
#include <memory>
#include <vector>

constexpr int square(int x) { return x * x; }

// fungsi sum tidak memodifikasi argument karena const
double sum(const std::vector<double> &v) {
  double total{0};
  for (double x : v) {
    total += x;
  }

  return total;
}

int main() {
  const int dmv = 17; // ini constan
  int var = 69;       // ini bulan constan dan nilai dapat berubah

  constexpr double max1 = 1.4 * square(dmv); // aman karena dmv adalah constan
  // constexpr double max2 = 1.4 * square(var); // error karena var bukan
  // constan
  const double max3 = 1.4 * square(var); // ok akan dicek saat runtime

  std::cout << max1 << '\n';
  std::cout << max3 << '\n';
  std::cout << "--------------------------------" << '\n';

  std::vector<double> v{1, 2, 3, 4, 5, 6, 7, 8, 9}; // vector bukan const
  double result = sum(v);
  std::cout << result << '\n';

  const double s1 = sum(v); // o ok, dihitung saat program berjalan
  // constexpr double s2 = sum(v); // error, karena sum(v) bukan constexpr

  return 0;
}
