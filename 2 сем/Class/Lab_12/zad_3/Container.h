#pragma once
#include <iostream>
#include <map>
using namespace std;

template<class T>
class Container
{
	map<int, T> v;
	int len;
public:
	Container();
	Container(int n);
	void Print();
	~Container();
	T Srednee();
	T Max();
	int Max_i();
	T Min();
	int Min_i();
	void Umn();
	void Del();
	void Add_map(int pos, T el);
};

template<class T>
Container<T>::Container() { len = 0; }

template<class T>
Container<T>::~Container() {};

template<class T>
Container<T>::Container(int n)
{
	T a;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		v[i] = a;
	}
	len = v.size();
}

template<class T>
void Container<T>::Print()
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << "Element: " << i << ": " << v[i] << endl;
	}
	cout << endl;
}


template<class T>
void Container<T>::Add_map(int pos, T el)
{
	map<int, T> temp;
	int size = v.size() + 1;
	int i = 0;
	int j = i;
	while (i < size && j < size)
	{
		if (i == pos)
		{
			temp.insert(make_pair(pos, el));
			temp.insert(make_pair(i + 1, v[i]));
			j++;
		}
		else
		{
			temp.insert(make_pair(j, v[i]));

		}
		i++;
		j++;
	}
	v = temp;

}

template<class T>
T Container<T>::Srednee()
{
	T s = v[0];
	for (int i = 0; i < v.size(); i++)
	{
		s = s + v[i];
	}
	int n = v.size();
	return s / n;
}

template<class T>
int Container<T>::Max_i()
{
	typename map<int, T>::iterator i = v.begin();
	int n = 0, k = 0;
	T m = (*i).second;
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


template<class T>
T Container<T>::Max()
{
	typename map<int, T>::iterator i = v.begin();
	int n = 0, k = 0;
	T m = (*i).second;
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

template<class T>
int Container<T>::Min_i()
{
	typename map<int, T>::iterator i = v.begin();
	int n = 0, k = 0;
	T m = (*i).second;
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

template<class T>
T Container<T>::Min()
{
	typename map<int, T>::iterator i = v.begin();
	int n = 0, k = 0;
	T m = (*i).second;
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

template<class T>
void Container<T>::Del()
{
	T s = Srednee();
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] > s)
		{
			v.erase(i);
		}
	}
}

template<class T>
void Container<T>::Umn()
{
	T m = Max();
	for (int i = 0; i < v.size(); i++)
	{
		v[i] = v[i] * m;
	}
}
