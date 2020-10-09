

// in case of multiple test cases and N=1e5 don't intialize arrays as global except for graph vector-array
// always check whether or not you are doing mod of a negative number
// always use 1LL instead of 1
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
 
using namespace __gnu_pbds;
using namespace std;

// using long doubles saves you from corner cases but is very time consuming
#define double      	long double
#define int         	long long
#define pb          	push_back
#define pii         	pair<int,int>
#define vi          	vector<int>
#define vii         	vector<pii>
#define mi          	map<int,int>
#define mii         	map<pii,int>
#define all(a)      	(a).begin(),(a).end()
#define sz(x)       	(int)x.size()
// just comment the line below in case of interactive problems
#define endl        	"\n"
#define repp(i,a,b) 	for(int i=a;i<b;i++)
#define rep(i,a,b) 		for(int i=a;i<=b;i++)
#define brep(i,a,b)     for(int i=a;i>=b;i--)
#define deb1(x)      	cout << #x << "=" << x << endl
#define deb2(x, y)  	cout << #x << "=" << x << "," << #y << "=" << y << endl
#define deb3(x, y, z)  	cout << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl
#define trace(v) 		for(auto it=v.begin();it!=v.end();it++)cout<<*it<<" ";cout<<endl;
#define tracearr(a,l,r) for(int iii=l;iii<=r;iii++)cout << a[iii] << " ";cout << endl;
#define PI          	3.1415926535897932384626
#define F 				first
#define S 				second
#define clr(x,y) 		memset(x, y, sizeof(x))
#define IOS         	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);


typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
// *s.find_by_order(1) - gives the 2nd samllest element in set
// s.order_of_key(x)   - gives the number of elements in the set which are strictly smaller than x

int form(int x1, int y1, int x2, int y2){
    if(x1 == x2 and y1 == y2){
          return 0;
    }
    int north, south;
    if(y1 + 2 * x1 > 0){
      north = form(x1, y1 + 2 * x1, x2, y2); 
    }
    else if(y1 + 2 * x1 < 0){
      north = form(-1*x1, -1*(y1 + 2 * x1), x2, y2); 
    }
    if(y1 - 2 * x1 > 0){
      south = form(x1, y1 - 2 * x1, x2, y2); 
    }
    else if(y1 - 2 * x1 < 0){
      south = form(-1*x1, -1*(y1 - 2 * x1), x2, y2); 
    }
    return 1 + min(min(form(x1 + 2 * y1, y1, x2, y2), form(x1 - 2 * y1, y1, x2, y2)), min(north, south));
}

void solve()
{
   int x1, y1, x2, y2;
   cin >> x1 >> y1 >> x2 >> y2;
   //cout << x1 << y1 << x2 << y2;
   cout << form(x1, y1, x2, y2) << endl;	
}

int32_t main()
{
	IOS;
	int T=1;
	cin >> T;
	// int numOfSetBits = __builtin_popcountll(n);
	//std::cout << std::fixed << std::setprecision(12);
	while(T--)
	{
		solve();
	}
}