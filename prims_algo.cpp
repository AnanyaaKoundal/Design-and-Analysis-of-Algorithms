#include <bits/stdc++.h>
using namespace std;

class Graph{
    int v;
    vector<vector<int>> *adj;
    public:
    Graph(int V){
        v=V;
        adj->resize(v);
    }
    void addEdge(int u,int v, int w){
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    void MST(){
        vector<int> key(v, INT_MAX);
        vector<bool> visited(v, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        key[0]=0;
        pq.push({0,0});
        while(!pq.empty()){
            auto top= pq.top();
            pq.pop();
            int node= top.first;
            if(visited[node]==true) continue;
            visited[node]=true;
            for(auto x: adj[node]){
                int cur=x[0];
                int w=x[1];
                if(visited[cur]==false && w<key[cur]){
                    key[cur]=w;
                    pq.push({cur,w});
                }else if(visited[cur]==false){
                    pq.push({cur,w});
                }
            }
        }
        int ans=0;
        for(int x: key) ans+=x;
        cout<<"Weight of minimum spanning tree is "<<ans;
    }
};