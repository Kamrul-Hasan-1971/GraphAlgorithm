#include <bits/stdc++.h>
using namespace std;
#define ll long long int
char s[21][21];
bool visited[21][21];
int b,c,cnt=0;

int dx4[]= {-1,0,1,0};
int dy4[]= {0,+1,0,-1};

bool valid(int x, int y)
{
    if(x>=0 && x<b && y>=0 && y<c && s[x][y]!='#' && !visited[x][y])
    {
        return 1;
    }
    return 0;
}


void DFS(int x,int y)
{
    int i;
    visited [x][y]=1;
    cnt++;
    for(i=0; i<=3; i++)
    {
        int xx=x+dx4[i];
        int yy=y+dy4[i];
        if(valid(xx,yy))
        {
            DFS(xx,yy);
        }
    }
}

int main()
{

    int a,i,j,k,f,h;
    cin>>a;
    for(i=0; i<a; i++)
    {
        cnt = 0 ;
        cin>>c>>b;
        memset( visited, 0, sizeof( visited ) ) ;
        for(j=0; j<b; j++)
        {
            cin>>s[j] ;
            for(k=0; k<c; k++)
            {
                if(s[j][k]=='@')
                {
                    f=j;
                    h=k;
                }
            }
        }
        DFS(f,h);
        printf("Case %d: %d\n", i+1,cnt);
    }
}
