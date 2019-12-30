#include <iostream>
#include <utility>
#include <cstring>
#include <conio.h>
#include <fstream>
#include <ctime>
#include "classes.hpp"
#include "map.hpp"

using namespace std;

int Play(const std::string& file){
  Map map(file);
  while (map.GetKnightHp() > 0 && map.SearchCharter('P')) {
    if (_kbhit()) {
      switch (getch()) {
        case 'w': {
          map.Walk(0, -1);
          break;
        }
        case 's': {
          map.Walk(0, 1);
          break;
        }
        case 'a': {
          map.Walk(-1, 0);
          break;
        }
        case 'd': {
          map.Walk(1, 0);
          break;
        }
      }
    }
  }
  if (map.GetKnightHp() < 0)
    return 0;
  else
    return 1;
}

int main() {
  srand(time(nullptr));
  if (Play("map1.txt")){
    Play("map2.txt");
  }
  return 0;
}