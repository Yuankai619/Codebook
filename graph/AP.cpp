/*
articulation point
N: number of node
dfn: the order of dfs
low: the lowest order of node that can reach
isap: whether the node is articulation point
ap: the articulation point

*/
#include<bits/stdc++.h>
using namespace std; 

const int N=1000;
struct AP{
    vector<vector<int>> g;
    int dfn[N], low[N],vis[N],isap[N],ti;
    vector<int> ap;
    void init(){    
        g.resize(N);
        memset(dfn,-1,sizeof(dfn));
        memset(low,0,sizeof(low));
        memset(vis,0,sizeof(vis));
        ap.clear();
        ti=0;
    }
    void add_edge(int u,int v){
        g[u].push_back(v);
        g[v].push_back(u);
    }
    void dfs(int u,int fa){
        vis[u]=true;
        dfn[u]=low[u]=ti++;
        int child=0;
        for(int v:g[u]){
            if(v==fa)continue;
            if(!vis[v]){
                child++;
                dfs(v,u);
                low[u]=min(low[u],low[v]);
                if(low[v]>=dfn[u]){
                    ap.push_back(u);
                    isap[u]=true;
                }
            }else{
                low[u]=min(low[u],dfn[v]);
            }
        }
        if(u==fa&&child>=1){
            ap.push_back(u);
            isap[u]=true;
        }
    }
    void solve(int root){
        dfs(root,root); 
    }
}ap;
int main(){
    ap.init();
    int u,v;
    while(cin>>u>>v){
        ap.add_edge(u,v);
    }
    ap.solve(3);
    cout<<"    ";
    for (int i = 0; i < N && ap.dfn[i] != -1; ++i){
            cout<<i<<" \n"[ap.dfn[i+1]==-1];
    }
    cout<<"dfn ";
    for (int i = 0; i < N && ap.dfn[i] != -1; ++i){
        cout << ap.dfn[i] << " \n"[ap.dfn[i+1] == -1];
    }
    cout << "low ";
    for (int i = 0; i < N && ap.dfn[i] != -1; ++i){
        cout << ap.low[i] << " \n"[ap.dfn[i+1] == -1];
    }
}