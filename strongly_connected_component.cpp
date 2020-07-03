#include<bits/stdc++.h>
using namespace std;
#define       zero(a)     memset(a,0,sizeof a)
#define       ll          long long int
#define       MX          100005
vector<ll>v1[MX],v2[MX];
ll node,vis[MX];
void dfs1(ll u)
{
    vis[u]=1;
    for(auto v:v1[u]) if(!vis[v]) dfs1(v);
}
void dfs2(ll u)
{
    vis[u]=1;
    for(auto v:v2[u]) if(!vis[v]) dfs2(v);
}
ll SCC()
{
    for(ll i=1;i<=node;i++) vis[i]=0;
    dfs1(1);
    for(ll i=1;i<=node;i++) if(!vis[i]) return 0;
    for(ll i=1;i<=node;i++) vis[i]=0;
    dfs2(1);
    for(ll i=1;i<=node;i++) if(!vis[i]) return 0;
    return 1;
}
int main()
{
    ll edges , i ,u,v;
    cin >> node >> edges ;
    for( i = 0 ; i < edges ; i++)
    {
        cin >> u >> v ;
        v1[u].push_back(v);
        //v2[v].push_back(u);
    }
    if(SCC()) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
// If graph is directed no need to run dfs2.
