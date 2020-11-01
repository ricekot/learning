#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T, A, B;
    int matches[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
	cin >> T;
	while (T--){
	    cin >> A >> B;
        int sum = A + B, res = 0;
        while (sum != 0){
            res += matches[sum%10];
            sum /= 10;
        }
	    cout << res << '\n';
	}
	return 0;
}
