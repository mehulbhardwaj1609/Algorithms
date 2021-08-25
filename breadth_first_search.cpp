#include <iostream>
#include <cstdlib>
using namespace std;
const int MAX = 100;
void fnBreadthFirstSearchReach(int vertex, int g[MAX][MAX], int v[MAX], int n);
class Queue
{
private:
int cQueue[MAX];
int front, rear;
public:
Queue();
~Queue();
int enqueue(int data);
int dequeue();
int empty() { return front == -1 ? 1 : 0; };
};

int main(void)
{
int i,j;
int graph[MAX][MAX];
int visited[MAX];
int numVert;
int startVert;
cout << "Enter the number of vertices : ";
cin >> numVert;
cout << "Enter the adjacency matrix :\n";
for (i=0; i<numVert; i++)
visited[i] = 0;
for (i=0; i<numVert; i++)
for (j=0; j<numVert; j++)
cin >> graph[i][j];
cout << "Enter the starting vertex : ";
cin >> startVert;
cout<<"The BFS traversal:";
fnBreadthFirstSearchReach(startVert-1,graph,visited,numVert);
cout << "\nVertices which can be reached from vertex " << startVert << "are :-" << endl;
for (i=0; i<numVert; i++)
if (visited[i])
cout << i+1 << ", ";
cout << endl;
return 0;
}

Queue::Queue()
{
front = rear = -1;
}

Queue::~Queue()
{
}

int Queue::enqueue(int data)
{
if (front == (rear+1)%MAX)
return 0;
if (rear == -1)
front = rear = 0;
else
rear = (rear+1)%MAX;
cQueue[rear] = data;
return 1;
}

int Queue::dequeue()
{
int data;
if (front == -1)
return -1;
data = cQueue[front];
if (front == rear)
front = rear = -1;

else
front = (front+1)%MAX;
return data;
}

void fnBreadthFirstSearchReach(int vertex, int g[MAX][MAX], int v[MAX], int n)
{
Queue verticesVisited;
int frontVertex;
int i;
v[vertex] = 1;
verticesVisited.enqueue(vertex);
while (!verticesVisited.empty())
{
frontVertex = verticesVisited.dequeue();
cout<<frontVertex+1<<" ";
for (i=0; i<n; i++)
{
if (g[frontVertex][i] && !v[i])
{
v[i] = 1;
verticesVisited.enqueue(i);
}
}
}
}
