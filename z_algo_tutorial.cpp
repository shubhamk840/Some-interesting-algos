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

vector<int> zalgo(string str)
{
	int n=str.length();
		vector<int> z(n);

	int left =0;
	int right= 0;
	for(int k=1;k<n;k++)  // k is the size of the string taken at any state
	{
		if(k>right)
		{
			left=right=k;
		    while(right<n and str[right]==str[right-left])
		    {
				right++;
			}
			z[k] = right - left;
			right--;
		}
		else
		{
			int k1=k-left;
			if(z[k1]<right-k+1)
			{
				z[k] =z[k1];
			}
			else
			{
				left=k;
				while(right<n and str[right]==str[right-left])
				{
					right++;
				}
				z[k]= right-left;
				right--;
			}
		}
	}
	return z;
			
}

int main()
{
  IOS;
  string main;
  cin>>main;
  string str;
  cin>>str;
  int temp = str.length();
  str += "$";
  str+= main;
  vector<int> answer = zalgo(str);
  for(int i=0;i<answer.size();i++)
  {
	  if(answer[i]==temp)
	  {
		  cout<<i-temp<<endl;
	  }
  }
}





































