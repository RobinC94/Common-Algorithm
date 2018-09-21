#include <bits/stdc++.h>
using namespace std;

int judLarge(vector<int> a, vector<int> b){
    int len = min(a.size(), b.size());
    for(int i = 0; i < len; ++i){
        if(a[i] > b[i])
            return 1;
        else if(a[i] < b[i])
            return -1;
    }
    if(a.size() > b.size())
        return 1;
    else if(a.size() < b.size())
        return -1;
    else
        return 0;
}

int main(){
    int num;
    cin >> num;
    vector<vector<int> > dic;
    vector<int> res;
    for(int i = 0; i < num; ++i) {
        int a;
        vector<int> l;
        cin >> a;
        l.push_back(a);
        while (cin.get() == '.') {
            cin >> a;
            l.push_back(a);
        }
        dic.push_back(l);
        res.push_back(i);
    }

    for(int i = 0; i < num - 1; ++i){
        bool change = false;
        for(int j = num-1; j > i; --j){
            int id1 = res[j];
            int id2 = res[j-1];
            if(judLarge(dic[id2], dic[id1]) == 1){
                change = true;
                res[j-1] = id1;
                res[j] = id2;
            }
        }
        if(!change) break;
    }
    for(auto &id : res){
        for(int i = 0; i < dic[id].size(); ++i){

            cout << dic[id][i];
            if(i != dic[id].size()-1)
                cout << '.';
        }
        cout << endl;
    }
    return 0;
}
