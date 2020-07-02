#include<bits/stdc++.h>
using namespace std;

#define  CIN            ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define  ll             long long int
vector<ll>v1[10005];
void topsort(ll node)
{
    ll i ,cnt=0,indegree[node+2]={0};
    for( i = 1 ; i<= node ; i++ )
        for( auto v: v1[i]) indegree[v]++;
    multiset<ll>ms;
    for( i = 1 ; i<= node ; i++)
        if(!indegree[i]) ms.insert(i);
    vector<ll>ans;
    while(!ms.empty())
    {
        auto it = ms.begin();
        ans.push_back(*it);
        ms.erase(it);
        for( auto v:v1[*it]){
            if(--indegree[v]==0) ms.insert(v);
        }
        cnt++;
    }
    if(cnt!=node) {cout<<"Sandro fails."<<endl;return;}
    for( i = 0 ; i < node ; i++) cout<<ans[i]<<" ";
    cout<<endl;
}
int main()
{
    CIN;
    ll  node,edges,u,v,i;
    cin >> node >> edges;
    for( i =1 ; i<= edges ; i++)
    {
        cin >> u >> v ;
        v1[u].push_back(v);
    }
    topsort(node);
    return 0 ;
}
