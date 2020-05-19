#include <iostream>
#include <fstream>

using namespace std;

int main (){

  fstream base_file;
  base_file.open("base_file.txt", ios::in);

  if(!base_file){
      std::cout << "Error! Could not open file `base_file.txt`" << '\n';
      return -1;
  }

  string new_file_name;

  std::cout << "How should the new file be called ?\n";
  std::cin >> new_file_name;

  fstream new_file;
  new_file.open(new_file_name, ios::out);

  if(!new_file){
    std::cout << "Error! Could not create new file!" << '\n';
    return  -1;
  }

  char ch;
  string line;
  while (!base_file.eof()) {
    base_file >> noskipws >> ch;
    new_file << ch;
  }

  std::cout << "Successfully copied base_file.txt to " + new_file_name << '\n';

  return 0;
}
