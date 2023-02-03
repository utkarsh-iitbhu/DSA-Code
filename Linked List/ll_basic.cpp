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

class Node{
public:
    int data;
    Node *next;
    Node(int d){
        data = d;
        next = NULL;
    }
    ~Node(){
        int val = this->data;
        
        //memory free
        if(this->next == NULL){
            delete next; 
            this->next = NULL;
        }
        cout<<"~Node()"<<endl;
    }
};

void insertAtHead(Node* &head, int data){
    // new node create
    Node *temp = new Node(data);
    temp->next = head;
    head = temp; 
}

void insertAtLast(Node* &tail, int data){
    // new node create
    Node *temp = new Node(data);
    tail->next = temp;
    tail = tail->next;
}

void insertAtMiddle(int pos, int data, Node* &head, Node* &tail){
    // insert at start
    if(pos==1){ insertAtHead(head,data); return;}
    Node *temp = head;
    int cnt = 1;
    while(cnt<pos-1){
        temp = temp->next; 
        cnt++;
    }

    // insert at last
    if(temp->next==NULL){
        insertAtLast(tail,data);
        return;
    }

    // create node for data
    Node *newNode = new Node(data);
    newNode->next = temp->next;
    temp->next = newNode; 
    
}

void printll(Node* &head){
    Node *temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    } 
    cout << endl;
}

void deleteNode_pos(int pos, Node* &head){
    if(pos==1){
        Node *temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node *temp = head; 
    int cnt = 1; 
    while(cnt<pos-1){
        temp = temp->next; 
        cnt++; 
    }
    temp->next = temp->next->next;
}

void deleteNode_val(int val, Node* &head){
    Node *temp = head; 
    while(!temp->next){
        if(temp->next->data==val){
            break;
        }
        temp = temp->next; 
    }
    temp->next = temp->next->next;
}

void solve(){
    Node *node1 = new Node(1);
    Node *root = node1;
    printll(root);
    insertAtHead(root, 2);
    insertAtHead(root, 3);
    cout<<"Insert node at head :"<<endl;
    printll(root);
    
    Node *node2 = new Node(1);
    Node *tail = node2; 
    insertAtLast(tail, 2);
    insertAtLast(tail, 3);
    insertAtLast(tail, 5);
    insertAtLast(tail, 6);
    cout<<"Insert node at last :"<<endl;
    printll(node2);

    cout<<"Insert node at middle :"<<endl;
    insertAtMiddle(4, 4, node2,tail);
    printll(node2);

    cout<<"Delete node at pos 3 :"<<endl;
    deleteNode_pos(3,node2);
    printll(node2);

    cout<<"Delete node at val 4 :"<<endl;
    deleteNode_val(4,node2);
    printll(node2);


}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

#ifndef ONLINE_JUDGE
freopen("Error.txt", "w", stderr);
#endif


solve(); 

return 0;}