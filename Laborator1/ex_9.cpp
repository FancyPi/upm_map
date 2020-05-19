#include "fstream"
#include "iostream"
#include "sstream"

using namespace std;

struct angajat {
  string name;
  string prenume;
  unsigned salariu;
};

int main(int argc, char const *argv[]) {

  string file_name;
  std::cout << "File name: ";
  std::cin >> file_name;

  fstream file;

  file.open(file_name, ios::in);

  if(!file){
    std::cout << "Could not open input file!" << '\n';
    return -1;
  }

  string line;
  string individual_information;
  int n;

  while (getline(file, line)) {
    if (line.length()  < 5) {
      n = stoi(line);
      break;
    }
  }

  angajat firma[n];
  int index = 0;

  float sum = 0;
  float medie_before = 0;

    try{
      while (getline(file, line)) {
        angajat angajat = {};
        if(line.length()  == 1){
            continue;
        }else{
          int data_index = 1;
          firma[index] = angajat;
          istringstream stream(line);
          while(stream >> individual_information){
            switch (data_index) {
              case 1:
              firma[index].name = individual_information;
                break;
              case 2:
              firma[index].prenume = individual_information;
                break;
              case 3:
              firma[index].salariu = stoi(individual_information);
              sum += firma[index].salariu;
                break;
            }
            data_index++;
          }
          index++;
        }
      }
    }catch(const std::exception& e){

    }
  medie_before = sum / n;

  for(angajat angajat : firma){
    std::cout << "-----------------------" << '\n';
    std::cout << "Nume : " << angajat.name << '\n';
    std::cout << "Prenume : " << angajat.prenume << '\n';
    std::cout << "Salariu : " << angajat.salariu << '\n';
    std::cout << "-----------------------" << '\n';
  }

  std::cout << "Medie before : " << medie_before << '\n';

  float after_sum = 0;

  for (angajat angajat : firma ) {
    angajat.salariu = angajat.salariu - (angajat.salariu*0.25);
    after_sum +=angajat.salariu;
  }
  float medie_after = after_sum / n;
  std::cout << "Medie after : " << medie_after << '\n';
  std::cout << "Diferenta : " << 100 - medie_after * 100 / medie_before  << '\n';

  return 0;
}
