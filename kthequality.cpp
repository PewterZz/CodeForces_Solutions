/*
Consider all equalities of form a+b=c
, where a
 has A
 digits, b
 has B
 digits, and c
 has C
 digits. All the numbers are positive integers and are written without leading zeroes. Find the k
-th lexicographically smallest equality when written as a string like above or determine that it does not exist.

For example, the first three equalities satisfying A=1
, B=1
, C=2
 are

1+9=10
,
2+8=10
,
2+9=11
.
An equality s
 is lexicographically smaller than an equality t
 with the same lengths of the numbers if and only if the following holds:

in the first position where s
 and t
 differ, the equality s
 has a smaller digit than the corresponding digit in t
.
Input
Each test contains multiple test cases. The first line of input contains a single integer t
 (1≤t≤103
) — the number of test cases. The description of test cases follows.

The first line of each test case contains integers A
, B
, C
, k
 (1≤A,B,C≤6
, 1≤k≤1012
).

Each input file has at most 5
 test cases which do not satisfy A,B,C≤3
.

Output
For each test case, if there are strictly less than k
 valid equalities, output −1
.

Otherwise, output the k
-th equality as a string of form a+b=c
.

Example
inputCopy
7
1 1 1 9
2 2 3 1
2 2 1 1
1 5 6 42
1 6 6 10000000
5 5 6 3031568815
6 6 6 1000000000000
outputCopy
2 + 1 = 3
10 + 90 = 100
-1
9 + 99996 = 100005
-1
78506 + 28543 = 107049
-1
Note
In the first test case, the first 9
 solutions are: ⟨1,1,2⟩,⟨1,2,3⟩,⟨1,3,4⟩,⟨1,4,5⟩,⟨1,5,6⟩,⟨1,6,7⟩,⟨1,7,8⟩,⟨1,8,9⟩,⟨2,1,3⟩
.

Int the third test case, there are no solutions as the smallest possible values for a
 and b
 are larger than the maximal possible value of c
 — 10+10=20>9
.

Please note that whitespaces in the output matter.

*/

#include<bits/stdc++.h>
using namespace std;
const int f[7]={1,10,100,1000,10000,100000,1000000};
int t,a,b,c;
long long n;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>a>>b>>c>>n; 
		for(int i=f[a-1];i<f[a];i++)
		{
			int l=max(f[b-1],f[c-1]-i),r=min(f[b],f[c]-i);
			if(r-l<n)
			{
				n-=max(0,r-l);
				continue;
			}
			printf("%d + %lld = %lld\n",i,l+n-1,l+n-1+i);
			n=0;
			break;
		}
		if(n)
			cout<<-1<<endl;
	}
}