#include "../common.h"

class Questions {

public:
  int max_rectangle(vector<int> arr) {
    int n = arr.size();
    int ans = 0;
    int i = 1;

    stack<int> st;
    st.push(0);

    while (i < n) {
      while (!st.empty() && arr[st.top()] > arr[i]) {
        int top = st.top();
        int height = arr[top];
        st.pop();

        if (st.empty()) {
          ans = max(ans, height*i);
        } else {
          int len = i - st.top() - 1;
          ans = max(ans, height*len);
        }
      }
      st.push(i);
      i++;
    }
    return ans; 
  }
};

int main() {
  Questions q;
  // {2, 1, 5, 6, 2, 3}
  //  0  1  2  3  4  5
  vector<int> arr;
  arr.push_back(2);
  arr.push_back(1);
  arr.push_back(5);
  arr.push_back(6);
  arr.push_back(2);
  arr.push_back(3);

  cout << "The max rectangle is: " << q.max_rectangle(arr) << lb;

  return 0;
}