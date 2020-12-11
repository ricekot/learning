#include <bits/stdc++.h>

using namespace std;

vector<string> seats;
vector<string> new_state;

void replace(int, int);
void replace_all();

int main(){
    ifstream list("input/day11.txt");
    string line;
    while (getline(list, line)){
        seats.push_back(line);
    }
    new_state = seats;
    do {
        seats = new_state;
        replace_all();
    } while(new_state != seats);
    int occupied = 0;
    for (string row: seats){
        occupied += count(row.begin(), row.end(), '#');
    }
    cout << occupied << '\n';
}

void replace_all(){
    for (int i = 0; i < seats.size(); ++i){
        for (int j = 0; j < seats[0].length(); ++j){
            replace(i, j);
        }
    }
}

void replace(int row, int col){
    int rl = row == 0 ? row : row - 1;
    int ru = row == seats.size() - 1 ? row : row + 1;
    int cl = col == 0 ? col : col - 1;
    int cu = col == seats[0].length() - 1 ? col : col + 1;
    int occupied = 0;
    for (int i = rl; i <= ru; ++i){
        for (int j = cl; j <= cu; ++j){
            if (i == row && j == col) continue;
            if (seats[i][j] == '#') ++occupied;
        }
    }

    if (seats[row][col] == 'L' && occupied == 0) new_state[row][col] = '#';
    else if (seats[row][col] == '#' && occupied >= 4) new_state[row][col] = 'L';
}


