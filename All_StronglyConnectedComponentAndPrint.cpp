/*A directed graph is strongly connected if there is a path between all pairs of vertices. A 
strongly connected component of a directed graph is a maximal strongly connected subgraph*/
/* full graph strongly connected component naki check korte bolley just normal+reverse graph 
traverse kore shob node visit hocchey naki chack korle e hobey.*/

#include<bits/stdc++.h>
using namespace std;
#define       zero(a)              memset(a,0,sizeof a)

vector<int> adj[1000],radj[1000],temp;
vector<vector<int> > res;
bool vis[1000];
stack<int>st;

void dfs(int u)
{
    vis[u]=1;
    for(auto v: adj[u]) if(vis[v]==0) dfs(v);
    st.push(u);
}
void dfs2(int u)
{
    temp.push_back(u);
    vis[u]=1;
    for(auto v: radj[u]) if(vis[v]==0) dfs2(v);
}
int main()
{
    int node,edge,a,b, i, T;
    cin >> node >> edge ;
    for(i=0; i<edge; i++)
    {
        cin >> a >> b ;
        adj[a].push_back(b);
        radj[b].push_back(a);
    }
    zero(vis);
    for(i=1; i<=node; i++) if(vis[i]==0) dfs(i);
    zero(vis);
    while(!st.empty())
    {
        int u=st.top();
        st.pop();
        if(vis[u]==0)
        {
            temp.clear();
            dfs2(u);
            res.push_back(temp);
        }
    }
    cout<<"There are "<<res.size()<<" component"<<endl;
    for(int i=0; i<res.size(); i++){
        for(auto v:res[i]) cout<<v<<" ";
        cout<<endl;
    }
    return 0;
}

/*
7 8
1 2
2 3
3 1
3 4
4 5
5 6
6 7
7 5
*/
