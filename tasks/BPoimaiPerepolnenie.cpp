#include <iostream>

#include "../library/lib.hpp"

class BPoimaiPerepolnenie
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll l = read_ll();

		ll mul = 1;

		stack<ll> stk;
		stack<ll> stk2;

		ll ans = 0;

		vll forv;

		forn(i, l)
		{
			auto cmd = read_s();

			if (cmd == "for")
			{
				ll m = read_ll();
				stk.push(m);
				stk2.push(m);
			}

			if (cmd == "end")
			{
				if(stk2.size())
				{
					stk.pop();
					stk2.pop();
				}
				else
				{
					ll m = stk.top();
					mul /= m;
					stk.pop();
				}
			}

			if (cmd == "add")
			{
				ll m = 1;

				while(stk2.size())
				{
					m *= stk2.top();
					stk2.pop();

					if(m >= (1ll << 32))
					{
						print "OVERFLOW!!!";
						return;
					}
				}

				mul *= m;

				if(mul >= (1ll << 32))
				{
					print "OVERFLOW!!!";
					return;
				}

				ans += mul;
				
				if(ans >= (1ll << 32))
				{
					print "OVERFLOW!!!";
					return;
				}
			}
		}

		print ans;
	}
};
