#include <bits/stdc++.h>

using namespace std;

void displayVector(vector<int> a){
    for(auto &i : a){
        cout << i << ' ';
    }
    cout << endl;
}

int main(){
    int n;
    cin >> n;
    vector<int> l(n);
    vector<int> r(n);
    map<int, int> m;
    for(int i = 0; i < n; ++i){
        int x;
        cin >> x;
        l[i] = x;
        m[x] = i;
    }
    int begin = 0;
    int end = n-1;
    int curMax = n;
    int id = 0;
    int preId = 0;
    while(true){
        r[begin] = curMax;
        begin++;
        id = m[curMax];
        m.erase(curMax);
        for(int i = preId; i < id; ++i){
            r[end] = l[i];
            end--;
            m.erase(l[i]);
        }
        preId = id+1;
        if(begin > end) break;
        auto it = m.end();
        it--;
        curMax = (*it).first;
        //cout << curMax << ' ' << id << ' ' << preId << ' ' << begin << ' ' << end;
    }
    displayVector(r);
    return 0;

}