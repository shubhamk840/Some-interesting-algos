#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#include <numeric>
#include <climits>
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
#define mod 1000000007
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

int main()
{
    IOS;
    ll int n;
    cin>>n;
    vector<ll int> arr(n);
    ai(arr,n);
    ll int netsum=0;
    for(int i=0;i<n;i++)
    netsum+=arr[i];
    
    if(netsum%3!=0)
    {
    cout<<0<<endl;
     }
    else
    {
		//creating a prefix and suffix array
		ll int pre[n];
		pre[0]=arr[0];
		for(int i=1;i<n;i++)
		{
			pre[i]=arr[i]+pre[i-1];
		}
		ll int suffix[n];
		suffix[n-1]=arr[n-1];
		for(int i=n-2;i>=0;i--)
		{
			suffix[i]=suffix[i+1]+arr[i];
		}
		vector<ll int> temp;
		ll answer=0;
		for(int i=0;i<n;i++)
		{
			if(suffix[i]==netsum/3)
			temp.pb(i);
		}
		//ao(suffix);
		//cout<<endl;
		//ao(pre);
		//cout<<endl;
		//ao(temp);
		//cout<<endl;
		for(int i=0;i<n;i++)
		{
			if(pre[i]==netsum/3)
			{
				// now looking for total number of indexes present in the temp greater than i+1 which can be used to split the array
				if(upper_bound(all(temp),i+1)!=temp.end()) // found
				{
					answer+= distance(upper_bound(all(temp),i+1),temp.end());
				}
			}
		}
		cout<<answer<<endl;
	}
    
}
