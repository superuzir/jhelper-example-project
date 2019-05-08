#include <iostream>

#include "../library/lib.hpp"

class BMinimalnayaTroichnayaStroka
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		auto s = read_s();
		ll n = s.size();

		auto first2 = s.find_first_of('2');
		
		if(first2 == string::npos)
		{
			sort(all(s));
			print s;
		}
		else
		{
			string ans = s.substr(0, first2);
			
			sort(all(ans));

			string pref;
			string suf;
			
			for(ll i = first2; i < n; i++)
			{
				if(s[i] == '1')
					pref += s[i];
				else
					suf += s[i];
			}

			print ans + pref + suf;
		}
	}
};
