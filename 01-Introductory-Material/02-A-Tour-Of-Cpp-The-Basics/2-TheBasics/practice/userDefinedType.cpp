#include <iostream>

// user defined type
struct Player {
  int hp{0};
  int mana{0};
  int level{0};
};

int main() {
  Player hero;

  hero.hp = 100;
  hero.mana = 50;
  hero.level = 1;

  std::cout << "HP: " << hero.hp << '\n';
  std::cout << "Mana: " << hero.mana << '\n';
  std::cout << "Level: " << hero.level << '\n';

  return 0;
}
