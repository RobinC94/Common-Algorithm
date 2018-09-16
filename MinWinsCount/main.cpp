#include <bits/stdc++.h>

using namespace std;

int findLess(long a, int n){
    if(a <= n)
        return 1;
    else{
        return 1 + findLess(a - n, n-1);
    }
}


int main() {
    long a,b;
    cin >> a >> b;
    long sum = a + b;
    auto n = (int)sqrt(sum * 2);
    //cout << n << endl;
    if(sum*2 % n != 0 || sum*2 / n != n+1){
        cout << -1;
        return 0;
    }
    int res = findLess(a, n);

    cout << res << endl;

    return 0;
}
