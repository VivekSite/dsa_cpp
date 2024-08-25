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

void preorder_print(struct Node* root) {
  if (root == NULL) return;

  cout << root->data << " ";
  preorder_print(root->left);
  preorder_print(root->right);
}

void inorder_print(struct Node* root) {
  if (root == NULL) return;

  inorder_print(root->left);
  cout << root->data << " ";
  inorder_print(root->right);
}

void postorder_print(struct Node* root) {
  if (root == NULL) return;

  postorder_print(root->left);
  postorder_print(root->right);
  cout << root->data << " ";
}

int search(int inorder[], int start, int end, int curr) {
  for (int i=start; i<=end; i++) {
    if (inorder[i] ==  curr) return i;
  }

  return -1;
}

Node* build_tree_from_preorder(int preorder[], int inorder[], int start, int end) {
  static int idx = 0;
  if (start > end) return NULL;

  int curr = preorder[idx];
  idx++;
  Node* node = new Node(curr);
  if (start == end) return node;

  int pos = search(inorder, start, end, curr);
  node->left = build_tree_from_preorder(preorder, inorder, start, pos-1);
  node->right = build_tree_from_preorder(preorder, inorder, pos+1, end);

  return node;
}

Node* build_tree_from_postorder(int postorder[], int inorder[], int start, int end) {
  static int idx = 4;
  if (start > end) return NULL;

  int curr = postorder[idx];
  idx--;
  Node* node = new Node(curr);
  if (start == end) return node;

  int pos = search(inorder, start, end, curr);
  node->right = build_tree_from_postorder(postorder, inorder, pos+1, end);
  node->left = build_tree_from_postorder(postorder, inorder, start, pos-1);

  return node;
}

int main () {
  int postorder[] = { 4, 2, 5, 3, 1 };
  int preorder[] = { 1, 2, 4, 3, 5 };
  int inorder[] = { 4, 2, 1, 5, 3 };

  Node* root = build_tree_from_postorder(preorder, inorder, 0, 4);
  inorder_print(root);
  cout << lb;

  return 0;
}