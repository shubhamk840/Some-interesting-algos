#include <iostream>
#include <iosfwd>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cassert>
#include <cctype>
#include <climits>
#include <vector>
#include <bitset>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <deque>
#include <string>
#include <list>
#include <iterator>
#include <sstream>
#include <complex>
#include <fstream>
#include <functional>
#include <numeric>
#include <utility>
#include <algorithm>
#include <assert.h>
#include <unordered_map>
using namespace std;
// I hope you understand what i have coded :D , All the best
// shubhamk840@gmail.com
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);
#define endl '\n'
#define stackofi stack<int>
#define queueofi queue<int>  
#define vectoriterator vector<int>::iterator
#define mapiterator map<int,int>::iterator
#define setiterator set<int>:: iterator
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define MOD 1000000007
// macros for inputting 1-D and 2-D array.
#define stringiterator string:: iterator
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
#define ai(arr,n) for(int i=0;i<n;i++)cin>>arr[i];
#define ao(arr) for(auto wtf:arr) cout<<wtf<<" ";
#define mi(arr,m,n) for(int i=0;i<m;i++){ for(int j=0;j<n;j++) cin>>arr[i][j];}
#define mo(arr,m,n) for(int i=0;i<m;i++){ for(int j=0;j<n;j++) cout<<arr[i][j]<<" "; cout<<endl;}
#define countsetbits(x) __builtin_popcount(x)
#define ll long long
#define debugger cout<<"I AM EXECUTING"<<endl
#define F first
#define S second
#define testcases int asdf; cin>>asdf; while(asdf--)
#define space cout<<endl
#define vi vector<int>
#define si set<int>
#define vc vector<char>
#define sc set<char>
#define vll vector<long long int>
#define vs vector<string>

string sconvert(int n)
{
	stringstream ss;
	ss<<n;
	string str = ss.str();
	return str;
}
bool sortbysec(const pair<int,int> &a, 
              const pair<int,int> &b) 
{ 
    return (a.second > b.second); 
}
template<typename KeyType, typename ValueType>  // for finding max element in the map.
std::pair<KeyType,ValueType> get_max( const std::map<KeyType,ValueType>& x ) {
  using pairtype=std::pair<KeyType,ValueType>; 
  return *std::max_element(x.begin(), x.end(), [] (const pairtype & p1, const pairtype & p2) {
        return p1.second < p2.second;
  }); 
}

int add(int a, int b, int mod = MOD) {
    if (a + b >= mod) {
        return a + b - mod;
    }
    return a + b;
}
 
int sub(int a, int b, int mod = MOD) {
    if (a - b < 0) {
        return a - b + mod;
    }
    return a - b;
}
 
int mul(int a, int b, int mod = MOD) {
    return (int)(1ll * a * b % mod);
}


int  single()
{
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
	cin>>arr[i];
	vector<int> dp(n,0);
	dp[0] = arr[0];
	for(int i=1;i<n;i++)
	{
		int m=0;
		for(int j=i-1;j>=0;j--)
		{
			if(arr[j]<arr[i])
			{
				m = max(m,dp[j]);
			}
		}
		
		dp[i] = arr[i]+m;
	}
	cout<<*max_element(all(dp));
	cout<<endl;
	return 0;
}
void multiple()
{
	testcases
    {
		single();
	}
}

int main()
{
  IOS;
  
  multiple();
}













