/*
You are given a string s
, consisting of lowercase English letters. In one operation, you are allowed to swap any two characters of the string s
.

A string s
 of length n
 is called an anti-palindrome, if s[i]≠s[n−i+1]
 for every i
 (1≤i≤n
). For example, the strings "codeforces", "string" are anti-palindromes, but the strings "abacaba", "abc", "test" are not.

Determine the minimum number of operations required to make the string s
 an anti-palindrome, or output −1
, if this is not possible.

Input
The first line contains a single integer t
 (1≤t≤104
) — the number of test cases. The description of the test cases follows.

Each test case consists of two lines. The first line contains a single integer n
 (1≤n≤2⋅105
) — the length of the string s
.

The second line contains the string s
, consisting of n
 lowercase English letters.

The sum of n
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output a single integer — the minimum number of operations required to make the string s
 an anti-palindrome, or −1
 if this is not possible.

Example
inputCopy
10
10
codeforces
3
abc
10
taarrrataa
10
dcbdbdcccc
4
wwww
12
cabbaccabaac
10
aadaaaaddc
14
aacdaaaacadcdc
6
abccba
12
dcbcaebacccd
outputCopy
0
-1
1
1
-1
3
-1
2
2
2
Note
In the first test case, the string "codeforces" is already an anti-palindrome, so the answer is 0
.

In the second test case, it can be shown that the string "abc" cannot be transformed into an anti-palindrome by performing the allowed operations, so the answer is −1
.

In the third test case, it is enough to swap the second and the fifth characters of the string "taarrrataa", and the new string "trararataa" will be an anti-palindrome, so the answer is 1
.
*/

#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
int t, n; cin >> t; while (t--) {
vector<int> F(26), G(26);
string s;
cin>>n>>s;
int a {-1}, p {};
for (int i{}; i<n; ++i) {
char c {s[i]};
F[c-'a']++;
if (s[i]==s[n-1-i]) {G[c-'a']++; p++;}
}
int M {ranges::max(G)};
if (!(n&1) and 2*ranges::max(F)<=n) a = 2*M>p ? M/2 : (p+2)/4;
cout<<a<<'\n';
}
}