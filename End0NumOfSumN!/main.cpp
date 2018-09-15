#include <bits/stdc++.h>

using namespace std;

pair<int, int> calNum2and5(int a){
    pair<int, int>res;
    res.first = 0;
    res.second = 0;
    while(a%2 == 0){
        a /= 2;
        res.first++;
    }
    while(a%5 == 0){
        a /= 5;
        res.second++;
    }

    return res;

}

int main(){
    int n;
    cin >> n;
    int totalNum2 = 0;
    int totalNum5 = 0;
    int curNum2 = 0;
    int curNum5 = 0;
    for(int i = 2; i <= n; ++i) {
        pair<int, int> res = calNum2and5(i);
        curNum2 += res.first;
        curNum5 += res.second;
        totalNum2 += curNum2;
        totalNum5 += curNum5;

    }
    cout << min(totalNum2, totalNum5);

    return 0;
}