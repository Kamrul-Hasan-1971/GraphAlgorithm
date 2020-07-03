#include<bits/stdc++.h>
using namespace std;
#define  CIN            ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define  ll             long long int
#define  MX             100005
bool vis[MX];
vector<ll>v1[MX];
ll in[28],out[28];
string s1;

void dfs(ll u)
{
    vis[u]=true;
    for(auto v:v1[u]) if(!vis[v]) dfs(v);
}
int main()
{
    CIN;
    ll  n,i,T,u,v,s;
    cin>> T ;
    while(T--)
    {
        memset(in,0,sizeof in);
        memset(out,0,sizeof out);
        cin >> n;
        for( i =1 ; i<= 26;i++) v1[i].clear();
        for( i = 1 ; i <= n ; i++)
        {
            cin >> s1;
            u=s1[0]-'a'+1;
            v=s1.back()-'a'+1;
            in[v]++;
            out[u]++;
            v1[u].push_back(v);
        }
        ll chk1=0,chk2=0,chk=0;
        for( i = 1 ; i<= 26 ; i++)
        {
            if(abs(in[i]-out[i])>1) chk=1;
            if(in[i]-out[i]==1) chk1++;
            else if(out[i]-in[i]==1) chk2++;
        }
        if(chk1>1||chk2>1) chk=1;
        if(chk==1) goto f;
        for( i = 1 ; i<= 26 ; i++)
        {
            if(v1[i].size())
            {
                dfs(i);
                break;
            }
        }
        for( i = 1 ;i<=26;i++) if(!vis[i]&&v1[i].size()) chk=1;
        f:
        if(chk) cout<<"The door cannot be opened."<<endl;
        else cout<<"Ordering is possible."<<endl;
    }
    return 0 ;
}
