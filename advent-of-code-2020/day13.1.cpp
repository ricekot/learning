#include <bits/stdc++.h>

using namespace std;

int main(){
    ifstream list("input/day13.txt");
    string line;
    getline(list, line);
    int time = stoi(line), earliest = INT_MAX, early_bus_id;
    while (getline(list, line, ',')){
        if (line[0] == 'x') continue;
        int bus_id = stoi(line);
        int option = time - time%bus_id + bus_id;
        if (earliest > option){
            earliest = option;
            early_bus_id = bus_id;
        }
    }
    cout << early_bus_id * (earliest - time) << '\n';
    return 0;
}
