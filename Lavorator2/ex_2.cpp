#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

typedef struct {
  int x;
  int y;
} Punct2D;

double distanta(Punct2D first, Punct2D second){
  return sqrt((first.x - second.x) + (first.y - second.y));
}

Punct2D centru_greutate(Punct2D first,Punct2D second,Punct2D third){
  Punct2D new_;
  new_.x = (first.x + second.x + third.x) /3;
  new_.y = (first.y + second.y + third.y) /3;

  return new_;
}

int main(){

  Punct2D first;
  Punct2D second;
  Punct2D third;
  Punct2D centru_de_greutate;

  int switcher;

  std::cout << "First coord:" << '\n';
  std::cout << "x:" ;
  std::cin >> first.x;
  std::cout << "y:" ;
  std::cin >> first.y;

  std::cout << "Second coord:" << '\n';
  std::cout << "x:" ;
  std::cin >> second.x;
  std::cout << "y:" ;
  std::cin >> second.y;

  std::cout << "Third coord:" << '\n';
  std::cout << "x:" ;
  std::cin >> third.x;
  std::cout << "y:" ;
  std::cin >> third.y;
  float dist;
again:
  std::cout << "Distanta intre care?" << '\n';
  std::cout << "1)  1 - 2" << '\n';
  std::cout << "2)  1 - 3" << '\n';
  std::cout << "3)  2 - 3" << '\n';

  std::cin >> switcher;

  switch (switcher) {
    case 1:
       dist = distanta(first, second);
       std::cout << "Distanta " <<  dist<< '\n';
      break;
    case 2:
       dist = distanta(first, third);
       std::cout << "Distanta " <<  dist<< '\n';
     break;

    case 3:
       dist = distanta(second, third);
       std::cout << "Distanta " <<  dist<< '\n';
      break;
    default:
      goto again;
      break;
  }

  centru_de_greutate = centru_greutate(first, second, third);

  std::cout << "Centru de greutate este :" << centru_de_greutate.x << " - " << centru_de_greutate.y << '\n';

}
