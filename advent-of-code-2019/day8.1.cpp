#include <iostream> 

using namespace std;

int main(){
    char image[100][150];       // image[layer][pixel]
    int count_zero = 0, count_one = 0, count_two = 0, least_count_zero = 200, result;
    for (int i = 0; i < 100; ++i){
        count_zero = count_one = count_two = 0;
        for (int j = 0; j < 150; ++j){
            cin >> image[i][j];
            if (image[i][j] == '0') ++count_zero;
            else if (image[i][j] == '1') ++count_one;
            else if (image[i][j] == '2') ++count_two;
        }
        if (least_count_zero > count_zero){
            least_count_zero = count_zero;
            result = count_one * count_two;
        }
    }
    cout << result << '\n';
    return 0;
}