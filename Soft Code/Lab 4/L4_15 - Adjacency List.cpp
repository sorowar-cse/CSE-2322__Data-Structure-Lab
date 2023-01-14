 #include <bits/stdc++.h>
using namespace std;
int main()
{
    int V,x,y,n;
    cin>>V>>n;
    vector<int> adj[V];
    for(int i=0; i<n; i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for (int d = 0; d < V; d++)
    {
        cout << endl << "Vertex " << d << ":";
        {
            for (auto i : adj[d])
                cout << "-> " << i;
            cout << endl;
        }
    }

    return 0;
}
