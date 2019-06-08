#include <iostream>

#include "../library/lib.hpp"

class DMiliePosledovatelnosti
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll q = read_ll();

		forn(i_, q)
		{
			ll a = read_ll();
			ll b = read_ll();
			ll m = read_ll();

			ll suml = 0;
			ll sumh = 0;
			vll l, h;

			l.pb(a);
			h.pb(a);
			suml += l.back();
			sumh += h.back();

			while(l.back() <= b)
			{
				l.pb(suml + 1);
				h.pb(sumh + m);
				suml += l.back();
				sumh += h.back();
			}

//			print a, b, m;
//			print l;
//			print h;

			bool found = false;

			forn(i, l.size())
			{
				if(b >= l[i] && b <= h[i])
				{
					double part = m == 1 ? 0 : double(b - l[i]) / double(h[i] - l[i]);
//					print part;
//
//					forn(j, i)
//					{
//						print j, part * j, l[j] + (part * j);
//					}

					out << i + 1 << " ";


					forn(j, i)
					{
//						ll g = m == 1 ? 0 : j * (m - 1) * (b - l[i]) / (h[i] - l[i]);
//						out << l[j] + g << " ";
						out << ll(l[j] + round(part * (h[j] - l[j]))) << " ";
					}

					out << b << "\n";

//					ll dif = b - l[i];
//					
//					print dif;

					found = true;
					break;
				}
			}

			if(!found)
				print -1;
		}
	}
};
