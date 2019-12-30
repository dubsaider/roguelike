#ifndef ROGUE__MAP_HPP_
#define ROGUE__MAP_HPP_
#include "classes.hpp"

class Map {
  int x_, wk_, zk_;
  char map_[25][25];
  Knight k_;
  Princess p_;
  Dragon d_;
  Wall *w_ = new Wall[625];
  Zombie *z_ = new Zombie[625];

 public:
  void CreatMap(char a, int x, int y) {
    map_[y][x] = a;
  }

  Map(const std::string &file) : wk_(0), zk_(0) {
    std::ifstream fin(file);
    int i = 0, l = 0;
    char str[25];
    fin >> str;
    x_ = strlen(str);
    fin.seekg(SEEK_SET);
    while (!fin.eof()) {
      char c;
      fin >> c;
      switch (c) {
        case '\n': {
          continue;
        }
        case 'K': {
          k_ = Knight(i % x_, i / x_);
          break;
        }
        case 'P': {
          p_ = Princess(i % x_, i / x_);
          break;
        }
        case 'D': {
          d_ = Dragon(i % x_, i / x_);
          break;
        }
        case 'Z': {
          z_[zk_++] = Zombie(i % x_, i / x_);
          break;
        }
        case 'W': {
          w_[wk_++] = Wall(i % x_, i / x_);
          break;
        }
      }
      CreatMap(c, i % x_, i / x_);
      i++;
    }
    fin.close();
    ShowMap();
  }

  ~Map() {
    system("cls");
    std::cout << "Game Over\n";
  }

  void ShowMap() {
    for (int i = 0; i < x_ + 2; i++)
      std::cout << "#";
    for (int i = 0; i < x_; i++) {
      std::cout << "\n#";
      for (int j = 0; j < x_; j++)
        std::cout << map_[i][j];
      std::cout << "#\n";
    }
    for (int i = 0; i < x_ + 2; i++)
      std::cout << "#";
    std::cout << "\n";
    std::cout << "Your HP = " << k_.GetHp() << "\n";
  }

  int GetKnightHp() {
    return k_.GetHp();
  }

  bool SearchCharter(char c) {
    for (int i = 0; i < x_; i++) {
      for (int j = 0; j < x_; j++) {
        if (map_[i][j] == c)
          return true;
      }
    }
    return false;
  }

  void Trigger() {
    srand(time(0));
    for (int i = 0; i < zk_; i++) {
      int rz = rand() % 2 + 0;
      int r = rand() % 2 + 0 == 1 ? 1 : -1;
      if (rz == 1) {
        if ((z_[i].GetPos().x_ + r) > -1 && (z_[i].GetPos().x_ + r) < x_
            && map_[z_[i].GetPos().y_][z_[i].GetPos().x_ + r] == '.') {
          CreatMap('.', z_[i].GetPos().x_, z_[i].GetPos().y_);
          CreatMap('Z', z_[i].GetPos().x_ + r, z_[i].GetPos().y_);
          Point a;
          a.x_ = z_[i].GetPos().x_ + r;
          a.y_ = z_[i].GetPos().y_;
          z_[i].SetPos(a);
        }
      } else {
        if ((z_[i].GetPos().y_ + r) > -1 && (z_[i].GetPos().y_ + r) < x_
            && map_[z_[i].GetPos().y_ + r][z_[i].GetPos().x_] == '.') {
          CreatMap('.', d_.GetPos().x_, z_[i].GetPos().y_);
          CreatMap('Z', d_.GetPos().x_, z_[i].GetPos().y_ + r);
          Point a;
          a.x_ = z_[i].GetPos().x_;
          a.y_ = z_[i].GetPos().y_ + r;
          z_[i].SetPos(a);
        }
      }
    }
    int rz = rand() % 2 + 0;
    int r = rand() % 2 + 0 == 1 ? 1 : -1;
    if (rz == 1) {
      if ((d_.GetPos().x_ + r) > -1 &&
          (d_.GetPos().x_ + r) < x_ &&
          map_[d_.GetPos().y_][d_.GetPos().x_ + r] == '.') {
        CreatMap('.', d_.GetPos().x_, d_.GetPos().y_);
        CreatMap('D', d_.GetPos().x_ + r, d_.GetPos().y_);
        Point a;
        a.x_ = d_.GetPos().x_ + r;
        a.y_ = d_.GetPos().y_;
        d_.SetPos(a);
      }
    } else {
      if ((d_.GetPos().y_ + r) > -1 &&
          (d_.GetPos().y_ + r) < x_ &&
          map_[d_.GetPos().y_ + r][d_.GetPos().x_] == '.') {
        CreatMap('.', d_.GetPos().x_, d_.GetPos().y_);
        CreatMap('D', d_.GetPos().x_, d_.GetPos().y_ + r);
        Point a;
        a.x_ = d_.GetPos().x_;
        a.y_ = d_.GetPos().y_ + r;
        d_.SetPos(a);
      }
    }

  }

  void Walk(int dx, int dy) {
    if (((k_.GetPos().x_ + dx) > -1 &&
        (k_.GetPos().x_ + dx) < x_) &&
        ((k_.GetPos().y_ + dy) > -1 &&
            (k_.GetPos().y_ + dy) < x_)) {
      switch (map_[k_.GetPos().y_ + dy][k_.GetPos().x_ + dx]) {
        case '.': {
          CreatMap('K', k_.GetPos().x_ + dx, k_.GetPos().y_ + dy);
          Point a;
          a.x_ = k_.GetPos().x_ + dx;
          a.y_ = k_.GetPos().y_ + dy;
          CreatMap('.', k_.GetPos().x_, k_.GetPos().y_);
          k_.SetPos(a);
          break;
        }
        case 'P': {
          CreatMap('K', k_.GetPos().x_ + dx, k_.GetPos().y_ + dy);
          Point a;
          a.x_ = k_.GetPos().x_ + dx;
          a.y_ = k_.GetPos().y_ + dy;
          CreatMap('.', k_.GetPos().x_, k_.GetPos().y_);
          k_.SetPos(a);
          system("cls");
          printf("You win!");
          system("pause");
          break;
        }
        case 'Z': {
          for (int i = 0; i < zk_; i++) {
            if (z_[i].GetPos().x_ == k_.GetPos().x_ + dx &&
                z_[i].GetPos().y_ == k_.GetPos().y_ + dy) {
              k_.Hit(z_[i].GetDamage());
              z_[i].Hit(k_.GetDamage());
              if (z_[i].GetHp() <= 0) {
                CreatMap('K', k_.GetPos().x_ + dx, k_.GetPos().y_ + dy);
                Point a;
                a.x_ = k_.GetPos().x_ + dx;
                a.y_ = k_.GetPos().y_ + dy;
                CreatMap('.', k_.GetPos().x_, k_.GetPos().y_);
                k_.SetPos(a);
              }
              break;
            }
          }
          break;
        }
        case 'D': {
          k_.Hit(d_.GetDamage());
          d_.Hit(k_.GetDamage());
          if (d_.GetHp() <= 0) {
            CreatMap('K', k_.GetPos().x_ + dx, k_.GetPos().y_ + dy);
            Point a;
            a.x_ = k_.GetPos().x_ + dx;
            a.y_ = k_.GetPos().y_ + dy;
            CreatMap('.', k_.GetPos().x_, k_.GetPos().y_);
            k_.SetPos(a);
          }
          break;
        }
      }
    }
    Trigger();
    ShowMap();
  }
};
#endif //ROGUE__MAP_HPP_
