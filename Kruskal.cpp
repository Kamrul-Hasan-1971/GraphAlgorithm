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

vector<edgeStructure>edgeVector,output;


void initializeSet(ll n)
{
    for(ll i=0;i<=n;i++){
        parent[i]=i;
    }
}

ll findParent(ll x)
{
    if(x!=parent[x])
        return parent[x]=findParent(parent[x]);
    else
        return x;
}

ll kruskal(ll n)
{
    initializeSet(n);
    sort(edgeVector.begin(),edgeVector.end());

    ll sz=edgeVector.size();
    ll ans=0;

    for(ll i=0;i<sz;i++){
        int uPr = findParent(edgeVector[i].u);
        int vPr = findParent(edgeVector[i].v);
        if(uPr != vPr)
        {
            output.pb(edgeVector[i]);
            parent[uPr] = vPr;
            ans+=edgeVector[i].w;
        }
    }
    return ans;
}


int main()
{
    ll vertex,edges,i;
    cin>>vertex>>edges;

    for( i=0;i<edges;i++){
        edgeStructure e;
        cin>>e.u>>e.v>>e.w;
        edgeVector.pb(e);
    }
    cout<<"MST Cost = "<<kruskal(vertex)<<endl;
    for( i = 0 ;i < output.size() ; i++)
    {
        cout<<output[i].u<<" "<<output[i].v<<" "<<output[i].w<<endl;
    }
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
