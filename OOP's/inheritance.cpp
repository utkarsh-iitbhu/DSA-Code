#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
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
typedef vector<vector<ll>> vdp;
typedef priority_queue <pi , vector<pi> , greater<pi>> minhppi;
#define sz(x) (int)(x).size()
#define F first
#define S second
#define PB push_back
#define POB pop_back
#define MP make_pair
#define YES cout<<"YES"<<endl
#define NO cout<<"NO"<<endl
#define line cout<<endl
#define all(x) (x).begin(), (x).end()

#ifndef ONLINE_JUDGE
#define dbg(x) cerr<<#x<<' ';_print(x);cerr<<endl;
#else
#define dbg(x)
#endif

void _print(int a) {cerr << a << ' ';}
void _print(string a) {cerr << a << ' ';}
void _print(char a) {cerr << a << ' ';}
void _print(ll a) {cerr << a << ' ';}
void _print(float a) {cerr << a << ' ';}
void _print(ull a) {cerr << a << ' ';}
void _print(lld a) {cerr << a << ' ';}
void _print(double a) {cerr << a << ' ';}
void _print(const char *x) {cerr << '"' << x << '"';}
void _print(bool x) {cerr << (x ? "true" : "false");}
void _print(const string &x) {cerr << '"' << x << '"';}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template<class T> class Array;
template <class T, class V> void _print(map <T, V> v);
template <class T, class V> void _print(unordered_map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T> void _print(unordered_set <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.F); cerr << ","; _print(p.S); cerr << "}";}
template<class T> void _print(vector<T> v){cerr<<"[ ";for(T i: v){_print(i);cerr<<", ";}cerr<<"]"<<endl;}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(unordered_map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <typename T>void print(vector<vector<T> >& a){cerr << "[ ";for (auto i : a){print(i);cerr << " ";}cerr << "]";}
template <typename T, typename V>void print(vector<pair<T, V> >& a){cerr << '[' << ' ';for (auto x : a){print(x.F);cerr << ":";print(x.S);cerr << ' ';}cerr << ']';}
template <class T> void _print(unordered_set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}


class Human{
    public: 
    int height; 
    int weight;

    private:
    int age;

    public:

    void print(){
        cout<<"Check it out"<<endl;
    }

    int getHeight(){
        return height;
    }
    int getWeight(){
        return weight;
    }
    int getAge(){
        return age;
    }
    void setHeight(int h){
        height = h;
    }

};


class male: public Human{
    public: 
    string color;

    void sleep(){
        cout<<"Male sleeping"<<endl;
    }
};


class female: protected Human{
    public: 
    string money;

    void walk(){
        cout<<"female walking"<<endl;
    }

    // Ye protected pseudo private hota hai 
    int getheight(){
        // female me height bas private jaisa ban jata hai
        return this->height ;
    }

};

class trans: private Human{
    // public: 
    // string money;

    void eat(){
        cout<<"Eating"<<endl;
    }

    public:

    // KOI FAYDA NAHI AGE PRIVATE HAI SUPER CLASS ME
    // int get_age(){
    //     return this->age;
    // }

    // Ye protected pseudo private hota hai 
    int getheight11(){
        // female me height bas private jaisa ban jata hai
        return this->height ;
    }

};

class boy: public male{
    // This is multi lvl inheritance
    // Human se Male and then boy
    public:
    void hit(){
        cout<<"Hit "<<endl;
    }
};

class girl{
    public:
    void bang(){
    cout<<"Bangr "<<endl;
    }
};
class boii{
    public:
    void hit(){
    cout<<"Hit "<<endl;
    }
};

class hybrid: public boy, public girl{
    // Multiple inherritance of boy and girl
};



class A{
    public:
    void func(){
        cout<<"A se aaya ye"<<endl;
    }
};
class B{
    public:
    void func(){
        cout<<"B se aaya ye"<<endl;
    }
};
class C : public A, public B{

};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

#ifndef ONLINE_JUDGE
freopen("Error.txt", "w", stderr);
#endif

male obj1 ; 
// Male me ye teeno prop inherit hoke aayi hai 


// ye dega error as age ab private class me hai super class ke
// cout<<obj1.age<<endl;   // Ye BT dega
cout<<obj1.height<<endl;
cout<<obj1.weight<<endl; 

obj1.setHeight(76);
cout<<obj1.height<<endl;

cout<<obj1.color<<endl;
obj1.sleep();
cout<<endl;


female f1;
cout<<f1.getheight()<<endl;

trans t1; 
cout<<"Trs"<<endl;
cout<<t1.getheight11()<<endl;
// Private me BT dega ye
// cout<<t1.get_age()<<endl;

boy b1; 
b1.print();


hybrid h1; 
h1.bang();
h1.hit(); 


C cc;
// cc.func(); // BT DEGA
cc.A::func();
cc.B::func();

return 0;}