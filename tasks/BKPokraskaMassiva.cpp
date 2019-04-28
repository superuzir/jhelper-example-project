#include <iostream>

#include "../library/lib.hpp"

class BKPokraskaMassiva
{
public:
	struct Elem
	{
		ll idx;
		ll val;
		ll color;
	};

	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll k = read_ll();
		vll vec = read_vll(n);

		vector<Elem> el(n);

		forn(i, n)
			el[i] = {i, vec[i], -1};

		sort(all(el), by(val));

		ll skvoz_k = 1;
		
		itersame(all(el), [&](auto b, auto e){
			ll k1 = 1;

			for(auto it = b; it != e; ++ it)
			{
				if(k1 > k)
				{
					print "NO";
					exit(0);
				}

				it->color = skvoz_k;
				k1++;
				skvoz_k++;
				if(skvoz_k > k)
					skvoz_k = 1;
			}
		}, eq(val));

		sort(all(el), by(idx));

		print "YES";
		
		for(auto e : el)
		{
			out << e.color << " ";
		}
	}
};
