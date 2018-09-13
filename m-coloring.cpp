#include<bits/stdc++.h>
#define n 4
using namespace std;
bool issafe(int v, int graph[n][n], int color[n], int c)
{
    for(int i=0;i<n;i++)
    {
        if(graph[v][i] == 1 && c == color[i] )
            return false;
    }
    return true;
}
bool coloring (int graph[n][n], int m, int color[n], int v)
{
    if(v==n)
        return true;
    for(int c=1;c<=m;c++)
    {
        if(issafe(v,graph,color,c))
            {
                color[v]=c;

                if(coloring (graph, m, color, v+1)==true)
                    return true;
                color[v]=0;
            }
    }
    return false;
}
int main()
{
    int graph[n][n] = {{0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}};
        int m=3;
        int color[n]={0};

        bool flag =coloring (graph, m, color, 0);
        if( flag== false)
        {
            cout<<"solution does not exist \n";
            //return false;
        }
    else
    {
        for(int i=0;i<n;i++)
            cout<<color[i]<<"\n";

        //return true;
    }

}
