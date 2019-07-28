#include <iostream>

#include "../library/lib.hpp"

class DSbalansirovannayaTroichnayaStroka
{
	void changeFirst(string & s, ll f, char before, char after)
	{
		forr(c, s)
		{
			if(!f)
				break;

			if(c == before)
			{
				--f;
				c = after;
			}
		}
	}

	void changeLast(string & s, ll f, char before, char after)
	{
		nfor(i, s.size())
		{
			char & c = s[i];

			if(!f)
				break;

			if(c == before)
			{
				--f;
				c = after;
			}
		}
	}

public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		auto s = read_s();

		ll c0 = count(all(s), '0');
		ll c1 = count(all(s), '1');
		ll c2 = count(all(s), '2');

		if(c0 < n/3)
		{
			if(c1 > n/3)
			{
				ll c = min(n/3 - c0, c1 - n/3);

				changeFirst(s, c, '1', '0');

				c0 += c;
				c1 -= c;
			}
			
			if(c0 < n/3 && c2 > n/3)
			{
				ll c = min(n/3 - c0, c2 - n/3);

				changeFirst(s, c, '2', '0');

				c0 += c;
				c2 -= c;
			}
		}

		if(c2 < n/3)
		{
			if(c2 < n/3 && c1 > n/3)
			{
				ll c = min(n/3 - c2, c1 - n/3);

				changeLast(s, c, '1', '2');

				c2 += c;
				c1 -= c;
			}

			if(c2 < n/3 && c0 > n/3)
			{
				ll c = min(n/3 - c2, c0 - n/3);

				changeLast(s, c, '0', '2');

				c2 += c;
				c0 -= c;
			}
		}

		if(c1 < n/3)
		{
			if(c2 > n/3)
			{
				ll c = min(n/3 - c1, c2 - n/3);

				changeFirst(s, c, '2', '1');

				c1 += c;
				c2 -= c;
			}

			if(c1 < n/3 && c0 > n/3)
			{
				ll c = min(n/3 - c1, c0 - n/3);

				changeLast(s, c, '0', '1');

				c1 += c;
				c0 -= c;
			}
		}

		print s;
	}
};
