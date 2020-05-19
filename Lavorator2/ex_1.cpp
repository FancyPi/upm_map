#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

struct coord {
  float x;
  float y;
  float z;
};

double distanta(coord first, coord second){
  return sqrt((first.x - second.x) + (first.y - second.y) + (first.z - second.z));
}

int main(){

  coord first;
  coord second;

  std::cout << "Primele coords :" << '\n';
  std::cout << "x: ";
  std::cin >> first.x;
  std::cout << "y: ";
  std::cin >> first.y;
  std::cout << "z: ";
  std::cin >> first.z;
  std::cout << "Second coords :" << '\n';
  std::cout << "x: ";
  std::cin >> second.x;
  std::cout << "y: ";
  std::cin >> second.y;
  std::cout << "z: ";
  std::cin >> second.z;

  float _distanta = distanta(first, second);

  std::cout << "Distanta este: " << _distanta << '\n';


}
