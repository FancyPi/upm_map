#include "iostream"
#include "fstream"


using namespace std;

int main(int argc, char const *argv[]) {


  string file_name;
  string search;

  string::iterator it;

  std::cout << "File name : ";
  std::cin >> file_name;

  fstream file;
  file.open(file_name, ios::in);

  if(!file){
    std::cout << "Error! Could not open input file." << '\n';
    return -1;
  }

  choose_word:
  std::cout << "What word should I count ?" << '\n';
  std::cin >> search;

  if(search.length() == 0){
      std::cout << "That's not even character :(" << '\n';
      goto choose_word;
  }

  string file_contents;

  string line;

  while (file >> line) {
    file_contents  += line;
  }

  string substring;
  int occurences, pos = 0;

  while (file_contents.length() != 0) {
    substring = file_contents.substr(0, search.length());
    if(substring == search){
        occurences++;
        file_contents.erase(0, search.length());
    }else{
      file_contents.erase(0,1);
    }
  }

  std::cout << "The word `" << search << "` appears " << occurences << " times in " << file_name <<'\n';

  return 0;
}
