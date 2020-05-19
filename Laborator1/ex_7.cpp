#include "iostream"
#include "fstream"
#include "sstream"
using namespace std;

int main(int argc, char const *argv[]) {

  string input_file_name;
  std::cout << "File name: ";
  std::cin >> input_file_name;

  fstream file;
  file.open(input_file_name, ios::in);

  if(!file){
    std::cout << "Error could not open input file!" << '\n';
    return -1;
  }

  string line;

  string integers = "";

  int n = 0;

  while(file >> line){
    try{
        float a = stoi(line);
        if(a == (int)a){
          if(line.find(".", 0) == string::npos){
            n++;
            integers += " " + line;
          }
        }
      }catch(std::exception&){}
  }

  istringstream numbers_stream(integers);

  int numbers[n];
  int counter = 0;

  while (numbers_stream >> line) {
    numbers[counter] = stoi(line);
    counter++;
  }

  int sum = 0;
  int product = 1;

  for(int item: numbers){

    sum += item;
    product *= item;

  }

  std::cout << "Sum : " << sum << " | Product : " << product << '\n';


  /*
  Sorting the array
  */

  int i, j, temp;

  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      if (numbers[j] < numbers[i]) {
        temp = numbers[i];
        numbers[i] = numbers[j];
        numbers[j] = temp;
      }
    }
  }

  for(int item: numbers){
    std::cout << item << '\n';
  }

  return 0;
}
