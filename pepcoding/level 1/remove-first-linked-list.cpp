// PROBLEM

//https://pepcoding.com/resources/online-java-foundation/linked-lists/remove-first-linked-list-official/ojquestion

#include <iostream>
#include<string>
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
    node* tmp = new node;
    tmp->data = n;
    tmp->next = NULL;

    if (head == NULL){
      head = tmp;
      tail = tmp;
    }
    else{
      tail->next = tmp;
      tail = tail->next;
    }
    size++;


  }
  void display() {
    for (node* tmp = head; tmp != NULL; tmp = tmp->next) {
      cout << tmp->data << " ";
    }
    cout << endl;

  }
  void removeFirst() {
    //write your code here
    if (head != NULL) {
      if (size == 1) {
        head = tail = NULL;
      } else {
        head = head->next;
      }
      size--;
    }
    else {
      cout << "List is empty" << endl;
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
    else if (str[0] == 'a') {
      string ss = str.substr(8, 2);
      int n = stoi(ss);
      l.addLast( n);

    }
    else if (str[0] == 's') {
      cout << l.size << endl;
    }
    else if (str[0] == 'd') {
      l.display();
    }
    else if (str[0] == 'r') {
      l.removeFirst();
    }
  }


  return 0;

}


/*
Sample Input: 
addLast 10
addLast 20
addLast 30
display
removeFirst
size
addLast 40
addLast 50
removeFirst
display
size
removeFirst
removeFirst
removeFirst
removeFirst
quit
Sample Output: 
10 20 30 
2
30 40 50 
3
List is empty
*/