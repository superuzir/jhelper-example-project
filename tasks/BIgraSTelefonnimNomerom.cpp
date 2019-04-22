#include <iostream>

#include "../library/lib.hpp"

class BIgraSTelefonnimNomerom
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		string str = read<string>(in);

		ll steps = (n - 11) / 2;
		ll eights = count(str.begin(), str.end() - 10, '8');

		if(steps >= eights)
			print "NO";
		else
			print "YES";
	}
};
