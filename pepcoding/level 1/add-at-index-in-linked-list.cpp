// PROBLEM

//https://pepcoding.com/resources/online-java-foundation/linked-lists/add-at-index-in-linked-list-official/ojquestion

#include <iostream>
using namespace std;
class node {
public:
  int val;
  node* next;

};
class LinkedList {
public:
  node* head = nullptr;
  node* tail = nullptr;
  int size_ = 0;

  void insert_at_tail(int val) {
    if (head == NULL) {
      node* newnode = new node;
      newnode->val = val;
      newnode->next = NULL;
      head = newnode;

    }
    else {
      node* newnode = new node;
      newnode->val = val;
      newnode->next = NULL;
      node* temp = head;
      while (temp->next != NULL) {
        temp = temp->next;
      }
      temp->next = newnode;
    }
    size_++;

  }

  void print () {
    node* temp = head;
    if (head == NULL) {
      cout << "0" << endl;
      return;
    }
    while (temp != NULL) {
      cout << temp->val << " ";
      temp = temp->next;
    }
    cout << endl;
  }
  void deletion_at_head() {
    if (head == NULL) return;
    node* temp = head;
    head = head->next;
    delete temp;
    size_--;
  }

  int size() {
    int cnt = 0;
    node* temp = head;
    while (temp != NULL) {
      temp = temp->next;
      cnt++;
    }
    return cnt;
  }

  void getFirst() {
    cout << head->val << endl;
  }

  void getLast() {
    node* temp = head;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    cout << temp->val << endl;
  }

  node* getAt(int p) {
    int cnt = 0;
    node* temp = head;
    while (cnt < p) {
      cnt++;
      temp = temp->next;
    }
    cout << temp->val << endl;
    return temp;
  }

  void addFirst(int val) {
    node* newnode = new node;
    newnode->val = val;
    newnode->next = NULL;
    if (head == NULL) {
      head = tail = newnode;
    }
    else {
      newnode ->next = head;
      head = newnode;
    }
    size_++;

  }

  void addAt(int pos, int data) {
    //write your code here
    if (head == NULL || pos == 0) {
      addFirst(data);
      return;
    }
    if (pos == size_) {
      insert_at_tail(data);
      return;
    }
    int i = 0;
    node* curr;
    node* prev;
    for (curr = head, prev = head; curr != NULL; prev = curr, curr = curr->next, i++) {
      if ( i == pos) {
        node* newnode = new node;
        newnode->val = data;
        newnode->next = curr;
        prev->next = newnode;
        size_++;
      }

    }
  }

};
int main() {
  LinkedList l1;
  string s;
  cin >> s;
  while (s != "quit") {
    if (s == "addLast") {
      int data;
      cin >> data;
      l1.insert_at_tail(data);
    }
    else if (s == "addFirst") {
      int data;
      cin >> data;
      l1.addFirst(data);
    }
    else if (s == "getFirst") {
      if (l1.head != NULL) {
        l1.getFirst();
      } else {
        cout << "List is empty" << endl;
      }
    }
    else if (s == "getLast") {
      if (l1.head != NULL) {
        l1.getLast();
      }
      else
      {
        cout << "List is empty";
      }

    }
    else if (s == "removeFirst") {
      if (l1.head != NULL) {
        l1.deletion_at_head();
      }
      else {
        cout << "List is empty" << endl;
      }
    }
    else if (s == "addAt") {
      int val, i;
      cin >> i >> val;
      if (i > l1.size()) {
        cout << "Invalid arguments" << endl;
      }
      else {
        l1.addAt(i, val);
      }
    }
    else if (s == "getAt") {
      if (l1.head != NULL) {
        int i;
        cin >> i;
        if (i >= l1.size()) {
          cout << "Invalid arguments" << endl;
        }
        else {
          l1.getAt(i);
        }
      }
      else
      {
        cout << "List is empty";
      }
    }
    else if (s == "display") {
      if (l1.head != NULL) {
        l1.print();
      }
      else {
        cout << endl;
      }
    }
    else if (s == "size") {
      if (l1.head != NULL) {
        cout << l1.size() << endl;
      }
    }
    cin >> s;
  }
}

/*
Sample Input: 
addFirst 10
getFirst
addAt 0 20
getFirst
getLast
display
size
addAt 2 40
getLast
addAt 1 50
addFirst 30
removeFirst
getFirst
removeFirst
removeFirst
addAt 2 60
display
size
removeFirst
removeFirst
getFirst
quit

Sample Output: 
10
20
10
20 10 
2
40
20
10 40 60 
3
60

*/