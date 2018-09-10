#include <bits/stdc++.h>
using namespace std;

int find(int n, int a[])
{
    if(a[n] < 0) return n;
    else return a[n] = find(a[n], a);
}

void merge(int root1, int root2, int a[])
{
    if(a[root1] < a[root2]){
        a[root1] = root2;
    }
    else{
        if(a[root1] == a[root2])
            a[root1]--;
        a[root2] = root1;
    }
}

int main()
{
    int M;
    cin >> M;
    int *a = new int[M*M];
    int num = 0;
    int left = 0;
    int up = 0;
    for (int i = 0; i < M*M; ++i){

        int cur;
        cin >> cur;
        if (cur == 0){
            a[i] = M*M;
            continue;
        }
        if (i%M != 0)
            left = a[i-1];
        else
            left = M*M;
        if(i >= M)
            up = a[i-M];
        else
            up = M*M;

        if(left == M*M && up == M*M){
            a[i] = -1;
        }
        else if(left == M*M){
            a[i] = find(i-M, a);
        }
        else if(up == M*M){
            a[i] = find(i-1, a);
        }
        else if(find(i-1, a) == find(i-M, a)){
            a[i] = find(i-1, a);
        }
        else{
            merge(find(i-1, a), find(i-M, a), a);
            a[i] = find(i-1, a);
        }
    }

    for (int i = 0; i < M*M; ++i){
        cout << a[i] << ' ';
        if(a[i] < 0)
            num++;
    }
    cout << endl << num;
    return 0;
}