#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <algorithm>

using namespace std;

typedef struct {

  char CNP[50];
  char nume[50];
  char prenume[50];
  char loc_nastere[50];
  char domiciliu[50];

} person;




int return_age(string cnp){
  cnp.erase(cnp.begin());
  cnp.erase(cnp.begin()+2, cnp.end());
  int year = stoi(cnp);
  if(year <= 19){
    year+= 2000;
  }else{
    year+= 1900;
  }
  return (2019-year);
}


bool acompare(person *lhs, person *rhs) {
  string s(lhs->CNP);
  int age_left = return_age(s);

  string s_(rhs->CNP);
  int age_right = return_age(s);

  return age_left < age_right;
 }
int main(){

  int n;
  std::cout << "Numar persoane: ";
  std::cin >> n;

  person *persoane[n];
  person *sorted_pers[n];

  int counter = 0;

  for (int i = 0;i <n;i++) {
    counter += 1;
    std::cout << "\nPersoana - " << counter << '\n';
    std::cout << "CNP :";
    std::cin >> persoane[i]->CNP;
    std::cout << "Nume :";
    std::cin >> persoane[i]->nume;
    std::cout << "Prenume :";
    std::cin >> persoane[i]->prenume;
    std::cout << "Loc nastere :";
    std::cin >> persoane[i]->loc_nastere;
    std::cout << "Domiciliu :";
    std::cin >> persoane[i]->domiciliu;
  }

  std::sort(persoane, persoane+n, acompare);

}
