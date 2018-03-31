#include<bits/stdc++.h>
using namespace std;

unordered_map<int, int> vis;

bool isSafe(vector<list<int> > graph, int a){
    if(vis.find(a) != vis.end()){
        if (vis[a] == 1) return true;
        else return false;
    }
    if (graph[a].empty()){
        vis[a] = 1;
        return true;
    }
    vis[a] = 0;
    for(auto i: graph[a]){
        if(!isSafe(graph, i)){
            return false;
        }
    }
    vis[a] = 1;
    return true;
}

int main()
{
    int n, m;
    scanf("%d%d", &n,&m);
    vector<list<int> > graph(n);
    for(int i = 0; i < m;++i){
        int x,y;
        scanf("%d,%d",&x,&y);
        graph[x-1].push_back(y-1);
    }
    int id = 0;
    while(vis.find(id) == vis.end() && id < n){
        isSafe(graph, id);
        id++;
    }
    for(int i = 0; i < n; ++i)
        if(vis.find(i) == vis.end() || vis[i] == 1)
            printf("%d ", i+1);
    return 0;
}



