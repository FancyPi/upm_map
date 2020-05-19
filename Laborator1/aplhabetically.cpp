#include "iostream"
#include "fstream"

using namespace std;

int main(int argc, char const *argv[]) {
  char alphabet[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
  string file_name;
  std::cout << "File name : ";
  std::cin >> file_name;
  fstream file;
  file.open(file_name, ios::in);
  fstream output;
  output.open("sorted_"+file_name, ios::out);
  if(!file){
    std::cout << "Could not open input file!" << '\n';
    return -1;
  }
  string line;
  char letter;
  for(int i = 0; i < 26;i++){
    letter = alphabet[i];
    while (getline(file, line)) {
      if(line[0] == letter){
        output << line << endl;
      }
    }
    file.clear();
    file.seekg(0, ios::beg);
  }
  return 0;
}
