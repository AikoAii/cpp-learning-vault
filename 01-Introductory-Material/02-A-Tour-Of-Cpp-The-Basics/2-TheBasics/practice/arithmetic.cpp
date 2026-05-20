#include <iostream>

int main() {
  // operator aritmatka
  int angka1 = 2;
  int angka2 = 8;
  int minus = -5;

  std::cout << "pertambahan: " << angka1 + angka2 << '\n';
  std::cout << "pengurangan: " << angka2 - angka1 << '\n';
  std::cout << "perkalian: " << angka1 * angka2 << '\n';
  std::cout << "pembagian: " << angka2 / angka1 << '\n';
  std::cout << "modula (sisa hasil bagi): " << angka2 % angka1 << '\n';

  // operator unary
  std::cout << "plus: " << +minus << '\n';
  std::cout << "minus: " << -angka2 << '\n';

  // operator perbandingan
  int a = 25;
  int b = 67;

  std::cout << (angka2 == angka1) << '\n';
  std::cout << (a != b) << '\n';
  std::cout << (a > b) << '\n';
  std::cout << (a < b) << '\n';
  std::cout << (a >= b) << '\n';
  std::cout << (a <= b) << '\n';

  return 0;
}
