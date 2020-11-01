#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T, N;
	cin >> T;
	while (T--){
	    cin >> N;
        vector<short> freq(1000001, 0);
        vector<int> A;
        for (int i = 0; i < N; ++i){
            cin >> A[i];
            freq[A[i]]++;
        }
        for (int j = 0; j < N; ++j){
            int toprint = 0;
            for (int k = j+1; k < 1000001; ++k){
                toprint += freq[k];
            }
            cout << toprint << ' ';
        }
	    cout << '\n';
	}
	return 0;
}
