#include <bits/stdc++.h>

using namespace std;

#define all(c) c.begin(), c.end()
#define soa(c) sort(all(c))
#define sua(c) accumulate(all(c), 0ll)
#define pb push_back
#define forn(i, n)  for(ll i = 0; i < ll(n); ++i)
#define forn1(i, n) for(ll i = 1; i < ll(n); ++i)
#define nfor(i, n)  for(ll i = ll(n) - 1; i >= 0; --i)
#define nfor1(i, n) for(ll i = ll(n) - 2; i >= 0; --i)
#define forlr(i, l, r) for(ll i = l; i < ll(r); ++i)
#define forrl(i, l, r) for(ll i = ll(r) - 1; i >= l; --i)
#define forr(elem, vec) for(auto & elem : vec)
#define print WhiteSpacedCout(out).start(),
#define dbg(...) pr_dbg(out, #__VA_ARGS__, __VA_ARGS__);
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define by(x) [](const auto& a, const auto& b) { return a.x < b.x; } // C++14
#define eq(x) [](const auto& a, const auto& b) { return a.x == b.x; } // C++14
#define fi first
#define se second
#define divceil(x, y) (((x) + (y) - 1) / (y))

template<typename T1, typename T2> std::ostream &operator<<(std::ostream &s, const std::pair<T1,T2> &x){ s << "pair(" << x.first << " ," << x.second << ')'; return s; }
template<typename T> std::ostream &operator<<(std::ostream &s, const std::vector<T> &x){ if(x.empty()){ s << "vector(empty)"; return s;} s << "vector("; for(size_t i = 0; i < x.size() - 1; i++){ s << x[i] << ", "; } s << x[x.size() - 1] << ')'; return s; }
template<typename V>             std::ostream &operator<<(std::ostream &s, const std::set<V> &x)        { if(x.empty()){ s << "set(empty)";      return s;} s << "set(";      for(auto it = x.begin(); it != x.end();){ auto & v = *it; s << v; if(++it != x.end()) s << ", "; else s << ")"; } return s; }
template<typename V>             std::ostream &operator<<(std::ostream &s, const std::multiset<V> &x)   { if(x.empty()){ s << "multiset(empty)"; return s;} s << "multiset("; for(auto it = x.begin(); it != x.end();){ auto & v = *it; s << v; if(++it != x.end()) s << ", "; else s << ")"; } return s; }
template<typename K, typename V> std::ostream &operator<<(std::ostream &s, const std::map<K, V> &x)     { if(x.empty()){ s << "map(empty)";      return s;} s << "map(";      for(auto it = x.begin(); it != x.end();){ auto & v = *it; s << v.fi << "=" << v.se; if(++it != x.end()) s << ", "; else s << ")"; } return s; }
template<typename K, typename V> std::ostream &operator<<(std::ostream &s, const std::multimap<K, V> &x){ if(x.empty()){ s << "multimap(empty)"; return s;} s << "multimap("; for(auto it = x.begin(); it != x.end();){ auto & v = *it; s << v.fi << "=" << v.se; if(++it != x.end()) s << ", "; else s << ")"; } return s; }
template<typename T1, typename T2> std::istream & operator >> (std::istream &s, std::pair<T1,T2> & pair){ s >> pair.fi >> pair.se; return s;  }

struct WhiteSpacedCout { bool space; std::ostream& out; explicit WhiteSpacedCout(std::ostream& out) : space(false), out(out) {} ~WhiteSpacedCout() { out << std::endl; }  WhiteSpacedCout & start() {return *this;} template <typename T> WhiteSpacedCout &operator , (const T &t) { if (space) out << ' '; else space = true; out << t; return *this; } };

template<typename T> static void pr_dbg(std::ostream &s, const string& name, T t) { s << name << ": " << t << endl; }
template<typename T, typename ... Types> static void pr_dbg(std::ostream &s, const string& names, T t, Types ... rest) { auto comma_pos = names.find(','); s << names.substr(0, comma_pos) << ": " << t << ", "; pr_dbg(s, string(names, names.find_first_not_of(" \t\n", comma_pos + 1)), rest ...); }

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<string> vs;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<vll> vvll;
typedef vector<pll> vpll;
typedef vector<vll> Graph;

template<typename T> static vector<T> vin(ll n, std::istream& in){ vector<T> ret; forn(i, n){ T val; in >> val; ret.pb(val); } return ret; }
template<typename T> static vector<pair<T, ll>> vini(ll n, std::istream& in){ vector<pair<T, ll>> ret; forn(i, n){ T val; in >> val; ret.pb({val, i}); } return ret; }
template<typename T> static T read(std::istream& in){ T val; in >> val; return val; }
template<typename T> static void answer(const T & cont, std::ostream & out){ for(auto & v : cont){ out << v << ' '; }; out << '\n'; }

#define read_vll(n)   vin<ll>(n, in)
#define read_vlli(n)  vini<ll>(n, in)
#define read_vpll(n)  vin<pll>(n, in)
#define read_vplli(n) vini<pll>(n, in)
#define read_vs(n)    vin<string>(n, in)
#define read_s()      read<string>(in)
#define read_ll()     read<ll>(in)
#define read_pll()    read<pll>(in)

#define max_ll std::numeric_limits<ll>::max()
#define min_ll std::numeric_limits<ll>::min()
#define min3(a,b,c) std::min(std::min(a, b), c)
#define max3(a,b,c) std::max(std::max(a, b), c)

const ll MOD = 1000000007;
