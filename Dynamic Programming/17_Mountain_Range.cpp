/*
Question :  
input :  
output : 
intution : 
soln : 

state : 
transition : 
initialization :
*/



#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int mod=1e9+7;
int dp[1000000];

int main(){
   int n; cin>>n;
   vector<int> v(n);
   for(int i=0;i<n;i++) cin>>v[i];
   vector<int> f(n,-1),b(n,-1);
   stack<pair<int,int> > st;
   for(int i=n-1;i>=0;i--){
      while(!st.empty() and st.top().first<=v[i]) st.pop();
      if(!st.empty()) f[i]=(st.top()).second;
      st.push({v[i],i});
   }
   while(!st.empty()) st.pop();
   for(int i=0;i<n;i++){
      while(!st.empty() and st.top().first<=v[i]) st.pop();
      if(!st.empty()) b[i]=(st.top()).second;
      st.push({v[i],i});
   }
   vector<pair<int,int> > p;
   for(int i=0;i<n;i++) p.push_back({v[i],i});
   sort(p.rbegin(),p.rend());
   for(int i=0;i<n;i++){
      int x=0,y=0;
      
      if(f[p[i].second]!=-1) x=dp[f[p[i].second]];
      if(b[p[i].second]!=-1) y=dp[b[p[i].second]];
      dp[p[i].second]=max(x,y)+1;
   }
   int ans=0;
   for(int i=0;i<n;i++) ans=max(ans,dp[i]); 
   cout<<ans<<endl;
   
}

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(false), cin.tie(NULL);
#define mod 1000000007 // 1e9+7
const int N=1e6+10;

// Container Declarations
#define iipair pair<int,int>
#define ivp vector<pair<int,int> >
#define ivec vector<int>
#define cvec vector<char>
#define iset set<int>
#define cset set<char>
#define imset multiset<int>
#define cmset multiset<char>
#define iuset unordered_set<int>
#define imap map<int, int>
#define cmap map<char, int>
#define immap multimap<int, int>
#define cmmap multimap<char, int>
#define iump unordered_map<int, int>
#define cump unordered_map<char, int>
#define istk stack<int>
#define ique queue<int>
#define deq deque<int>
#define pque priority_queue<int>

// Input Output
#define in(a) int a; cin >> a
#define sin(s) string s; cin >> s
#define in2(a,b) int a,b; cin >> a >> b
#define sin2(s,t) string s,t; cin >> s >> t
#define in3(a,b,c) int a,b,c; cin >> a >> b >> c
#define in4(a,b,c,d) int a,b,c,d; cin >> a >> b >> c >> d
#define ain(arr,n) int arr[n]; for(int i=0;i<n;i++) cin>>arr[i]
#define ivi(v,n) ivec v; for(int i=0;i<n;i++) {int x; cin>>x; v.push_back(x);}
#define ipi(v,n) ivp v; for(int i=0;i<n;i++) {in2(x,y); v.push_back(mpr(x,y));}
#define imi(m,v) for(auto x:v) m[x]++;
#define vout(v) for(auto &x:v) cout<<x<<" "; cout<<endl
#define dout(v) for(auto &x:v) {vout(x); }
#define pout(v) for(auto &x:v) cout<<x.first<<" "<<x.second<<endl;

// Container Operations
#define pb(v, x) v.push_back(x)
#define mpr make_pair
#define pp(v) v.pop_back()
#define srt(v) sort(v.begin(), v.end())
#define csrt(v) sort(v.begin(), v.end(),cmp)
#define rsrt(v) sort(v.rbegin(), v.rend())
#define rev(v) reverse(v.begin(), v.end())
#define fnd(v, x) find(v.begin(), v.end(), x)
#define lb(v, x) lower_bound(v.begin(), v.end(), x) - v.begin()
#define ub(v, x) upper_bound(v.begin(), v.end(), x) - v.begin()
#define bn begin()
#define en end()
#define rbn rbegin()
#define ren rend()
#define vsum(v) accumulate(v.begin(), v.end(), 0LL)
#define vmin(v) *min_element(v.begin(), v.end())
#define vmax(v) *max_element(v.begin(), v.end())
#define cnt(v, x) count(v.begin(), v.end(), x)

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
int countSetBits(int n) { int count = 0; while (n) { n &= (n - 1); count++;} return count; }
int lsb(int n) { return n ? __builtin_ctzll((unsigned long long)n) : -1; }
int msb(int n) { return n ? 63 - __builtin_clzll((unsigned long long)n) : -1; }

bool isSquare(long long x) { if (x < 0) return false; long long s = sqrt((long double)x); while ((s+1)*(s+1) <= x) ++s; while (s*s > x) --s; return s*s == x; }
bool prime(int n) { if (n <= 1) { return false;} int r = sqrt(n); for (int i = 2; i <= r; ++i) { if (n % i == 0) { return false; }} return true;}
vector<int> getdivisors(int n) { vector<int> divs; for (int i = 1; i * i <= n; i++) { if (n % i == 0) { divs.push_back(i); if (i != n / i) divs.push_back(n / i); }} sort(divs.begin(), divs.end()); return divs; }

string to_str(int n) { string s; while (n) { s += (n % 10) + '0'; n /= 10; } reverse(s.begin(), s.end()); return s; }
int to_int(string s) { int n = 0; for (int i = 0; i < (int)s.size(); i++) n = n * 10 + s[i] - '0'; return n; }
string to_bin(int n) { string s; while (n) { s += (n % 2) + '0'; n /= 2; } reverse(s.begin(), s.end()); return s; }

int digsum(int n){ int sum = 0; while (n != 0) { sum = sum + n % 10; n = n / 10; } return sum; }
int digcnt(int n){ int c = 0; while (n != 0) { n /= 10; c++; } return c; }
bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
    if(a.first!=b.first) return a.first > b.first;
    return  a.second>b.second;
}

void mew() {
   
}

int32_t main() {
  fast;
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  int t=1;
  cin >> t;
  // precomputeFactorials(N);
  // precomputeDivisors();
  // sieve();
  while (t--) {
    mew();
  }
}