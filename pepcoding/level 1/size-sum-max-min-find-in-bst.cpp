// PROBLEM

//https://www.pepcoding.com/resources/online-java-foundation/binary-search-tree/size-sum-max-min-find-in-bst-official/ojquestion

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


int min(Node* node) {
//     Write your code here
  if (node->left == NULL) {
    return node->data;
  }
  min(node->left);
}

int max(Node* node) {
//     Write your code here
  if (node->right == NULL) {
    return node->data;
  }
  max(node->right);
}

int sum(Node* node) {

//     Write your code here
  if (node == NULL) {
    return 0;
  }
  return node->data + sum(node->left) + sum(node->right);

}


int size(Node* node) {

//     Write your code here
  if (node == NULL) {
    return 0;
  }
  return 1 + size(node->left) + size(node->right);
}


bool find(Node* node, int data) {

//     Write your code here
  if (node == NULL) {
    return false;
  }
  if (node->data == data) {
    return true;
  }
  if (node->data > data) {
    return find(node->left, data);
  }
  if (node->data < data) {
    return find(node->right, data);
  }
}


int main() {
  int n;
  cin >> n;
  vector<int> arr(n, 0);
  for (int i = 0; i < n; i++) {
    string x;
    cin >> x;
    if (x == "n") {
      arr[i] = -1;

    }
    else {
      arr[i] = stoi(x);
    }
  }
  int data;
  cin >> data;
  Node* root = construct(arr);
  cout << size(root) << "\n" << sum (root) << "\n" << max(root) << "\n" << min(root) <<  "\n";
  if (find(root, data)) {
    cout << "true" << endl;
  }
  else {
    cout << "false" << endl;
  }
}

/*
Sample Input:
19
50 25 12 n n 37 30 n n n 75 62 n 70 n n 87 n n
70

Sample Output:
9
448
87
12
true
*/