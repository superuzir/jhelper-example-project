#include <iostream>

#include "../library/lib.hpp"

class DCvetnieBotinki
{
	struct Pair
	{
		int l;
		int r;
		int idx;
	};

public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n; in >> n;
		string sl, sr; in >> sl >> sr;

		vector<int> vl[26];
		vector<int> vr[26];

		vll anyl;
		vll anyr;

		forn(i, n)
		{
			if(sl[i] != '?')
				vl[sl[i] - 'a'].push_back(i + 1);
			else
				anyl.pb(i + 1);

			if(sr[i] != '?')
				vr[sr[i] - 'a'].push_back(i + 1);
			else
				anyr.pb(i + 1);
		}

		ll pairs = 0;

		forn(i, 26)
		{
			pairs += std::min(vl[i].size(), vr[i].size());
		}

		print std::min(ll(pairs + anyl.size() + anyr.size()), n);

		forn(i, 26)
		{
			while(vl[i].size() && vr[i].size())
			{
				int l = vl[i].back();
				int r = vr[i].back();

				vl[i].pop_back();
				vr[i].pop_back();
				print l, r;
			}
		}

		
		forn(i, 26)
		{
			while(anyl.size() && vr[i].size())
			{
				int l = anyl.back();
				int r = vr[i].back();
				
				anyl.pop_back();
				vr[i].pop_back();
				
				print l, r;
			}

			while(anyr.size() && vl[i].size())
			{
				int r = anyr.back();
				int l = vl[i].back();

				anyr.pop_back();
				vl[i].pop_back();

				print l, r;
			}
		}

		while(anyr.size() && anyl.size())
		{
			int r = anyr.back();
			int l = anyl.back();

			anyr.pop_back();
			anyl.pop_back();

			print l, r;
		}
	}
};
