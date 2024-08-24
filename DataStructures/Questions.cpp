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

  int max_consecutive_ones_with_k_zeros(int arr[],int size, int k) {
    int k_count = 0;
    int start = 0;
    int ans = 0;

    for (int end=0; end<size; end++) {
      if (arr[end] == 0) k_count++;

      if (k_count > k) {
        while (arr[start] != 0) start++;
        start++;
        k_count--;
      }
      ans = max(ans, end-start+1);
    }

    return ans;
  }

  int logest_substring_without_repeating(string str) {
    vector<int> dict(256, -1);
    int maxLen = 0, start = -1;

    for (int end=0; end<str.length(); end++) {
      if(dict[str[end]] > start)
        start = dict[str[end]];
      
      dict[str[end]] = end;
      maxLen = max(maxLen, end-start);
    }

    return maxLen;
  }
};

int main() {
  Questions q;
  cout << q.logest_substring_without_repeating("abcabc") << lb;
  return 0;
}