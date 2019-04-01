#include <bits/stdc++.h>

using namespace std;

#define all(c) c.begin(), c.end()
#define pb push_back
#define forn(i, n)  for(ll i = 0; i < ll(n); ++i)
#define forn1(i, n) for(ll i = 1; i < ll(n); ++i)
#define nfor(i, n)  for(ll i = ll(n) - 1; i >= 0; --i)
struct WhiteSpacedCout { bool space; std::ostream& out; explicit WhiteSpacedCout(std::ostream& out) : space(false), out(out) {} ~WhiteSpacedCout() { out << std::endl; }  WhiteSpacedCout & start() {return *this;} template <typename T> WhiteSpacedCout &operator , (const T &t) { if (space) out << ' '; else space = true; out << t; return *this; } };
#define print WhiteSpacedCout(out).start(),
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define by(x) [](const auto& a, const auto& b) { return a.x < b.x; } // C++14
#define fi first
#define se second
#define th third

template<typename T1, typename T2> std::ostream &operator<<(std::ostream &s, const std::pair<T1,T2> &x){ s << "pair(" << x.first << " ," << x.second << ')'; return s; }
template<typename T> std::ostream &operator<<(std::ostream &s, const std::vector<T> &x){ if(x.empty()){ s << "vector(empty)"; return s;} s << "vector("; for(size_t i = 0; i < x.size() - 1; i++){ s << x[i] << ", "; } s << x[x.size() - 1] << ')'; return s; }

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<string> vs;
typedef vector<ll> vll;
typedef vector<pll> vpll;

template<typename T> static vector<T> vin(ll n){ vector<T> ret; forn(i, n){ T val; cin >> val; ret.pb(val); } return ret; }
