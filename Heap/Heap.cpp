#include <bits/stdc++.h>
using namespace std;
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define mod 1e9 + 7
#define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++)
#define FORL(a, b, c) for (int(a) = (b); (a) <= (c); (a)++)
#define FORR(a, b, c) for (int(a) = (b); (a) >= (c); (a)--)
#define INF 1000000000000000003
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define F first
#define S second
#define PB push_back
#define POB pop_back
#define MP make_pair

typedef pair<int, int> ppi;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

ll n; cin >> n;
ll a[n];
FOR(i, n)
cin >> a[i];

// HEAP is basically stack of a given size "k", where k is the number of elements in the heap.

// How do we define min and max heap 
// We define it using Priority queue

// For max-heap we use 
// priority_queue<int> maxheap ;

// For min-heap we use
priority_queue<int, vector<int>, greater<int>> minheap ;

// For using pair in priority queue we use
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minheap ;

// So instead of writting pair<..... we can use typedef
// typedef pair<int, int> ppi;
priority_queue<ppi, vector<ppi>, greater<ppi>> pairheap ; // Like this we can use ppi instead of pair<int, int>

return 0;}