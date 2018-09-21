#include <bits/stdc++.h>

using namespace std;

int main(){
    int num;
    cin >> num;
    vector<string> in;
    vector<string> out;
    unordered_map<string, int> m;
    for(int i = 0; i < num; ++i){
        string str;
        cin >> str;
        in.push_back(str);
        int len = str.length();
        string key;
        string comp;
        for(int j = 0; j < len; ++j){
            key += str[j];
            if(m.find(key) == m.end()){
                m[key] = i;
                out.push_back(key);
                break;
            }
            else{
                int conf = m[key];
                if(out[conf].length() == j+1) {
                    comp = in[conf];
                    out[conf] += comp[j + 1];
                    m[out[conf]] = conf;
                }
            }
        }

    }

    for(int i = 0; i < num; ++i){
        cout << out[i];
        if(i != num-1)
            cout << endl;
    }
}
