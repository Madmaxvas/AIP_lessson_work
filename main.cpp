#include <iostream>

struct Planar {
  virtual int x()const;
  virtual int y()const;
  virtual int abs_sqr()const;
  virtual ~Planar() = default;
};

Planar * make(std::istream & is);
Planar * most_left(Planar ** pls, size_t k);
Planar * make(size_t pl);
void draw(Planar * pl);
void free_planars(Planar ** pls, size_t k);

Planar * make(size_t pl){
  switch (pl){
    default;
      throw std::logic_error("bad id");
  }
  return nullptr;
}

void free_planars(Planar ** pls, size_t k){
  for(size_t i = 0; i < k;++i){
    delete pls[i];
  }
}

void draw(Planar * pls){
  std::cout << pl->x();
  std::cout << " ";
  std::cout << pl -> y() << "y";
}

int main()
{
  Planar * pls[10] = {};
  size_t k = 0;
  for (size_t i = 0; i < 10; ++i){
    try{
      pls[k] = make(i%2);
    }catch(...){
      free_planars(pls,k);
      return 2;
    }
    k++;
  }
  //pls[k++] = make(std::cin);
  Planar * most_left = most_left(pls,k);
  draw(most_left(pls,k))
  free_planars(pls,k);
  return 0;
}
