/*
This is the easy version of the problem. The only difference is that in this version, ai≤106
.

For a given sequence of n
 integers a
, a triple (i,j,k)
 is called magic if:

1≤i,j,k≤n
.
i
, j
, k
 are pairwise distinct.
there exists a positive integer b
 such that ai⋅b=aj
 and aj⋅b=ak
.
Kolya received a sequence of integers a
 as a gift and now wants to count the number of magic triples for it. Help him with this task!

Note that there are no constraints on the order of integers i
, j
 and k
.

Input
The first line contains a single integer t
 (1≤t≤104
) — the number of test cases. The description of the test cases follows.

The first line of the test case contains a single integer n
 (3≤n≤2⋅105
) — the length of the sequence.

The second line of the test contains n
 integers a1,a2,a3,…,an
 (1≤ai≤106
) — the elements of the sequence a
.

The sum of n
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output a single integer — the number of magic triples for the sequence a
.

Example
inputCopy
7
5
1 7 7 2 7
3
6 2 18
9
1 2 3 4 5 6 7 8 9
4
1000 993 986 179
7
1 10 100 1000 10000 100000 1000000
8
1 1 2 2 4 4 8 8
9
1 1 1 2 2 2 4 4 4
outputCopy
6
1
3
0
9
16
45
Note
In the first example, there are 6
 magic triples for the sequence a
 — (2,3,5)
, (2,5,3)
, (3,2,5)
, (3,5,2)
, (5,2,3)
, (5,3,2)
.

In the second example, there is a single magic triple for the sequence a
 — (2,1,3)
.
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;
int c[(int)1e6+1];
int main(){
	int t;cin>>t;
	while(t--){
		int n;cin>>n;int a[n];
		ll ans=0;
		for(int i=0;i<n;i++){cin>>a[i];c[a[i]]++;}
		for(int i=0;i<n;i++){
			ans+=(ll)(c[a[i]]-1)*(c[a[i]]-2);
			for(int b=2;a[i]*b*b<=1e6;b++)ans+=(ll)c[a[i]*b]*c[a[i]*b*b];
		}
		cout<<ans<<"\n";
		for(int i=0;i<n;i++)c[a[i]]--;
	}
}