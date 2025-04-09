#pragma once
struct Money
{
	unsigned int first;
	unsigned int second;

	void Init(int, int);
	void Read();
	void Show();
	int sum();
};