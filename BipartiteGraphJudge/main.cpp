#include <bits/stdc++.h>

using namespace std;

bool judge(vector<vector<int> > graph, int num){
    if (num < 2) return true;
    int *a = new int[num];
    for(int i = 0; i < num; ++i){
        if(a[i] == 0){
            queue<int> Q;
            Q.push(i);
            a[i] = 1;

            while(!Q.empty()){
                int cur = Q.front();
                Q.pop();

                int next;
                if(a[cur] == 1)
                    next = -1;
                else if(a[cur] == -1)
                    next = 1;

                for(int j = 0; j < num; j++){
                    if(j == cur) continue;
                    if(graph[cur][j]){
                        if(a[j] == 0){
                            a[j] = next;
                            Q.push(j);
                        }
                        else{
                            if(a[j] == next)
                                continue;
                            else
                                return false;
                        }
                    }
                }

            }
        }
    }

    return true;
}


int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int> > graph(N);
    for (size_t i = 0; i < N; ++i){
        graph[i].resize(N);
    }
    for(int i = 0; i < M; ++i){
        int x, y;
        cin >> x >> y;
        graph[x-1][y-1] = 1;
        graph[y-1][x-1] = 1;
    }

    if(judge(graph, N)){
        cout << 1;
    }
    else{
        cout << 0;
    }

    return 0;
}