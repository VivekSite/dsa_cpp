#include "../common.h"

class StackUsingQueue1 {
  int N;
  queue<int> q1;
  queue<int> q2;

  public:
    StackUsingQueue1() {
      N = 0;
    }

    void push(int value) {
      q2.push(value);
      N++;

      while (!q1.empty()) {
        q2.push(q1.front());
        q1.pop();
      }

      queue<int> temp = q1;
      q1 = q2;
      q2 = temp;
    }

    void pop() {
      q1.pop();
      N--;
    }

    int top() {return q1.front();}
    int size() {return N;}
};

class StackUsingQueue2 {
  int N;
  queue<int> q1;
  queue<int> q2;

  public:
    StackUsingQueue2() {
      N = 0;
    }

    void push(int value) {
      q1.push(value);
      N++;
    }

    void pop() {
      if (q1.empty()) {
        cout << "Stack is empty" << lb;
        return;
      }

      while (q1.size() != 1) {
        q2.push(q1.front());
        q1.pop();
      }

      q1.pop();
      N--;

      queue<int> temp = q1;
      q1 = q2;
      q2 = temp;
    }

    int top() {
      if (q1.empty()) {
        cout << "Stack is empty" << lb;
        return -1;
      }

      while (q1.size() != 1) {
        q2.push(q1.front());
        q1.pop();
      }

      int x = q1.front();
      q2.push(x);
      q1.pop();

      queue<int> temp = q1;
      q1 = q2;
      q2 = temp;

      return x;
    }

    int size() {return N;}
};

int main() {
  StackUsingQueue2 stack;
  stack.push(10);
  stack.push(20);
  stack.push(30);

  while (stack.size() != 0) {
    cout << stack.top() << lb;
    stack.pop();
  }
}
