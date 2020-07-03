#include<bits/stdc++.h>
using namespace std;
#define       zero(a)              memset(a,0,sizeof a)

vector<int> adj[1000];
vector<int> radj[1000];
vector<int> result[1000];
bool visited[1000];
bool color[1000];
stack<int>st;

void dfs(int u)
{
    color[u]=1;
    for(int i=0; i<adj[u].size(); i++)
    {
        int v=adj[u][i];
        if(color[v]==0)
            dfs(v);
    }
    st.push(u);
}

void dfs2(int u,int mark)
{
    result[mark].push_back(u);
    visited[u]=1;
    for(int i=0; i<radj[u].size(); i++)
    {
        int v=radj[u][i];
        if(visited[v]==0)
        {
            dfs2(v, mark);
        }
    }
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

    zero(color);

    for(i=1; i<=node; i++)
    {
        if(color[i]==0)
        {
            dfs(i);
        }
    }

    zero(visited);
    int mark=0;
    while(!st.empty())
    {
        int u=st.top();
        st.pop();
        if(visited[u]==0)
        {
            mark+=1;
            dfs2(u,mark);
        }
    }
    cout<<"There are "<<mark<<" component"<<endl;
    for(int i=1; i<=mark; i++)
    {
        for(int j=0; j<result[i].size(); j++)
        {
            cout<<result[i][j]<<" ";
        }
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
