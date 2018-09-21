#include <bits/stdc++.h>

using namespace std;

int main(){
    string in;
    cin >> in;
    int len = in.length();
    if (len <= 1){
        cout << "/";
        return 0;
    }
    int i = 0;
    string cur;
    stack<string> s;
    string res;
    while(i < len){
        if(in[i] == '/') {
            i++;
            continue;
        }
        cur.clear();
        while(i < len && in[i] != '/'){
            cur += in[i];
            i++;
        }

        if(cur == ".."){
            if(!s.empty())
                s.pop();
        }

        else if(cur == ".")
            continue;
        else{
            s.push(cur);
        }
    }

    if(s.empty()){
        res = "/";
    }
    else{
        while(!s.empty()) {
            res = "/" + s.top() + res;
            s.pop();
        }
    }

    cout << res;

    return 0;
}