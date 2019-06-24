#include<bits/stdc++.h>
using namespace std;

#define           CIN              ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define           ll               long long int
#define           ull              unsigned long long int
#define           pii              pair < int, int>
#define           pll              pair < ll, ll>
#define           MOD              1000000007
#define           pb               push_back
#define       min3(a,b,c)          min(a,min(b,c))
#define       min4(a,b,c,d)        min(d,min(a,min(b,c)))
#define       max3(a,b,c)          max(a,max(b,c))
#define       max4(a,b,c,d)        max(d,max(a,max(b,c)))
#define         ms(a,b)            memset(a,b,sizeof(a))
#define           mp               make_pair
#define       gcd(a, b)            __gcd(a,b)
#define       lcm(a, b)            ((a)*(b)/gcd(a,b))
#define         input              freopen("input.txt","rt", stdin)
#define         output             freopen("output.txt","wt", stdout)
#define           PI               2*acos(0.0)

///--------------Graph Moves--------------------------------------
///const int fx[] = {+1,-1,+0,+0};
///const int fy[] = {+0,+0,+1,-1};
///const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
///const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///king's Move
///const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///knight's move
///const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///knight's move
///---------------------------------------------------------------


vector<ll>vec[200];
ll vis[200];
#define white 0
#define blue 2
#define red 1

ll BFS(ll x)
{
    queue<ll>Q;
    Q.push(x);
    vis[x]=red;

    while(!Q.empty())
    {
        ll u=Q.front();
        Q.pop();
        for(ll i=0; i<vec[u].size(); i++)
        {
            int v=vec[u][i];
            if(vis[v]==white)
            {
                if(vis[u]==red)
                {
                    vis[v]=blue;
                }
                else
                {
                    vis[v]=red;
                }
                Q.push(v);
            }
            if(vis[u]==vis[v])
            {
                return 0;
            }
        }
    }
    return 1;

}

int main()
{
    ll node,edge,a,b,p,q,s,i,res;
    cin>>node>>edge;
    for(i=0; i<edge; i++)
    {
        cin>>a>>b;
        vec[a].pb(b);
        vec[b].pb(a);
    }
    cin>>p;
    res=BFS(p);
    if(res)
    {
        cout<<"BICOLOURABLE"<<endl;
    }
    else
    {
        cout<<"NOT BICOLOURABLE"<<endl;
    }
    return 0;

}
