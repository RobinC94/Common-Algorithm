#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, M;
    cin >> N;
    cin >> M;
    unordered_map<int, set<int> > mat;

    for(int i = 0; i < M; ++i){
        int a, b;
        cin >> a >> b;
        mat[b].insert(a);
        mat[b].insert(b);
        if(!mat[a].empty())
            mat[b].insert(mat[a].begin(), mat[a].end());
    }
    int num = 0;
    for(auto &i : mat){
        cout << i.first << ": ";
        for(auto &j : i.second){
            cout << j << ' ';
        }
        if (i.second.size() == N)
            num++;
    }
    cout << num;

}

