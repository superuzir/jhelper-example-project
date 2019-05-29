#include <iostream>

#include "../library/lib.hpp"

class CNaimensheeSlovo
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		string str = read_s();
		
		forn(i, str.size() - 1)
			out << (str[i] != str[i + 1]) << " ";

		out << (str.back() == 'a') << "\n";
	}
};
