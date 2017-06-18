/*
	AARUSH JUNEJA
	@vivace
	TOPICS : 2-D BIT (Binary Indexed Tree / Fenwick Tree)
*/

#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define N 100010

typedef double lf;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef set<ll> sll;
typedef vector<ll> vll;
typedef map<string,ll> msl;
typedef pair<int,int> pii;
typedef pair<ll,ll> ii;
typedef vector<ii > vpll;
typedef map<ll,ll> mll;
typedef vector<vll > vvll;
typedef list<ll> lll;
typedef vector<lll > vlll;
typedef pair<ll,ii> iii;

#define rtn return 
#define gc getchar
#define pb push_back
#define ff first
#define ss second
#define mp(x,y) make_pair(x,y)
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define lp(i,b) for(ll i = ll(0); i<ll(b) ; i++) 
#define lpit(it,a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#define mid(s,e) (s+(e-s)/2)
#define min3(a,b,c)	min(a,min(b,c))
#define max3(a,b,c)	max(a,max(b,c))

ll ip(){
	ll x = 0; bool isNeg = false; char c;
	c = gc();
	if(c == '-')	isNeg = true , c = gc();
	for( ; c >= '0'  && c <= '9' ; c = gc()); x = (x << 1) + (x << 3) + c - '0';
	if(isNeg)	x *= -1;	return x;
}
//////////////////////////////////////////// CONTAINERS FOR FUNCTIONS MENTIONED IN TEMPLATE ///////////////////////////////////
#define MAX 100005
//bool isPrime[MAX];
//int spf[MAX];
//////////////////////////////////////////// FUNCTIONS THAT NEED COMMENTED OUT CONTAINERS ////////////////////////////////////


//void prime_sieve(){ for(ll i=2 ; i*i<=MAX ; i++){	if(!isPrime[i]){ for(ll j=i*i ; j<=MAX ; j+=i)	isPrime[j] = 1;} } 	}
//void spf_sieve(){	for(ll i=2 ; i<MAX ; i+=2)	spf[i] = 2;
//	for(ll i=3 ; i<MAX ; i+=2){	if(!isPrime[i]){ spf[i] = i; for(ll j=i ; (j*i)<MAX ; j+=2){ if(!isPrime[i*j])	isPrime[i*j] = true , spf[i*j] = i; } } }
//}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
inline ll ncr(ll n,ll r){ ll ans = 1 ; if(r > n-r) r = n-r; lp(i,r+1){ans*=(n-i) ; ans/=(i+1); } rtn ans; }
inline ll gcd(ll a,ll b){if(!a) rtn b; rtn gcd(b%a,a); }
inline ll fme(ll x,ll n){ll ans=1;x%=MOD;while(n>0){if(n&1){ ans*=x;ans%=MOD;} x*=x;x%=MOD;n>>=1;}rtn ans%MOD;}
inline bool isPalin(string &s){	int len = s.size()-1;lp(i,(len/2)+2){if(!(s[i]==s[len-i]))	rtn false;} rtn true;}
inline ll lcm(ll a,ll b){rtn (a*b)/gcd(a,b); }
inline ll fmm(ll a,ll b) {ll r=0;a%=MOD;b%=MOD;while(b>0){if(b&1){r+=a;r%=MOD;}a+=a;a%=MOD;b>>=1;}rtn r%MOD;}
inline ll sfme(ll a,ll b) {ll r=1;a%=MOD;while(b>0){if(b&1)r=fmm(r,a);a=fmm(a,a);b>>=1;}rtn r%MOD;}
inline int in(){ int NR=0; register char c=gc(); while( c < 48 || c > 57 ){c=gc();} 
	while(c>47 && c< 58){	NR = (NR << 3) + (NR << 1) + (c - 48); c=gc();} return NR;
}

ll dx[] = {0,0,1,-1}, dy[] = {1,-1,0,0};
//--------------------------------TEMPLATE ENDS HERE--------------------------------------------------//

int bit[1030][1030], arr[1030][1030];

void update(int x, int y, int val){
	int y1;
	while( x <= 1024 ){
		y1 = y;
		while( y1 <= 1024 ){
			bit[x][y1] += val;
			y1 += (y1 & -y1);
		}
		x += (x & -x);
	}
}

int getsum(int x, int y){
	int y1, sum = 0;
	while( x > 0 ){
		y1 = y;
		while( y1 > 0 ){
			sum += bit[x][y1];
			y1 -= (y1 & -y1);
		}
		x -= (x & -x);
	}
	return sum;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t,n,m,e,a,b,q,h,f,w,x,y,k,p;
    ///////////// START FROM HERE ////////////////////
	cin >> t;
	while(t--){
		cin >> n;
		lp(i,n+1){
			lp(j,n+1){
				bit[i][j] = 0;
				arr[i][j] = 0;
			}
		}
		string str;
		while( 1 ){
			cin >> str;
			if( str[0] == 'E' )	break;
			if( str == "SET" ){
				int val;
				cin >> x >> y >> val;
				x++; y++;
				if( arr[x][y] != val)	update(x,y,val-arr[x][y]);	
				arr[x][y] = val;
			}else{
				int x1,y1,x2,y2;
				cin >> x1 >> y1 >> x2 >> y2;
				x1++; y1++; x2++; y2++;
				int ans = getsum(x2,y2) + getsum(x1-1,y1-1) - getsum(x1-1,y2) - getsum(x2,y1-1);
				cout << ans << "\n";
			} 
		}
	}    
		
			
	return 0;
}