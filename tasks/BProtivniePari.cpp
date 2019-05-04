#include <iostream>

#include "../library/lib.hpp"
#include "../library/itersame.h"

class BProtivniePari
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();

		forn(i, n)
		{
			string str = read_s();

			sort(all(str));

			vs st;

			itersame(all(str), [&](auto b, auto e)
			{
				st.pb(string(b, e));
			});

			if (st.size() == 1)
			{
				print st[0];
			}
			else if(st.size() == 2)
			{
				if(abs(st[0][0] - st[1][0]) == 1)
				{
					print "No answer";
				}
				else
				{
					string ans = st[0] + st[1];
					print ans;
				}
			}
			else if(st.size() == 3)
			{
				ll dif01 = abs(st[0][0] - st[1][0]);
				ll dif12 = abs(st[1][0] - st[2][0]);

				if(dif01 == 1 && dif12 == 1)
				{
					print "No answer";
				}
				else
				{
					if(dif12 > 1)
					{
						string ans = st[0] + st[2] + st[1];
						print ans;
					}
					else
					{
						string ans = st[1] + st[0] + st[2];
						print ans;
					}
				}
			}
			else if(st.size() >= 4)
			{
				string ans;
				for(ll j = st.size() - (st.size() % 2 == 0) - 1; j >= 0; j -= 2)
				{
					ans += st[j];
				}

				for(ll j = st.size() - (st.size() % 2) - 1; j >= 0; j -= 2)
				{
					ans += st[j];
				}
				print ans;
			}
		}
	}
};
