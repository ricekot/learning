#include <bits/stdc++.h>

using namespace std;

vector<string> seats;
vector<string> new_state;

void replace(int, int);
void replace_all();
int visibly_occupied(int, int);

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
    int occupied = visibly_occupied(row, col);
    if (seats[row][col] == 'L' && occupied == 0) new_state[row][col] = '#';
    else if (seats[row][col] == '#' && occupied >= 5) new_state[row][col] = 'L';
}

int visibly_occupied(const int row, const int col){
    int occupied = 0;
    // north
    for (int i = row - 1; i >= 0; --i){
        if (seats[i][col] == '#'){
            ++occupied;
            break;
        }
        else if (seats[i][col] == 'L') break;
    }

    // south
    for (int i = row + 1; i < seats.size(); ++i){
        if (seats[i][col] == '#'){
            ++occupied;
            break;
        }
        else if (seats[i][col] == 'L') break;
    }

    // west
    for (int i = col - 1; i >= 0; --i){
        if (seats[row][i] == '#'){
            ++occupied;
            break;
        }
        else if (seats[row][i] == 'L') break;
    }

    // east
    for (int i = col + 1; i < seats[0].length(); ++i){
        if (seats[row][i] == '#'){
            ++occupied;
            break;
        }
        else if (seats[row][i] == 'L') break;
    }

    // north-west
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j){
        if (seats[i][j] == '#'){
            ++occupied;
            break;
        }
        else if (seats[i][j] == 'L') break;
    }

    // south-east
    for (int i = row + 1, j = col + 1; i < seats.size() && j < seats[0].length(); ++i, ++j){
        if (seats[i][j] == '#'){
            ++occupied;
            break;
        }
        else if (seats[i][j] == 'L') break;
    }

    // north-east
    for (int i = row - 1, j = col + 1; i >= 0 && j < seats[0].length(); --i, ++j){
        if (seats[i][j] == '#'){
            ++occupied;
            break;
        }
        else if (seats[i][j] == 'L') break;
    }

    // south-west
    for (int i = row + 1, j = col - 1; i < seats.size() && j >= 0; ++i, --j){
        if (seats[i][j] == '#'){
            ++occupied;
            break;
        }
        else if (seats[i][j] == 'L') break;
    }

    return occupied;
}
