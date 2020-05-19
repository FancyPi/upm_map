#include <stdio.h>
#include <iostream>

using namespace std;

int compara_int_binar (const void * a, const void * b)
{
  if(*(int*)a< *(int*)b ) return -1;
  else if(*(int*)a== *(int*)b ) return 0;
  else return 1;
}

int compara_float_binar (const void * a, const void * b)
{
 float dif=( *(float*)a - *(float*)b );
 if(dif>0) return 1;
 else if(dif==0) return 0;
   else return -1;
}

void interschimabre(){

}

void sortVector(void*vector, int nr_elemente,size_t dim_element,TIP_PF comp_f){



}

int main(){

  int v[] = { 64, 25, 12, 22, 11 };

  sortVector(&v, 5, sizeof(int), compara_int_binar);

}
