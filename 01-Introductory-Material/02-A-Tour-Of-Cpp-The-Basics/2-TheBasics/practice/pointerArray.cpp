#include <iostream>

void copy_fct() {
  int v1[10]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int v2[10]; // nanti isinya akan copy dari v1

  for (auto i = 0; i != 10; ++i) {
    v2[i] = v1[i];
  }
}

void print() {
  int v[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  std::cout << "Ini element asli\n";
  for (auto asli : v) {
    std::cout << asli << '\n'; // untuk setiap elemen di v simpan ke ke x
  }

  std::cout << "Increment tp tidak mengubah nilai asli\n";
  for (auto incr : v) {
    ++incr;
    std::cout << incr << '\n';
  }

  std::cout << "Ini element asli setelah increment\n";
  for (auto asli : v) {
    std::cout << asli << '\n'; // untuk setiap elemen di v simpan ke ke x
  }

  std::cout << "Increment tp mengubah nilai asli\n";
  for (auto &incr : v) {
    ++incr;
    std::cout << incr << '\n';
  }

  std::cout << "Ini element asli setelah increment\n";
  for (auto asli : v) {
    std::cout << asli << '\n'; // untuk setiap elemen di v simpan ke ke x
  }

  for (auto x : {10, 21, 32, 43, 54, 65})
    std::cout << x << '\n'; //
}

int main() {
  char v[6] = {'A', 'B', 'C', 'D', 'E', 'F'}; // array 6 element
  char *p = &v[2]; // pointer ke array elemen ke 3, alamat memory
  char x = *p;     // deference menunjur isi alamat memory

  std::cout << x << '\n';

  copy_fct();
  print();

  return 0;
}
