#include <bits/stdc++.h>

using namespace std;

int main(){
    ifstream list("input/day5.txt");
    string line;
    int maxID = 0;
    while (getline(list, line)){
        int rowLower = 0, rowUpper = 127, seatLower = 0, seatUpper = 7;
        for (char c: line){
            switch (c) {
                case 'F':
                    rowUpper = floor((rowUpper + rowLower) / 2.0);
                    break;
                case 'B':
                    rowLower = ceil((rowUpper + rowLower) / 2.0);
                    break;
                case 'L':
                    seatUpper = floor((seatUpper + seatLower) / 2.0);
                    break;
                case 'R':
                    seatLower = ceil((seatUpper + seatLower) / 2.0);
                    break;
            }
        }
        int id = rowLower * 8 + seatLower;
        if (id > maxID) maxID = id;
    }
    cout << maxID << '\n';
    return 0;
}
