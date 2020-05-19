#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <chrono>
#include <ctime>

using namespace std;
using namespace std::chrono;

int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x){
            return mid;
        }
        if (arr[mid] > x){
            return binarySearch(arr, l, mid - 1, x);
        }
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}

int secventialSearch(int arr[], int n, int s){

  for (int i = 0; i < n; i++){
    if(s == arr[i]){
      return i;
    }
  }
  return -1;
}

int main (){

  int n;
  std::cout << "N = " << '\n';
  std::cin >> n;

  int arr[n];

  for (int i = 0; i < n; i++){
    arr[i] = rand();
  }

 int s = arr[150];
 std::cout << "searching for:" << s << '\n';

 sort(arr, arr+n);

 high_resolution_clock::time_point start = high_resolution_clock::now();
 int a = binarySearch(arr, 0, n-1, s);
 high_resolution_clock::time_point end = high_resolution_clock::now();
 auto duration = duration_cast<microseconds>( end - start ).count();

 std::cout << "Binary" << a << '\n';


 high_resolution_clock::time_point start1 = high_resolution_clock::now();
 int ab = secventialSearch(arr, n, s);
 high_resolution_clock::time_point end1 = high_resolution_clock::now();
 auto duration1 = duration_cast<microseconds>( end1 - start1 ).count();

 std::cout << "Secvential" << ab << '\n';

 std::cout << duration<< '\n';
 std::cout << duration1<< '\n';

}
