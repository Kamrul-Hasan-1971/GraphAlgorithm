#include<bits/stdc++.h>
using namespace std;

#define           CIN              ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define           ll               long long int
#define           pb               push_back
#define           mx               100


struct edgeStructure
{
    ll u;
    ll v;
    ll w;
};

bool operator<(edgeStructure lhs,edgeStructure rhs)
{
    return lhs.w<rhs.w;
}

ll parent[mx];
ll rankParent[mx];

vector<edgeStructure>edgeVector;


void initializeSet(ll n)
{
    for(ll i=0;i<=n;i++){
        parent[i]=i;
        rankParent[i]=0;
    }
}

ll findParent(ll x)
{
    if(x!=parent[x])
        return parent[x]=findParent(parent[x]);
    else
        return x;
}

ll unionSet(ll x, ll y)
{
    ll px=findParent(x);
    ll py=findParent(y);

    if(rankParent[px]<rankParent[y]){
        parent[px]=py;
    }
    else if(rankParent[px]>rankParent[y]){
        parent[py]=px;
    }
    else{
        parent[py]=px;
        rankParent[px]++;
    }
}


ll kruskal(ll n)
{
    initializeSet(n);
    sort(edgeVector.begin(),edgeVector.end());

    ll sz=edgeVector.size();
    ll ans=0;

    for(ll i=0;i<sz;i++){
        if(findParent(edgeVector[i].u)!=findParent(edgeVector[i].v))
        {
            unionSet(parent[edgeVector[i].u],parent[edgeVector[i].v]);
            ans+=edgeVector[i].w;
        }
    }
    return ans;
}


int main()
{
    ll vertex,edges;
    cin>>vertex>>edges;

    for(ll i=0;i<edges;i++){
        edgeStructure e;
        cin>>e.u>>e.v>>e.w;
        edgeVector.pb(e);
    }
    cout<<"MST Cost = "<<kruskal(vertex)<<endl;
    return 0;
}
