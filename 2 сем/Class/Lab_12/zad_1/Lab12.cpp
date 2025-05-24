#include <iostream>
#include <map>
using namespace std;
typedef map<int, float>TMap;
typedef TMap::iterator it;

TMap make_map(int n)
{
	TMap m;
	float a;
	for (int i = 0; i < n; i++)
	{
		cout << "Element double: ";
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

float Srednee(TMap v)
{
	float s = 0.0;
	for (int i = 0; i < v.size(); i++)
	{
		s += v[i];
	}
	int n = v.size();
	return s / n;
}

int Max(TMap v)
{
	it i = v.begin();
	int n = 0, k = 0;
	float m = (*i).second;
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

int Min(TMap v)
{
	it i = v.begin();
	int n = 0;
	int k = 0;
	float m = (*i).second;
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

void Del(TMap& v)
{
	float s = Srednee(v);
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
	int m = v[Max(v)];
	for (int i = 0; i < v.size(); i++)
	{
		v[i] = v[i] * m;
	}
}


void main()
{
	int n;
	cout << "Сколько значений выводить: "; cin >> n;
	TMap m = make_map(n);
	print_map(m);
	int el = Min(m);
	cout << "Минимальный: " << m[el] << endl;
	cout << "Позиция: ";
	int pos; cin >> pos;
	TMap add = add_map(m, pos, el);
	m = add;
	print_map(m);
	float sr = Srednee(m);
	cout << "Среднее: " << sr << endl;
	Del(m);
	print_map(m);
	cout << "Максимальное: " << m[Max(m)] << endl;
	Umn(m);
	print_map(m);



}