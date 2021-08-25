#include <iostream>
#include <cstdlib>
using namespace std;
const int MAX = 100;
void fnDepthFirstSearch(int currentVertex, int v[MAX], int g[MAX][MAX], int n);

int main(void) 
{
int i,j,k; 
      int visited[MAX];
      int graph[MAX][MAX];
      int numVert, Vert;
      cout << "Enter the number of vertices : ";
      cin >> numVert;
      for (i=0; i<numVert; i++)
            visited[i] = 0;
      cout << "Enter the adjacency matrix :\n";
      for (i=0; i<numVert; i++)
            for (j=0; j<numVert; j++)
                  cin >> graph[i][j];
      cout << "Enter the source vertex : ";
      cin >> Vert;
      cout<<"The DFS traversal:";
      
    fnDepthFirstSearch(Vert-1,visited,graph,numVert);
    for (k=0; k<numVert; k++)
    {
        if(visited[k])
        {
            cout << "\nVertex " << k+1 << " reachable " << endl;
        }
else { 
            cout << "\nVertex " << k+1 << " not reachable " << endl;
        }
} 
return 0; 
} 

void fnDepthFirstSearch(int currentVertex, int v[MAX], int g[MAX][MAX], int n)
{
      int i;
      v[currentVertex] = 1;
      for (i=0; i<n; i++)
if (g[currentVertex][i] && !v[i])
      fnDepthFirstSearch(i,v,g,n);
      cout<<currentVertex+1<<" ";
}
