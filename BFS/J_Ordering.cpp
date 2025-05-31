// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <tuple>
#include <bitset>
using namespace std;

#ifdef TOWRIST
    #define debug(...) cout << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__);
#else
    #define debug(...);
#endif

template <typename T> ostream &operator<<(ostream &stream, const vector<T> &vec) {for (size_t i = 0; i < vec.size(); i++) { stream << vec[i]; if (i != vec.size() - 1) stream << ' '; }; return stream; } template <typename T> istream &operator>>(istream &stream, vector<T> &vec) {for (T &x : vec) stream >> x; return stream; } template <typename T, typename U> ostream &operator<<(ostream &stream, const pair<T, U> &pr) {stream << pr.first << ' ' << pr.second; return stream; } template <typename T, typename U> istream &operator>>(istream &stream, pair<T, U> &pr) {stream >> pr.first >> pr.second; return stream; } template <typename A, typename B> string to_string(pair<A, B> p); template <typename A, typename B, typename C> string to_string(tuple<A, B, C> p); template <typename A, typename B, typename C, typename D> string to_string(tuple<A, B, C, D> p); string to_string(const string &s) { return '"' + s + '"'; } string to_string(char c) {string s; s += c; return s; } string to_string(const char *s) { return to_string((string)s); } string to_string(bool b) { return (b ? "1" : "0"); } string to_string(vector<bool> v) {bool first = true; string res = "{"; for (int i = 0; i < static_cast<int>(v.size()); i++) {if (!first) {res += ", "; } first = false; res += to_string(v[i]); } res += "}"; return res; } template <size_t N> string to_string(bitset<N> v) {string res = ""; for (size_t i = 0; i < N; i++) {res += static_cast<char>('0' + v[i]); } return res; } template <typename A> string to_string(A v) {bool first = true; string res = "{"; for (const auto &x : v) {if (!first) {res += ", "; } first = false; res += to_string(x); } res += "}"; return res; } template <typename A, typename B> string to_string(pair<A, B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; } template <typename A, typename B, typename C> string to_string(tuple<A, B, C> p) { return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")"; } template <typename A, typename B, typename C, typename D> string to_string(tuple<A, B, C, D> p) { return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")"; } void debug_out() { cout << endl; } template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) {cout << " " << to_string(H); debug_out(T...); }

#define int             long long
#define all(x)          x.begin(), x.end()
#define double          long double
#define endl            '\n'
#define ff              first
#define ss              second
#define v               vector
#define pb              push_back
#define bit(num, i)     (num & (1ll << i))

using pii = pair<int, int>;
const bool multipleTestCases = 0;
v<int> dx{1, -1, 0, 0, 1, 1, -1, -1};
v<int> dy{0, 0, 1, -1, 1, -1, 1, -1};
string dir = "DURL";
int INF = 1e18;

void backtrack(v<v<int>> &adj, v<int> &in, v<bool> &visited, string &curr, v<string>& res, unordered_map<int, char>& map2){
    if(curr.size() == in.size()){
        res.pb(curr);
        return;
    }
    for(int i = 0; i < in.size(); i++){
        if(!visited[i] && in[i] == 0){
            curr += map2.at(i);
            visited[i] = true;
            for(auto nb: adj[i]){
                in[nb]--;
            }
            backtrack(adj, in, visited, curr, res, map2);
            curr.pop_back();
            visited[i] = false;
            for(auto nb: adj[i]){
                in[nb]++;
            }
        }
    }
}
void solve()
{
    int num;
    cin >> num;
    cin.ignore();
    while (num--) {

        string vars, edges, empty;

        getline(cin, empty);
        getline(cin, vars);
        getline(cin, edges);

        unordered_map<char, int> map1;
        unordered_map<int, char> map2;
        int count = 0;

        sort(all(vars));

        for(int i = 0; i < vars.size(); i++){
            if(vars[i] == ' ') continue;
            map1.insert({vars[i], count});
            map2.insert({count, vars[i]});
            count++;
        }

        int n = map2.size();

        v<set<int>> adjSet(n);
        v<int> in(n, 0);
        for(int i = 0; i < edges.size(); i+=4){
            char uc = edges[i];
            char vc = edges[i+2];

            int u = map1.at(uc);
            int v = map1.at(vc);

            if(adjSet[u].insert(v).second) {
                in[v]++;
            }
        }

        v<v<int>> adj(n);
        for(int i = 0; i < n; i++){
            adj[i] = v<int>(all(adjSet[i]));
        }

        v<bool> visited(n, false);
        string curr = "";
        v<string> res;
        
        backtrack(adj, in, visited, curr, res, map2);
        if(res.empty()) {
            cout << "NO" << endl;
        } else {
            for(auto curr : res){
                for(int i = 0; i < curr.size(); i++) {
                    if(i > 0) cout << " ";
                    cout << curr[i];
                }
                cout << endl;
            }
        }
        if(num) cout << endl;

    }
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
    }
}
