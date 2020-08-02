#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define MO 1000000007
#define mem(a,s) memset(a,s,sizeof(a))
#define IOS ios_base::sync_with_stdio(0); cin.tie(NULL);
#define lop(i,s,e) for(ll i=s;i<e;i++)
#define lopi(i,s,e) for(int i=s;i>=e;i--)
#define prina(a,n) for(int i=0;i<=n;i++)cout<<a[i]<<" ";cout<<endl; 
#define prin2da(a,n,m) lop(i,1,n){lop(j,1,m)cout<<a[i][j]<<" ";cout<<endl;}
#define atout(v) for(auto x:v) cout<<x<<" ";cout<<endl;
#define atin(v) for(auto &x:v) cin>>x;
#define vl vector<ll >
#define vi vector<int >
#define lb lower_bound
#define ub upper_bound
#define sort(a) sort(a.begin(),a.end())  
#define mp make_pair
#define all(v) v.begin(),v.end() 
using namespace std;

int main() {
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
    IOS

    ll t,T;
    cin>>t;
    T=t;
    while(t--) {
    	ll n,m;
    	cin>>n>>m;
    	//cout<<n<<" "<<m<<endl;
    	vl c(n);
    	atin(c);

    	vl dp(n);
    	dp[0]=0;
    	ll start;
    	for(start=1 ; start<m ; start++) dp[start]=c[start];

    	dp[start]=c[start];
    	start++;

    	bool flag=false;
    	lop(i,start,n) {
    		ll cnt=0,j=i-1,mn=1e18;
    		while(j>=(i-m)) {
    			if(c[j]==0) cnt++;
    			else mn=min(mn,dp[j]);
    			if(cnt>=m) {
    				flag=true;
    				break;
    			}
    			j--;
    		}
    		dp[i]=mn+c[i];
    	}
    	//atout(dp);
    	if(flag) cout<<"Case #"<<T-t<<": -1"<<endl;
    	else cout<<"Case #"<<T-t<<": "<<dp[n-1]-c[n-1]<<endl;
    }

    return 0;
}