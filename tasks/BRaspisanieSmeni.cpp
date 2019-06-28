#include <iostream>

#include "../library/lib.hpp"

class BRaspisanieSmeni
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		auto s = read_s();
		auto t = read_s();

		ll n = t.size();

		vll lps(n);

		forn1(i, n)
		{
			ll j = lps[i - 1];

			while(j > 0 && t[i] != t[j])
				j = lps[j - 1];

			if(t[i] == t[j])
				j++;

			lps[i] = j;
		}

		auto p = t.substr(0, t.size() - lps.back());

		ll sc0 = count(all(s), '0');
		ll sc1 = count(all(s), '1');

		ll pc0 = count(all(p), '0');
		ll pc1 = count(all(p), '1');

		string ans;

		while(sc0 >= pc0 && sc1 >= pc1)
		{
			sc0 -= pc0;
			sc1 -= pc1;

			ans += p;
		}

		auto left = p;
		
		forn(i, p.size())
		{
			if(p[i] == '0') 
			{
				if(!sc0)
					break;
				
				ans += '0';
				sc0--;
			}
			if(p[i] == '1') 
			{
				if(!sc1)
					break;
				
				ans += '1';
				sc1--;
			}
		}

		ans += string(sc0, '0');
		ans += string(sc1, '1');

		print ans;
	}
};
