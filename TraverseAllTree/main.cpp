#include <bits/stdc++.h>
using namespace std;

int bfs(vector<vector<int> > g, vector<int> vis){
    int depth = 0;
    queue<int> q;
    int curNum = 1;
    int nextNum = 0;
    q.push(0);
    vis[0] = 1;
    while(!q.empty()){
        int curPoint = q.front();
        q.pop();
        for (auto &i : g[curPoint]) {
            if (vis[i] == 0) {
                vis[i] = 1;
                nextNum++;
                q.push(i);
            }
        }
        curNum--;
        if(curNum == 0 && nextNum != 0){
            curNum = nextNum;
            nextNum = 0;
            depth++;
        }
    }
    return depth;
}

int main()
{
    int pNum;
    cin >> pNum;
    vector<vector<int> >g(pNum);
    vector<int> vis(pNum);
    for(int i = 0; i < pNum - 1; ++i){
        int x, y;
        cin >> x >> y;
        g[x-1].push_back(y-1);
        g[y-1].push_back(x-1);
    }

    int depth = bfs(g, vis);
    cout << endl << (pNum-1) * 2 - depth;
    return 0;

}
