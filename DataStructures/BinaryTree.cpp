#include "../common.h"

struct Node {
  int data;
  struct Node* left;
  struct Node* right;

  Node(int data) {
    this->data = data;
    this->left = NULL;
    this->right = NULL;
  }
};

class Print {
public:
  void preorder(struct Node* root) {
    if (root == NULL) return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
  }

  void inorder(struct Node* root) {
    if (root == NULL) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
  }

  void postorder(struct Node* root) {
    if (root == NULL) return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
  }

  void levels(struct Node* root) {
    if (root == NULL) return;

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
      Node* node = q.front();
      q.pop();

      if (node != NULL) {
        cout << node->data << " ";
        
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
      } else if (!q.empty()) {
        q.push(NULL);
      }
    }
  }

};

class Tree {
private:
  int search(int inorder[], int start, int end, int curr) {
    for (int i=start; i<=end; i++) {
      if (inorder[i] ==  curr) return i;
    }

    return -1;
  }

public:
  Node* from_preorder(int preorder[], int inorder[], int start, int end) {
    static int idx = 0;
    if (start > end) return NULL;

    int curr = preorder[idx];
    idx++;
    Node* node = new Node(curr);
    if (start == end) return node;

    int pos = search(inorder, start, end, curr);
    node->left = from_preorder(preorder, inorder, start, pos-1);
    node->right = from_preorder(preorder, inorder, pos+1, end);

    return node;
  }

  Node* from_postorder(int postorder[], int inorder[], int start, int end) {
    static int idx = 4;
    if (start > end) return NULL;

    int curr = postorder[idx];
    idx--;
    Node* node = new Node(curr);
    if (start == end) return node;

    int pos = search(inorder, start, end, curr);
    node->right = from_postorder(postorder, inorder, pos+1, end);
    node->left = from_postorder(postorder, inorder, start, pos-1);

    return node;
  }


};

class Questions {
public:
  int sum_at_k_level(Node* root, int k) {
    if (root == NULL) return -1;

    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    int level = 0;
    int sum = 0;

    while (!q.empty()) {
      Node* node = q.front();
      q.pop();

      if (node != NULL) {
        if (level == k) sum += node->data;
        
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
      } else if (!q.empty()) {
        q.push(NULL);
        level++;
      }
    }

    return sum;
  }
};

int main () {
  Questions q;
  Print p;
  Tree t;

  Node* root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->right->left = new Node(6);
  root->right->right = new Node(7);

  cout << q.sum_at_k_level(root, 2) << lb;

  return 0;
}