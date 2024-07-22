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

};

int main() {
  int array[10] = {2, 5, 4, 1, 0, 6, 18, 12, 9, 10};
  Sorting_algo s1;
  print_array(array, 10);
  s1.quick_sort(array, 0, 9);
  print_array(array, 10);

  return 0;
}