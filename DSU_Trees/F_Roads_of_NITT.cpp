#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <tuple>
#include <bitset>
#include <algorithm>
#include <cmath>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <iomanip>
using namespace std;

#ifdef TOWRIST
    #define debug(...) cout << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__);
#else
    #define debug(...);
#endif

template <typename T> std::ostream &operator<<(std::ostream &stream, const vector<T> &vec) {for (size_t i = 0; i < vec.size(); i++) { stream << vec[i]; if (i != vec.size() - 1) stream << ' '; }; return stream; } template <typename T> std::istream &operator>>(std::istream &stream, vector<T> &vec) {for (T &x : vec) stream >> x; return stream; } template <typename T, typename U> std::ostream &operator<<(std::ostream &stream, const pair<T, U> &pr) {stream << pr.first << ' ' << pr.second; return stream; } template <typename T, typename U> std::istream &operator>>(std::istream &stream, pair<T, U> &pr) {stream >> pr.first >> pr.second; return stream; } template <typename A, typename B> string to_string(pair<A, B> p); template <typename A, typename B, typename C> string to_string(tuple<A, B, C> p); template <typename A, typename B, typename C, typename D> string to_string(tuple<A, B, C, D> p); string to_string(const string &s) { return '"' + s + '"'; } string to_string(char c) {string s; s += c; return s; } string to_string(const char *s) { return to_string((string)s); } string to_string(bool b) { return (b ? "1" : "0"); } string to_string(vector<bool> v) {bool first = true; string res = "{"; for (int i = 0; i < static_cast<int>(v.size()); i++) {if (!first) {res += ", "; } first = false; res += to_string(v[i]); } res += "}"; return res; } template <size_t N> string to_string(bitset<N> v) {string res = ""; for (size_t i = 0; i < N; i++) {res += static_cast<char>('0' + v[i]); } return res; } template <typename A> string to_string(A v) {bool first = true; string res = "{"; for (const auto &x : v) {if (!first) {res += ", "; } first = false; res += to_string(x); } res += "}"; return res; } template <typename A, typename B> string to_string(pair<A, B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; } template <typename A, typename B, typename C> string to_string(tuple<A, B, C> p) { return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")"; } template <typename A, typename B, typename C, typename D> string to_string(tuple<A, B, C, D> p) { return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")"; } void debug_out() { cout << endl; } template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) {cout << " " << to_string(H); debug_out(T...); }

#define int             long long
#define all(x)          x.begin(), x.end()
#define double          long double
#define endl            '\n'
#define ff              first
#define ss              second
#define v               vector
#define pb              push_back
#define bit(num, i)     (num & (1ll << i))
#define Yes             cout << "Yes" << endl
#define No              cout << "No" << endl
#define f(i, a, b, c) for (int i = (a); (c) > 0 ? i < (b) : i > (b); i += (c))

using pii = pair<int, int>;
const bool multipleTestCases = true;
v<int> dx{1, -1, 0, 0, 1, 1, -1, -1};
v<int> dy{0, 0, 1, -1, 1, -1, 1, -1};
string dir = "DURL";
int INF = 1e18;

struct DSU {
    v<int> vec;
    int n;
    int connectedPairs = 0;

    DSU(int N) {
        n = N;
        debug(n);
        vec = v<int>(N + 1, -1);
    }

    int parent(int x) {
        if (vec[x] < 0) return x;
        return vec[x] = parent(vec[x]);
    }

    void merge(int x, int y) {
        x = parent(x);
        y = parent(y);
        if (x == y) return;

        if (vec[x] < vec[y]) swap(x, y);

        int sizeX = vec[x];
        int sizeY = vec[y];
        connectedPairs += (sizeX * sizeY);
        debug(x, y, connectedPairs)

        vec[x] += vec[y];
        vec[y] = x;
    }

    long long disconnectedPairs() {
        return ((n * (n - 1)) / 2) - connectedPairs;
    }
};


void solve()
{
    int n;
    cin >> n;

    unordered_set<int> dQueries;
    v<pii> edges(n-1);
    f(i, 0, n-1, 1){
        cin >> edges[i].ff >> edges[i].ss;
    }
    int m;
    cin >> m;

    DSU d(n);

    v<pii> q;
    while(m--){
        char c; cin >> c;
        if(c == 'Q'){
            q.pb({1, 0});
        } else{
            int x; cin >> x;
            q.pb({2, x});
            dQueries.insert(x);
        }
    }

    f(i, 0, n - 1, 1){
        if (dQueries.find(i+1) == dQueries.end()){
            debug(dQueries, i)
            int a = edges[i].ff;
            int b = edges[i].ss;
            d.merge(a, b);
        }
    }
    v<int> ans;
    debug(edges)
    f(i, q.size()-1, -1, -1){
        auto [type, x] = q[i];
        debug(type, x)
        x--;
        if(type == 2){
            debug(edges[x])

            d.merge(edges[x].ff, edges[x].ss);
        }
        else{
            ans.pb(d.disconnectedPairs());
        }
    }

    reverse(all(ans));
    for(auto it : ans) cout << it << endl;
}  

signed main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int t = 1;
    multipleTestCases and cin >> t;
    for (int i = 1; i <= t; i++)
    {
        // cout << "Case #" << i << ": ";
        solve();
        cout << endl;
    }
}
