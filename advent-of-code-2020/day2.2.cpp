#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ifstream list("input/day2.txt");
    string line;
    int validPasswords = 0;
    while (getline(list, line)){
        int dashPos = line.find('-');
        int pos_1 = stoi(line.substr(0, dashPos)) - 1;
        int pos_2 = stoi(line.substr(dashPos+1, line.find(' ')-dashPos)) - 1;
        char policyChar = line.substr(line.find(' ') + 1, 1)[0];
        string password = line.substr(line.find(':') + 2);
        if ((password[pos_1] == policyChar || password[pos_2] == policyChar) && password[pos_1] != password[pos_2])
            ++validPasswords;
    }
    cout << validPasswords << '\n';
    return 0;
}
