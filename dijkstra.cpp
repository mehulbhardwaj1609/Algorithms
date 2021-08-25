#include <iostream> 
#include <cstdio> 
using namespace std; 
const int MAXNODES = 10,INF = 9999; 
void fnDijkstra(int [][MAXNODES], int [], int [], int[], int, int, int); 

int main(void) 
{ 
 int n,cost[MAXNODES]
[MAXNODES],dist[MAXNODES],visited[MAXNODES],path[MAXNODES],i,j,source,dest; 
 cout << "\nEnter the number of nodes\n"; 
 cin >> n; 
 cout << "Enter the Cost Matrix\n" << endl; 
 for (i=0;i<n;i++) 
 for (j=0;j<n;j++) 
 cin >> cost[i][j]; 
// cout << "Enter the Source vertex" << endl; 
// cin >> source; 
// cout << "Enter the Destination vertex" << endl; 
// cin >> dest; 
 for (source = 0; source < n; source++) 
 { 
getchar(); 
cout << "\n//For Source Vertex : " << source << " shortest path to other vertices//"<< endl; 
 for (dest=0; dest < n; dest++) 
 { 
 fnDijkstra(cost,dist,path,visited,source,dest,n); 
 if (dist[dest] == INF) 
 cout << dest << " not reachable" << endl; 
 else 
 { 
 cout << endl; 
 i = dest; 
do 
 { 

 cout << i << "<--"; 
 i = path[i]; 
 }while (i!= source); 
 cout << i << " = " << dist[dest] << endl; 
 } 
 } 
cout << "Press Enter to continue..."; 
 } 
 return 0; 
} 

void fnDijkstra(int c[MAXNODES][MAXNODES], int d[MAXNODES], int p[MAXNODES], 
int s[MAXNODES], int so, int de, int n) 
{ 
 int i,j,a,b,min; 
 for (i=0;i<n;i++) 
 { 
 s[i] = 0; 
 d[i] = c[so][i]; 
 p[i] = so; 
 } 
 s[so] = 1; 
 for (i=1;i<n;i++) 
 { 
 min = INF; 
 a = -1; 
 for (j=0;j<n;j++) 
 { 
 if (s[j] == 0) 
 { 
 if (d[j] < min) 
 { 
 min = d[j]; 
 a = j; 
 } 
 } 
 } 
 if (a == -1) return; 
 s[a] = 1; 
 if (a == de) return; 

 for (b=0;b<n;b++) 
 { 
 if (s[b] == 0) 
 { 
 if (d[a] + c[a][b] < d[b]) 
 { 
 d[b] = d[a] + c[a][b]; 
 p[b] = a; 
 } 
 } 
 } 
 } 
}
