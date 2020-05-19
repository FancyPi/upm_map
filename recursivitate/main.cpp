#include <iostream>
#include <stdio.h>



void euclid(int a, int b, int *d){
  if (b == 0) {
      *d = a;
  } else{
      euclid(b, a % b, d);
  }
}

void pow(int base, int _pow, int *res){

  if(_pow == 0){
    return;
  }else{
      *res *= base;
      pow(base, --_pow, res);
  }

}

void factorial(int n, int *res){

  if(n == 0){
    return;
  }

  *res *=n;

  factorial(n-1, res);

}

void reverse(int n){
  if(n<10){
    std::cout << n << '\n';
    return;
  }
  int t = n % 10;
  std::cout << t;
  reverse(n / 10);
}

  int search_max(int arr[], int n, int max){
    if(arr[n] > max){
      max = arr[n];
      search_max(arr, n-1, max);
    }else{
      if(n >= 0){
        search_max(arr, n-1, max);
      }else{
        return max;
      }
    }
  }
  
int main(){
  int res = 1;

  pow(3, 3, &res);

  std::cout << res << '\n';

  int fact = 1;

  factorial(res, &fact);

  std::cout << fact << '\n';

  reverse(fact);

//             1 2 3 4 5 6 7 8 9 10 11 12 13
  int arr[] = {2,1,4,2,4,6,7,8,3,2,55,3,19};

  int maxim = search_max(arr, 12, 0);

  std::cout << maxim << '\n';
}
