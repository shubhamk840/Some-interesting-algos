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
#define prime 31
ll int find(string str,string second)
{
	ll int m=second.length();
   ll int n = str.length();
   ll int sum=0;
   ll int sum2=0;
   for(int i=0;i<str.length();i++)
   {
	   sum+= (str[i]*(ll)pow(prime,i));
	   sum2+=(second[i]*(ll)pow(prime,i));
   }
   for(int i=0;i<m-n+1;i++) // points to remember that 0 has been made the basis
   {
	   if(sum==sum2)
	   {
		   // this has been written to verify or target the problem of spurious hits
		   int f=0;
		   int s=i;
		   while(str[f]==second[s]&&f<n)
		   {
			   f++;s++;
		   }
		   if(f==n)
		   {
			   //cout<<"found at index"<<i<<endl;
			   return 1;
		   }
	   }
	   if(i<m-n)
	   {
		   sum2 = ((sum2-second[i])/prime +second[i+n]*(ll)pow(prime,n-1))%mod;
		   if(sum2<0)
		   sum2+=mod;
	   }
   }
   return 0;
}

int main()
{
    IOS;
    string second;
    cin>>second;
    string str;
    cin>>str;
    if(find(str,second))
    cout<<"yes found"<<endl;
    else
    cout<<"not found"<<endl;
}
    
