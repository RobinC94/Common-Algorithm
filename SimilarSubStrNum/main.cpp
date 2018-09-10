#include <bits/stdc++.h>
using namespace std;

/*请完成下面这个函数，实现题目要求的功能
当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^
******************************开始写代码******************************/
int solve(string S, string T) {
    int num = 0;
    vector<int> L(T.size());
    unordered_map<char, int> dict;
    for(size_t i = 0; i < T.size(); ++i){
        char c = T[i];
        if (dict.find(c) == dict.end()){
            dict[c] = i;
            L[i] = i;
        }
        else{
            L[i] = dict[c];
        }
    }
    for(auto &i : L){
        cout << i << ' ';
    }
    cout << endl;

    for(size_t i = 0; i <= S.size() - T.size(); ++i){
        dict.clear();
        bool hit = true;
        for(size_t j = 0; j < T.size(); ++j){
            char c = S[i+j];
            if (L[j] == j){
                if (dict.find(c) == dict.end()){
                    dict[c] = j;
                    continue;
                }
                else
                    hit = false;
                break;
            }
            else if (dict.find(c) == dict.end()){
                hit = false;
                break;
            }
            else if(L[j] != dict[c]){
                hit = false;
                break;
            }
        }
        if(hit){
            num++;
        }
    }

    return num;

}
/******************************结束写代码******************************/


int main() {
    int res;

    string _S;
    getline(cin, _S);
    string _T;
    getline(cin, _T);

    res = solve(_S, _T);
    cout << res << endl;

    return 0;

}