#include <cmath>
#include <complex.h>
#include <complex>
#include <iostream>
#include <vector>

int main() {
  double d1 = 27.7; // inisialisasi tradisional style C
  double d2{56.3};  // Uniform Initialization atau Bracket Initialization

  std::cout << "nilai d1: " << d1 << '\n';
  std::cout << "nilai s2: " << d2 << '\n';

  // pakai nilai complex Initialization
  std::complex<double> z = 1;      // nilainya i + 0i dg satu nilai
  std::complex<double> z2{d1, d2}; // artinya d1 + d1 i

  std::cout << "Nilai z: " << z << '\n';
  std::cout << "nilai z2: " << z2 << '\n';

  // vector Initialization
  std::vector<int> v{1, 2, 3, 4, 5, 6};

  std::cout << v[0] << '\n';
  std::cout << v[1] << '\n';
  std::cout << v[2] << '\n';

  // narrowing conversion
  int i1 = 7.2; // akan menjadi 7 angka dibekakan diabaikan
  // int i2{7.2};  // error: bilangan bulat jadi desimal
  // int i3{7.2};  // error

  // jangan sampai variable kosong karena nanti isinya bisa memory random, angka
  // random atau sampah
  int sampah;

  std::cout << "isi sampah: " << sampah << '\n';

  // yang benar isi aja nol
  int var = 0;
  std::cout << var << '\n';

  // type deduction
  auto cilok = true;
  auto pi{3.14159};
  auto nilai{'a'};
  auto ank{81};
  auto zx = std::sqrt(ank);

  std::cout << cilok << '\n';
  std::cout << pi << '\n';
  std::cout << nilai << '\n';
  std::cout << zx << '\n';

  // Compound Assignment Operators
  ank += 19;
  std::cout << ank << '\n';
  ank *= 192;
  std::cout << ank << '\n';

  // Increment dan Decrement
  ++pi;
  std::cout << pi << '\n';
  --pi;
  std::cout << pi << '\n';

  return 0;
}
