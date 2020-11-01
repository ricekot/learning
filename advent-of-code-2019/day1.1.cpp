#include <iostream>

using namespace std;

int main(){
    int mass, fuel_sum = 0;
    while (cin >> mass){
        fuel_sum += mass/3 - 2;
    }
    cout << fuel_sum;
}