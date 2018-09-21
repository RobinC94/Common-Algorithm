#include <bits/stdc++.h>

using namespace std;

long long state[21][21][21][3];

long long get(int a, int b, int c){
    return state[a][b][c][0] + state[a][b][c][1] + state[a][b][c][2];
}

int main(){
    int m, n, p;
    cin >> m >> n >> p;
    state[1][0][0][0] = 1;
    state[0][1][0][1] = 1;
    state[0][0][1][2] = 1;
    for(int i = 0; i <= m; ++i){
        for(int j = 0; j <= n; ++j){
            for(int k = 0; k <= p; ++k){
                if(i + j + k <= 1)
                    continue;
                if(i > 0){
                    state[i][j][k][0] = state[i-1][j][k][1] + state[i-1][j][k][2];
                }
                if(j > 0){
                    state[i][j][k][1] = state[i][j-1][k][0] + state[i][j-1][k][2];
                }
                if(k > 0){
                    state[i][j][k][2] = state[i][j][k-1][0] + state[i][j][k-1][1];
                }

            }
        }
    }
    long long res = get(m,n,p);
    cout << res;

    return 0;
}
