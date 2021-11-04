// PROBLEM

//https://www.pepcoding.com/resources/online-java-foundation/binary-tree/diameter-of-binary-tree-official/ojquestion

#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
  int data = 0;
  Node* left = nullptr;
  Node* right = nullptr;
  Node(int data)
  {
    this->data = data;
  }
};

class Pair {
public:
  Node* node = nullptr;
  int state = 0;

  Pair(Node* node, int state) {
    this->node = node;
    this->state = state;
  }
};

int idx = 0;
Node* constructTree(vector<int>& arr)
{

  if (idx == arr.size() || arr[idx] == -1)
  {
    idx++;
    return nullptr;
  }
  Node* node = new Node(arr[idx++]);
  node->left = constructTree(arr);
  node->right = constructTree(arr);
  return node;
}

//Display function
void display(Node* node)
{
  if (node == nullptr)
    return;
  string str = "";
  str += node->left != nullptr ? to_string(node->left->data) : ".";
  str += " <- " + to_string(node->data) + " -> ";
  str += node->right != nullptr ? to_string(node->right->data) : ".";
  cout << str << endl;

  display(node->left);
  display(node->right);
}


//Height function
int height(Node* node)
{
  return node == nullptr ? -1 : max(height(node->left), height(node->right)) + 1; // for no of edges: -1, and in terms of no of nodes return 0;
}

int helper(Node* node) {
  if (node == NULL) return 0;
  int l = 1 + helper(node->left);
  int r = 1 + helper(node->right);
  if (l > r) {
    return l;
  }
  else
    return r;
}

int diameter(Node* node)
{
  // write your code here
  if (node == NULL) return 0;
  return helper(node->left) + helper(node->right);

}

int main() {
  int n;
  cin >> n;

  vector<int> arr(n, 0);
  for (int i = 0; i < n; i++) {
    string tmp;
    cin >> tmp;
    if (tmp == "n") {
      arr[i] = -1;
    } else {
      arr[i] = stoi(tmp);
    }
  }


  Node* root = constructTree(arr);

  int dia = 0;
  dia = diameter(root);
  cout << dia;



}

/*
Sample Input: 
19
50 25 12 n n 37 30 n n n 75 62 n 70 n n 87 n n
Sample Output: 
6
*/