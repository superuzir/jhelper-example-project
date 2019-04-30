#include <bits/stdc++.h>

using namespace std;

#define all(c) c.begin(), c.end()
#define pb push_back
#define forn(i, n)  for(ll i = 0; i < ll(n); ++i)
#define forn1(i, n) for(ll i = 1; i < ll(n); ++i)
#define nfor(i, n)  for(ll i = ll(n) - 1; i >= 0; --i)
#define nfor1(i, n) for(ll i = ll(n) - 2; i >= 0; --i)
#define forr(elem, vec) for(auto & elem : vec)
struct WhiteSpacedCout { bool space; std::ostream& out; explicit WhiteSpacedCout(std::ostream& out) : space(false), out(out) {} ~WhiteSpacedCout() { out << std::endl; }  WhiteSpacedCout & start() {return *this;} template <typename T> WhiteSpacedCout &operator , (const T &t) { if (space) out << ' '; else space = true; out << t; return *this; } };
#define print WhiteSpacedCout(out).start(),
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define by(x) [](const auto& a, const auto& b) { return a.x < b.x; } // C++14
#define eq(x) [](const auto& a, const auto& b) { return a.x == b.x; } // C++14
#define fi first
#define se second

template<typename T1, typename T2> std::ostream &operator<<(std::ostream &s, const std::pair<T1,T2> &x){ s << "pair(" << x.first << " ," << x.second << ')'; return s; }
template<typename T> std::ostream &operator<<(std::ostream &s, const std::vector<T> &x){ if(x.empty()){ s << "vector(empty)"; return s;} s << "vector("; for(size_t i = 0; i < x.size() - 1; i++){ s << x[i] << ", "; } s << x[x.size() - 1] << ')'; return s; }

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<string> vs;
typedef vector<ll> vll;
typedef vector<pll> vpll;

template<typename T> static vector<T> vin(ll n, std::istream& in){ vector<T> ret; forn(i, n){ T val; in >> val; ret.pb(val); } return ret; }
template<typename T> static T read(std::istream& in){ T val; in >> val; return val; }
template<typename T> void answer(const T & cont, std::ostream & out){ for(auto & v : cont){ out << v << ' '; }; out << '\n'; }

#define read_vll(n) vin<ll>(n, in)
#define read_vs(n)  vin<string>(n, in)
#define read_s()    read<string>(in)
#define read_ll()   read<ll>(in)

#define max_ll std::numeric_limits<ll>::max()
#define min_ll std::numeric_limits<ll>::min()
#define min3(a,b,c) std::min(std::min(a, b), c)
#define max3(a,b,c) std::max(std::max(a, b), c)

const ll MOD = 1000000007;
