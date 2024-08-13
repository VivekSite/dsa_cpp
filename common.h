#include <bits/stdc++.h>
#define lb "\n"
using namespace std;

void reverse_str(string &str)
{
  int start = 0;
  int end = str.length() - 1;

  while (start < end)
  {
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;

    start++;
    end--;
  }
}

void print_array(const int* array, const int size) {
  cout << "[ ";

  for(int i=0; i<size; i++) {
    if(i == size-1) 
      cout << array[i];
    else 
      cout << array[i] << ", ";
  }
  
  cout << " ]" << lb;
}
