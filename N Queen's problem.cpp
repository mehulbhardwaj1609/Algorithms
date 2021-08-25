#include <iostream>
#include <cstdlib>
using namespace std;
const int MAX = 10;
int SolnCount =0;
void fnChessBoardShow(int n, int row[MAX]);
bool fnCheckPlace(int KthQueen, int ColNum, int row[MAX]);
int NQueen(int k,int n, int row[MAX]);
int main(void)
{
int n;
int row[MAX];
cout << "Enter the number of queens : ";
cin >> n;

if (!NQueen(0,n,row))
cout << "No solution exists for the given problem instance." <<endl;
else
cout << "Number of solution for the given problem instance is : "<< SolnCount << endl;
return 0;
}
int NQueen(int k,int n, int row[MAX])
{
static int flag;
for(int i=0; i<n; i++)
{
if(fnCheckPlace(k,i,row) == true)
{
row[k] = i;
if(k == n-1)
{
fnChessBoardShow(n,row);
SolnCount++;
flag = 1;
return flag;
}
NQueen(k+1, n, row);
}
}
return flag;
}
bool fnCheckPlace(int KthQueen, int ColNum, int row[MAX])
{
for(int i=0; i<KthQueen; i++)
{
if(row[i] == ColNum || abs(row[i]-ColNum) == abs(i-KthQueen))
return false;
}
return true;
}
void fnChessBoardShow(int n, int row[MAX])
{
cout << "\nSolution #" << SolnCount+1 << endl << endl;
for (int i=0; i<n; i++)
{
for (int j=0; j<n; j++)
{
if (j == row[i])
cout << "Q ";
else
cout << "# ";
}
cout << endl;
}
cout << endl;
}
