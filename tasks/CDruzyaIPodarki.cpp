#include <iostream>

#include "../library/lib.hpp"


class CDruzyaIPodarki
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		auto v = read_vll(n);

		set<ll> s;
		{
			vll t(n);
			iota(all(t), 1);
			s = set<ll>(all(t));
		}

		vll idx;

		forn(i, n){
			if(v[i])
				s.erase(v[i]);
			else
				idx.pb(i + 1);
		}

		vll ss(all(s));

		forn(i, idx.size()){
			if(ss[i] == idx[i])
				swap(idx[i], idx[(i + 1) % idx.size()]);
		}

//		dbg(ss);
//		dbg(idx);

		forn(i, idx.size()){
			v[idx[i] - 1] = ss[i];
		}

		answer(v, out);
	}
};
