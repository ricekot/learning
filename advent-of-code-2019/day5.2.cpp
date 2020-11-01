#include <iostream>
#include <vector>

using namespace std;

vector<int> arr = {3,15,3,16,1002,16,10,16,1,16,15,15,4,15,99,0,0};

int parameter(int n, int pos);

int main(){
    for (int i = 0; i < arr.size();){ 
        int n = arr[i];                        // ABCDE
        int opcode = n % 100; n /= 100;        // DE - two-digit opcode
        int mode[3];
        mode[0] = n % 10; n /= 10;             //  C - mode of 1st parameter
        mode[1] = n % 10; n /= 10;             //  B - mode of 2nd parameter
        mode[2] = n;                           //  A - mode of 3rd parameter
        switch(opcode){
            case 1:{
                arr[arr[i + 3]] = parameter(mode[0], i + 1) + parameter(mode[1], i + 2);
                i += 4;
                break;
            }
            case 2:{
                arr[arr[i + 3]] = parameter(mode[0], i + 1) * parameter(mode[1], i + 2);
                i += 4;
                break;
            }
            case 3:{
                cout << "Give me an input value: ";
                cin >> arr[arr[i + 1]];
                i += 2;
                break;
            }
            case 4:{
                cout << parameter(mode[0], i + 1) << ' ';
                i += 2;   
                break;
            }
            case 5:{
                if (parameter(mode[0], i + 1) != 0) i = parameter(mode[1], i + 2);
                else i += 3;
                break;
            }
            case 6:{
                if (parameter(mode[0], i + 1) == 0) i = parameter(mode[1], i + 2);
                else i += 3;
                break;
            }
            case 7:{
                if (parameter(mode[0], i + 1) < parameter(mode[1], i + 2)) arr[arr[i+3]] = 1;
                else arr[arr[i + 3]] = 0;
                i += 4;
                break;
            }
            case 8:{
                if (parameter(mode[0], i + 1) == parameter(mode[1], i + 2)) arr[arr[i + 3]] = 1;
                else arr[arr[i + 3]] = 0;
                i += 4;
                break;
            }
            case 99:{
                cout << '\n';
                return 0;
            }
            default:{
                cerr << "Something went wrong.\n";
                return -1;
            }
        }
    }
    return 0;
}

int parameter(int n, int pos){
    if (n == 0) return arr[arr[pos]];
    else if(n == 1) return arr[pos];
}
