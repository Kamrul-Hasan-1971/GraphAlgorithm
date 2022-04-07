class Solution
{
public:
    bool cycleDirected(int v,vector<int>v1[], int color[])
    {
        color[v] = 1;
        for(int w : v1[v])
        {
            if(color[w] == 1) return true;
            if(color[w] == 0 && cycle(w,v1,color)) return true;
        }
        color[v] = 2;
        return false;
    }

    bool cycleUnDirected(int v,int parent,vector<int>v1[], int color[])
    {
        color[v] = 1;
        for(int w : v1[v])
        {
            if(w == parent) continue;
            if(color[w]) return true;
            if(cycle(w,v,v1,color)) return true;
        }
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        vector<int>v1[numCourses+1];
        int color[numCourses];
        for(int i = 0 ; i< numCourses; i++)color[i]=0;
        bool ck=0;
        for(auto x : prerequisites ) v1[x[0]].push_back(x[1]);
        for( int i = 0 ; i <numCourses ; i++ )
            if(color[i]==0 && cycle(i,v1,color)) return false; // directed
            if(color[i]==0 && cycle(i,-1,v1,color)) return false; //undirected
        return true;
    }
};
