#include <bits/stdc++.h>

using namespace std;

int triNum(int a, int b, int c){
    if (a == 1) return min(b, c);
    else{
        int res = 0;
        for(int i = 1; i <= a; ++i){
            for(int j = 1; j < min(c+i, b+1); ++j){

                int minc = abs(i-j) + 1;
                int maxc = min(i+j-1, c);

                cout << i << ' ' << j << ' ' << minc << '-' << maxc << endl;
                res += (maxc - minc + 1);
                res %= 1000000007;
            }
        }
        return res;
    }
}

void mySort(int& a, int& b, int& c){
    int tmp;
    if(a > c){
        tmp = a;
        a = c;
        c = tmp;
    }
    if(b > c){
        tmp = b;
        b = c;
        c = tmp;
    }
    if(a > b){
        tmp = a;
        a = b;
        b = tmp;
    }
}

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    mySort(a, b, c);
    cout << triNum(a,b,c);

    return 0;
}