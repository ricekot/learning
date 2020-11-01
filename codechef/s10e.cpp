#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T, N;
	cin >> T;
	while (T--){
        cin >> N;
        vector<int> P(N);
        int small = 1000, good_count = 0;
        for (int i = 0; i < N; ++i){
            cin >> P[i];
            if (i < 5){
                if (small > P[i]){
                    small = P[i];
                    good_count++;
                    continue;
                }
                else continue;
            }
            else{
                bool price_is_good = true;
                for (int j = i-5; j < i; ++j){
                    if (P[i] >= P[j]){
                        price_is_good = false;
                        break;
                    }
                }
                if (price_is_good) ++good_count;
            }
        }
        cout << good_count << '\n';
	}
	return 0;
}
