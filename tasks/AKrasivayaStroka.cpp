#include <iostream>

#include "../library/lib.hpp"
#include "../library/itersame.h"


class AKrasivayaStroka
{
public:
	static char other(char c){
		if(c == 'a') return 'b';
		if(c == 'b') return 'c';
		if(c == 'c') return 'a';
		exit(1);
	}

	static char other(char c1, char c2){
		if(c1 > c2)
			swap(c1, c2);

		if(c1 == 'a' && c2 == 'c') return 'b';
		if(c1 == 'a' && c2 == 'b') return 'c';
		if(c1 == 'b' && c2 == 'c') return 'a';
		if(c1 == 'a' && c2 == 'a') return 'b';
		if(c1 == 'b' && c2 == 'b') return 'c';
		if(c1 == 'c' && c2 == 'c') return 'a';
		exit(1);
	}

	void solve(std::istream& in, std::ostream& out)
	{
		ll t = read_ll();

		forn(_, t){
			auto s = read_s();

			{
				bool ok = true;

				itersameall(s, {
					if(*b != '?' && e - b > 1)
						ok = false;
				});

				if(!ok)
				{
					print -1;
					continue;
				}
			}

			itersameall(s, {
				if(*b != '?')
					return;

				char c = b != s.begin() ? *(b - 1) : 'a';

				while(e - b > 1)
				{
					*b = other(c);
					c = *b;
					++b;
				}
			});

			if(s.size() == 1)
			{
				if(s[0] == '?')
					s[0] = 'a';
			}
			else if(s.size() == 2)
			{
				if(s[0] == '?')
					s[0] = other(s[1]);

				if(s[1] == '?')
					s[1] = other(s[0]);
			}
 			else
			{
				forlr(i, 2, s.size())
				{
					if (s[i - 1] == '?')
						s[i - 1] = other(s[i - 2], s[i]);
				}
				
				if(s[0] == '?')
					s[0] = other(s[1]);

				if(s[s.size() - 1] == '?')
					s[s.size() - 1] = other(s[s.size() - 2]);
			}
				
			print s;
		}
	}
};
