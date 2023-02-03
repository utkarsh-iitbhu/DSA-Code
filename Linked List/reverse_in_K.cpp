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
    Node *next;
    int data;
    Node(int data){
        this->data = data;
        next = NULL;
    }
};

void insertAtLast(Node* &tail, int data){
    // new node create
    Node *temp = new Node(data);
    tail->next = temp;
    tail = tail->next;
}


void print_ll(Node* head){
    Node *temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

Node* reverse_ll(Node* head){
    Node *prev = NULL;
    Node *curr = head;
    Node *next = NULL;
    while(curr){
        // For forward traversal, next is assigned to curr->next
        next = curr->next;
        // Ab curr se pointer hatake peech point karva do
        curr->next = prev;
        // Ab pahle prev ko aage badhao aur fir curr ko 
        prev = curr;
        curr = next;
    }
    head = prev;
    return prev;
}

void recursive_rr(Node* &head, Node* &curr, Node* prev){
    
    // BAse case last me
    if(!curr){
        head = prev; 
        return ; 
    }

    Node *forward = curr->next; // Forword is assigned to curr->next
    recursive_rr(head, forward, curr); // Recursive call is made
    // This is important. cur->next ko prev karoge to poora ll reverse hoga
    curr->next = prev; // curr->next is assigned to prev
}

Node* recursion_op(Node* &head, int k){
    
    if(!head){
        return head;
    }
    
    // Step 1: iterative reverse first K nodes 
    Node *prev = NULL;
    Node *curr = head;
    Node *next = NULL;
    int l = 0 ; 
    // If curr exists and l<k then only move
    while(curr && l<k){
        // For forward traversal, next is assigned to curr->next
        next = curr->next;
        // Ab curr se pointer hatake peech point karva do
        curr->next = prev;
        // Ab pahle prev ko aage badhao aur fir curr ko 
        prev = curr;
        curr = next;
        l++;
    }
    
    
    // Step 2: Recursion aage dekhega
    // If next exists then only send karo 
    if(next){
        // Head ke next me hi jodte jao as head ab reversed hai
        cout<<"Curr: "<<curr->data <<endl;
        cout<<"Prev: "<<prev->data <<endl;
        head->next = recursion_op(next, k);
    }

    // step 3: Return head of reverse ll 
    return prev;

}

Node* middleNode(Node* head){
    Node *slow = head;
    Node *fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

void solve(){

    Node *head = new Node(1);
    Node *tail = head;
    insertAtLast(tail, 2);
    insertAtLast(tail, 3);
    insertAtLast(tail, 4);
    insertAtLast(tail, 5);
    insertAtLast(tail, 6);
    
    cout<<"Before reverse"<<endl;
    print_ll(head);

    cout<<"Middle Node "<<endl;
    print_ll(middleNode(head));

    cout<<"After reverse"<<endl;
    // print_ll(reverse_ll(head));
    // print_ll(tail);

    // Recursion se reverse
    // Node *curr = head; 
    // Node *prev = NULL;
    // recursive_rr(head, curr, prev);
    // print_ll(head);

    // REcusrion OP 
    print_ll(recursion_op(head,2));

}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

#ifndef ONLINE_JUDGE
freopen("Error.txt", "w", stderr);
#endif


solve(); 

return 0;}