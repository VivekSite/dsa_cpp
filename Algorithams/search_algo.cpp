#include <bits/stdc++.h>
#define lb "\n"

using namespace std;

class Search_algo
{
public:
  int linear_search(int array[], int size, int target)
  {
    for (int i = 0; i < size; i++)
    {
      if (array[i] == target)
        return i;
    }

    return -1;
  }

  int binary_search(int array[], int size, int target)
  {
    int start = 0;
    int end = size - 1;

    while (start <= end)
    {
      int mid = start + (end - start) / 2;
      if (array[mid] == target)
      {
        return mid;
      }
      else if (array[mid] < target)
      {
        start = mid + 1;
      }
      else
      {
        end = mid - 1;
      }
    }

    return -1;
  }
};
