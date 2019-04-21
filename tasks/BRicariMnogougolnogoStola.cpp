#include <iostream>

#include "../library/lib.hpp"

class BRicariMnogougolnogoStola
{
public:
	struct Kn
	{
		ll power;
		ll coins;
		ll ans;
		ll idx;
	};

	struct Sum
	{
		ll k;
		ll sum = 0;
		multiset<ll> q;

		Sum(ll k) : k(k) {}

		void add(ll coins)
		{
			q.insert(coins);
			sum += coins;
			
			if(q.size() > k)
			{
				auto least = q.begin();
				sum -= *least;
				q.erase(least);
			}
		}
	};

	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll k = read_ll();

		vector<Kn> kn(n);

		{
			vll power = read_vll(n);
			vll coins = read_vll(n);
			forn(i, n) kn[i] = {power[i], coins[i], 0, i};
		}

		sort(all(kn), by(power));

		Sum sum(k);
		
		forn(i, n)
		{
			kn[i].ans = sum.sum + kn[i].coins;
			sum.add(kn[i].coins);
		}

		sort(all(kn), by(idx));

		forn(i, n)
			out << kn[i].ans << " ";

		out << endl;
	}
};
