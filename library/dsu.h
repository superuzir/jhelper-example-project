#pragma once


class Dsu
{
public:
	Dsu(ll n)
		: parent(n)
		, rank(n)
	{}

	void make(ll v)
	{
		parent[v] = v;
		rank[v] = 0;
	}

	ll find(ll v)
	{
		if (v == parent[v])
			return v;
		return parent[v] = find(parent[v]);
	}

	ll unite(ll a, ll b)
	{
		a = find(a);
		b = find(b);
		if (a != b)
		{
			if (rank[a] < rank[b])
				swap(a, b);
			parent[b] = a;
			if (rank[a] == rank[b])
				++rank[a];
		}

		return find(a);
	}

	void out(std::ostream& out)
	{
		map<ll, vll> map;

		forn(i, parent.size())
		{
			ll p = find(i);
			map[p].pb(i);
		}

		print "Dsu", map;
	}

private:
	vll parent;
	vll rank;
};
