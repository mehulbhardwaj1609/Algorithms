#include <iostream> 
#include <cstdlib> 
using namespace std; 
const int MAX = 10; 
inline int max(int a, int b); 
void fnProfitTable(int w[MAX], int p[MAX], int n, int c, int t[MAX][MAX]); 
void fnSelectItems(int n,int c, int t[MAX][MAX], int w[MAX], int l[MAX]);
int main(void) 
{ 
int i, j, totalProfit; 
int weight[MAX]; 
int profit[MAX]; 
int capacity; 
int num; 
int loaded[MAX]; 
int table[MAX][MAX]; 
cout << "Enter the maxium number of objects : "; 
cin >> num; 
cout << "Enter the weights : \n"; 
for (i=1; i<=num; i++) 
{ 
 cout << "\nWeight " << i << ": "; 
cin >> weight[i]; 
 } 
cout << "\nEnter the profits : \n"; 
for (i=1; i<=num; i++) 
{ 
 cout << "\nProfit " << i << ": "; 
cin >> profit[i]; 
 } 
cout << "\nEnter the maximum capacity : "; 
cin >> capacity; 
totalProfit = 0; 
for( i=1; i<=num; i++) 
loaded[i] = 0; 
fnProfitTable(weight,profit,num,capacity,table); 
fnSelectItems(num,capacity,table,weight,loaded); 
cout << "Profit Matrix\n"; 
for (i=0; i<=num; i++) 
{ 
 for(j=0; j<=capacity; j++) 
 { 
 cout <<"\t"<<table[i][j]; 
 } 
 cout << endl; 
} 
cout << "\nItem numbers which are loaded : \n{ "; 
for (i=1; i<=num; i++) 
{ 
if (loaded[i]) 
{ 
cout << i << " "; 
totalProfit += profit[i]; 
} 
} 
cout << "}" << endl; 
cout << "\nTotal Profit : " << totalProfit << endl; 
return 0; 
} 
inline int max(int a, int b) 
{ 
return a>b ? a : b; 
} 
void fnProfitTable(int w[MAX], int p[MAX], int n, int c, int t[MAX][MAX]) 
{ 
int i,j; 
for (j=0; j<=c; j++) 
t[0][j] = 0; 
for (i=0; i<=n; i++) 
t[i][0] = 0; 
for (i=1; i<=n; i++) 
{ 
for (j=1; j<=c; j++) 
{ 
if (j-w[i] < 0) 
t[i][j] = t[i-1][j]; 
else 
t[i][j] = max( t[i-1][j], p[i] + t[i-1][j-w[i]]);
} 
} 
}
void fnSelectItems(int n,int c, int t[MAX][MAX], int w[MAX], int l[MAX]) 
{ 
int i,j; 
i = n; 
j = c; 
while (i >= 1 && j >= 1) 
{ 
if (t[i][j] != t[i-1][j]) 
{ 
l[i] = 1; 
j = j - w[i]; 
i--; 
} 
else 
i--; 
} 
}
