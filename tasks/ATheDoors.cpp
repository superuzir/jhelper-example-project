#include <iostream>

#include "../library/lib.hpp"

class ATheDoors
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		vll vec = read_vll(n);
		
		itersame(all(vec), [&](auto b, auto e){
			if(e == vec.end())
			{
				print n - (e - b);
			}
		});
	}
};
