#include <cmath>
#include <iostream>
using namespace std;

// buat fungsi kuadrat
double square(double x) { return x * x; }

// fungsi cetak
// void tidak ada nilai kembalian (return)
void print_square(double x) {
  cout << "Square of " << x << " is " << square(x) << '\n';
}

int main() {
  print_square(12345); // panggil fungsi cetak
}
