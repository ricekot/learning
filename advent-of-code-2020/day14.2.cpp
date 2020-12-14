#include <bits/stdc++.h>

using namespace std;

map<unsigned long, int> mem;
void decode_and_set(string, int);

int main(){
    ifstream list("input/day14.txt");
    string line, mask;
    while (getline(list, line)){
        if (line.substr(0, 4) == "mask") mask = line.substr(7);
        else {
            string location, equals, value;
            istringstream iss(line);
            iss >> location >> equals >> value;
            int loc = stoi(location.substr(4)), val = stoi(value);
            string address = bitset<36>(loc).to_string();
            for (int i = 0; i < 36; ++i)
                if (mask[i] != '0')
                    address[i] = mask[i];
            decode_and_set(address, val);
        }
    }
    unsigned long result = 0;
    for (const auto& kv : mem){
        result += kv.second;
    }
    cout << result << '\n';
    return 0;
}

void decode_and_set(string address, int value){
    size_t X = address.find('X');
    if (X == string::npos) {
        mem[bitset<36>(address).to_ulong()] = value;
        return;
    }
    address[X] = '0'; decode_and_set(address, value);
    address[X] = '1'; decode_and_set(address, value);
}
