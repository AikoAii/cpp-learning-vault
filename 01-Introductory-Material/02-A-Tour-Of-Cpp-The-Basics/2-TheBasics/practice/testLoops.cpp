#include <iostream>

// statement operator
bool accept() {
  std::cout << "Apakah kamu ingin memprosesnya? (y/n)\n";

  char jawaban{0};
  std::cin >> jawaban;

  if (jawaban == 'y')
    return true;
  return false;
}

// switch operator
bool accept2() {
  std::cout << "Apakah kamu ingin memprosesnya? (y/n)\n";

  char jawaban{0};
  std::cin >> jawaban;

  switch (jawaban) {
  case 'y':
    return true;

  case 'n':
    return false;

  default:
    std::cout << "Saya anggap jawabannya tidak.\n";
    return false;
  }
}

// while loops
bool accept3() {
  int percobaan = 1;
  while (percobaan < 4) {
    std::cout << "Apakah kamu ingin memprosesnya? (y/n)\n";

    char jawaban{0};
    std::cin >> jawaban;

    switch (jawaban) {
    case 'y':
      return true;
    case 'n':
      return false;
    default:
      std::cout << "Maaf, aku tidak memahaminya.\n";
      ++percobaan;
    }
  }
  std::cout << "Saya anggap jawabannya tidak.\n";
  return false;
}

int main() {

  // accept();
  std::cout << "Jawaban: " << accept3() << '\n';
  return 0;
}
