#include <iostream>

#include "../library/lib.hpp"

class AKlonirovanieIgrushek
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll copy = read_ll();
		ll orig = read_ll();

		if(orig == 0)
		{
			print "No";
			return;
		}

		ll clone_orig = orig - 1;
		
		if(clone_orig == 0 && copy != 0)
		{
			print "No";
			return;
		}
		
		ll copy_left = copy - clone_orig;

		if(copy_left < 0 || copy_left % 2)
		{
			print "No";
			return;
		}

		print "Yes";
	}
};
