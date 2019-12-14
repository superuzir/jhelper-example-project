#include <iostream>

#include "../library/lib.hpp"

class BRestrictionsTomsk2019
{
public:
	ll idx(char c){
		return tolower(c) - 'a';
	}
	
	void solve(std::istream& in, std::ostream& out)
	{
		auto s = read_s();
		ll n = read_ll();

		vll cnt(26, max_ll);

		forn(i, n){
			char c = read<char>(in);

			cnt[idx(c)] = read_ll();
		}

		forr(c, s){
			if(cnt[idx(c)]){
				out << c;
				cnt[idx(c)]--;
			}
		}
		
		out << endl;
	}
};
