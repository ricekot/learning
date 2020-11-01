#include <iostream>
#include <vector>

using namespace std;

bool is_valid(int);

int main(){
    int count = 0;
    for (int i = 240298; i <= 784956; ++i){
        if(is_valid(i)) ++count;
    }
    cout << count << '\n';
    return 0;
}

bool adjacent(int);
bool increase(int);

bool is_valid(int n){
    if (adjacent(n) && increase(n)) return true;
    return false;
}

bool adjacent(int n){
    int counter[6] = {0}, counter_index = 0;
    int current = n % 10;
    while (n != 0){
        if (current == n % 10){
            ++counter[counter_index];
            n /= 10;
        }
        else {
            current = n % 10;
            ++counter_index;
        }
    }
    for (int i = 0; i < 6; ++i){
        if (counter[i] == 2) return true;
    }
    return false;
}

bool increase(int n){
    while (n != 0){
        if (n % 10 < (n/10) % 10)
            return false;
        n /= 10;
    }
    return true;
}

