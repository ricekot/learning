#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long T, N;
    string S;
	cin >> T;
	while (T--){
        cin >> N;
        vector<long long> S(N);
        for (long long i = 0; i < N; ++i){
            cin >> S[i];
        }
        long long result = 0, prev_least = 0;
        for (long long i = 0; S.size(); ++i){
            auto least = min_element(S.begin(), S.end());
            result += (*least - prev_least) * (S.size());
            prev_least = *least;
            S.erase(least, S.end());
        }
        cout << result << '\n';
	}
	return 0;
}
