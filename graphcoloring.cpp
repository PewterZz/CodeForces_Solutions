/*
The only difference between the easy and the hard version is the constraint on n
.

You are given an undirected complete graph on n
 vertices. A complete graph is a graph where each pair of vertices is connected by an edge. You have to paint the edges of the graph into two colors, red and blue (each edge will have one color).

A set of vertices S
 is red-connected if, for every pair of vertices (v1,v2)
 such that v1∈S
 and v2∈S
, there exists a path from v1
 to v2
 that goes only through red edges and vertices from S
. Similarly, a set of vertices S
 is blue-connected if, for every pair of vertices (v1,v2)
 such that v1∈S
 and v2∈S
, there exists a path from v1
 to v2
 that goes only through blue edges and vertices from S
.

You have to paint the graph in such a way that:

there is at least one red edge;
there is at least one blue edge;
for each set of vertices S
 such that |S|≥2
, S
 is either red-connected or blue-connected, but not both.
Calculate the number of ways to paint the graph, and print it modulo 998244353
.

Input
The first (and only) line contains one integer n
 (3≤n≤5⋅104
).

Output
Print one integer — the number of ways to paint the graph, taken modulo 998244353
.

Examples
inputCopy
3
outputCopy
6
inputCopy
4
outputCopy
50
inputCopy
100
outputCopy
878752271
inputCopy
1337
outputCopy
520628749
inputCopy
42013
outputCopy
906821221
*/

#include<bits/stdc++.h>
using namespace std;
const int N=5e4+5,P=998244353;
 
int n,A[N],B[N],c[N];
 
inline void inc(int &x,int y) { x+=y-P; x+=(x>>31)&P; }
 
int main() {
	cin>>n; 
	A[1]=B[1]=1; c[0]=1;
	for(int i=2;i<=n;i++) {
		for(int j=i-1;j>0;j--) inc(c[j],c[j-1]);		
		for(int j=1;j<i;j++) inc(B[i],1LL*c[j-1]*B[j]%P*A[i-j]%P);
		A[i]=2LL*B[i]%P;
	}
	cout<<(A[n]-2+P)%P<<endl;
	return 0;
}