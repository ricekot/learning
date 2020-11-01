#include <iostream>
#include <vector>
#include <string>
#include <cmath>

#define CORNER 50

/*
With CORNER 27500, points of intersection of the two wires (obtained from day3.cpp)
(13223, 13650)
(13223, 13982)
(13242, 12872)
(13256, 12872)
(13406, 12570)
(13406, 12744)
(13406, 12757)

*/

using namespace std;

int count_of_checker = 0;

void checker(int x, int y, int steps_to_inter[], int abspos[]){
    int xy[7][2] = {{27, 20}, {27, 25}};
    for (int j = 0; j < 7; ++j){
        if (x == xy[j][0] && y == xy[j][1] && steps_to_inter[j] == 0){
            steps_to_inter[j] = abspos[0] + abspos[1];
            ++count_of_checker;
            break;
        }
    }
}

vector<int> movedir(vector<vector<int>> &coord, vector<int> pos, int abspos[], char direction, int step, int steps_to_inter[]){
    int x = pos[0], y = pos[1];
    if (direction == 'U'){
        for (x = pos[0] + 1; x <= pos[0] + step; ++x){
            ++abspos[0];
            coord[x][y] = 1;
            checker(x, y, steps_to_inter, abspos);
        }
        pos[0] += step;
    }
    else if (direction == 'D'){
        for (x = pos[0] - 1; x >= pos[0] - step; --x){
            ++abspos[0];
            coord[x][y] = 1;
            checker(x, y, steps_to_inter, abspos);
        }
        pos[0] -= step;
    }
    else if (direction == 'L'){
        for (y = pos[1] - 1; y >= pos[1] - step; --y){
            ++abspos[1];
            coord[x][y] = 1; 
            checker(x, y, steps_to_inter, abspos);
        }
        pos[1] -= step;
    }
    else if (direction == 'R'){
        for (y = pos[1] + 1; y <= pos[1] + step; ++y){
            ++abspos[1];
            coord[x][y] = 1;
            checker(x, y, steps_to_inter, abspos);
        }
        pos[1] += step;
    }
    return pos;
}


vector<vector<int>> plot(vector<string> instructions, int steps_to_inter[]){
    vector<vector<int>> coord(CORNER, vector<int>(CORNER, 0));
    vector<int> pos(2, CORNER/2);
    int abspos[2] = {0};
    for (int i = 0; i < instructions.size(); ++i){
        string single = instructions[i];
        char direction = single[0];
        single.erase(0,1);
        int step = stoi(single);
        pos = movedir(coord, pos, abspos, direction, step, steps_to_inter);
    }
    return coord;
}

int main(){
    vector<string> instructions1{"U5", "L5", "D5"};
    vector<string> instructions2{"R2", "U2", "L8"};
    int steps_to_inter1[7] = {0}, steps_to_inter2[7] = {0};
    vector<vector<int>> coord1, coord2;
    coord1 = plot(instructions1, steps_to_inter1);
    coord2 = plot(instructions2, steps_to_inter2);
    for (int i = 0; i < CORNER; ++i){
        for (int j = 0; j < CORNER; ++j){
            if (coord1[i][j] == 1 && coord2[i][j] == 1){
                cout << "{" << i << ", " << j << "}, ";
            }
        }
    }
    cout << '\n';
    int result = 999999;
    for (int i = 0; i < 7; ++i){
        cout << i << ": " << steps_to_inter1[i] + steps_to_inter2[i] << '\n';
        if (result > steps_to_inter1[i] + steps_to_inter2[i])
            result = steps_to_inter1[i] + steps_to_inter2[i];
    }
    cout << result << '\n' << count_of_checker << '\n';
    return 0;
}