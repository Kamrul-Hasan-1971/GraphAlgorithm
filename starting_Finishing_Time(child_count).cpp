#include<bits/stdc++.h>
using namespace std;
#define  CIN            ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define  ll             long long int
#define  pb             push_back
#define  rall(v)        v.rbegin(),v.rend()
vector<ll>v1[200005],v2;
ll level[200005],start[200005],finish[200005],cnt;
void dfs(ll x, ll parent , ll lev)
{
    start[x]=++cnt;
    level[x]=lev;
    ll i , sz = v1[x].size();
    for( i = 0 ; i < sz ; i++)
    {
        ll y = v1[x][i];
        if(y==parent) continue;
        dfs(y,x,lev+1);
    }
    finish[x]=++cnt;
}
int main()
{
    CIN;
    ll  n,k,i,a,b,sum=0;
    cin >> n >> k ;
    for( i = 1 ; i<=n-1 ; i++ )
    {
        cin >> a >> b ;
        v1[a].pb(b);
        v1[b].pb(a);
    }
    dfs(1,0,0);
    for( i= 1 ; i<= n ; i++) v2.pb(level[i]-(finish[i]-start[i])/2ll);
    sort(rall(v2));
    for( i = 0 ; i < k ; i++) sum+=v2[i];
    cout<<sum<<endl;
    return 0 ;
}
//https://codeforces.com/contest/1337/problem/C
