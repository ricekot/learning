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
    for (int j = 0; j < instructions.size(); ++j){
        string original = instructions[j].first;
        if (instructions[j].first == "nop") instructions[j].first = "jmp";
        else if (instructions[j].first == "jmp") instructions[j].first = "nop";
        else continue;
        int accumulator = 0, i = 0;
        vector<bool> visited(instructions.size(), false);
        for (i = 0; i < instructions.size() && !visited[i];){
            visited[i] = true;
            if (instructions[i].first == "acc") {
                accumulator += instructions[i].second;
                i++;
            } else if (instructions[i].first == "jmp"){
                i += instructions[i].second;
            } else if (instructions[i].first == "nop") {
                i++;
            }
            if (i >= instructions.size()){
                cout << accumulator << '\n';
                return 0;
            }
        }
        instructions[j].first = original;
    }
    return 0;
}
