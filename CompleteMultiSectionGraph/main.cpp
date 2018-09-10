#include <bits/stdc++.h>
using namespace std;

int find(int n, int a[])
{
    if(a[n] < 0) return n;
    else return a[n] = find(a[n], a);
}

void merge(int root1, int root2, int a[])
{
    if(a[root1] <= a[root2]){
        a[root1] += a[root2];
        a[root2] = root1;
    }
    else{
        a[root2] += a[root1];
        a[root1] = root2;
    }
}

bool judge(vector<vector<int> > graph, int num){
    int *a = new int[num];
    for(int i = 0; i < num; ++i){
        a[i] = -1;
    }
    int edgeNum = 0;
    int totalNum = num*(num-1) / 2;
    for(size_t i = 0; i < num-1; ++i){
        for(size_t j = i+1; j < num; ++j){
            if(graph[i][j] == 0){
                if(find(i, a) == find(j, a)){
                    continue;
                }
                else
                    merge(find(i, a), find(j, a), a);
            }
            else{
                edgeNum++;
            }
        }
    }

    for(int i = 0; i < num; ++i){
        if(a[i] < 0){
            int k = -a[i];
            int curNum = k*(k-1) / 2;
            totalNum -= curNum;
        }
    }
    if(totalNum == edgeNum)
        return true;
    else
        return false;
}


int main() {
    int T;
    cin >> T;
    vector<bool> res;
    for(int t = 0; t < T; ++t){
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
            res.push_back(true);
        }
        else{
            res.push_back(false);
        }

    }
    for(auto b : res){
        if(b){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }
    return 0;
}