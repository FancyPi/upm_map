#include "iostream"
#include "fstream"
#include <stdio.h>

using namespace std;

int main(int argc, char const *argv[]) {

  string file_name;
  string output_file_name;

  std::cout << "File name : ";
  std::cin >> file_name;
  fstream base_file;
  base_file.open(file_name, ios::in | ios::out);

  if (!base_file) {
    std::cout << "Error! Could not open input file.";
    return  -1;
  }

  std::cout << "Output file name : ";
  std::cin >> output_file_name;

  fstream new_file;
  new_file.open(output_file_name, ios::out);

  if(!new_file){
    std::cout << "Error! Could not create new file!";
    return -1;
  }

  string line;
  int counter = 1;

  while (getline(base_file, line)) {
    new_file << counter <<  " "  << line << endl;
    counter++;
  }

  if(remove(file_name.c_str()) != 0){
      std::cout << "Error while deleting and renaming file" << '\n';
      return -1;
  }
  rename(output_file_name.c_str(), file_name.c_str());
  return 0;
}
