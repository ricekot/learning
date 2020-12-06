#include <bits/stdc++.h>

using namespace std;

int main(){
    ifstream list("input/day6.txt");
    string line;
    int valid = 0;
    while (getline(list, line)){
        set<string> fields;
        istringstream iss(line);
        set<char> field;
        char question;
        while (iss >> question) {
            field.insert(question);
        }
        valid += field.size();
    }
    cout << valid << '\n';
    return 0;
}
