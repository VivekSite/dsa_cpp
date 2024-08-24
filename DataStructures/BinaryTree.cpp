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

void preorder(struct Node* root) {
  if (root == NULL) return;

  cout << root->data << " ";
  preorder(root->left);
  preorder(root->right);
}

void inorder(struct Node* root) {
  if (root == NULL) return;

  preorder(root->left);
  cout << root->data << " ";
  preorder(root->right);
}

void postorder(struct Node* root) {
  if (root == NULL) return;

  preorder(root->left);
  preorder(root->right);
  cout << root->data << " ";
}

int main () {
  struct Node* root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);

  preorder(root);
  cout << lb;

  inorder(root);
  cout << lb;

  postorder(root);
  cout << lb;

  return 0;
}