//https://medium.com/%E0%A6%AA%E0%A7%8D%E0%A6%B0%E0%A7%8B%E0%A6%97%E0%A7%8D%E0%A6%B0%E0%A6%BE%E0%A6%AE%E0%A6%BF%E0%A6%82-%E0%A6%AA%E0%A6%BE%E0%A6%A4%E0%A6%BE/kruskals-algorithm-minimum-spanning-tree-74fda4b98638
#include<bits/stdc++.h>
using namespace std;

#define           CIN              ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define           ll               long long int
#define           pb               push_back
#define           mx               100
struct data
{
    ll u,v,w;
    bool operator<(const data &other)
    {
        return w<other.w;
    }
};
ll parent[mx];
vector<data>v1,output;
ll findParent(ll x)
{
    if(x!=parent[x]) return parent[x]=findParent(parent[x]);
    return x;
}
ll kruskal(ll n)
{
    for(ll i=0; i<=n; i++) parent[i]=i;
    sort(v1.begin(),v1.end());
    ll sz=v1.size(),ans=0;
    for(ll i=0; i<sz; i++)
    {
        int uPr = findParent(v1[i].u);
        int vPr = findParent(v1[i].v);
        if(uPr != vPr)
        {
            output.pb(v1[i]);
            parent[uPr] = vPr;
            ans+=v1[i].w;
        }
    }
    return ans;
}
int main()
{
    ll node,edges,i;
    cin>>node>>edges;
    for( i=0; i<edges; i++)
    {
        data e;
        cin>>e.u>>e.v>>e.w;
        v1.pb(e);
    }
    cout<<"MST Cost = "<<kruskal(node)<<endl;
    for( i = 0 ; i < output.size() ; i++)
        cout<<output[i].u<<" "<<output[i].v<<" "<<output[i].w<<endl;
    return 0;
}
/*
4 5
0 1 10
0 2 6
0 3 5
1 3 15
2 3 4
ans:
19
2 3 4
0 3 5
0 1 10
*/
