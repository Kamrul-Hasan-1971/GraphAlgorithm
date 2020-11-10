//O(Nodes+Edges)
// topSort is only possible,when graph is a DAG.
//A DAG G has at least one vertex with in-degree 0 and one vertex with out-degree 0.
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
    queue<ll>qu;
    for( i = 1 ; i<= node ; i++)
        if(!indegree[i]) qu.push(i);
    vector<ll>ans;
    while(!qu.empty())
    {
        ll id = qu.front();
        qu.pop();
        ans.push_back(id);
        for( auto v:v1[id]){
            if(--indegree[v]==0) qu.push(v);
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
        v1[u].push_back(v);//u comes first before v in ordering;
    }
    topsort(node);
    return 0 ;
}
