//Nene is training her team as a basketball coach. Nene's team consists of n
//  players, numbered from 1
//  to n
// . The i
// -th player has an arm interval [li,ri]
// . Two players i
//  and j
//  (i≠j
// ) can pass the ball to each other if and only if |i−j|∈[li+lj,ri+rj]
//  (here, |x|
//  denotes the absolute value of x
// ).

// Nene wants to test the cooperation ability of these players. In order to do this, she will hold several rounds of assessment.

// In each round, Nene will select a sequence of players p1,p2,…,pm
//  such that players pi
//  and pi+1
//  can pass the ball to each other for all 1≤i<m
// . The length of the sequence m
//  can be chosen by Nene. Each player can appear in the sequence p1,p2,…,pm
//  multiple times or not appear in it at all.
// Then, Nene will throw a ball to player p1
// , player p1
//  will pass the ball to player p2
//  and so on... Player pm
//  will throw a ball away from the basketball court so it can no longer be used.
// As a coach, Nene wants each of n
//  players to appear in at least one round of assessment. Since Nene has to go on a date after school, Nene wants you to calculate the minimum number of rounds of assessment needed to complete the task.

// Input
// Each test contains multiple test cases. The first line contains the number of test cases t
//  (1≤t≤2⋅105
// ). The description of test cases follows.

// The first line contains a single integer n
//  (1≤n≤2⋅106
// ) — the number of players.

// The i
// -th of the next n
//  lines contains two integers li
//  and ri
//  (1≤li≤ri≤n
// ) — the arm interval of the i
// -th player.

// It is guaranteed that the sum of n
//  over all test cases does not exceed 2⋅106
// .

// Output
// For each test case, output one integer — the minimum number of rounds of assessment Nene needs to complete her work.

// Example
// inputCopy
// 5
// 2
// 1 1
// 1 1
// 2
// 1 1
// 2 2
// 3
// 1 3
// 1 3
// 1 3
// 5
// 1 1
// 2 2
// 1 5
// 2 2
// 1 1
// 6
// 1 2
// 5 5
// 2 3
// 2 3
// 2 2
// 1 2
// outputCopy
// 2
// 2
// 2
// 1
// 3

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define N 4000000
int i,j,k,n,m,t,res,x[N+5],y[N+5];
int dfn[N+N+5],f[N+N+5],idx[N+N+5];
int fa[N+5];
 
inline int find(int x){return (fa[x]==x)?x:fa[x]=find(fa[x]);}
inline void hb(int x,int y){fa[find(y)]=find(x);}
 
void add(int T,int x,int y,int id){
	for(;x<=N+N;x+=(-x&x)){
		if(dfn[x]!=T)f[x]=-1e9,idx[x]=-1;
		dfn[x]=T;
		if(y>=f[x]){f[x]=y; idx[x]=id;}
	}
}
void get(int T,int x,int y,int id){
	for(;x;x-=(-x&x)){
		if(dfn[x]!=T)f[x]=-1e9;
		dfn[x]=T;
		if(y+f[x]>=0)hb(id,idx[x]);
	}
}
 
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>t;
	for(int T=1;T<=t;T++){
		cin>>n; res=0;
		for(i=1;i<=n;i++)fa[i]=i,cin>>x[i]>>y[i];
		for(i=1;i<=n;i++){
			get(T*2,-(x[i]-i)+N,y[i]-i,i);
			add(T*2,x[i]+i+N,y[i]+i,i);
		}
		for(i=n;i>=1;i--){
			get(2*T+1,-(x[i]+i)+N,y[i]+i,i);
			add(2*T+1,x[i]-i+N,y[i]-i,i);
		}
		for(i=1;i<=n;i++)if(find(i)==i)res++;
		cout<<res<<'\n';
	}
}