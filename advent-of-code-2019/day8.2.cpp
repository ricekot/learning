#include <iostream> 

using namespace std;

int main(){
    char image[100][150];       // image[layer][pixel]
    for (int i = 0; i < 100; ++i){;
        for (int j = 0; j < 150; ++j){
            cin >> image[i][j];
        }
    }
    
    char result[150];
    for (int i = 0; i < 150; ++i){  
        for (int j = 0; j < 100; ++j){
            if (image[j][i] != '2'){
                result[i] = image[j][i];
                break;
            }
        }
    }

    for (int i = 0; i < 150; ++i){
        if (i % 25 == 0) cout << '\n';
        if (result[i] == '0') cout << "⬛ ";
        else cout << "⬜ ";
    }

    cout << '\n';

    return 0;
}