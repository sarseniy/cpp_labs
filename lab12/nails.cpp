#include <iostream>
#include <vector>

using namespace std;

void sort(vector<int>& a)
{
	for (size_t i = 0; i < a.size() - 1; i++)
	{
		for (size_t j = i + 1; j < a.size(); j++)
		{
			if (a[j] < a[i])
			{
				swap(a[i], a[j]);
			}
		}
	}
}

/*
В данной задаче сначала отсортируем массив coord по возрастанию.
В массив frame будем записывать минимальные длины нити, необходимые для связывания i гвоздей.
Базовой задачей является соединение 2-х или 3-х гвоздиков.
В этом случае вариантов нет и минимальная длина нити равна расстоянию между гвоздиками.
(2 и 1, 3 и 1 соответственно)
При добавлении i-ого гвоздя появляются варианты:
1) T.....T   T--T
    |i-2|   i-1 i
   Т.е. оставить уд. условию задачи группу из i-2 гвоздей и связать вместе i-1 и i.
   В таком случае длина нити будет равна frame[i-2] + coord[i] - coord[i-1]
2) T.....T--T
    |i-1|   i
   Привязать i гвоздик к группе из i-1 гвоздиков, которые уд. условию задачи.
   В таком случае длина нити равна frame[i-1] + coord[i] - coord[i-1]
Тогда ответ на задачу будет лежать в ячейке frame[n-1].
*/

int main()
{
	int n;
	cin >> n;
	vector<int> coord(n);
	vector<int> frame(n);
	for (int i = 0; i < n; i++)
	{
		cin >> coord[i];
	}
	sort(coord);
	frame[1] = coord[1] - coord[0];
	frame[2] = coord[2] - coord[0];
	for (int i = 3; i < n; i++)
	{
		frame[i] = min(frame[i - 1], frame[i - 2]) + coord[i] - coord[i - 1];
	}
	cout << frame[n - 1];
}