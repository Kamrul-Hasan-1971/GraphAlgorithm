void cycle(int v,vector<int>v1[],bool &ck,int color[])
{
    color[v] = 1;
    for(int w : v1[v])
    {
        if(color[w] == 1) ck=1;
        if(ck) return ;
        if(color[w] == 0) cycle(w,v1,ck,color);
    }
    color[v] = 2;
}
bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
{
    vector<int>v1[numCourses+1];
    int color[numCourses];
    for(int i = 0 ; i< numCourses; i++)color[i]=0;
    bool ck=0;
    for(auto x : prerequisites ) v1[x[0]].push_back(x[1]);
    for( int i = 0 ; i <numCourses ; i++ )
    {
        if(color[i]==0)
        {
            cycle(i,v1,ck,color);
            if(ck) return false;
        }
    }
    return true;
}
