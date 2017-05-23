/*
	AARUSH JUNEJA
	@vivace
	IIT(ISM),Dhanbad
*/

#include<bits/stdc++.h>
using namespace std;

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
#define lp(i,a,b) for(ll i = ll(a); i<=ll(b) ; i++) 
#define lpit(it,a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#define mid(s,e) (s+(e-s)/2)

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
inline ll ncr(ll n,ll r){ ll ans = 1 ; if(r > n-r) r = n-r; lp(i,0,r){ans*=(n-i) ; ans/=(i+1); } rtn ans; }
inline ll gcd(ll a,ll b){if(!a) rtn b; rtn gcd(b%a,a); }
inline ll fme(ll x,ll n,ll mod){ll ans=1;x%=mod;while(n>0){if(n&1){ ans*=x;ans%=mod;} x*=x;x%=mod;n>>=1;}rtn ans%mod;}
inline bool isPalin(string &s){	int len = s.size()-1;lp(i,0,(len/2)+1){if(!(s[i]==s[len-i]))	rtn false;} rtn true;}
inline ll lcm(ll a,ll b){rtn (a*b)/gcd(a,b); }
inline ll fmm(ll a,ll b,ll m) {ll r=0;a%=m;b%=m;while(b>0){if(b&1){r+=a;r%=m;}a+=a;a%=m;b>>=1;}rtn r%m;}
inline ll sfme(ll a,ll b,ll m) {ll r=1;a%=m;while(b>0){if(b&1)r=fmm(r,a,m);a=fmm(a,a,m);b>>=1;}rtn r%m;}
inline int in(){ int NR=0; register char c=gc(); while( c < 48 || c > 57 ){c=gc();} 
	while(c>47 && c< 58){	NR = (NR << 3) + (NR << 1) + (c - 48); c=gc();} return NR;
}

ll dx[] = {0,0,1,-1}, dy[] = {1,-1,0,0};
//--------------------------------TEMPLATE ENDS HERE--------------------------------------------------//

#define MOD 1000000007
#define N 100010

vector<vector<pair<ll,ll> > > g;

void dijkstra(ll n, vll &distTo, ll beg){
	
	priority_queue< pii, vector< pii >, greater<pii> > q;
	q.push(mp(0,beg));		// (dist,from)
		
	while(!q.empty()){
		int dist = q.top().ff;
		int prev = q.top().ss;
			
		q.pop();
			
		if(dist <= distTo[prev] ){
				
			lpit(it,g[prev]){
					
				ll next = it->ff , cost = it->ss;
					
				if(distTo[next] > distTo[prev] + cost ){
					distTo[next] = distTo[prev] + cost;
					q.push(mp(distTo[next],next));
				}
					
			}
							
		}
	
	}
	
}

int main(){
	ios::sync_with_stdio(false);
	//cin.tie(NULL);
	ll t,n,m,e,a,b,q,w,k,x,s;
	//ll p,q,curr,c;
    ///////////// START FROM HERE ////////////////////
	cin >> t;
	while(t--){
		cin >>  n >> k >> x >> m >> s;
		s--;
		g.resize(n);
		
		lp(i,1,m){
			cin >> a >> b >> w;
			a--; b--;
			g[a].pb(mp(b,w));
			g[b].pb(mp(a,w));
		}
			
		vll distTo(n,LLONG_MAX);
		ll beg = s;
		distTo[beg] = 0;
		
		if(s <= k ){
			lp(i,0,k-1){
				g[s].pb(mp(i,x));
				g[i].pb(mp(s,x));
			}
			dijkstra(n, distTo, beg);
			lp(i,0,n-1)	cout << distTo[i] << " ";	cout << "\n";
		}else{
			dijkstra(n, distTo, beg);
			
			ll minn = LLONG_MAX;
			ll minIdx;
			lp(i,0,k-1){
				if(i != beg && distTo[i] < minn){
					minIdx = i;
					minn = distTo[i];
				}
			}
			
			minn = minIdx;
			
			lp(i,0,k-1){
				if(i != minn){
					g[minn].pb(mp(i,x));
					g[i].pb(mp(minn,x));	
				}
			}
			
			vll dist(n,LLONG_MAX);
			dist[beg] = 0;
			
			dijkstra(n, dist, beg);
			lp(i,0,n-1)	cout << dist[i] << " ";	cout << "\n";
		}	
		
		
		g.clear();		
	}
	
    
	return 0;
}