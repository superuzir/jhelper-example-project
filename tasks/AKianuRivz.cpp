#include <iostream>

#include "../library/lib.hpp"

class AKianuRivz
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		auto s = read_s();

		ll c0 = count(all(s), '0');
		ll c1 = count(all(s), '1');

		if(c0 != c1)
		{
			print 1;
			print s;
		}
		else
		{
			print 2;
			out << s[0] << " " << s.substr(1) << endl;
		}
	}
};
