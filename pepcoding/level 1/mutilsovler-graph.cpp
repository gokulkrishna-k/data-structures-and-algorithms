// PROBLEM

//https://www.pepcoding.com/resources/online-java-foundation/graphs/mutilsovler-graph-official/ojquestion


#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

struct result {
  string path;
  int cost;
};
vector<result> res;
struct edge {
  vector<int> nodes;
  vector<int> weights;
};


void multiSolver(struct edge edges[], int src, int des, int visited[], string path, int cost) {
  if (visited[src] == 1) return;
  if (src == des) {
    result* temp ;
    temp = new result;
    temp->path = path;
    temp->cost = cost;
    res.push_back(*temp);
    return;
  }

  visited[src] = 1;
  for ( int i = 0; i < edges[src].nodes.size(); i++) {
    multiSolver(edges, edges[src].nodes[i], des, visited, path + to_string(edges[src].nodes[i]), cost + edges[src].weights[i] );
  }
  visited[src] = 0;

}

int main() {

  int non, noe;
  cin >> non;
  cin >> noe;
  edge edges[non];
  int src, des, weg;
  for ( int i = 0; i < noe; i++) {
    cin >> src >> des >> weg;
    edges[src].nodes.push_back(des);
    edges[src].weights.push_back(weg);
    edges[des].nodes.push_back(src);
    edges[des].weights.push_back(weg);
  }
  int visited[non];
  for (int i = 0; i < non; i++) {
    visited[i] = 0;
  }
  int cir, k;
  cin >> src;
  cin >> des;
  cin >> cir;
  cin >> k;
  string path = "" + to_string(src);

  multiSolver(edges, src, des, visited, path, 0);



  for (int i = 0; i < res.size() - 1; i++)
    for (int j = 0; j < res.size() - i - 1; j++) {

      if (res[j].cost > res[j + 1].cost) {
        result temp = res[j + 1];
        res[j + 1] = res[j];
        res[j] = temp;
      }
    }

  cout << "Smallest Path = " << res[0].path << "@" << res[0].cost << endl;
  cout << "Largest Path = " << res[res.size() - 1].path << "@" << res[res.size() - 1].cost << endl;

  for (int i = 0; i < res.size() ; i++) {
    if (res[i].cost == cir) {
      cout << "Just Larger Path than " << cir << " = " << res[i + 1].path << "@" << res[i + 1].cost << endl;
      cout << "Just Smaller Path than " << cir << " = " << res[i - 1].path << "@" << res[i - 1 ].cost << endl;
      break;
    }
    if (res[i].cost > cir) {
      cout << "Just Larger Path than " << cir << " = " << res[i].path << "@" << res[i].cost << endl;
      cout << "Just Smaller Path than " << cir << " = " << res[i - 1].path << "@" << res[i - 1 ].cost << endl;
      break;
    }
  }

  if (res.size() >= k)
    cout << k << "th largest path = " << res[res.size() - k].path << "@" << res[res.size() - k].cost << endl;
  return 0;
}

/*
Sample Input: 
7
9
0 1 10
1 2 10
2 3 10
0 3 40
3 4 2
4 5 3
5 6 3
4 6 8
2 5 5
0
6
30
4

Sample Output: 
Smallest Path = 01256@28
Largest Path = 032546@66
Just Larger Path than 30 = 012546@36
Just Smaller Path than 30 = 01256@28
4th largest path = 03456@48
*/