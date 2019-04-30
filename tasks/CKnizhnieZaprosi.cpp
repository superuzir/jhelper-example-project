#include <iostream>

#include "../library/lib.hpp"

class CKnizhnieZaprosi
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();

		vll vec(3*n);
		map<ll, ll> map;

		ll curl = vec.size() / 2;
		ll curr = vec.size() / 2 + 1;

		forn(i, n)
		{
			char c = read<char>(in);
			ll id = read_ll();

			if(c == 'L')
			{
				vec[curl] = id;
				map[id] = curl--;
			}
			else if(c == 'R')
			{
				vec[curr] = id;
				map[id] = curr++;
			}
			else
			{
				auto it = map[id];

				ll l = it - curl - 1;
				ll r = curr - it - 1;

				print min(l, r);
			}
		}
	}
};
