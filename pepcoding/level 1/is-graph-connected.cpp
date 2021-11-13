// PROBLEM

//https://www.pepcoding.com/resources/online-java-foundation/graphs/is-graph-connected-official/ojquestion

#include<bits/stdc++.h>
using namespace std;
class Edge {
public:
  int src;
  int nbr;
  int wt;

  Edge(int src, int nbr, int wt) {
    this->src = src;
    this->nbr = nbr;
    this->wt = wt;
  }
};

void isConnected(vector<Edge> graph[], int curr, int vtces, int visited[]) {
  if (visited[curr] == 1) {
    return;
  }
  if (curr >= vtces ) {
    return;
  }
  visited[curr] = 1;
  for (int i = 0; i < graph[curr].size(); i++) {
    isConnected(graph, graph[curr][i].nbr, vtces, visited);
  }
  return;
}

int main() {
  int vtces;
  cin >> vtces;
  vector<Edge>graph[vtces];

  int edges;
  cin >> edges;
  for (int i = 0; i < edges; i++) {
    int v1 ;
    int v2 ;
    int wt ;
    cin >> v1 >> v2 >> wt;
    graph[v1].push_back( Edge(v1, v2, wt));
    graph[v2].push_back( Edge(v2, v1, wt));
  }

  int visited[vtces];
  for (int i = 0; i < vtces; i++) {
    visited[i] = 0;
  }

  isConnected(graph, 0, vtces, visited);
  bool result = true;
  for (int i = 0; i < vtces; i++) {
    if(visited[i] == 0){
        result = false;
        break;
    }
  }
  if(result) {
      cout << "true";
  }
  else{
      
  cout << "false";
  }
 
}

/*
Sample Input: 
7
5
0 1 10
2 3 10
4 5 10
5 6 10
4 6 10

Sample Output: 
false

*/