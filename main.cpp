#include <iostream>
#include <stdexcept>

struct Planar {
  virtual int x() const = 0;
  virtual int y() const = 0;
  virtual int abs_sqr() const = 0;
  virtual ~Planar() = default;
};

struct Point : Planar {
    Point(int xx, int yy);  // Объявление конструктора
    virtual int x() const;
    virtual int y() const;
    virtual int abs_sqr() const;
    virtual ~Point() = default;
  private:
    int data[2];
};

// Определение конструктора Point
Point::Point(int xx, int yy) {
    data[0] = xx;
    data[1] = yy;
}

int Point::x() const{
  return data[0];
}

int Point::y() const{
  return data[1];
}

int Point::abs_sqr() const{
  return x()*x()+y()*y();
}

Planar* make(std::istream & is);
Planar* most_left(Planar** pls, size_t k);
Planar* make(size_t pl);
void draw(Planar* pl);
void free_planars(Planar** pls, size_t k);

Planar* make(size_t id){
  Planar* r = nullptr;  // Исправлено: добавлено =
  switch(id){
    case 0:  // Исправлено: : вместо ;
      r = new Point(0,0);
      break;
    default:
      throw std::logic_error("bad id");
  }
  return r;
}

void free_planars(Planar** pls, size_t k) {
  for(size_t i = 0; i < k; ++i) {
    delete pls[i];
  }
}

void draw(Planar* pl) {
  std::cout << pl->x() << " " << pl->y();
}

Planar* most_left(Planar** pls, size_t k) {
  if (k == 0) return nullptr;
  Planar* leftmost = pls[0];
  for (size_t i = 1; i < k; ++i) {
    if (pls[i]->x() < leftmost->x()) {
      leftmost = pls[i];
    }
  }
  return leftmost;
}

int main() {
  Planar* pls[10] = {};
  size_t k = 0;
  for (size_t i = 0; i < 10; ++i) {
    try {
      pls[k] = make(i % 2);
      k++;
    } catch(...) {
      free_planars(pls, k);
      return 2;
    }
  }

  Planar* leftmost = most_left(pls, k);
  draw(leftmost);
  free_planars(pls, k);
  return 0;
}

