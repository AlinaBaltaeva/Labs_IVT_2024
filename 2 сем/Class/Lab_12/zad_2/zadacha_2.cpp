#include <iostream>
#include <map>
#include "Money.h"
using namespace std;
typedef map<int, Money>TMap;
typedef TMap::iterator it;

TMap make_map(int n)
{
	TMap m;
	Money a;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		m.insert(make_pair(i, a));
	}
	return m;
}

TMap add_map(TMap m, int pos, int el)
{
	TMap temp;
	int size = m.size() + 1;
	int i = 0;
	int j = i;
	while (i < size && j < size)
	{
		if (i == pos)
		{
			temp.insert(make_pair(pos, m[el]));
			temp.insert(make_pair(i + 1, m[i]));
			j++;
		}
		else
		{
			temp.insert(make_pair(j, m[i]));

		}
		i++;
		j++;
	}
	m = temp;
	return m;
}


void print_map(TMap m)
{
	cout << "Map: " << endl;
	for (int i = 0; i < m.size(); i++)
	{
		cout << "Element: " << i << " : " << m[i] << endl;
	}
}

Money Srednee(TMap v)
{
	Money s = v[0];
	for (int i = 0; i < v.size(); i++)
	{
		s = s + v[i];
	}
	int n = v.size();
	return s / n;
}

int Max_i(TMap v)
{
	it i = v.begin();
	int n = 0, k = 0;
	Money m = (*i).second;
	while (i != v.end())
	{
		if (m < (*i).second)
		{
			m = (*i).second;
			n = k;
		}
		i++;
		k++;
	}
	return n;
}

Money Max(TMap v)
{
	it i = v.begin();
	int n = 0, k = 0;
	Money m = (*i).second;
	while (i != v.end())
	{
		if (m < (*i).second)
		{
			m = (*i).second;
			n = k;
		}
		i++;
		k++;
	}
	return m;
}

int Min(TMap v)
{
	it i = v.begin();
	int n = 0;
	int k = 0;
	Money m = (*i).second;
	while (i != v.end())
	{
		if (m > (*i).second)
		{
			m = (*i).second;
			n = k;
		}
		i++;
		k++;
	}
	return n;
}

Money Min_i(TMap v)
{
	it i = v.begin();
	int n = 0;
	int k = 0;
	Money m = (*i).second;
	while (i != v.end())
	{
		if (m > (*i).second)
		{
			m = (*i).second;
			n = k;
		}
		i++;
		k++;
	}
	return m;
}

void Del(TMap& v)
{
	Money s = Srednee(v);
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] > s)
		{
			v.erase(i);
		}
	}
}

void Umn(TMap& v)
{
	Money m = Max(v);
	for (int i = 0; i < v.size(); i++)
	{
		v[i] = v[i] * m;
	}
}


void main()
{
	int n;
	cout << "N: "; cin >> n;
	TMap m = make_map(n);
	print_map(m);
	int el = Min(m);
	cout << "Min: " << m[el] << endl;
	cout << "Position: ";
	int pos; cin >> pos;
	TMap add = add_map(m, pos, el);
	m = add;
	print_map(m);
	Money sr = Srednee(m);
	cout << "Srednee: " << sr << endl;
	Del(m);
	print_map(m);
	Money mx = Max(m);
	cout << "Max: " << mx << endl;
	Umn(m);
	print_map(m);



}