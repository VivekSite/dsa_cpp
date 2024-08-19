#include "../common.h"

int main() {
  deque<int> dq;
  dq.push_back(10);
  dq.push_back(20);
  dq.push_front(30);
  dq.push_front(40);

  for (auto i: dq) 
    cout << i << " ";
  cout << "\n";

  dq.pop_back();
  dq.pop_front();

  for (auto i: dq) 
    cout << i << " ";
  cout << "\n";
}