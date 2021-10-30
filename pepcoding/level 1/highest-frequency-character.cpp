/*
Problem : 

https://www.pepcoding.com/resources/online-java-foundation/hashmap-and-heap/hfc-official/ojquestion

*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    string str;
    cin >> str;

    // write your code here
    unordered_map<char, int> umap;
    char max;
    int maxVal = 0;
    for(int i = 0; i < str.length(); i++){
        umap[str[i]] += 1;
        if(umap[str[i]] > maxVal){
            maxVal = umap[str[i]];
            max = str[i];
        }
    }
    cout << max;
}

/*
Sample Input: 
zmszeqxllzvheqwrofgcuntypejcxovtaqbnqyqlmrwitc

Sample Ouput:
q
*/