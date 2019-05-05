
template<typename T>
static vector<vector<T>> vin(ll n, ll m, std::istream& in)
{
	vector<vector<T>> ret(n);
	forn(i, n) ret[i] = vin<T>(m, in);
	return ret;
}

#define read_mll(n, m) vin<ll>(n, m, in)
