#include<bits/stdc++.h>
using namespace std;

#define  CIN            ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define  ll             long long int
#define  pb             push_back

vector<ll>v1[200005],v3;
ll dfs(ll c,ll p)
{
    ll ans = 1,val;
    for( auto v: v1[c])
    {
        if(v!=p)
        {
            val = dfs(v,c);
            v3.pb(val);
            ans+=val;
        }
    }
    return ans;
}

int main()
{
    CIN;
    ll  a,b,c,i;
    cin >> a ;
    for( i = 0 ; i < a-1 ; i++)
    {
        cin >> b >> c ;
        v1[b].pb(c);
        v1[c].pb(b);
    }
    dfs(1,-1);
    for( i = 0 ; i < a-1 ; i++)
        v3[i]*=(a-v3[i]);
    return 0 ;
}

