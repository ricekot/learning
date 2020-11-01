#include <bits/stdc++.h> 

using namespace std;

int parameter(vector<int> &arr, int n, int pos);
int output_signal(int phase_setting[]);

int main(){
    int phase[] = {0, 1, 2, 3, 4}, result = -1;
    do{
        int phase_setting[2], output = 0;
        for(int i = 0; i < 5; ++i){
            phase_setting[0] = phase[i];
            phase_setting[1] = output;
            output = output_signal(phase_setting);
        }
        if (result < output) result = output;
    }while(next_permutation(phase, phase + 5));
    cout << result << '\n';
    return 0;
}

int output_signal(int phase_setting[]){
    int phase_index = 0;
    vector<int> arr = {3,8,1001,8,10,8,105,1,0,0,21,38,63,72,85,110,191,272,353,434,99999,3,9,102,4,9,9,101,2,9,9,102,3,9,9,4,9,99,3,9,1001,9,4,9,102,2,9,9,1001,9,5,9,1002,9,5,9,101,3,9,9,4,9,99,3,9,1001,9,2,9,4,9,99,3,9,1001,9,3,9,102,2,9,9,4,9,99,3,9,101,2,9,9,102,2,9,9,1001,9,2,9,1002,9,4,9,101,2,9,9,4,9,99,3,9,1002,9,2,9,4,9,3,9,102,2,9,9,4,9,3,9,101,2,9,9,4,9,3,9,101,2,9,9,4,9,3,9,101,1,9,9,4,9,3,9,101,2,9,9,4,9,3,9,1002,9,2,9,4,9,3,9,101,2,9,9,4,9,3,9,101,1,9,9,4,9,3,9,1002,9,2,9,4,9,99,3,9,1001,9,1,9,4,9,3,9,102,2,9,9,4,9,3,9,1001,9,2,9,4,9,3,9,102,2,9,9,4,9,3,9,1001,9,2,9,4,9,3,9,101,2,9,9,4,9,3,9,1002,9,2,9,4,9,3,9,1001,9,2,9,4,9,3,9,1001,9,2,9,4,9,3,9,1001,9,1,9,4,9,99,3,9,1001,9,1,9,4,9,3,9,1001,9,1,9,4,9,3,9,1001,9,2,9,4,9,3,9,102,2,9,9,4,9,3,9,1002,9,2,9,4,9,3,9,102,2,9,9,4,9,3,9,1002,9,2,9,4,9,3,9,1002,9,2,9,4,9,3,9,101,2,9,9,4,9,3,9,101,2,9,9,4,9,99,3,9,1001,9,2,9,4,9,3,9,1002,9,2,9,4,9,3,9,101,1,9,9,4,9,3,9,102,2,9,9,4,9,3,9,1001,9,2,9,4,9,3,9,1002,9,2,9,4,9,3,9,102,2,9,9,4,9,3,9,1001,9,2,9,4,9,3,9,1002,9,2,9,4,9,3,9,102,2,9,9,4,9,99,3,9,1002,9,2,9,4,9,3,9,101,1,9,9,4,9,3,9,101,2,9,9,4,9,3,9,101,1,9,9,4,9,3,9,101,2,9,9,4,9,3,9,102,2,9,9,4,9,3,9,101,2,9,9,4,9,3,9,1002,9,2,9,4,9,3,9,1002,9,2,9,4,9,3,9,101,2,9,9,4,9,99};
    for (int i = 0; i < arr.size();){ 
        int n = arr[i];                        // ABCDE
        int opcode = n % 100; n /= 100;        // DE - two-digit opcode
        int mode[3];
        mode[0] = n % 10; n /= 10;             //  C - mode of 1st parameter
        mode[1] = n % 10; n /= 10;             //  B - mode of 2nd parameter
        mode[2] = n;                           //  A - mode of 3rd parameter
        switch(opcode){
            case 1:{
                arr[arr[i + 3]] = parameter(arr, mode[0], i + 1) + parameter(arr, mode[1], i + 2);
                i += 4;
                break;
            }
            case 2:{
                arr[arr[i + 3]] = parameter(arr, mode[0], i + 1) * parameter(arr, mode[1], i + 2);
                i += 4;
                break;
            }
            case 3:{
                arr[arr[i+1]] = phase_setting[phase_index++];
                i += 2;
                break;
            }
            case 4:{
                return parameter(arr, mode[0], i + 1);
                i += 2;   
                break;
            }
            case 5:{
                if (parameter(arr, mode[0], i + 1) != 0) i = parameter(arr, mode[1], i + 2);
                else i += 3;
                break;
            }
            case 6:{
                if (parameter(arr, mode[0], i + 1) == 0) i = parameter(arr, mode[1], i + 2);
                else i += 3;
                break;
            }
            case 7:{
                if (parameter(arr, mode[0], i + 1) < parameter(arr, mode[1], i + 2)) arr[arr[i+3]] = 1;
                else arr[arr[i + 3]] = 0;
                i += 4;
                break;
            }
            case 8:{
                if (parameter(arr, mode[0], i + 1) == parameter(arr, mode[1], i + 2)) arr[arr[i + 3]] = 1;
                else arr[arr[i + 3]] = 0;
                i += 4;
                break;
            }
            case 99:{
                return 0;
            }
            default:{
                cerr << "Something went wrong.\n";
                return -1;
            }
        }
    }
}

int parameter(vector<int> &arr, int n, int pos){
    if (n == 0) return arr[arr[pos]];
    else if(n == 1) return arr[pos];
}
