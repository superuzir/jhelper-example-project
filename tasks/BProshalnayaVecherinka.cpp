#include <iostream>

#include "../library/lib.hpp"
#include "../library/itersame.h"

class BProshalnayaVecherinka
{
	struct Chel
	{
		ll other;
		ll idx;
		ll shlyapa;

		bool operator<(const Chel &rhs) const
		{
			return std::tie(other, idx, shlyapa) < std::tie(rhs.other, rhs.idx, rhs.shlyapa);
		}

		bool operator==(const Chel &rhs) const
		{
			return std::tie(other) == std::tie(rhs.other);
		}

		friend ostream &operator<<(ostream &os, const Chel &chel)
		{
			os << chel.shlyapa;
			return os;
		}
	};

public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		vector<Chel> vec;

		forn(i, n)
		{
			vec.pb({read_ll(), i, -1});
		}

		sort(all(vec));

		ll shlyapa = 1;
		bool imposibol = false;
		
		itersameall(vec,{
			if(imposibol)
				return;

			ll cnt_same = n - b->other;

			if(cnt_same > e - b || (e - b) % cnt_same)
			{
				imposibol = true;
				return;
			}

			ll cnt = (e - b) / cnt_same;

			forn(i, cnt)
			{
				forn(j, cnt_same)
				{
					b->shlyapa = shlyapa;
					b++;
				}

				shlyapa++;
			}
		});
		
		sort(all(vec), by(idx));
		
		if(imposibol)
			print "Impossible";
		else
		{
			print "Possible";
			answer(vec, out);
		}
	}
};
