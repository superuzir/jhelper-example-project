#include <iostream>

#include "../library/lib.hpp"

class CServalISkobochnayaPosledovatelnost
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		auto s = read_s();
		n = s.size();

		if(s[0] == '?')
			s[0] = '(';

		if(s[n-1] == '?')
			s[n-1] = ')';

		if(s[0] != '(')
		{
			print ":(";
			return;
		}

		if(s[n-1] != ')')
		{
			print ":(";
			return;
		}

		ll op = 0;

		forn1(i, n - 1)
		{
			if(s[i] == '(') op++;
			if(s[i] == ')') op--;
		}

		if(op < 0)
		{
			forn1(i, n - 1)
			{
				if(op == 0)
					break;

				if(s[i] == '?')
				{
					s[i] = '(';
					op++;
				}
			}
		}

		if(op > 0)
		{
			lrfor(i, 1, n - 1)
			{
				if(op == 0)
					break;

				if(s[i] == '?')
				{
					s[i] = ')';
					op--;
				}
			}
		}


		if(op)
		{
			print ":(";
			return;
		}

		ll qc = count(all(s), '?');

		if(qc % 2)
		{
			print ":(";
			return;
		}

		ll qci = 0;

		forn(i, n)
		{
			if(s[i] == '?')
			{
				s[i] = qci < qc / 2 ? '(' : ')';
				qci++;
			}
		}

		forn1(i, n - 1)
		{
			op += s[i] == '(' ? 1 : -1;

			if(op < 0)
			{
				print ":(";
				return;
			}
		}

		print op ? ":(" : s;
	}
};
