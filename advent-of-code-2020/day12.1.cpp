#include <bits/stdc++.h>

using namespace std;

char turn(char, int);

int main(){
    ifstream list("input/day12.txt");
    string line;
    int ns = 0, ew = 0;
    char F = 'E';
    while (getline(list, line)){
        istringstream iss(line);
        char direction; string value_str;
        iss >> direction >> value_str;
        int value = stoi(value_str);
        if (direction == 'F') direction = F;
        switch(direction){
            case 'N': ns += value; break;
            case 'S': ns -= value; break;
            case 'E': ew += value; break;
            case 'W': ew -= value; break;
            case 'L': F = turn(F, -value); break;
            case 'R': F = turn(F, value); break;
        }
    }
    cout << abs(ns) + abs(ew) << '\n';
    return 0;
}

char turn(char F, int angle){
    angle = (angle%360)/90;
    switch(F){
        case 'E': F = 'D'; break;
        case 'N': F = 'K'; break;
        case 'S': F = 'R'; break;
        case 'W': F = 'Y'; break;
    }
    F += angle;
    switch (F){
        case 'A': case 'E': case 'I': case 'M':           case 'R':           case 'X': case '\\':  return 'S';
        case 'B': case 'F': case 'J': case 'N': case 'O': case 'S':           case 'Y':             return 'W';
        case 'C': case 'G': case 'K':           case 'P': case 'T': case 'V': case 'Z':             return 'N';
        case 'D': case 'H': case 'L':           case 'Q': case 'U': case 'W': case '[':             return 'E';
        default: return '\0';
    }
}
