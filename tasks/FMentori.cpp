#include <iostream>

#include "../library/lib.hpp"
#include "../library/itersame.h"

class FMentori
{
	struct Ment
	{
		ll skill;
		ll ssor;
		ll idx;
		ll ans;

		friend ostream &operator<<(ostream &os, const Ment &ment)
		{
			os << "skill: " << ment.skill << " ssor: " << ment.ssor << " ans: " << ment.ans;
			return os;
		}
	};

public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll k = read_ll();

		vector<Ment> ms;

		forn(i, n)
		{
			ms.pb({read_ll(), 0, i, 0});
		}

		forn(i, k)
		{
			pll s = read_pll();
			
			if(ms[s.se - 1].skill > ms[s.fi - 1].skill)
				ms[s.se - 1].ssor++;

			if(ms[s.se - 1].skill < ms[s.fi - 1].skill)
				ms[s.fi - 1].ssor++;
		}

		sort(all(ms), by(skill));

		itersame(all(ms), [&](auto b, auto e){ 
			ll ans = b - ms.begin();
			
			for(; b != e; ++b)
			{
				b->ans = ans - b->ssor;
			}
		}, eq(skill) );

		sort(all(ms), by(idx));

//		print ms;

		forr(m, ms)
		{
			out << m.ans << ' ';
		}
		
		out << endl;
	}
};
