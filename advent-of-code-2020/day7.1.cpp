#include <bits/stdc++.h>

using namespace std;

void find_parents(string, set<string>&);

map<string, vector<string>> parents_of;

int main(){
    ifstream list("input/day7.txt");
    string line;
    while (getline(list, line)){
        istringstream iss(line);
        string parent_adjective, parent_colour;
        iss >> parent_adjective >> parent_colour;
        string parent = parent_adjective + ' ' + parent_colour;
        string child_quantity, child_adjective, child_colour;
        while (iss >> child_quantity >> child_adjective >> child_colour){
            string child = child_adjective + ' ' + child_colour;
            parents_of[child].push_back(parent);
        }
    }
    set<string> parents;
    find_parents("shiny gold", parents);
    cout << parents.size() << '\n';
    return 0;
}

void find_parents(string child, set<string> &parents){
    if (parents_of.count(child) == 0) return;
    for (string parent: parents_of[child]){
        find_parents(parent, parents);
        parents.insert(parent);
    }
}
