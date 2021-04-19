#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int s;
	int n;
	cin >> s >> n;
	vector<int> nominals(n + 1, 0);
	for (size_t i = 1; i < n + 1; i++)
	{
		cin >> nominals[i];
	}

	vector<vector<int>> frame(s + 1, vector<int>(n + 1, 0));
	for (size_t i = 0; i < s + 1; i++)
	{
		frame[i][0] = s + 1;
	}
	for (size_t i = 0; i < n + 1; i++)
	{
		frame[0][i] = 0;
	}

	for (int j = 1; j < n + 1; j++)
	{
		for (int i = 1; i < s + 1; i++)
		{
			if ((i - nominals[j]) >= 0)
			{
				if (frame[i - nominals[j]][j] + 1 < frame[i][j - 1])
				{
					frame[i][j] = frame[i - nominals[j]][j] + 1;
				}
				else
				{
					frame[i][j] = frame[i][j - 1];
				}
			}
			else
			{
				frame[i][j] = frame[i][j - 1];
			}
		}
	}
	cout << frame[s][n];
}