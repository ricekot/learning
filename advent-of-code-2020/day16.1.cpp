#include <bits/stdc++.h>

using namespace std;

int main(){
    ifstream list("input/day16.txt");
    string line;
    vector<bool> valid(1000, false);
    int result = 0;
    while (getline(list, line)){
        if (line.find("or") != string::npos){
            int l1 = stoi(line.substr(line.find(": ") + 2));
            int u1 = stoi(line.substr(line.find("-") + 1));
            int l2 = stoi(line.substr(line.find("or ") + 3));
            int u2 = stoi(line.substr(line.find('-', line.find("or")) + 1));
            for(int i = l1; i <= u1; ++i) valid[i] = true;
            for(int i = l2; i <= u2; ++i) valid[i] = true;
        } else if (line == "your ticket:") {
            // ignore next line
            getline(list, line);
        } else if (line == "nearby tickets:") continue;
        else {
            string num;
            istringstream iss(line);
            while(getline(iss, num, ',')){
                if (!valid[stoi(num)]) {
                    result += stoi(num);
                }
            }
        }
    }
    cout << result << '\n';
    return 0;
}
