// Problem : 

//   https://www.pepcoding.com/resources/online-java-foundation/binary-tree/binary-tree-path-to-leaves-from-root-official/ojquestion

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Node{
  public:
    int data;
    Node *left = nullptr;
    Node *right = nullptr;
    Node(int data) {
      this->data = data;
    }
};

int idx = 0;
Node *constructTree(vector<int> &arr){
  if (idx == arr.size() || arr[idx] == -1){
    idx++;
    return nullptr;
  }
  Node *node = new Node(arr[idx++]);
  node->left = constructTree(arr);
  node->right = constructTree(arr);
  return node;
}

void pathToLeafFromRoot(Node *node, string path, int sum, int lo, int hi){
  if (node == NULL)
    return;
  sum += node->data;
  if (node->left == NULL && node->right == NULL){
    if (sum >= lo && sum <= hi){
      cout << path << node->data << endl;
      return;
    }
  }
  pathToLeafFromRoot(node->left, path + to_string(node->data) + " ", sum, lo, hi);
  pathToLeafFromRoot(node->right, path + to_string(node->data) + " ", sum, lo, hi);
  return;
}

int main(){
  vector<int> arr;
  int n;
  cin >> n;

  for (int i = 0; i < n; i++){
    string inp;
    cin >> inp;
    if (inp != "n"){
      arr.push_back(stoi(inp));
    }
    else{
      arr.push_back(-1);
    }
  }

  int lo;
  cin >> lo;
  int hi;
  cin >> hi;

  Node *root = constructTree(arr);
  pathToLeafFromRoot(root, "", 0, lo, hi);
  return 0;
}

/* 
Sample Input:
23
50 25 12 n n 37 30 n n 40 n n 75 62 60 n n 70 n n 87 n n
150
250

Sample Ouput: 
50 25 37 40
50 75 62 60
50 75 87
*/