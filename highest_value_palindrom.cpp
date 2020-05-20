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
    int n;
    cin>>n;
    int k;
    cin>>k;
    string arr;
    cin>>arr;
    int count=0;
    for(int i=0;i<n/2;i++)
    {
		if(arr[i]==arr[n-1-i])
		continue;
		else
		count++;
	}
	map<int,int> m;
	if(count>k)
	cout<<-1<<endl;
	else if(n==1&&k>=1)
	cout<<9<<endl;
	else
	{
		for(int i=n/2-1;i>=0;i--)
		{
			if(arr[i]!=arr[n-i-1])
			{
				m.insert({i,n-i-1});
				arr[i]=max(arr[i],arr[n-i-1]);
				arr[n-i-1]=arr[i];
				k--;
			}
		}
		
	
	int temp2=k;
	//cout<<temp2<<endl;
	for(int i=0;i<n/2;i++)
	{
		if(temp2==0)
		break;
		 if(arr[i]==(9+'0')&&arr[n-i-1]==(9+'0'))
	      {
			  continue;
		  }
		else if(m.find(i)!=m.end()) // if found
		{
         temp2++;
         if(arr[i]==(9+'0'))
         {
         arr[n-i-1]=(9+'0');
		 temp2--;
	     }
	     else if(arr[n-i-1]==(9+'0'))
	     {
		arr[i]=(9+'0');
		temp2--;
	      }
	     
	      else
	      {
 arr[n-i-1]=(9+'0');
 arr[i]=(9+'0');
 temp2--;
 temp2--;
		  }
	     }
	     else
	     {
			 if(temp2==1)
			 break;
			  if(arr[i]==(9+'0')&&arr[n-i-1]==(9+'0'))
	      {
			  continue;
		  }
			else if(arr[i]==(9+'0'))
         {
         arr[n-i-1]=(9+'0');
		 temp2--;
	     }
	     else if(arr[n-i-1]==(9+'0'))
	     {
		arr[i]=(9+'0');
		temp2--;
	      }
	     
	      else
	      {
             arr[n-i-1]=(9+'0');
              arr[i]=(9+'0');
               temp2--;
                temp2--;
		  }
	}

	   
	}
	if(temp2>=1)
	{
		if(n&1)
		{
			arr[n/2]=9+'0';
		}
	}
	
	cout<<arr<<endl;
}
}
    
