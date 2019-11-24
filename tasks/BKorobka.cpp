#include <iostream>

#include "../library/lib.hpp"

class BKorobka
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll t = read_ll();
		forn(_, t)
		{
			ll n = read_ll();
			auto q = read_vll(n);


			set<ll> s;


			forlr(j, 1, q[0] + 1)
			{
				s.insert(j);

//				dbg(j);
			}
			
			ll f = q[0];

			vll ans;

			{
				auto it = prev(s.end());
				ans.pb(*it);
				s.erase(it);
			}

//			dbg(s);
			bool ok = true;
			
			forn1(i, n){
//				print f, q[i];

				forlr(j, f + 1, q[i] + 1)
				{
					s.insert(j);

//					dbg(j);
				}

//				dbg(s);
				
				if(s.size())
				{
					{
						auto it = prev(s.end());
						ans.pb(*it);
						s.erase(it);
					}
				} else {
					ok = false;
				}

				f = q[i];
			}

			if(ok && s.empty())
				answer(ans, out);
			else
				print -1;
		}
	}
};
