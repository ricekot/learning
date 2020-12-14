#include <bits/stdc++.h>

using namespace std;

int main(){
    ifstream list("input/day14.txt");
    string line, mask;
    map<int, bitset<36>> mem;
    while (getline(list, line)){
        if (line.substr(0, 4) == "mask") mask = line.substr(7);
        else {
            string location, equals, value;
            istringstream iss(line);
            iss >> location >> equals >> value;
            int loc = stoi(location.substr(4)), val = stoi(value);
            mem[loc] = bitset<36>(val);
            for (int i = 0; i < 36; ++i)
                if (mask[35 - i] != 'X')
                    mem[loc][i] = mask[35 - i] - '0';
        }
    }
    unsigned long result = 0;
    for (const auto& kv : mem){
        result += kv.second.to_ulong();
    }
    cout << result << '\n';
    return 0;
}
