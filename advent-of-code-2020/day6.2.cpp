#include <bits/stdc++.h>

using namespace std;

int main(){
    ifstream list("input/day6.txt");
    string line;
    int valid = 0;
    while (getline(list, line)){
        vector<int> letters(26, 0);
        istringstream iss(line);
        char question;
        while (iss >> question) {
            letters[question - 'a']++;
        }
        int totalPeople = count(line.begin(), line.end(), ' ') + 1;
        for (int letterCount: letters) {
            if (letterCount == totalPeople)
                ++valid;
        }
    }
    cout << valid << '\n';
    return 0;
}
