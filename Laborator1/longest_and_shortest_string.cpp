#include "iostream"
#include "fstream"

using namespace std;

int main(int argc, char const *argv[]) {

  fstream file;
  string file_name;
  std::cout << "File name : ";
  std::cin >> file_name;

  file.open(file_name, ios::in);
  if(!file){
    std::cout << "Could not open input file!" << '\n';
    return -1;
  }


  string shortest;
  string longest;

  int shortest_length = 99999999999;
  int longest_length = 0;

  string line;

  while (file >> line) {

    if(line.length() > longest_length){
        longest_length = line.length();
        longest = line;
    }

    if(line.length() < shortest_length){
        shortest_length = line.length();
        shortest = line;
    }

  }

  std::cout << "Shortest : " << shortest << " | Longest : " << longest  <<'\n';

  return 0;
}
