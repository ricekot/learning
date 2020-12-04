#include <bits/stdc++.h>

using namespace std;

int main(){
    ifstream list("input/day4.txt");
    string line;
    int valid = 0;
    while (getline(list, line)){
        set<string> fields;
        istringstream iss(line);
        string field;
        while (iss >> field) fields.insert(field.substr(0, field.find(':')));
        if (fields.size() == 8 || (fields.size() == 7 && !fields.count("cid"))) ++valid;
    }
    cout << valid << '\n';
    return 0;
}
