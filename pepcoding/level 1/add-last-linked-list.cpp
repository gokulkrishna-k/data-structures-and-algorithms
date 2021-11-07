// PROBLEM

//https://pepcoding.com/resources/online-java-foundation/linked-lists/add-last-linked-list-official/ojquestion

#include <iostream>

using namespace std;

class node{
public :
  int data;
  node* next;
};

class linked_list{
public:
  node* head, *tail;
  int size = 0;

public:
  linked_list(){
    head = NULL;
    tail = NULL;
  }

  void addLast(int n){
    // Write your code here
    node* temp = new node();
    temp->data = n;
    temp->next = NULL;
    if (head == NULL) {
      head = tail = temp;
      size++;
      return;
    }
    tail->next = temp;
    tail = temp;
    size++;
  }
  void display() {
    for (node* tmp = head; tmp != NULL; tmp = tmp->next) {
      cout << tmp->data << " ";
    }

  }


  void testList() {
    for (node* temp = head; temp != NULL; temp = temp->next) {
      cout << temp->data << endl;
    }
    cout << size << endl;

    if (size > 0) {
      cout << tail->data << endl;
    }
  }
};


int main() {


  string str;
  linked_list l;
  while (true) {
    getline(cin, str);
    if (str[0] == 'q') {
      break;
    }
    if (str[0] == 'a') {
      string ss = str.substr(8, 2);
      int n = stoi(ss);
      l.addLast( n);

    }

  }

  l.testList();
  return 0;

}

/*
Sample Input: 
addLast 10
addLast 20
addLast 30
addLast 40
addLast 50
quit
Sample Output: 
10
20
30
40
50
5
50

*/