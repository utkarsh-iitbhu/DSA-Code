#include <bits/stdc++.h>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
#pragma GCC optimization ('unroll-loops')
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define mod 1000000007
#define set_bits __builtin_popcountll
#define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++)
#define FORL(a, b, c) for (int(a) = (b); (a) <= (c); (a)++)
#define FORR(a, b, c) for (int(a) = (b); (a) >= (c); (a)--)
#define INF 1e18
typedef long long int ll;
typedef unsigned long long ull;
typedef long double lld;
//typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key
typedef priority_queue<ll, vector<ll>, greater<ll>>  minhp;
typedef priority_queue<ll> maxhp;
typedef vector<ll> vi;
typedef pair<int, int> pi;
typedef priority_queue <pi , vector<pi> , greater<pi>> minhppi;
#define sz(x) (int)(x).size()
#define F first
#define S second
#define PB push_back
#define POB pop_back
#define MP make_pair
#define all(x) (x).begin(), (x).end()

#ifndef ONLINE_JUDGE
#define dbg(x) cerr<<#x<<' ';_print(x);cerr<<endl;
#else
#define dbg(x)
#endif

void _print(int a) {cerr << a << ' ';}
void _print(string a) {cerr << a << ' ';}
void _print(bool a) {cerr << a << ' ';}
void _print(char a) {cerr << a << ' ';}
void _print(ll a) {cerr << a << ' ';}
void _print(float a) {cerr << a << ' ';}
void _print(ull a) {cerr << a << ' ';}
void _print(lld a) {cerr << a << ' ';}
void _print(double a) {cerr << a << ' ';}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.F); cerr << ","; _print(p.S); cerr << "}";}
template<class T> void _print(vector<T> v){cerr<<"[ ";for(T i: v){_print(i);cerr<<", ";}cerr<<"]"<<endl;}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}


bool isPal(string s, int st, int en){
    if(st>=en) return true;
    if(s[st]!=s[en]) return false;
    return isPal(s,st+1,en-1);
}

int digitSum(string s , int ind, int &sum){
    if(ind==s.size()) return sum;
    sum += (s[ind]-'0');
    return digitSum(s,ind+1,sum);
}

int digitSum_digits(int n){
    if(n==0) return 0;
    return (n%10) + digitSum_digits(n/10);

}

int maxi(int a, int b, int c){
    return max(a,max(b,c));
}

int rope_equal_size(int n , int a , int b , int c){
    if(n<0) return -1 ;
    if(n==0) return 0;
    return 1 + maxi(rope_equal_size(n-a,a,b,c) ,
    rope_equal_size(n-b,a,b,c) 
    ,rope_equal_size(n-c,a,b,c)) ;
}

vector<string> res ;
void generate_subset(string s, int ind , string ans = ""){    
    if(ind == s.size()){
        cout<< ans<<" ";
        return ;  
    }

    // two recurssive calls to include and to exclude 
    generate_subset(s,ind+1,ans); 
    generate_subset(s,ind+1,ans+s[ind]); 
    // Bich me print nahi karna as leaf par hi saare ans milenge 
}

void tower_of_hanoi(int n , char a, char b , char c){
    if(n==1){ 
        cout<<"Move : "<<n<<" from : " <<a<<" to : "<<c<<endl;
        return ;}
    tower_of_hanoi(n-1,a,c,b);
    cout<<"Move : "<<n<<" from : " <<a<<" to : "<<c<<endl;
    tower_of_hanoi(n-1,c,b,a);
}

int josephus_killing(int n, int k){
    if(n==1) return 0;
    // +k is for new shifting of position 
    // %n to stop overflow
    return (josephus_killing(n-1,k)+k)%n;
}

void primesieve(int n)
{
    int prime[100] = {0};
    // prime[1] = 1;
    // prime[2] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (prime[i] == 0)
        {
            for (int j = i * i ; j <= n; j += i)
            {
                prime[j] = 1;
            }
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if (prime[i] == 0)
        {
            cout << i << " ";
        }
    }
    cout << endl;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

#ifndef ONLINE_JUDGE
freopen("Error.txt", "w", stderr);
#endif

// string s; cin>>s; 
// cout<<isPal(s,0,s.size()-1)<<endl;

// string num ; cin>>num; 
// int sum =0 ; 
// cout<<digitSum(num,0,sum)<<endl;

// int number ; cin>>number; 
// cout<<digitSum_digits(number)<<endl;

// int n , a,b,c; cin>>n>>a>>b>>c;
// cout<<rope_equal_size(n,a,b,c)<<endl;

// string s; cin>>s ;
// string ans = "";
// generate_subset(s,0,ans);

// int n ; cin>>n ; 
// tower_of_hanoi(n,'A','B','C');

// int n , k ; 
// cin>>n>>k ; 
// cout<<josephus_killing(n,k)<<endl;

 int n;
 cin >> n;
 primesieve(n);

return 0;
}