// PROBLEM

//https://pepcoding.com/resources/online-java-foundation/linked-lists/add-first-in-linked-list-official/ojquestion

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
    node* newnode = new node;
    newnode->val = val;
    newnode->next = NULL;
    if (head == NULL) {
      head = tail =  newnode;

    }
    else {
      tail->next = newnode;
      tail = newnode;
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
    //write your code here
    if (head == NULL) {
      return;
    }
    cout << head->val << endl;
  }

  void getLast() {
    //write your code here
    if (head == NULL) {
      return;
    }
    cout << tail->val << endl;
  }

  node* getAt(int p) {
    //write your code here
    if (head == NULL) {
      return nullptr;
    }
    int i = 0;
    node* curr;
    for (curr = head; curr != NULL; curr = curr->next, i++) {
      if (i != p) continue;
      cout << curr->val << endl;
    }
    return curr;

  }

  void addFirst(int data) {
    node* newnode = new node;
    newnode->val = data;
    newnode->next = nullptr;

    if (head == NULL) {
      head = tail = newnode;
    }
    else {
      newnode->next = head;
      head = newnode;
    }
    size_++;
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
addFirst 20
getFirst
getLast
display
size
addLast 40
getLast
addLast 50
addFirst 30
removeFirst
getFirst
removeFirst
removeFirst
getAt 3
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
Invalid arguments
40 50 
2
List is empty
*/