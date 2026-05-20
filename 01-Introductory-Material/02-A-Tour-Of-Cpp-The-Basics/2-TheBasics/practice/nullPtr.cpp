#include <iostream>

int count_x(char *p, char x) {
  if (p == nullptr) {
    return 0;
  }

  int count{0};

  for (; *p != 0; ++p) {
    if (*p == x) {
      ++count;
    }
  }

  return count;
}

int main() {
  double *pd = nullptr;

  if (pd == nullptr)
    std::cout << "Kosong\n";

  char teks[]{"Hidup jokowi!"};

  int hasil = count_x(teks, 'i');

  std::cout << hasil << '\n';

  return 0;
}
