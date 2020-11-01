#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
    string S;
	cin >> T;
	while (T--){
        string result = "";
	    cin >> S;
        for (int i = 0; i < S.size(); ++i){
            result += S[i];
            int count = 1; 
            while (S[i] == S[i+1]){
                ++count;
                ++i;
            }
            result += to_string(count);
        }
        if (result.length() >= S.length()) cout << "NO\n";
        else cout << "YES\n";
	}
	return 0;
}
