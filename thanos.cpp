/* 
  * There is an array a
 of size 2k
 for some positive integer k
, which is initially a permutation of values from 1
 to 2k
. Alice and Bob play the following game on the array a
. First, a value t
 between 1
 and k
 is shown to both Alice and Bob. Then, for exactly t
 turns, the following happens:

Alice either does nothing, or chooses two distinct elements of the array a
 and swaps them.
Bob chooses either the left half or the right half of the array a
 and erases it.
The score of the game is defined as the maximum value in a
 after all t
 turns have been played. Alice wants to maximize this score, while Bob wants to minimize it.

You need to output k
 numbers: the score of the game if both Alice and Bob play optimally for t
 from 1
 to k
.

Input
Each test contains multiple test cases. The first line contains an integer t
 (1≤t≤104
) — the number of test cases. The description of the test cases follows.

The first line of each test case contains an integer k
 (1≤k≤20
) — the parameter of the size of a
.

The second line of each test case contains 2k
 integers a1,a2,…,a2k
 (1≤ai≤2k
, ai
's are pairwise distinct) — the given array a
.

It is guaranteed that the sum of 2k
 over all test cases does not exceed 220
.

Output
For each test case, print k
 numbers, where the i
-th number is the score of the game if both Alice and Bob play optimally for t=i
. 
  */
#include<bits/stdc++.h>
using namespace std;
int n,a[1<<20];
#define pi pair<int,int>
#define F first
#define S second
#define mp make_pair
int mid,le;
pi calc(int l,int r){
	if(r-l+1<=le){
		int e=0;
		for(int j=l;j<=r;j++)e+=(a[j]>=mid);
		if(e)return mp(e-1,0);return mp(0,1);
	}
	int m=(l+r)>>1;
	pi f=calc(l,m),f_=calc(m+1,r);f.F+=f_.F,f.S+=f_.S;
	if(f.F&&f.S)f.F--,f.S--;
	return f;
}
void sol(){
	scanf("%d",&n);for(int i=0;i<(1<<n);i++)
	scanf("%d",&a[i]);
	for(int t=1;t<=n;t++){
		le=(1<<(n-t));
		int l=1,r=(1<<n),ans=-1;
		while(l<=r){
			mid=(l+r)>>1;
			if(calc(0,(1<<n)-1).S==0)ans=mid,l=mid+1;
			else r=mid-1;
		}
		printf("%d ",ans);
	}
	puts("");
}
int main(){
	int T;scanf("%d",&T);while(T--)sol();
	return 0;
}
