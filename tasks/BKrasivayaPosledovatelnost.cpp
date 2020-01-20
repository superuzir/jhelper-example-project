#include <iostream>

#include "../library/lib.hpp"

class BKrasivayaPosledovatelnost
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		auto vinit = read_vll(4);

		forn(st, 4){
			auto v = vinit;

			ll s = st;

			vll ans;

			while(sua(v)){
				if(v[s]){
					v[s]--;
					ans.pb(s);
					if(s > 0 && v[s - 1])
						s = s - 1;
					else if(s < 3 && v[s + 1])
						s = s + 1;
					else
						break;
				} else {
					break;
				}
			}

			if(sua(v) == 0){
				print "YES";
				answer(ans, out);
				return;
			}
		}

		print "NO";
	}
};
