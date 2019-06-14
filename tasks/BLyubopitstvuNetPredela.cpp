#include <iostream>

#include "../library/lib.hpp"

class BLyubopitstvuNetPredela
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		vll a = read_vll(n - 1);
		vll b = read_vll(n - 1);

		vll t1(n);
		vll t2(n);

		{
			bool ok = true;

			vll & t = t1;

			forn(i, n - 1)
			{
				ll ai = a[i] & 1;
				ll bi = b[i] & 1;
				
				if(t[i])
				{
					if(ai == 0){ ok = false; break; }
					t[i + 1] = bi;
				}
				else
				{
					if(bi == 1){ ok = false; break; }
					t[i + 1] = ai;
				}
			}
			
			if(!ok)
			{
				ok = true;

				t[0] = 1;

				forn(i, n - 1)
				{
					ll ai = a[i] & 1;
					ll bi = b[i] & 1;

					if(t[i])
					{
						if(ai == 0){ ok = false; break; }
						t[i + 1] = bi;
					}
					else
					{
						if(bi == 1){ ok = false; break; }
						t[i + 1] = ai;
					}
				}

				if(!ok)
				{
					print "NO";
					return;
				}
			}
		}


		{
			bool ok = true;

			vll & t = t2;

			forn(i, n - 1)
			{
				ll ai = a[i] >> 1;
				ll bi = b[i] >> 1;

				if(t[i])
				{
					if(ai == 0){ ok = false; break; }
					t[i + 1] = bi;
				}
				else
				{
					if(bi == 1){ ok = false; break; }
					t[i + 1] = ai;
				}
			}

			if(!ok)
			{
				ok = true;

				t[0] = 1;

				forn(i, n - 1)
				{
					ll ai = a[i] >> 1;
					ll bi = b[i] >> 1;

					if(t[i])
					{
						if(ai == 0){ ok = false; break; }
						t[i + 1] = bi;
					}
					else
					{
						if(bi == 1){ ok = false; break; }
						t[i + 1] = ai;
					}
				}

				if(!ok)
				{
					print "NO";
					return;
				}
			}
		}

		forn(i, n)
		{
			t1[i] |= t2[i] << 1;
		}

		print "YES";
		answer(t1, out);
	}
};
