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

// Agr doosre files se uthana hai to 
// #include "Hero.cpp"

// Make a class 
class Hero{
    // properties
    
    // Public lagate hi sahu.health and level se error hat gaya 
    public:
    int health; 
    // public: likha to bas level hoga public not health
    char level; 
    char *name; // name[101] fukat ka memory lega
    // nmame ko hum ab constructor me dynamicaly space denge
    // INDEPENDENT OF CLASS 
    static int time; // static variable 

    // ye bana hai ek CONSTRUCTOR
    // Ab har instane pe ye Constructor run hoga
    Hero(){
        // Har baar ye line print hogi static dynamic dono me
        cout<<"Simple Constructor called : "<<endl;
        name = new char[101];
    }

    void setname(char name[]){
        // Dono likh sakte hai 
        this->name = name; 
        // strcpy(this->name, name); // Yr bhi sahi hai 
    }



    // Parametersied constructor
    Hero(int health){
        // health = health NAHI LIKH SAKTE HAI 

        // pointer print karega
        cout<<"this-> "<<this<<endl;
        // Current obj ka address this me store hota hai 
        this->health = health;
        
    }

    Hero(int health, char level){
        this->health = health;
        this->level = level;
    }

    
    void print(){
        cout<<"Name : "<<this->name<<endl;
        cout<<"Health : "<<this->health<<endl;
        cout<<"Level : "<<this->level<<endl;
    }
    
    
    // Copy constructor DEEP KE LIYE 
    Hero(Hero& temp){
        
        // Ye ha ideep copy ke liye constructor
        // Ye banaega naya array
        char *ch = new char[strlen(temp.name)+1];
        // naye array me temp.name ko copy kar liya
        strcpy(ch, temp.name);
        this->name = ch;

        cout<<"Copy constructor called : "<<endl;
        this->health = temp.health;
        this->level = temp.level;
    }

    // DEFAULT USE KARNA HAI ISLIYE HATAYA
    // Hero(Hero& temp){
    //     cout<<"Copy constructor called : "<<endl;
    //     this->health = temp.health;
    //     this->level = temp.level;
    // }

    // Destructor
    ~Hero(){
        cout<<"Destructor called : "<<endl;
    }

    // Static functions
    static int random(){
        // Ye chalega as time is static
        cout<<"Time : ";
        // return karna padta hai isme 
        return time ; 
        // Ye dono error dega as THIS not Allowed and level is not static
        // cout<<this->health<<endl;
        // cout<<level<<endl;
    }

    private:
    int hp;

    public:
    int get_hp(){
        return hp;
    }
    void set_hp(int x){
        hp = x;
    }
    void set_hp_cond(int x, char c){
        if(c == 'A'){
            hp = x; 
        }
    }


    // private wale bas class ke under hi access kiye jaa sakte hai 
    private: 
    char NAME[101];
    // void print(){
    //     cout<<name<<endl;
    // }

};

    
    // Static Keyword
    // Initialise static keyword time 
    int Hero::time = 5 ; 


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

#ifndef ONLINE_JUDGE
freopen("Error.txt", "w", stderr);
freopen("output.txt", "w", stdout);
#endif

    Hero sahu ; 
    sahu.health = 69; 
    sahu.level = 'A';
    cout<<"Size : " <<sizeof(sahu)<<endl;
    cout<<"Health : " <<sahu.health<<endl;
    cout<<"Level : " <<sahu.level<<endl;
    // Ye error dega as ye private ke under hai 
    // cout<<"Name : " <<sahu.NAME<<endl;

    // sahu.hp = 7; // Ye dega error as ye private hai
    sahu.set_hp(7);
    cout<<"HP using getters : " <<sahu.get_hp()<<endl;

    sahu.set_hp_cond(8,'D'); // This cond will fail as char != 'A'
    sahu.set_hp_cond(9,'A');
    cout<<"HP using getters : " <<sahu.get_hp()<<endl; // 9 aaefa output
    cout<<endl; 

    // Static and dynamic
    
    // Static initialisation
    Hero a;
    a.health = 10;
    a.level = 'B';
    a.set_hp(99);
    cout<<"Health of a : " <<a.health<<endl;
    cout<<"Level of a : " <<a.level<<endl;
    cout<<"HP of a : " <<a.get_hp()<<endl;
    cout<<endl;

    // Dynamic initialisation
    Hero *b = new Hero();
    b->health = 12;
    b->level = 'C';
    b->set_hp(15);
    cout<<"Size of b : "<<sizeof(b)<<endl;
    cout<<"Health of b : " <<(*b).health<<endl;
    cout<<"Level of b : " <<(*b).level<<endl;
    cout<<endl; 
    cout<<"_Aise bhi likh sakte hai_b->__"<<endl;
    cout<<"Health of b : " <<b->health<<endl;
    cout<<"Level of b : " <<b->level<<endl;
    cout<<"HP of b : " <<b->get_hp()<<endl;
    cout<<endl;

    // Constructors 
    /*  Agr constructor prop ke saath bana diya hai 
        To automatic wala cancel ho jaega 
        Hero h2; will give error as default constructor is not there 
    */
    Hero c(10); // Parameterised me pass karna hai 
    // this and &c dono same hoga as dono ka adress same hai 
    cout<<"Adress of c : "<<&c<<endl;

    Hero cc(10,'F'); // Isme dono pass kara hai
    cout<<"Adress of cc : "<<&cc<<endl;
    cc.print(); 
    cout<<endl;


    // Copy Constructor
    Hero ramesh(55,'Y');
    ramesh.print(); 

    // Copy constructor called
    Hero suresh(ramesh);
    suresh.print();
    cout<<endl;

    // Shallow and Deep Constructor
    Hero h1;
    h1.set_hp(6);
    h1.health = 33;
    h1.level = 'L';
    char name[5] = "Sahu";
    h1.name = name;
    h1.print(); 

    Hero h2(h1);
    // Hero h2 = h1; // Dono same hai 
    h2.print();
    cout<<endl;

    h1.name[0] = 'Y';
    h1.level = 'T';
    h1.print();
    // DEFAULT WALE ME ALAG HOGA CHECK CONSTRUCTOR DO CONST. HAI 
    // FOR NAME ONLY CHANGE HOGA COZ USE *name KAR KE PASS KARA HAI
    // BUT Level CHANGE HO RAHA HAI DONO ME
    // Ab h2 me bhi SAHU ka YAHU ho gaya game fas gaya
    // As default me hota hai shallow copy of constructor
    h2.print();
    cout<<endl;
    // Deep copy wale constructor me naam change nahi hoga 
    

    // Copy Assignment operator 
    h1 = h2; // Ab h1 me h2 ka copy assign kar diya
    // Ab dono same honge
    h1.print();
    h2.print();
    cout<<endl; 

    // Destructor
    
    // Static
    Hero d1 ;
    // Dynamic
    Hero *d2 = new Hero(); 
    // Dynamic ke liye namually delete karna padta hai 
    // Multiple outputs as multiple obj were created
    cout<<"Manually called dest -> ";
    delete d2; 

    // Static Keyword
    // Initialise static keyword time 
    // int Hero::time = 5 ;   // AISE HOGA ABOVE main()
    // Bina obj create kare print kar diya 
    cout<<"Time : " <<Hero::time<<endl;

    Hero stat ; 
    // Ye aise bhi chal jaega bhaii
    // BUT DONT USE THIS
    cout<<"Time statically : " <<stat.time<<endl;

    // Isko bhi change kar sakte hai
    Hero stat2;
    stat2.time = 11; 
    cout<<"Time statically : " <<stat.time<<endl;
    cout<<"Time statically : " <<stat2.time<<endl;

    // Static functions 
    // Isme time jo static hai wo print hoga
    cout<<Hero::random()<<endl;

    
    cout<<endl;
    cout<<"_______END______________"<<endl;
    cout<<endl;

    /*   WHAT HAVE WE LEARNED TODAY: 
        Class
        Obj -> Data Member && Behaviour
        Access Modifier -> Public, Private, Protected
        Static / Dynammic Allocation 
        Constructor -> Default, Parameterised, Copy
        Copy assignment operator
        Destructor -> Static, Dynamic
        Shallow copy && Deep copy
        Static data member
        Static functions

        
        HW: 
        Padding
        Greedy allignment
        Const function 
        Initialisation list 
    
    */  

    return 0;
}