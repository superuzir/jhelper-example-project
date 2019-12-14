#include <iostream>

#include "../library/lib.hpp"

class CProstoKakOneITwo
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll t = read_ll();

		forn(_, t)
		{
			auto s = read_s();

			ll i = 0;

			vll ans;

			while(i != string::npos){
				i = s.find("twone", i);

				if(i != string::npos){
					ans.pb(i + 2 + 1);
					s[i + 2] = 'x';
				}
			}

			i = 0;

			while(i != string::npos){
				i = s.find("one", i);

				if(i != string::npos){
					ans.pb(i + 1 + 1);
					s[i + 1] = 'x';
				}
			}

			i = 0;

			while(i != string::npos){
				i = s.find("two", i);

				if(i != string::npos){
					ans.pb(i + 1 + 1);
					s[i + 1] = 'x';
				}
			}

			print ans.size();
			answer(ans, out);
		}
	}
};
