#include <bits/stdc++.h>

using namespace std;

char turn(char, int);
void turn(pair<pair<char,int>,pair<char,int>> &, int);
void update(pair<char, int> &, char, int);

int main(){
    ifstream list("input/day12.txt");
    string line;
    /**
     * waypoint
     *  ├── waypoint.first -> North / South direction and value
     *  │   ├── waypoint.first.first -> 'N' or 'S'
     *  │   └── waypoint.first.second -> value
     *  └── waypoint.second -> East / West direction and value
     *      ├── waypoint.second.first -> 'E' or 'W'
     *      └── waypoint.second.second -> value
     */
    pair<pair<char, int>, pair<char, int>> waypoint(make_pair('N', 1), make_pair('E', 10));
    /* the ship structure is identical to waypoint */
    pair<pair<char, int>, pair<char, int>> ship(make_pair('N', 0), make_pair('E', 0));
    while (getline(list, line)){
        istringstream iss(line);
        char direction; string value_str;
        iss >> direction >> value_str;
        int value = stoi(value_str);
        switch(direction){
            case 'N': case 'S': update(waypoint.first, direction, value); break;
            case 'E': case 'W': update(waypoint.second, direction, value); break;
            case 'L': turn(waypoint, -value); break;
            case 'R': turn(waypoint, value); break;
            case 'F':
                update(ship.first, waypoint.first.first, waypoint.first.second * value);
                update(ship.second, waypoint.second.first, waypoint.second.second * value);
                break;
        }
        /* print each step
        cout << line << ' ' << waypoint.first.first << waypoint.first.second <<  ' '
             << waypoint.second.first << waypoint.second.second << ' ' << ship.first.first
             << ship.first.second << ' ' << ship.second.first << ship.second.second << ' ' << '\n';
        */
    }
    cout << abs(ship.first.second) + abs(ship.second.second) << '\n';
    return 0;
}

/* updates a direction - value pair */
void update(pair<char, int> &existing, char update_dir, int update_val){
    if (existing.first == update_dir) existing.second += update_val;
    else if (existing.second < update_val){
        switch(existing.first){
            case 'N': existing.first = 'S'; break;
            case 'S': existing.first = 'N'; break;
            case 'E': existing.first = 'W'; break;
            case 'W': existing.first = 'E'; break;
        }
        existing.second = update_val - existing.second;
    } else existing.second -= update_val;
}

/* overloaded function for convenience */
void turn(pair<pair<char,int>,pair<char,int>> &waypoint, int angle){
    waypoint.first.first = turn(waypoint.first.first, angle);
    waypoint.second.first = turn(waypoint.second.first, angle);
    if (waypoint.first.first == 'E' || waypoint.first.first == 'W') {
        waypoint.first.swap(waypoint.second);
    }
}

/** 
 * returns the direction obtained by turning the given direction F by the given angle
 *      or -1 if something isn't right
 * angle should be a multiple of 90 deg
 */
char turn(char F, int angle){
    /**
     * find new direction based on ASCII offset:
     * East:   ABC D EFG
     * North:  HIJ K LMN
     * South:  OPQ R STU
     * West:   VWX Y Z[\
     * e.g.: 
     * N -270 -> K -3 -> H -> E
     */
    switch(F){
        case 'E': F = 'D'; break;
        case 'N': F = 'K'; break;
        case 'S': F = 'R'; break;
        case 'W': F = 'Y'; break;
    }
    /* reduce angle to a value in {-3, -2, -1, 0, 1, 2, 3} */
    angle = (angle % 360) / 90;
    F += angle;
    switch (F){
        case 'A': case 'E': case 'I': case 'M':           case 'R':           case 'X': case '\\':  return 'S';
        case 'B': case 'F': case 'J': case 'N': case 'O': case 'S':           case 'Y':             return 'W';
        case 'C': case 'G': case 'K':           case 'P': case 'T': case 'V': case 'Z':             return 'N';
        case 'D': case 'H': case 'L':           case 'Q': case 'U': case 'W': case '[':             return 'E';
        default: return -1;
    }
}
