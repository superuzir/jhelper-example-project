#include <iostream>

#include "../library/lib.hpp"
#include "../library/factorize.h"
#include "../library/itersame.h"


vll cong(vll f, ll k){
	vll ans;
	bool bad = false;

	itersameall(f, {
		if(e - b > k){
			bad = true;
		}

		forn(i, (e - b) == k ? k : k - (e - b))
			ans.pb(*b);
	});

	return bad ? vll() : ans;
}


vll simpl(vll f, ll k){
	vll ans;
	bool bad = false;

	itersameall(f, {
		if(e - b > k){
			bad = true;
		}

		forn(i, (e - b) <= k ? (e - b) : (e - b) % k)
			ans.pb(*b);
	});

	return bad ? vll() : ans;
}



class DProizvedeniyaStepeni
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll k = read_ll();
		auto vec = read_vll(n);

		map<vll, ll> m;

		ll ones = 0;
		ll ks = 0;

		if (vec[0] == 1)
		{
			ones++;
		}
		else
		{
			auto f = factorize(vec[0]);
			m[f]++;
		}
//		dbg(m, ones);

		ll ans = 0;

		forn1(i, n){

			if (vec[i] == 1)
			{
				ans += ks;

				ones++;
			}
			else
			{
				auto f = simpl(factorize(vec[i]), k);

				auto cg = cong(f, k);

//				dbg(f, cg);
				if(!cg.empty()) {
					ans += m[cg];
				}

				m[f]++;
				
				if(f.size() && f.size() % k == 0 && f.front() == f.back()){
					ks++;
					ans += ones;
				}
			}
			
			dbg(vec[i], m, ones, ans);


		}
		
		ans += ones * (ones - 1) / 2;

		print ans;
	}
};
