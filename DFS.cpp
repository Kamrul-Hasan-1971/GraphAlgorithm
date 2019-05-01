#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define output freopen("output.txt","wt", stdout)
vector<int>adj[1005];
vector<int>vec;
//vector<int>cost[30005];
int visited[1005];
map<int,int>mp;

void DFS(int s)
{
    int i,d=adj[s].size();
    visited[s]=1;
    mp[s]++;
    for(i=0;i<d;i++){
            int v=adj[s][i];
        if(visited[v]==0){
            DFS(v);
        }
    }
    return;
}


int main()
{
    //output;
    int a,b,d,e,j,k,i,f,cnt=0,c;
    scanf("%d", &a);
    for(i=0; i<a; i++)
    {
        scanf("%d %d %d", &b, &c, &d);

        for(j=0; j<b; j++)
        {
            scanf("%d", &e);
            vec.push_back(e);
        }


        for(k=0;k<d;k++){
            scanf("%d %d", &e, &f);
            adj[e].push_back(f);
        }

        for(e=0;e<b;e++){
            DFS(vec[e]);
            memset(visited,0,sizeof(visited));
        }

        for(e=1;e<=c; e++){
            if(mp[e]==b){
                cnt++;
            }
            //cout<<e<<"---"<<mp[e]<<" "<<b<<endl;
        }
        printf("Case %d: %d\n",i+1,cnt);


        cnt=0;
        for(k=1;k<=c;k++){
            adj[k].clear();
        }
        vec.clear();
        mp.clear();

    }
    return 0;
}
