#include <iostream>

#include "../library/lib.hpp"

class BSbalansirovannayaPodstroka
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n; in >> n;
		string str; in >> str;

		vpll vec(n);

		ll sum = 0;

		forn(i, n)
		{
			sum += str[i] == '1' ? 1 : -1;

			vec[i] = {sum, i};

//			print vec[i];
		}

		vec.pb({0, -1});
		
		sort(all(vec));

		ll max_dif = 0;

		for(auto it = vec.begin(); it != vec.end();)
		{
			ll sum_to_find = it->first;

			auto to = std::find_if(it, vec.end(), [=](const pll & p){
				return p.first != sum_to_find;
			});

			max_dif = std::max(max_dif, (to - 1)->second - it->second);

//			print *it, *(to - 1);
			
			it = to;
		}

		print max_dif;
	}
};
