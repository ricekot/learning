#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	short T;
    string S;
	cin >> T;
    cin.ignore();
	while (T--){
        long long F_count = 0;
        getline(cin, S);
        long long L = 0, R = 0;
        while (R < S.size()){
            string U = S;
            for (long long i = L; i <= R; ++i){
                if (U[i] == '0') U[i] = '1';
                else U[i] = '0';
            }
            for (long long i = 1; i < S.size(); ++i){
                if (U[i] == U[i-1]) ++F_count;
            }
            if (R == S.size() - 1){ 
                ++L;
                R = L;
            }
            else ++R;
        }
        cout << F_count << '\n';
	}
	return 0;
}
