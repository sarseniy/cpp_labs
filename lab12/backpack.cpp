#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int w;
	int n;
	cin >> w >> n;
	vector<vector<int>> frame(w + 1, vector<int>(n + 1, 0));

	vector<int> weight(n + 1, 0);
	vector<int> value(n + 1, 0);

	for (int i = 1; i < n + 1; i++)
	{
		cin >> value[i];
	}

	for (int i = 1; i < n + 1; i++)
	{
		cin >> weight[i];
	}

	for (int i = 1; i < w + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
		{
			if ((i - weight[j]) >= 0)
			{
				if (frame[i - weight[j]][j - 1] + value[j] > frame[i][j - 1])
				{
					frame[i][j] = frame[i - weight[j]][j - 1] + value[j];
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
	cout << frame[w][n];
}