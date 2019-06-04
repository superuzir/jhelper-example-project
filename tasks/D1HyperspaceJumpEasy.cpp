#include <iostream>

#include "../library/lib.hpp"
#include "../library/itersame.h"

class D1HyperspaceJumpEasy
{
	struct Ship
	{
		ll nom;
		ll denom;
		ll idx;
		ll ans;

		bool operator<(const Ship &rhs) const
		{
			return std::tie(nom, denom, idx, ans) < std::tie(rhs.nom, rhs.denom, rhs.idx, rhs.ans);
		}

		bool operator==(const Ship &rhs) const
		{
			return std::tie(nom, denom) == std::tie(rhs.nom, rhs.denom);
		}

		friend ostream &operator<<(ostream &os, const Ship &ship)
		{
			os << "nom: " << ship.nom << " denom: " << ship.denom << " idx: " << ship.idx << " ans: " << ship.ans;
			return os;
		}
	};

public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();

		vector<Ship> coords;

		forn(i, n)
		{
			char _;
			in >> _;

			ll a; in >> a;
			ll b; in >> b;

			in >> _;
			in >> _;

			ll c; in >> c;

			Ship p = {a + b, c, i, 0};
			ll g = __gcd(p.nom, p.denom);

			p.nom /= g;
			p.denom /= g;

			coords.pb(p);
		}

		sort(all(coords));

		itersameall(coords, { ll ans = e - b; for(; b != e; ++b) b->ans = ans; });

		sort(all(coords), by(idx));

		forr(c, coords)
			out << c.ans << " ";

		out << endl;
	}
};
