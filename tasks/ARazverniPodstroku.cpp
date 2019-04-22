#include <iostream>

#include "../library/lib.hpp"

class ARazverniPodstroku
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		string str = read<string>(in);

		forn1(i, n)
		{
			if(str[i] < str[i - 1])
			{
				print "YES";
				print i, i + 1;
				return;
			}
		}

		print "NO";
	}
};
