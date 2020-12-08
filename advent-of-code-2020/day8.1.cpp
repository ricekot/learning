#include <bits/stdc++.h>

using namespace std;

int main(){
    ifstream list("input/day8.txt");
    string line;
    vector<pair<string, int>> instructions;
    while (getline(list, line)){
        istringstream iss(line);
        string operation, argument;
        iss >> operation >> argument;
        instructions.push_back(make_pair(operation, stoi(argument)));
    }
    int accumulator = 0, i = 0;
    vector<bool> visited(instructions.size(), false);
    while(i < instructions.size() && !visited[i]){
        visited[i] = true;
        if (instructions[i].first == "acc") {
            accumulator += instructions[i].second;
            i++;
        } else if (instructions[i].first == "jmp"){
            i += instructions[i].second;
        } else if (instructions[i].first == "nop") {
            i++;
        }
    }
    cout << accumulator << '\n';
    return 0;
}
