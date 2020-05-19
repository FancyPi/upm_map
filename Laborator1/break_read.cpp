#include "iostream"
#include "fstream"
#include "conio.h"
using namespace std;

int main(int argc, char const *argv[]) {



  string file_name;
  std::cout << "File namne : ";
  std::cin >> file_name;
  fstream file;

  file.open(file_name, ios::out);

  string writing;

  while (std::cin >> writing) {
    if(writing == "^Z"){
        break;
    }else{
      file << writing << endl;
    }
  }
  std::cout << "Done!" << '\n';
  return 0;
}
