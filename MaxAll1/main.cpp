#include <bits/stdc++.h>
using namespace std;

int main(){
    int length, chance;
    cin >> length >> chance;
    vector<int> ch(length);
    for (int i = 0; i < length; ++i){
        int cur;
        cin >> cur;
        ch[i] = cur;
    }

    vector<int> ch0;
    vector<int> ch1;

    int cur = ch[0];
    int begin = cur;
    int num = 0;
    for(auto &i : ch){
        if (cur == i){
            num++;
        }
        else{
            if(cur == 0){
                ch0.push_back(num);
            }
            else{
                ch1.push_back(num);
            }
            num = 1;
            cur = i;
        }
    }
    if(cur == 0){
        ch0.push_back(num);
    }
    else{
        ch1.push_back(num);
    }
    int end = cur;

    for(auto &i : ch0){
        cout << i;
    }
    cout << endl;

    for(auto &i : ch1){
        cout << i;
    }
    cout << endl;

    int dis = -1;
    int num0 = ch0.size();
    int num1 = ch1.size();

    for(int i = 0; i < num0; i++){
        int changeN = ch0[i];
        int length = ch0[i];
        bool cut = false;
        if(ch0[i] > chance) {
            length = chance;
            cut = true;
        }
        int j = i;
        if (ch[0] == 1){
            j = i + 1;
        }

        if(cut){
            if(num1 != 0){
                if(j >= num1)
                    length += ch1[j-1];
                else if (j < 1)
                    length += ch1[j];
                else{
                    length += (ch1[j] > ch1[j-1]) ? ch1[j] : ch1[j-1];
                }

            }
        }
        else {
            if (j < num1) length += ch1[j];
            if (j - 1 >= 0) length += ch1[j - 1];
        }


        int search = i;
        if(++search < num0 && changeN + ch0[search] <= chance){
            length += ch0[search];
            if(++j < num1){
                length += ch1[j];
            }
        }
        cout << i << ' ' << length << endl;
        if (length > dis){
            dis = length;
        }
    }

    cout << endl << dis;

    return 0;
}

