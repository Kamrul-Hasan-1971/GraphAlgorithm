#include<bits/stdc++.h>
using namespace std;
#define  CIN            ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define  ll             long long int
#define  MX             100005
bool vis[MX];
vector<ll>v1[MX];
void dfs(ll u)
{
    vis[u]=true;
    for(auto v:v1[u]) if(!vis[v]) dfs(v);
}
bool isConnected(ll node)
{
    ll i;
    for(i=1;i<=node;i++) vis[i]=false;
    for(i=1;i<=node;i++) if(v1[i].size()) break;
    if(i==node+1) return true;
    dfs(i);
    for(i=1;i<=node;i++) if(!vis[i]&&v1[i].size()) return false;
    return true;
}
ll eulerian(ll node)
{
    if(isConnected(node)==false) return 0;
    ll odd=0;
    for(ll i=1;i<=node;i++) if(v1[i].size()&1) odd++;
    if(odd>2) return 0;
    return (odd)?1:2;
}
int main()
{
    CIN;
    ll  a,b,c,d,e,i,T,node,edge,u,v,s;
    cin>> T ;
    while(T--)
    {
        cin >> node >> edge;
        for( i =1 ; i<= node;i++) v1[i].clear();
        for( i = 1 ; i <= edge ; i++)
        {
            cin >> u>>v;
            u++,v++;
            v1[u].push_back(v);
            v1[v].push_back(u);
        }
        ll ans = eulerian(node);
        if(!ans) cout<<"NO Eulerian"<<endl;
        else if(ans==2) cout<<"Euleria Cycle"<<endl;
        else cout<<"Eulerian Path"<<endl;
    }
    return 0 ;
}
