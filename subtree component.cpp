#include<bits/stdc++.h>
using namespace std;

#define  CIN            ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define  ll             long long int
#define  pb             push_back
#define  pii            pair < ll, ll>
#define  all(a)         a.begin(),a.end()
#define  rall(a)        a.rbegin(),a.rend()
#define  ff             first
#define  ss             second

vector<ll>v1[100005];
vector<pii>v2;
ll cnt,start[100005],finish[100005];

ll a,under[100005];

/*void dfs(ll u,ll p)
{
    under[u]=1;
    ll ret =0;
    for( auto v: v1[u]){
        if(v!=p)
        {
            dfs(v,u);
            under[u]+=under[v];
            ret=max(under[v],ret);
        }
    }
    ret=max(ret,a-under[u]);
    v2.pb({ret,u});
}*/

void dfs(ll u,ll p)
{
    start[u]=++cnt;
    for( auto v: v1[u]) if(v!=p) dfs(v,u);
    finish[u]=cnt;
}

int main()
{
    CIN;
    ll  b,c,d,e,f=0,i,T;
    cin>> T ;
    while(T--)
    {
        cnt=0;
        v2.clear();
        cin>>a;
        for( i = 0 ; i <= a ; i++) v1[i].clear();
        for( i = 0 ; i < a-1 ; i++)
        {
            cin >> b >> c ;
            v1[b].pb(c);
            v1[c].pb(b);
        }
        dfs(1,-1);
        for( i = 1 ; i<= a ; i++)
        {
            ll p = finish[i]-start[i]+1,ans=0;
            for( auto x : v1[i] )
            {
                ll q = finish[x]-start[x]+1;
                if(start[x]<start[i]) ans=max(a-p,ans);
                else ans=max(ans,q);
            }
            v2.pb({ans,i});
        }
    }
    return 0 ;
}


