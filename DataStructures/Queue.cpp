#include "../common.h"
#define queue_size 100

class Queue
{
  int *arr;
  int front;
  int back;

public:
  Queue()
  {
    arr = new int[queue_size];
    front = -1;
    back = -1;
  }

  void push(int x)
  {
    if (back == queue_size - 1)
    {
      cout << "Queue is full!" << lb;
      return;
    }
    back++;
    arr[back] = x;

    if (front == -1)
    {
      front++;
    }
  }

  void pop()
  {
    if (front == -1 || front > back)
    {
      cout << "Queue is Empty!" << lb;
      return;
    }
    front++;
  }

  int peek()
  {
    if (front == -1 || front > back)
    {
      cout << "Queue is Empty!" << lb;
      return -1;
    }

    return arr[front];
  }

  bool empty()
  {
    if (front == -1 || front > back)
    {
      cout << "Queue is Empty!" << lb;
      return true;
    }

    return false;
  }
}

class QueueUsingStack {
  stack<int> s1;

public:
  void push(int x) {
    s1.push(x);
  }

  int pop() {
    if(s1.empty()) {
      cout << "Queue is empty" << lb;
      return -1;
    }

    int x = s1.top();
    s1.pop();
    if(s1.empty()) {
      return x;
    }

    int item = pop();
    s.push(x);
    return item;
  }
}