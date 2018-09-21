#include <bits/stdc++.h>

using namespace std;

int get(int a, int b, char op){
    switch(op){
        case '+':
            return a+b;
        case '-':
            return a-b;
        case '*':
            return a*b;
        case '/':
            return a/b;
        default:
            return -1;
    }
}

int main(){
    string in;
    map<char, int> p;
    p['+'] = 1;
    p['-'] = 1;
    p['*'] = 2;
    p['/'] = 2;
    vector<int> res;
    while(cin >> in){
        if(in[0] == 'E') break;
        stack<char> op;
        stack<int> nums;
        int tmp = 0;
        int i = 0;
        while(i < in.length()){
            char ch = in[i];
            if(ch <= '9' && ch >= '0'){
                while(ch <= '9' && ch >= '0'){
                    tmp = tmp * 10 + (ch-'0');
                    i++;
                    ch = in[i];
                }
                //cout << "num: " << tmp << endl;
                if(op.size() > 1 && p[op.top()] == 2){
                    int x = nums.top();
                    nums.pop();
                    char oper = op.top();
                    op.pop();
                    int r = get(x, tmp, oper);
                    nums.push(r);
                    tmp = 0;

                }
                else{
                    nums.push(tmp);
                    tmp = 0;
                    continue;
                }
            }
            else{
                if(op.empty()){
                    op.push(ch);
                    ++i;
                    continue;
                }
                else if(p[op.top()] == 1 && p[ch] == 1){
                    int x, y, r;
                    char oper;
                    y = nums.top();
                    nums.pop();
                    x = nums.top();
                    nums.pop();
                    oper = op.top();
                    op.pop();
                    r = get(x, y, oper);
                    nums.push(r);
                    op.push(ch);
                    ++i;
                }
                else{
                    op.push(ch);
                    i++;
                }
            }
        }
        while(!op.empty()){
            int x, y, r;
            char oper;
            y = nums.top();
            nums.pop();
            x = nums.top();
            nums.pop();
            oper = op.top();
            op.pop();
            r = get(x, y, oper);
            nums.push(r);
        }
        res.push_back(nums.top());
    }

    for(int i = 0; i < res.size(); ++i){

        int r = res[i];
        cout << r;
        if(i != res.size()-1){
            cout << endl;
        }
    }

    return 0;
}
