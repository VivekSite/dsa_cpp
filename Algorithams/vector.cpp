#include <iostream>
#include <vector>

using namespace std;

bool custom_comparator(pair<int, int> p1, pair<int, int> p2) {
  return p1.first < p2.first
}

int main() {
  vector<int> v;
  v.push_back(10);
  v.push_back(20);
  v.push_back(30);

  v.pop_back();
  int size = v.size();

  // for(int i=0; i<size; i++) {
  //   cout << v[i] << " ";
  // }
  // cout << endl;

  // vector<int>::iterator it;
  // for(it=v.begin(); it!=v.end(); it++) {
  //   cout << *it << " ";
  // }
  // cout << endl;

  // for(auto element: v) {
  //   cout << element << " ";
  // }
  // cout << endl;

  pair<int, char> p1;
  p1.first = 10;
  p1.second = 'A';

  vector< pair<int, int> > v2; // vector of pairs
  sort(v2.begin(), v2.end(), custom_comparator);
  return 0;
}