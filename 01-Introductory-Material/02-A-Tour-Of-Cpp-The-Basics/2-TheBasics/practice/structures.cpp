#include <cmath>
#include <iostream>

struct Vector {
  int sz;       // ukuran elemen array
  double *elem; // pointer ke elemen
};

void vector_init(Vector &v, int s) {
  v.elem = new double[s]; // dynamic allocation, memesan memori sebanyak s
  v.sz = s;               // menentukan ukuran
}

double read_and_sum(int s) {
  Vector v;
  vector_init(v, s);

  for (int i = 0; i != s; i++)
    std::cin >> v.elem[i];

  double sum{0};
  for (int i = 0; i != s; ++i)
    sum += v.elem[i];

  return sum;
}

int main() {
  Vector v; // buat object

  vector_init(v, 10); // inisialisasi Vector

  for (int i = 0; i < v.sz; ++i) {
    v.elem[i] = i * 10;
  }

  for (int i = 0; i < v.sz; ++i) {
    std::cout << v.elem[i] << '\n';
  }

  std::cout << "-------------------------------\n";

  std::cout << "Input angka:\n";

  double hasil = read_and_sum(5);

  std::cout << "Hasil: " << hasil << '\n';

  return 0;
}
