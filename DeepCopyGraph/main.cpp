#include <bits/stdc++.h>
using namespace std;

struct node{
    int val;
    vector <node*> edgeList;
    node(int x) : val(x) {}
};

void displayVector(vector<int> &l) {
    for (auto &i : l) {
        cout << i << ", ";
    }
    cout << endl;
}

void displayGraphFromNode(node* n){
    unordered_map<int, node*> vexMap;
    unordered_set<int> vis;
    int v = n->val;
    vexMap[v] = n;
    queue<int> q;
    q.push(v);
    while(!q.empty()){
        v = q.front();
        node* tmp = vexMap[v];
        q.pop();
        cout << v << "--";
        for(auto &t : tmp->edgeList){
            v = t->val;
            cout << v << ',';
            if(vis.find(v) == vis.end()){
                q.push(v);
                vis.insert(v);
            }
            if(vexMap.find(v) == vexMap.end()){
                vexMap[v] = t;
            }
        }
        cout << endl;
    }
}

void initGraph(vector<int> &vex, vector<vector<int>> &graph){
    vex = {2,8,7,5,1,6,4,3};
    vector<int> l;
    l = {0, 1, 1, 0, 0, 0, 0, 0};//0--1,2
    graph.push_back(l);
    l = {1, 0, 0, 0, 1, 1, 0, 0};//1--0,4,5
    graph.push_back(l);
    l = {1, 0, 0, 1, 1, 0, 0, 0};//2--0,3,4
    graph.push_back(l);
    l = {0, 0, 1, 0, 1, 0, 1, 0};//3--2,4,6
    graph.push_back(l);
    l = {0, 1, 1, 1, 0, 1, 1, 0};//4--1,2,3,5,6
    graph.push_back(l);
    l = {0, 1, 0, 0, 1, 0, 1, 0};//5--1,4,6
    graph.push_back(l);
    l = {0, 0, 0, 1, 1, 1, 0, 1};//6--3,4,5,7
    graph.push_back(l);
    l = {0, 0, 0, 0, 0, 0, 1, 0};//7--6
    graph.push_back(l);
}

node* vectorToNodeGraph(vector <int> &vex, vector<vector<int>> &graph, int n){
    unordered_map<int, node*> vexMap;
    for(auto &i : vex){
        vexMap[i] = new node(i);
    }
    for(int i = 0; i < vex.size(); ++i){
        auto l = graph[i];
        int v = vex[i];
        for(int j = 0; j < vex.size(); ++j){
            if(l[j] == 1){
                vexMap[v]->edgeList.push_back(vexMap[vex[j]]);
            }
        }
    }
    return vexMap[n];
}

node* deepCopy(node* n){
    unordered_map<int, pair<node*, node*>> vexMap;
    unordered_set<int> vis;
    int v = n->val;
    node* cur = new node(v);
    pair<node*, node*> p;
    p.first = n;
    p.second = cur;
    vexMap[v] = p;
    vis.insert(v);
    queue<int> q;
    q.push(v);
    while(!q.empty()){
        int curV = q.front();
        pair<node*, node*> curP = vexMap[curV];
        q.pop();
        node* ori = curP.first;
        node* newOne = curP.second;
        for(auto &t : ori->edgeList){
            v = t->val;
            if(vis.find(v) == vis.end()){
                q.push(v);
                vis.insert(v);
            }
            if(vexMap.find(v) == vexMap.end()){
                node* tmp = new node(v);
                p.first = t;
                p.second = tmp;
                vexMap[v] = p;
                newOne->edgeList.push_back(tmp);
            }
            else{
                newOne->edgeList.push_back(vexMap[v].second);
            }
        }
    }
    return cur;
}

int main(){
    vector <int> vex;
    vector <vector<int> > graph;
    initGraph(vex, graph);

    displayVector(vex);
    cout << endl;
    for(auto &i : graph) {
        displayVector(i);
    }
    node* n = vectorToNodeGraph(vex, graph, 8);

    displayGraphFromNode(n);
    cout << endl;

    node* res = deepCopy(n);
    displayGraphFromNode(res);

    return 0;
}