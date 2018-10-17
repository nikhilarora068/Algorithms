#include <bits/stdc++.h>
using namespace std;
int V, graph[100][100];
bool safe(int v, int path[], int pos)
{
    // If it is adjacent to prev included vertex
    if (!graph[path[pos - 1]][v])
        return false;
    // Check if it already included
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;
    return true;
}
int hamcycle(int path[], int pos)
{
    // If all vertices are included and if there is a path
    // from last included vertex to 1st vertex,return 1
    if (pos == V && graph[path[pos - 1]][path[0]])
        return 1;
    // Try other vertices to add in path
    for (int v = 1; v < V; v++)
    {
        if (safe(v, path, pos))
        {
            path[pos] = v;
            if (hamcycle(path, pos + 1))
                return 1;
            path[pos] = -1;
        }
    }
    return 0;
}
int main()
{
    int i, j;
    cout << "Enter number of Vertices: \n";
    cin >> V;
    int path[V];
    cout << "Enter Adjacency Matrix: \n";
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            cin >> graph[i][j];
    memset(path, -1, sizeof(path));
    path[0] = 0;
    if (!hamcycle(path, 1))
        cout << "No solution \n";
    else
    {
        cout << "One possible solution is: \n";
        for (i = 0; i < V; i++)
            cout << path[i] << " ";
        cout << path[0] << endl;
    }
}

