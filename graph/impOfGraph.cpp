#include<iostream>
#include<vector>
#include<queue>
using namespace std;
// MAKING FUNCTION FOR BFS
void BFS(int n, vector<int>adj[])
{
    bool isVisited[n];
    for(int i=0;i<n;i++)
    isVisited[i]=false;

    queue<int>q;

    isVisited[0]=true;
    q.push(0);

    while(!q.empty())
    {
        int node =q.front();
        q.pop();
        cout<<node <<" ";
        for(int it:adj[node])
            if(!isVisited[it])
            {
                isVisited[it]=true;
                q.push(it);
            }
    }

}

int main()
{
    int n,m;
    cin>>n>>m;
    //NOW I HAVE TO MAKE THE ADJ LIST (U ----> V)
    vector<int> adj[n];
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    BFS(n,adj);
}