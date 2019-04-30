#include <iostream>

#include "../library/lib.hpp"

class CProstiePrefiksnieSummi
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		vll vec = read_vll(n);

		ll ones = count(all(vec), 1);
		ll twos = count(all(vec), 2);

		if(ones && twos)
		{
			string ans;

			ans += "21";
			twos--;
			ones--;

			ans += string(twos, '2');
			ans += string(ones, '1');

			answer(ans, out);
		}
		else
		{
			answer(vec, out);
		}
	}
};
