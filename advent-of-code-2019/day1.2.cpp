#include <iostream>

using namespace std;

int main(){
    int mass, fuel, result = 0;
    while (cin >> mass){
        fuel = mass/3 - 2;
        while (fuel > 0){
            result += fuel;
            fuel = fuel/3 - 2;
        }
    }
    cout << result << '\n';
}