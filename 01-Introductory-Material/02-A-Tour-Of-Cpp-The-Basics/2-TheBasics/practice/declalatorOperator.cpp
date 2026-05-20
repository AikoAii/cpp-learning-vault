#include <iostream>

// T (A) fungsi menerima int dan mengembalikan int
int square(int x) { return x * x; }

int main() {
  // T a[n]; array of int
  int angka[5]{1, 2, 3, 4, 5};

  for (auto num : angka) {
    std::cout << num << '\n';
  }

  // T* p; pointer ke int
  int *p = &angka[2]; // pointer menunjur ke alamat elemen ke-3 array = ke-3
  std::cout << "Alamat: " << p << '\n';
  std::cout << "Isi: " << *p << '\n';

  // T& r; reference to int
  int value{100};

  int &r = value;

  std::cout << "value: " << value << '\n';
  std::cout << "r: " << r << '\n';

  // T (A); function
  int hasil = square(5);
  std::cout << "Square(5): " << hasil << '\n';
  return 0;
}
