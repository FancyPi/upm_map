#include "iostream"
#include "fstream"

using namespace std;

int main(int argc, char const *argv[]) {


  string  first_file_name;
  string  second_file_name;

  fstream first_file;
  std::cout << "First file Name : " << '\n';
  std::cin >> first_file_name;

  first_file.open(first_file_name,ios::out | ios::in);
  if(!first_file){
     std::cout << "Could not open input file!" << '\n';
     return -1;
  }

  fstream second_file;
  std::cout << "Second file Name : " << '\n';
  std::cin >> second_file_name;

  second_file.open(second_file_name, ios::in);
  if(!second_file){
     std::cout << "Could not open input file!" << '\n';
     return -1;
  }

  string first_text;
  string second_text;
  string line;


  while (first_file >> line) {
     first_text += line + "\n";
  }

  while (second_file >> line) {
     first_text += line + "\n";
  }

  std::cout << (first_text + second_text) << '\n';

  first_file << (first_text + second_text);

  fstream file_one;
  file_one.open(first_file_name, ios::out);
  file_one << (first_text + second_text);

  file_one.close();
  first_file.close();
  second_file.close();

  return 0;
}
