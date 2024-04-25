/* 
After realizing that Zookeeper is just a duck, the animals have overthrown Zookeeper. They now have to decide a new ruler among themselves through a fighting tournament of the following format:

Initially, animal 0
 is king, while everyone else queues up with animal 1
 at the front of the queue and animal n−1
 at the back. The animal at the front of the queue will challenge the king to a fight, and the animal with greater strength will win the fight. The winner will become king, while the loser joins the back of the queue.

An animal who wins 3
 times consecutively will be crowned ruler for the whole zoo. The strength of each animal depends on how many consecutive fights he won. Animal i
 has strength Ai
 with 0
 consecutive win, Bi
 with 1
 consecutive win, and Ci
 with 2
 consecutive wins. Initially, everyone has 0
 consecutive win.

For all animals, Ai>Bi
 and Ci>Bi
. Also, the values of Ai
, Bi
, Ci
 are distinct (all 3n
 values are pairwise different).

In other words, an animal who is not a king has strength Ai
. A king usually has a strength of Bi
 or Ci
. The exception is on the first turn, the first king (animal 0
) has strength Ai
.

Who is the new ruler, and after how many fights? Or will it end up that animals fight forever with no one ending up as ruler?

Input
The first line contains one integer n
 (4≤n≤6000
) — number of the animals.

i
-th of the next n
 lines contains 3
 integers Ai
, Bi
 and Ci
 (0≤Ai,Bi,Ci≤109
).

It is guaranteed that Ai>Bi
 and Ci>Bi
, and that all values of Ai
, Bi
 and Ci
 are distinct.

Output
Output two integers in a single line. The first is the index of the animal that will become ruler, and the second is the number of fights passed until some animal becomes the ruler.

If the animals will fight for infinitely long, output -1 -1 instead.

Examples
inputCopy
4
5 1 2
10 8 11
9 0 3
7 4 6
outputCopy
-1 -1
inputCopy
5
11 7 12
8 6 14
2 1 10
13 0 9
5 3 4
outputCopy
1 7

*/

#include<bits/stdc++.h>
#define For(i,l,r) for(register int i=(l);i<=(r);++i)
#define For_down(i,r,l) for(register int i=(r);i>=(l);--i)
using namespace std;
constexpr int n_MAX=6000+5;
int n,a[n_MAX],b[n_MAX],c[n_MAX],u[n_MAX]; bool w[n_MAX]; int p[n_MAX],q[n_MAX],x[n_MAX<<1],k,y[n_MAX<<1],l,r,skip,beat;
void insert(const int z){x[++k]=z; while((l<=r)&&(b[x[y[r]]]>b[z])) --r; y[++r]=k; if(c[x[k-1]]>a[z]) beat=(k-1);}
void rotate(const int m){rotate(q+1,q+((n-m)-skip)+1,q+(n-m)+1);}
pair<int,long long> simulate(long long sum,const bool prev)
{
	if(prev){if(c[u[1]]>a[u[2]]) return {u[1],sum+1}; rotate(u+1,u+2,u+n+1),++sum;}
	For(i,1,n-1){if(w[i-1]){if(c[u[i-1]]>a[u[i+1]]) return {u[i-1],sum+i}; w[i]=false;} else w[i]=(b[u[i]]>a[u[i+1]]);}
	if(w[n-1]&&(c[u[n-1]]>a[u[w[1]+1]])) return {u[n-1],sum+n};
	int m=0,cur=0; For(i,1,n){if(w[i-1]) p[++m]=i; else q[++cur]=u[i];}
	skip=(n-m),beat=k=0,l=1,r=0; For(i,1,n-m) insert(q[i]);
	For(i,1,m)
	{
		For(j,p[i-1]+1,p[i]-1) insert(u[j]);
		while((l<=r)&&(b[x[y[l]]]<a[u[p[i]]])) skip=min(skip,k-y[l]),++l; if(beat) skip=min(skip,k-beat);
	}
	if(skip==(n-m)) return {-1,-1};
	rotate(m),cur=0; For(i,1,n) if(!w[i-1]) u[i]=q[++cur]; return simulate(sum+((n-1)*skip),w[n-1]);
}
int main()
{
	ios::sync_with_stdio(false),cin.tie(nullptr);
	cin>>n; For(i,0,n-1) cin>>a[i]>>b[i]>>c[i]; iota(u+1,u+n,1); if(a[0]>a[1]) swap(u[1],u[n]);
	const pair<int,long long> ans=simulate(1,false); cout<<ans.first<<' '<<ans.second<<'\n'; return 0;
}