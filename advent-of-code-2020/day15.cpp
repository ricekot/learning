#include <bits/stdc++.h>

using namespace std;

int n_spoken(int);

int main(){
    cout << "2020th number spoken:\t\t" << n_spoken(2020) << '\n';
    cout << "30000000th number spoken:\t" << n_spoken(30000000) << '\n';
    return 0;
}

int n_spoken(int n){
    vector<int> starting_numbers{5,2,8,16,18,0,1};
    map<int, int> last_spoken;
    int spoken;
    for (int turn = 0; turn < n; ++turn){
        int prev_spoken = spoken;
        if (turn < starting_numbers.size())
            spoken = starting_numbers[turn];
        else if (last_spoken.count(prev_spoken))
            spoken = turn - 1 - last_spoken[prev_spoken];
        else spoken = 0;
        last_spoken[prev_spoken] = turn - 1;
    }
    return spoken;
}
