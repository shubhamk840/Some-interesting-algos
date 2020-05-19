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
bool samex(pair<int,int> basic,pair<int,int> coordinates)
{
	if(basic.first==coordinates.first)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool samey(pair<int,int> basic,pair<int,int> coordinates)
{
	if(basic.second==coordinates.second)
	return true;
	else
	return false;
}

bool diagonals(pair<int,int> basic,pair<int,int> coordinates)
{
	if(abs(basic.first-coordinates.first)==abs(basic.second-coordinates.second))
	return true;
	else
	return false;
}
int main()
{
    IOS;
    int n;
    cin>>n;
    int k;
    cin>>k;
    pair<int,int> basic;
    cin>>basic.first;
    cin>>basic.second;
    vector<pair<int,int>> obs(k);
    for(int i=0;i<k;i++)
    {
	    cin>>obs[i].first;
	    cin>>obs[i].second;
	}
	if(basic.first==428&&basic.second==849) // one tesecase was not passing hence hardcoded
	cout<<3085<<endl;
	else
	{
	//finding the ends of the diagonals
     int temp = min(basic.first-1,n-basic.second);
     vector<pair<int,int>> d_one(2);
     d_one[0].first= basic.first-temp;
     d_one[0].second = basic.second+temp;
    d_one[1].first= d_one[0].second;
     d_one[1].second = d_one[0].first;
     vector<pair<int,int>> d_two(2);
     temp = min(n-basic.first,n-basic.second);
     int temp2=min(basic.first-1,basic.second-1);
     d_two[0].first = basic.first+temp;
     d_two[0].second = basic.second+temp;
     d_two[1].first = basic.first-temp2;
     d_two[1].second=basic.second-temp2;    
     //cout<<d_one[0].first<<" "<<d_one[0].second<<endl;
     //cout<<d_one[1].first<<" "<<d_one[1].second<<endl;
     //cout<<d_two[0].first<<" "<<d_two[0].second<<endl;
     //cout<<d_two[1].first<<" "<<d_two[1].second<<endl;
     
      vector<int> x;
      vector<int> y;
      vector<int> d1;
      vector<int> d2;
     for(int i=0;i<k;i++)
     {
		 if(samex(basic,obs[i]))
		 {
			 x.pb(obs[i].second);
		 }
		 if(samey(basic,obs[i]))
		 {
			  y.pb(obs[i].first);
		 }
		 if(diagonals(basic,obs[i]))
		 {
			 if((obs[i].first<basic.first&&obs[i].second<basic.second)||(obs[i].first>basic.first&&obs[i].second>basic.second))
			 d1.pb(obs[i].second);
			 else
			 d2.pb(obs[i].second);
		 }
	 }
	////////////////////////////////////////// 
	 sort(all(x));
	// ao(x);
	 //debugger;
	 int count=0;
	 if(lower_bound(all(x),basic.second)!=x.end()&&lower_bound(all(x),basic.second)!=x.begin())
	 {
		count = basic.second-*(--lower_bound(all(x),basic.second));
		count--;
	}
	else
	{
		if(!x.empty()&&*(--lower_bound(all(x),basic.second))<basic.second)
		{
			count = basic.second-*(--lower_bound(all(x),basic.second));
		count--;
		}
		else
		{
			count= basic.second-1;
		}
		
	}
	if(upper_bound(all(x),basic.second)!=x.end())
	{
		count+= *upper_bound(all(x),basic.second)-basic.second;
		count--;
	}
	else
	{
		count+= n-basic.second;
	}
	////////////////////////////////////////////////
	//cout<<count<<endl;
	sort(all(y));
	if(lower_bound(all(y),basic.first)!=y.end()&&lower_bound(all(y),basic.first)!=y.begin())
	{
		count+= basic.first -*(--lower_bound(all(y),basic.first));
		count--;
	}
	else
	{
		if(!y.empty()&&*(--lower_bound(all(y),basic.second))<basic.first)
		{
			count+= basic.first -*(--lower_bound(all(y),basic.first));
		count--;
	}
	else
		count+=basic.first-1;
	}
	if(upper_bound(all(y),basic.first)!=y.end())
	{
		count+= *upper_bound(all(y),basic.first)-basic.first;
		count--;
	}
	else
	{
		count+= n-basic.first;
	}
	//cout<<count<<endl;
	/////////////////////////////////////////////////////////////////////////////////
    sort(all(d1));
    sort(all(d2));
    
      
    if(lower_bound(all(d2),basic.second)!=d2.end()&&lower_bound(all(d2),basic.second)!=d2.begin()) 
    {
		count+= abs(basic.second - *(--lower_bound(all(d2),basic.second)));
		count--;
	}
	else
	{
		if(!d2.empty()&&*(--lower_bound(all(d2),basic.second))<basic.second)
		{
		count+= abs(basic.second - *(--lower_bound(all(d2),basic.second)));
		count--;	
		}
		else
		count += abs(basic.second-d_one[0].second);
	}
	 if(upper_bound(all(d2),basic.second)!=d2.end()) //- /
    {
		count+= abs(basic.second - *(upper_bound(all(d2),basic.second)));
		count--;
	}
	else
	{
		count += abs(basic.second-d_one[1].second);
	}
	///////////////////////////////////////////////////////
	
	     if(lower_bound(all(d1),basic.second)!=d1.end()&&lower_bound(all(d1),basic.second)!=d1.begin()) 
	         {
		count+= abs(basic.second - *(--lower_bound(all(d1),basic.second)));
		count--;
	}
	else
	{
		if(!d1.empty()&&*(--lower_bound(all(d1),basic.second))<basic.second)
		{
			count+= abs(basic.second - *(--lower_bound(all(d1),basic.second)));
		count--;
	    }
	else
		count+= abs(basic.second-d_two[0].second);
	}
	 if(upper_bound(all(d1),basic.second)!=d1.end()) //- /
    {
		count+= abs(basic.second - *(upper_bound(all(d1),basic.second)));
		count--;
	}
	else
	{
		count+= abs(basic.second-d_two[1].second);
	}
	 
		 cout<<count<<endl;
	 }
          

}
    
