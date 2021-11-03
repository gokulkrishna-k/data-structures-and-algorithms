//PROBLEM 

//https://www.pepcoding.com/resources/online-java-foundation/binary-search-tree/add-node-to-bst-official/ojquestion

#include<bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node* left;
  Node* right;
  Node(int val) {
    data = val;
    left = nullptr;
    right = nullptr;
  }
};


Node* construct(vector<int>& arr) {
  Node* root = new Node(arr[0]);
  pair<Node*, int> p = {root, 1};

  stack<pair<Node*, int>> st;
  st.push(p);

  int idx = 1;
  while (!st.empty()) {
    if (st.top().second == 1) {
      st.top().second++;
      if (arr[idx] != -1) {
        st.top().first->left = new Node(arr[idx]);
        pair<Node*, int> lp = {st.top().first->left, 1};
        st.push(lp);
      }
      else {
        st.top().first->left = nullptr;
      }
      idx++;
    }
    else if (st.top().second == 2) {
      st.top().second++;
      if (arr[idx] != -1) {
        st.top().first->right = new Node(arr[idx]);
        pair<Node*, int> rp = {st.top().first->right, 1};
        st.push(rp);
      } else {
        st.top().first->right = nullptr;
      }
      idx++;
    }
    else {
      st.pop();
    }

  }
  return root;
}
void display(Node* node) {
  if (node == nullptr) {
    return;
  }

  string str = " <- " + to_string(node->data) + " -> ";

  string left = (node->left == nullptr) ? "." :  "" + to_string(node->left->data);
  string right = (node->right == nullptr) ? "." : "" + to_string(node->right->data);

  str = left + str + right;
  cout << str << endl;

  display(node->left);
  display(node->right);
}




void add(Node* node, int val) {

//     Write your code here
  if (node == NULL) return;
  if (node->data < val) {
    if (node->right == NULL) {
      Node* temp = new Node(val);
      node->right = temp;
      return;
    }
    add(node->right, val);
    return;
  }
  if (node->data > val) {
    if (node->left == NULL) {
      Node* temp = new Node(val);
      node->left = temp;
      return;
    }
    add(node->left, val);
    return;
  }
}


int main() {
  int n;
  cin >> n;
  vector<int> a(n, 0);
  for (int i = 0; i < n; i++) {
    string x;
    cin >> x;
    if (x == "n") {
      a[i] = -1;

    }
    else {
      a[i] = stoi(x);
    }
  }
  int data;
  cin >> data;
  Node* root = construct(a);
  add(root, data);

  display(root);
}

/*  
Sample Input:
23
50 25 12 n n 37 30 n n 40 n n 75 62 60 n n 70 n n 87 n n
61
Sample Output: 
25 <- 50 -> 75
12 <- 25 -> 37
. <- 12 -> .
30 <- 37 -> 40
. <- 30 -> .
. <- 40 -> .
62 <- 75 -> 87
60 <- 62 -> 70
. <- 60 -> 61
. <- 61 -> .
. <- 70 -> .
. <- 87 -> .
*/