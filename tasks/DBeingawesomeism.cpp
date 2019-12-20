#include <iostream>

#include "../library/lib.hpp"

class DBeingawesomeism
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll t = read_ll();

		forn(_, t)
		{
			ll r = read_ll();
			ll c = read_ll();

			auto s = read_vs(r);

			bool mort = true;
			bool allof = true;

			forr(ss, s)
			{
				if (ss.find('A') != string::npos)
					mort = false;
				if (ss.find('P') != string::npos)
					allof = false;
			}

			if(mort)
			{
				print "MORTAL";
				continue;
			}

			if(allof)
			{
				print 0;
				continue;
			}

			ll top = 0;
			ll bot = 0;
			ll rig = 0;
			ll lef = 0;

			ll toplef = 0;
			ll toprig = 0;
			ll botlef = 0;
			ll botrig = 0;

			forn(i, r)
			forn(j, c)
			{
				if(s[i][j] != 'A')
					continue;

				if(i == 0 && j == 0)
				{
					toplef++;
				}

				if(i == 0 && j == c - 1)
				{
					toprig++;
				}

				if(i == r - 1 && j == 0)
				{
					botlef++;
				}

				if(i == r - 1 && j == c - 1)
				{
					botrig++;
				}


				if(i == 0)
				{
					top++;
				}

				if(j == 0)
				{
					lef++;
				}

				if(i == r - 1)
				{
					bot++;
				}

				if(j == c - 1)
				{
					rig++;
				}
			}
			
			bool line = false;

			{
				forn(i, r)
				{
					ll cnt = 0;
					forn(j, c)
					{
						if(s[i][j] == 'A')
							cnt ++;
					}
					if(cnt == c)
					{
						line = true;
						break;
					}
				}
			}

			if(!line)
			{
				forn(j, c)
				{
					ll cnt = 0;
					forn(i, r)
					{
						if(s[i][j] == 'A')
							cnt ++;
					}
					if(cnt == r)
					{
						line = true;
						break;
					}
				}
			}
			
//			dbg(top, bot, lef, rig);
//			dbg(toplef, botlef, toprig, botrig);

			if(top == c || bot == c || lef == r || rig == r)
			{
				print 1;
			} else if(toplef || botlef || toprig || botrig || line){
				print 2;
			} else if(top || bot || lef || rig) {
				print 3;
			} else {
				print 4;
			}
		}
	}
};
