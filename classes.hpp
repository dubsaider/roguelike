#ifndef ROGUE__CLASSES_HPP_
#define ROGUE__CLASSES_HPP_

struct Point {
  int x_ = 0, y_ = 0;
};

class Characters {
 public:
  virtual Point GetPos() = 0;
  virtual int GetHp() = 0;
  virtual int GetDamage() = 0;
  virtual char GetSym() = 0;
};

class Knight : public Characters {
 private:
  Point pos_;
  char sym_ = 'K';
  int damage_ = 20;
  int max_hp_ = 100;
  int hp_;
 public:
  Knight() : pos_(), hp_() {}

  Knight(int x, int y) : hp_(max_hp_) {
    pos_.x_ = x;
    pos_.y_ = y;
  }

  Point GetPos() {
    return pos_;
  }
  void SetPos(Point a) {
    pos_.x_ = a.x_;
    pos_.y_ = a.y_;
  }
  int GetHp() {
    return hp_;
  }
  int GetDamage() {
    return damage_;
  }
  char GetSym() {
    return sym_;
  }
  void Hit(int a) {
    hp_ -= a;
  }
};

class Princess : public Characters {
 private:
  Point pos_;
  int hp_;
  int max_hp_ = -1;
  int damage_ = 0;
  char sym_ = 'P';
 public:
  Princess() {
    pos_.x_ = 0;
    pos_.y_ = 0;
    hp_ = max_hp_;
  }
  Princess(int x, int y) {
    pos_.x_ = x;
    pos_.y_ = y;
    hp_ = max_hp_;
  }

  Point GetPos() {
    return pos_;
  }
  int GetHp() {
    return hp_;
  }
  int GetDamage() {
    return damage_;
  }
  char GetSym() {
    return sym_;
  }
};

class Wall : public Characters {
 private:
  Point pos_;
  int hp_;
  int max_hp_ = -1;
  int damage_ = 0;
  char sym_ = '#';
 public:
  Wall() {
    pos_.x_ = 0;
    pos_.y_ = 0;
    hp_ = max_hp_;
  }
  Wall(int x, int y) {
    pos_.x_ = x;
    pos_.y_ = y;
    hp_ = max_hp_;
  }

  Point GetPos() {
    return pos_;
  }
  int GetHp() {
    return hp_;
  }
  int GetDamage() {
    return damage_;
  }
  char GetSym() {
    return sym_;
  }
};

class Zombie : public Characters {
 private:
  Point pos_;
  int hp_;
  int max_hp_ = 10;
  int damage_ = 10;
  char sym_ = 'Z';
 public:
  Zombie() {
    pos_.x_ = 0;
    pos_.y_ = 0;
    hp_ = max_hp_;
  }
  Zombie(int x, int y) {
    pos_.x_ = x;
    pos_.y_ = y;
    hp_ = max_hp_;
  }

  Point GetPos() {
    return pos_;
  }
  void SetPos(Point a) {
    pos_.x_ = a.x_;
    pos_.y_ = a.y_;
  }
  int GetHp() {
    return hp_;
  }
  int GetDamage() {
    return damage_;
  }
  char GetSym() {
    return sym_;
  }
  void Hit(int a) {
    hp_ -= a;
  }
};

class Dragon : public Characters {
 private:
  Point pos_;
  int hp_;
  int max_hp_ = 20;
  int damage_ = 90;
  char sym_ = 'D';
 public:
  Dragon() {
    pos_.x_ = 0;
    pos_.y_ = 0;
    hp_ = max_hp_;
  }
  Dragon(int x, int y) {
    pos_.x_ = x;
    pos_.y_ = y;
    hp_ = max_hp_;
  }

  Point GetPos() {
    return pos_;
  }
  void SetPos(Point a) {
    pos_.x_ = a.x_;
    pos_.y_ = a.y_;
  }
  int GetHp() {
    return hp_;
  }
  int GetDamage() {
    return damage_;
  }
  char GetSym() {
    return sym_;
  }
  void Hit(int a) {
    hp_ -= a;
  }
};

#endif //ROGUE__CLASSES_HPP_
