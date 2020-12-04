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
        int minChars = stoi(line.substr(0, dashPos));
        int maxChars = stoi(line.substr(dashPos+1, line.find(' ')-dashPos));
        char policyChar = line.substr(line.find(' ') + 1, 1)[0];
        string password = line.substr(line.find(':') + 2);
        int countPolicyChar = count(password.begin(), password.end(), policyChar);
        if (countPolicyChar >= minChars && countPolicyChar <= maxChars) {
            ++validPasswords;
        }
    }
    cout << validPasswords << '\n';
    return 0;
}
