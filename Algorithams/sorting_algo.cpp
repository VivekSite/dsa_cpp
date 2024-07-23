#include "../common.h"

class Sorting_algo {
private:
  void merge(int array[], int l, int mid, int r) {
    int n1 = mid - l + 1;
    int n2 = r - mid;

    // Create a new arrays and copy the elements
    int left[n1], right[n2];
    for(int i=0; i<n1; i++) left[i] = array[l+i];
    for(int i=0; i<n1; i++) right[i] = array[mid+i+1];

    int i = 0, j = 0, k = l;  // temp pointers to arrays
    while(i < n1 && j < n2) {
      if(left[i] < right[j]) array[k++] = left[i++];
      else array[k++] = right[j++];
    }

    while(i < n1) array[k++] = left[i++];
    while(j < n2) array[k++] = right[j++];
  }

  void swap(int array[], int i, int j) {
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
  }

  int partition(int array[], int l, int r) {
    int pivot = array[r];
    int i = l - 1;

    for(int j = l; j < r; j++) {
      if(array[j] < pivot) {
        i++;
        swap(array, i, j);
      }
    }

    swap(array, i+1, r);
    return i+1;
  }

public:
  void bubble_sort(int* array, const int size) {
    bool swapped;
    do {
      swapped = false;
      for (int i=0; i<size-1; i++) {
        if(array[i] > array[i+1]) {
          int temp = array[i];
          array[i] = array[i+1];
          array[i+1] = temp;

          swapped = true;
        }
      }
    } while(swapped);
  }

  void insertion_sort(int* array, const int size) {
    for(int i=1; i<size; i++) {
      int number_to_insert = array[i];
      int j = i - 1;

      while(j >= 0 && array[j] > number_to_insert) {
        array[j + 1] = array[j];
        j--;
      }
      array[j + 1] = number_to_insert;
    }
  }

  void selection_sort(int* array, const int size) {
    for(int i=0; i<size; i++) {
      for(int j=i+1; j<size; j++) {
        if(array[j] < array[i]) {
          int temp = array[j];
          array[j] = array[i];
          array[i] = temp;
        } 
      }
    }
  }

  void merge_sort(int* array, const int l, const int r) {
    if(l >= r) return;

    int mid = (l + r) / 2;
    merge_sort(array, l, mid);
    merge_sort(array, mid + 1, r);

    merge(array, l, mid, r);
  }

  void quick_sort(int array[], const int l, const int r) {
    if(l >= r) return;
  
    int pivot = partition(array, l, r);
    quick_sort(array, l, pivot - 1);
    quick_sort(array, pivot + 1, r);
  }

  void counting_sort(int array[], const int size) {
    int max_element = array[0];
    for(int i=0; i<size; i++) max(max_element, array[i]);

    int count[max_element + 1];
    for(int i=0; i<max_element+1; i++) count[i] = 0;
    for(int i=0; i<size; i++) count[array[i]]++;

    int idx = 0;
    for(int i=0; i<max_element+1; i++) {
      while(count[i]) {
        array[idx++] = i;
        count[i]--;
      }
    }
  }

  void dnf_sort(int array[], const int size) {
    int low = 0, mid = 0;
    int high = size-1;

    while(mid < high) {
      switch (array[mid])
      {
      case 0: 
        swap(array, low, mid);
        mid++; low++;
        break;
      case 1:
        mid++;
        break;
      case 2:
        swap(array, high, mid);
        high--;
        break;
      }
    }
  }

  void wave_sort(int array[], const int size) {
    for(int i=1; i<size-1; i+=2) {
      if(array[i] > array[i-1]) swap(array, i, i-1);

      if(array[i] > array[i+1] && i <= size-2) {
        swap(array, i, i+1);
      } 
    }
  }

};

int main() {
  int array[7] = {1, 3, 4, 7, 5, 6, 2};
  Sorting_algo s1;
  print_array(array, 7);
  s1.wave_sort(array, 7);
  print_array(array, 7);

  return 0;
}