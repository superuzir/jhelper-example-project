#include <iostream>

#include "../library/lib.hpp"

class BKubiki
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		auto s = read_s();

		ll bn = count(all(s), 'B');
		ll wn = count(all(s), 'W');

		if(bn % 2 && wn % 2)
		{
			print -1;
			return;
		}
		
		if(!bn || !wn)
		{
			print 0;
			return;
		}

		vll ans;

		forn1(i, n){
			string f;
			f+=s[i-1];
			f+=s[i];

			if(f == "BB")
				continue;

			if(f == "BW")
				continue;

			if(f == "WB")
			{
				swap(s[i-1], s[i]);
				ans.pb(i);
				continue;
			}

			if(f == "WW")
			{
				ans.pb(i);
				s[i-1] = 'B';
				s[i] = 'B';
			}
		}

		if(count(all(s), 'B') != s.size()){
			forn1(i, n){
				string f;
				f+=s[i-1];
				f+=s[i];

				if(f == "BB")
				{
					ans.pb(i);
					s[i-1] = 'W';
					s[i] = 'W';
				}
			}
		}

		print ans.size();
		answer(ans, out);
	}
};
