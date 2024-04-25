/*
You are given an array a
 of n
 integers, where all elements ai
 lie in the range [1,k]
. How many different arrays b
 of m
 integers, where all elements bi
 lie in the range [1,k]
, contain a
 as a subsequence? Two arrays are considered different if they differ in at least one position.

A sequence x
 is a subsequence of a sequence y
 if x
 can be obtained from y
 by the deletion of several (possibly, zero or all) elements.

Since the answer may be large, print it modulo 109+7
.

Input
The first line of the input contains a single integer t
 (1≤t≤104
) — the number of test cases. The description of the test cases follows.

The first line of each test case contains three integers n
, m
, k
 (1≤n≤2⋅105
, n≤m≤109
, 1≤k≤109
) — the size of a
, the size of b
, and the maximum value allowed in the arrays, respectively.

The next line of each test case contains n
 integers a1,a2,…an
 (1≤ai≤k
) — the elements of the array a
.

It is guaranteed that the sum of n
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output a single integer — the number of suitable arrays b
, modulo 109+7
.

Example
inputCopy
7
1 1000000 1
1
3 4 3
1 2 2
5 7 8
1 2 3 4 1
6 6 18
18 2 2 5 2 16
1 10 2
1
8 10 1234567
1 1 2 1 2 2 2 1
5 1000000000 1000000000
525785549 816356460 108064697 194447117 725595511
outputCopy
1
9
1079
1
1023
906241579
232432822
Note
For the first example, since k=1
, there is only one array of size m
 consisting of the integers [1,k]
. This array ([1,1,…,1]
) contains the original array as a subsequence, so the answer is 1.

For the second example, the 9
 arrays are [1,1,2,2]
, [1,2,1,2]
, [1,2,2,1]
, [1,2,2,2]
, [1,2,2,3]
, [1,2,3,2]
, [1,3,2,2]
, [2,1,2,2]
, [3,1,2,2]
.

For the fourth example, since m=n
, the only array of size m
 that contains a
 as a subsequence is a
 itself.

*/

#include<bits/stdc++.h>
using namespace std;
#define int long long
int _,x,n,m,k,A,p,O=1e9+7;
int Q(int x,int y){
	int z=1;
	for(;y;y/=2,x=x*x%O)
		if(y&1)
			z=z*x%O;
	return z;
}
void T(){
	cin>>n>>m>>k,A=Q(k,m),p=1;
	for(int i=1;i<=n;i++)
		cin>>x;
	for(int i=0;i<n;i++)
		(A-=p*Q(k-1,m-i))%=O,p=p*(m-i)%O*Q(i+1,O-2)%O;
	cout<<(A+O)%O<<'\n';
}
signed main(){
	for(cin>>_;_--;)
		T();
}