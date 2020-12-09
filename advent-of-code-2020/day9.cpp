#include <bits/stdc++.h>

using namespace std;

int main(){
    ifstream list("input/day9.txt");
    string line;
    vector<long long> numbers;
    while (getline(list, line)){
        numbers.push_back(stoll(line));
    }
    
    int invalid_number;

    for (int i = 25; i < numbers.size(); ++i){
        bool valid = false;
        for (int j = i - 25; j < i; ++j){
            vector<long long>::iterator it;
            it = find(numbers.begin() + j + 1, numbers.begin() + i, numbers[i] - numbers[j]);
            if (it != numbers.begin() + i) {
                valid = true;
                break;
            }
        }
        if (!valid){
            invalid_number = numbers[i];
            cout << "First Invalid Number:\t" << invalid_number << '\n';
            break;
        }
    }

    for (int i = 0; i < numbers.size(); ++i){
        int sum = 0;
        for (int j = i; sum < invalid_number; ++j){
            sum += numbers[j];
            if (sum == invalid_number) {
                vector<long long>::iterator b = numbers.begin();
                long long enc_weak = *min_element(b + i, b + j) + *max_element(b + i, b + j);
                cout << "Encryption Weakness:\t" << enc_weak << '\n';
                return 0;
            }
        }
    }
    return 0;
}
