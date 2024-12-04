#include <iostream>
using namespace std;
int main()
{
	int n, s, k;
	bool flag = false;

	cin >> n >> s;

	while (n > 0 && !flag)
	{
		flag = true;
		cout << "цифра найдена!" << endl;
	}
	if (!flag)
	{
		cout << "цифра найдена!" << endl;
		return 0;
	}
}