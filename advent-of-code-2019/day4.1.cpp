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
    while (n != 0){
        if (n % 10 == (n/10) % 10)
            return true;
        n /= 10;
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

