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

  int trap_rain_water(vector<int> arr) {
    int n = arr.size();
    stack<int> st;
    int ans = 0;

    for (int i=0; i<n; i++) {
      while (!st.empty() && arr[st.top()] < arr[i]) {
        int top = st.top();
        st.pop();

        if (st.empty()) break;
        int len = i - st.top() - 1;
        ans += (min(arr[st.top()], arr[i]) - arr[top]) * len;
      }
      st.push(i);
    }
    return ans;
  }

  bool redundant_paranthesis(string str) {
    stack<char> st;

    for (int i=0; i<str.length(); i++) {
      if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '(') {
        st.push(str[i]);
      } else if (str[i] == ')') {
        if (st.top() == '(') return true;
        while (st.top() == '+' || st.top() == '-' || st.top() == '*' || st.top() == '/') {
          st.pop();
        }
        st.pop();
      }
    }

    return false;
  }

  vector<int> stockspan(vector<int> prices) {
    vector<int> ans;
    stack<pair<int, int> > st;

    for (int i=0; i<prices.size(); i++) {
      int days = 1;
      while (!st.empty() && st.top().first <= prices[i]) {
        days += st.top().second;
        st.pop();
      }
      st.push(make_pair(prices[i], days));
      ans.push_back(days);
    }

    return ans;
  }

  bool three_sum(vector<int> arr, int target) {
    sort(arr.begin(), arr.end());

    for (int i = 0; i < arr.size(); i++) {
      int low = i + 1, high = arr.size() - 1;

      while (low < high) {
        int current = arr[low] + arr[high] + arr[i];

        if (target == current) return true;
        else if (current > target) high--;
        else low++;
      }
    }

    return false;
  }

};

int main() {
  Questions q;
  // {2, 1, 5, 6, 2, 3}
  //  0  1  2  3  4  5
  vector<int> arr;
  arr.push_back(100);
  arr.push_back(80);
  arr.push_back(60);
  arr.push_back(70);
  arr.push_back(60);
  arr.push_back(75);
  arr.push_back(85);

  // cout << "The max rectangle is: " << q.max_rectangle(arr) << lb;
  // cout << "Traped water area is: " << q.trap_rain_water(arr) << lb;
  // cout << "Is Redundant Paranthesis Present: " << q.redundant_paranthesis("((a + b))") << lb;
  // vector<int> stockspan = q.stockspan(arr);
  // cout << "The Size is: " << stockspan.size() << lb;
  // for (int i=0; i<stockspan.size(); i++) {
  //   cout << stockspan[i] << " ";
  // }
  // cout << lb;

  cout << q.three_sum(arr, 20) << lb;

  return 0;
}