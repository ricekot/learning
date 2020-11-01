#include <bits/stdc++.h>

using namespace std;

int main(){
    int T;
    cin >> T;
    while (T--){
        int N, M, result = 0;
        cin >> N >> M;
        vector<vector<int>> matrix(N, vector<int>(M));
        
        //matrix input
        for (int i = 0; i < N; ++i){
            for (int j = 0; j < M; ++j){
                cin >> matrix[i][j];
            }
        }

        for (int i = 0; i < N; ++i){
            for (int j = 0; j < M; ++j){
                for (int count = 0; i-count>=0 && i+count<N && j-count>=0 && j+count<M; ++count){
                    vector<int>row(count*2+1), col(count*2 + 1), rev(count*2 + 1);
                    for (int r = i - count, c = j - count, k; r <= i+count && c >= j+count; ++r, ++c, ++k){
                        rev[k] = row[k] = matrix[r][j];
                        col[k] = matrix[i][c];
                    }
                    reverse(rev.begin(), rev.end());
                    if (row == col && row == rev) ++result;
                }
            }
        }

        cout << result << '\n';
    }
    return 0;
}