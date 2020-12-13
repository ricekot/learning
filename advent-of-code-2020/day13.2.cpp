#include <bits/stdc++.h>

using namespace std;

long long mm_inv(long long n, long long mod);

int main(){
    ifstream list("input/day13.txt");
    string line;
    getline(list, line);
    vector<int> m;
    while (getline(list, line, ',')){
        m.push_back(line[0] == 'x' ? 1 : stoi(line));
    }

    long long M = 1;
    for (int m_i : m) M *= m_i;
    // cout << "M = " << M << '\n';
    
    long long result = 0;
    for (int i = 0; i < m.size(); ++i){
        // logic: chinese remainder theorem
        if (m[i] == 1) continue;
        int a = m[i] - i % m[i];
        long long b = M/m[i];
        long long b_inv = mm_inv(b, m[i]);
        // cout << "x = " << a << " mod " << m[i] << "\t| b = " << b << "\t| b' = " << b_inv << '\n';
        result += a * b * b_inv;
    }
    // cout << "x = ";
    cout << result % M << '\n';
    return 0;
}

// modular multiplicative inverse
long long mm_inv(long long n, long long mod) {
    for (int i = 0; i < mod; ++i){
        if (n * i % mod == 1) return i;
    }
    return 1;
}
