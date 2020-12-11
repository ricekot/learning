#include <bits/stdc++.h>

using namespace std;

int main(){
    ifstream list("input/day10.txt");
    string line;
    vector<int> numbers;
    while (getline(list, line)){
        numbers.push_back(stoi(line));
    }
    numbers.push_back(0);
    numbers.push_back(*max_element(numbers.begin(), numbers.end()) + 3);
    sort(numbers.begin(), numbers.end());
    int diff_1 = 0, diff_3 = 0;
    for(int i = 0; i < numbers.size() - 1; ++i){
        int difference = numbers[i+1] - numbers[i];
        if (difference == 1) ++diff_1;
        else if (difference == 3) ++diff_3;
        else cout << "difference = " << difference << '\n';
    }
    cout << "result = " << diff_1 * diff_3 << '\n';
    return 0;
}
