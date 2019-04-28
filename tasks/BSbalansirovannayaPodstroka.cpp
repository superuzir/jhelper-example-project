#include <iostream>

#include "../library/lib.hpp"

class BSbalansirovannayaPodstroka
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n; in >> n;
		string str; in >> str;

		vpll vec(n);

		ll sum = 0;

		forn(i, n)
		{
			sum += str[i] == '1' ? 1 : -1;

			vec[i] = {sum, i};

//			print vec[i];
		}

		vec.pb({0, -1});
		
		sort(all(vec));

		ll max_dif = 0;

		itersame(all(vec), [&](auto b, auto e)
		{
			max_dif = std::max(max_dif, (e - 1)->second - b->second);
		}, eq(fi));

		print max_dif;
	}
};
