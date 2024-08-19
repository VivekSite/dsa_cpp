#include "../common.h"

class SlidingWindow {
public:
  vector<int> max_in_window(vector<int> arr, int k) {
    // Time Complexity O(nlogn)
    vector<int> ans;
    multiset<int, greater<int> > set;

    for (int i=0; i<k; i++) {
      set.insert(arr[i]);
    }
    ans.push_back(*set.begin());

    for (int i=k; i<arr.size(); i++) {
      set.erase(set.lower_bound(arr[i-k]));
      set.insert(arr[i]);
      ans.push_back(*set.begin());
    }
    return ans;
  }

  vector<int> max_in_window_deque(vector<int> arr, int k) {
    // Time Complexity O(n)
    deque<int> dq;
    vector<int> ans;

    for (int i=0; i<k; i++) {
      while(!dq.empty() && arr[dq.back()] < arr[i]) {
        dq.pop_back();
      }
      dq.push_back(arr[i]);
    }
    ans.push_back(arr[dq.front()]);

    for (int i=k; i<arr.size(); i++) {
      if (dq.front() == i-k) {
        dq.pop_front();
      }

      while(!dq.empty() && arr[dq.back()] < arr[i]) {
        dq.pop_back();
      }
      dq.push_back(i);
      ans.push_back(arr[dq.front()]);
    }

    return ans;

  }

};

int main() {
  SlidingWindow sw;
  vector<int> arr;
  arr.push_back(1);
  arr.push_back(3);
  arr.push_back(-1);
  arr.push_back(3);
  arr.push_back(5);
  arr.push_back(3);
  arr.push_back(6);
  arr.push_back(7);

  vector<int> ans = sw.max_in_window_deque(arr, 3);
  
  for (int num: ans) {
    cout << num << " ";
  }
}