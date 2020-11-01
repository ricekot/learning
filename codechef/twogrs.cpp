#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T, A, B, C;
	cin >> T;
	while (T--){
	   cin >> A >> B >> C;
       int K = A + 2*B + 3*C;
       if (K & 1 == 1) {
           cout << "NO\n";
           continue;
       }
       else {
            int flag = 0, swell = 0;
            if (B == 0){
                for (int m = 3*C; m >= 0; m-=3){
                    if (K/2 - m >= 0 && K/2 - m <= A){
                        cout << "YES\n";
                        flag = 1;
                        break; 
                    }
                }
            }
            else if (C == 0){
                for (int m = 2*B; m >= 0; m-=2){
                    if (K/2 - m >= 0 && K/2 - m <= A){
                        cout << "YES\n";
                        flag = 1;
                        break; 
                    }
                }
            }
            else {
                for (int m = 2*B + 3*C; m >= 1; --m){
                    if (m == 1) m=0;
                    if (K/2 - m >= 0 && K/2 - m <= A){
                        cout << "YES\n";
                        flag = 1;
                        break; 
                    }
                }
            }
            if (flag == 0) cout << "NO\n";
       }
	}
	return 0;
}
