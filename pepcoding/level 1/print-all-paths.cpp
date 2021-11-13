// PROBLEM

//https://www.pepcoding.com/resources/online-java-foundation/graphs/print-all-paths-official/ojquestion

#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

void printAllPaths(vector<int> edges[], int src, int des, int visited[], string path) {
  if (visited[src] == 1) return;
  if (src == des) {
    cout << path << endl;
    return;
  }

  visited[src] = 1;
  for ( int i = 0; i < edges[src].size(); i++) {
    printAllPaths(edges, edges[src][i], des, visited, path + to_string(edges[src][i]));
  }
  visited[src] = 0;

}

int main() {

  int non, noe;
  cin >> non;
  cin >> noe;
  vector<int> edges[non];
  int src, des, weg;
  for ( int i = 0; i < noe; i++) {
    cin >> src >> des >> weg;
    edges[src].push_back(des);
    edges[des].push_back(src);
  }
  int visited[non];
  for (int i = 0; i < non; i++) {
    visited[i] = 0;
  }
  cin >> src;
  cin >> des;
  string path = "" + to_string(src);
  printAllPaths(edges, src, des, visited, path);

  return 0;
}

/*
Sample Input: 
7
8
0 1 10
1 2 10
2 3 10
0 3 10
3 4 10
4 5 10
5 6 10
4 6 10
0
6

Sample Output: 
0123456
012346
03456
0346
*/