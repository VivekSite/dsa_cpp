#include "../common.h"

class BitManipulation {
public:
  int get_bit(const int n, const int p) {
    return (n & (1 << p)) == 0 ? 0 : 1;
  }

  int set_bit(const int n, const int p) {
    return n | (1 << p);
  }

  int clear_bit(const int n, const int p) {
    return n & (~(1 << p));
  }

  int update_bit(int n, const int p, const int bit) {
    n = n & (~(1 << p));  // clear the bit
    return n | (bit << p);
  }

  bool is_power_of_two(const int n) {
    return (n && !(n & n-1));
  }

  int count_set_bits(int n) {
    int bits = 0;
    while(n) {
      n = n & n-1;
      bits++;
    }

    return bits;
  }

  void print_subsets(const int array[], const int n) {
    for(int i=0; i< (1 << n); i++) {
      for(int j=0; j<n; j++) {
        if(i & (1 << j)) {
          cout << array[j] << " ";
        }
      }
      cout << lb;
    }
  }

  int one_unique_from_doublet(const int array[], const int n) {
    int unique = 0;
    for(int i=0; i<n; i++) {
      unique ^= array[i];
    }

    return unique;
  }

  void two_unique_from_doublet(const int array[], const int n) {
    // Calculate Xor Sum
    int xor_sum = 0;
    for(int i=0; i<n; i++) {
      xor_sum ^= array[i];
    }

    int temp_xor = xor_sum;
    int set_bit = 0;
    int pos = 0;
    while(set_bit != 1) {  //  Find the position of rightmost set bit
      set_bit = temp_xor & 1;
      pos++;
      temp_xor >>= 1;
    }

    int new_xor = 0;
    for(int i=0; i<n; i++) {  // Xor every element which has set bit at that position
      if(array[i] & (1 << (pos-1))) {
        new_xor ^= array[i];
      }
    }

    cout << "First Unique: " << new_xor << lb;
    cout << "Second Unique: " << (new_xor^xor_sum) << lb;
  }

  int one_unique_from_triplet(const int array[], const int n) {
    int result = 0;
    
    for(int i=0; i<64; i++) {
      int sum = 0;
      for(int j=0; j<n; j++) {
        if(array[j] & (1 << i)) sum++;
      }
      if(sum % 3 != 0) result = result | (1 << i);
    }

    return result;
  }
};

int main() {
  BitManipulation bm;
  int array[10] = {1, 2, 3, 1, 2, 3, 1, 2, 3, 13};
  cout << bm.one_unique_from_triplet(array, 10) << lb;

  return 0;
}