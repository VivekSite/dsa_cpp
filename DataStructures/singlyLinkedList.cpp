#include<bits/stdc++.h>

using namespace std;

/*––––––––––––––––––– class node –––––––––––––––––––*/
class node{
  public:
  int data; node* next;
  node(int value){
    data = value;
    next = NULL;
  }
};

/*––––––––––––––––––– LinkedList Creation –––––––––––––––––––*/
class LinkedList{
  public:
  node* head;
  int size;
  LinkedList(){
    head = NULL;
    size = 0;
  }
  int getSize(){ return size; }
  bool isEmpty(){ return size == 0; }

  /*–––––--- append method –––––---*/
  void append(int value){
    node* newNode = new node(value);
    size++;
    if(head == NULL){
      head = newNode;
      return;
    }

    node* temp = head;
    while(temp->next != NULL){
      temp = temp->next;
    }
    temp->next = newNode;
  }

  /*-------- prepend method --------*/
  void prepend(int value){
    node* newNode = new node(value);
    if(isEmpty()){
      head = newNode;
    }else{
      newNode->next = head;
      head = newNode;
    }
    size++;
  }

  /*–––––––– deletion method ––––––––*/
  void deletion(int index){
    if(head == NULL || index > size-1){ return; }
    if(index == 0){ 
      node* toDelete = head;
      head = head->next; 
      size--;
      delete toDelete;
    }else{
      node* prev = NULL;
      node* curr = head;
      while(index--){
        prev = curr;
        curr = curr->next;
      }
      prev->next = curr->next;
      size--;
      delete curr;
    }
  }

  /*–––––––– reverse method ––––––––-*/
  void reverse(){
    node* prev = NULL;
    node* curr = head;
    node* next;
    while(curr != NULL){
      next = curr->next;
      curr->next = prev;

      prev = curr;
      curr = next;
    }
    head = prev;
  }

  /*–––––––– reverse k nodes ––––––––*/
  node* reverseKNodes(int k, node* &h){
    node* prev = NULL;
    node* curr = h;
    node* next;

    int count = 0;
    while(curr != NULL && count < k){
      next = curr->next;
      curr->next = prev;

      prev = curr;
      curr = next;
      count++;
    }

    if(next != NULL){
      h->next = reverseKNodes(k , next); 
    }
    return prev;
  }

  bool isCycle(){
    node* slow = head;
    node* fast = head;
    while(fast != NULL && fast->next != NULL){
      slow = slow->next;
      fast = fast->next->next;
      if(fast == slow){
        return true;
      }
    }
    return false;
  }

  void removeCycle(){
    node* slow = head;
    node* fast = head;

    do{
      slow = slow->next;
      fast = fast->next->next;
    }while(fast != slow);
    fast = head;

    while(fast->next != slow->next){
      fast = fast->next;
      slow = fast->next;
    }
    slow->next = NULL;
  }

  void createCycle(int pos){
    node* temp = head;
    node* startNode;

    int count = 1;
    while(temp->next != NULL){
      if(count == pos){
        startNode = temp;
      }
      temp = temp->next;
      count++;
    }
    temp->next = startNode;
  }

  /*--------- print method ----------*/
  void print(){
    node* temp = head;
    while(temp != NULL){
      cout << temp->data << "-->";
      temp = temp->next;
    }
    cout << "NULL" << endl;
  }
};

/*––––––––––––––––––– Main Function –––––––––––––––––––*/
int main(){
  #ifndef ONLINE_JUDGE
    freopen("./../input.txt","r", stdin);
    freopen("./../output.txt","w", stdout);
  #endif

  LinkedList list; 
  list.prepend(40);
  list.append(10);
  list.append(20);
  list.append(30);

  list.print();
  list.createCycle(2);
  cout << list.isCycle() << endl;
  list.removeCycle();
  list.print();
  cout << list.isCycle() << endl;

  return 0;
}