#include <bits/stdc++.h> 

using namespace std;

class amplifier{
    int phase_setting, pos;
    bool end;
    vector<int> arr;

public:
    amplifier(){
        end = false;
        pos = 0;
        arr = (vector<int>){3,8,1001,8,10,8,105,1,0,0,21,38,63,72,85,110,191,272,353,434,99999,3,9,102,4,9,9,101,2,9,9,102,3,9,9,4,9,99,3,9,1001,9,4,9,102,2,9,9,1001,9,5,9,1002,9,5,9,101,3,9,9,4,9,99,3,9,1001,9,2,9,4,9,99,3,9,1001,9,3,9,102,2,9,9,4,9,99,3,9,101,2,9,9,102,2,9,9,1001,9,2,9,1002,9,4,9,101,2,9,9,4,9,99,3,9,1002,9,2,9,4,9,3,9,102,2,9,9,4,9,3,9,101,2,9,9,4,9,3,9,101,2,9,9,4,9,3,9,101,1,9,9,4,9,3,9,101,2,9,9,4,9,3,9,1002,9,2,9,4,9,3,9,101,2,9,9,4,9,3,9,101,1,9,9,4,9,3,9,1002,9,2,9,4,9,99,3,9,1001,9,1,9,4,9,3,9,102,2,9,9,4,9,3,9,1001,9,2,9,4,9,3,9,102,2,9,9,4,9,3,9,1001,9,2,9,4,9,3,9,101,2,9,9,4,9,3,9,1002,9,2,9,4,9,3,9,1001,9,2,9,4,9,3,9,1001,9,2,9,4,9,3,9,1001,9,1,9,4,9,99,3,9,1001,9,1,9,4,9,3,9,1001,9,1,9,4,9,3,9,1001,9,2,9,4,9,3,9,102,2,9,9,4,9,3,9,1002,9,2,9,4,9,3,9,102,2,9,9,4,9,3,9,1002,9,2,9,4,9,3,9,1002,9,2,9,4,9,3,9,101,2,9,9,4,9,3,9,101,2,9,9,4,9,99,3,9,1001,9,2,9,4,9,3,9,1002,9,2,9,4,9,3,9,101,1,9,9,4,9,3,9,102,2,9,9,4,9,3,9,1001,9,2,9,4,9,3,9,1002,9,2,9,4,9,3,9,102,2,9,9,4,9,3,9,1001,9,2,9,4,9,3,9,1002,9,2,9,4,9,3,9,102,2,9,9,4,9,99,3,9,1002,9,2,9,4,9,3,9,101,1,9,9,4,9,3,9,101,2,9,9,4,9,3,9,101,1,9,9,4,9,3,9,101,2,9,9,4,9,3,9,102,2,9,9,4,9,3,9,101,2,9,9,4,9,3,9,1002,9,2,9,4,9,3,9,1002,9,2,9,4,9,3,9,101,2,9,9,4,9,99};
    }
    int generate_output(int input_signal);
    void set_phase(int input_phase);
    bool is_last_feedback_loop(){ return end; }
};

int parameter(vector<int> &arr, int n, int pos);

int main(){
    int phase[] = {5, 6, 7, 8, 9}, result = -1;
    do{
        amplifier amp[5];
        for (int i = 0; i < 5; ++i){
            amp[i].set_phase(phase[i]);
        }
        int output = amp[0].generate_output(0);
        for (int i = 1; !amp[4].is_last_feedback_loop(); ++i){
            output = amp[i % 5].generate_output(output);
        }
        if (result < output) result = output;
    }while(next_permutation(phase, phase + 5));
    cout << result << '\n';
    return 0;
}

int amplifier::generate_output(int input_signal){
    for (int i = pos; i < arr.size();){ 
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
                arr[arr[i+1]] = input_signal;
                i += 2;
                break;
            }
            case 4:{
                pos = i + 2;
                return parameter(arr, mode[0], i + 1);
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
                end = true;
                return input_signal;
            }
            default:{
                cerr << "Something went wrong.\n";
                return -1;
            }
        }
    }
}

void amplifier::set_phase(int input_phase){
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
                arr[arr[i + 1]] = input_phase;
                pos = i + 2;
                return;
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
            default:{
                cerr << "Something went wrong.\n";
                return;
            }
        }
    }
}

int parameter(vector<int> &arr, int n, int pos){
    if (n == 0) return arr[arr[pos]];
    else if(n == 1) return arr[pos];
}
