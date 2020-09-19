#include<bits/stdc++.h>
using namespace std;

#define  CIN            ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define  ll             long long int
#define  pb             push_back

vector<ll>v1[100005];
ll lvl[100005],mx;
ll dfs(ll u,ll par)
{
    ll len = 0 ;
    for( auto v: v1[u])
    {
        if(v!=par)
        {
            lvl[v]=lvl[u]+1;
            ll under = dfs(v,u)+1;
            mx = max(mx,len+under);
            len = max(len,under);
        }
    }
    return len;
}

int main()
{
    CIN;
    ll  a,b,da,db,c,d,i,n,T;
    cin>> T ;
    while(T--)
    {
        cin >> n >> a >> b >> da >> db;
        for( i = 1 ; i <= n ; i++) {v1[i].clear();lvl[i]=0;}
        ll ck=0;
        for( i = 0 ; i < n-1 ; i++)
        {
            cin >> c >> d ;
            v1[c].pb(d);
            v1[d].pb(c);
        }
        mx=0;
        dfs(a,-1);
        if(lvl[b]<=da || min(mx,db)<=da+da){
            cout<<"Alice"<<endl;
        }
        else cout<<"Bob"<<endl;
    }
    return 0 ;
}

