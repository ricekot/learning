#include <bits/stdc++.h>

using namespace std;

int main(){
    ifstream list("input/day3.txt");
    string line;
    int trees = 0, col = 3;
    getline(list, line);
    while (getline(list, line)){
        if (line[col] == '#') ++trees;
        col = (col+3)%(line.length()-1);
    }
    cout << trees << '\n';
    return 0;
}
