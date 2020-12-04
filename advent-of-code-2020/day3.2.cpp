#include <bits/stdc++.h>

using namespace std;

int step(int, int);

int main(){
    cout << step(1, 1) * step(3, 1) * step(5, 1) * step(7, 1) * step(1, 2) << '\n';
    return 0;
}

int step(int right, int down){
    ifstream list("input/day3.txt");
    string line;
    int trees = 0, col = right;
    getline(list, line); // ignore first row
    for (int i = 1; getline(list, line); ++i) {
        if (i % down != 0) continue;
        if (line[col] == '#') ++trees;
        col = (col + right) % (line.length() - 1);
    }
    return trees;
}
