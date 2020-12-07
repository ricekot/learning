#include <bits/stdc++.h>

using namespace std;

int total_bags_in(string);

map<string, vector<pair<int, string>>> bags_in;

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
            bags_in[parent].push_back(make_pair(stoi(child_quantity), child));
        }
    }
    cout << total_bags_in("shiny gold") << '\n';
    return 0;
}

int total_bags_in(string bag){
    int total_bags = 0;
    for (pair<int, string> child_bag : bags_in[bag]){
        total_bags += child_bag.first + child_bag.first * total_bags_in(child_bag.second);
    }
    return total_bags;
}
