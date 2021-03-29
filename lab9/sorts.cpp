#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <fstream>

using namespace std;

void merge(vector<double>* A, int p, int q, int r)
{

	int n1, n2, i, j, k;
      
	n1 = q - p + 1;
	n2 = r - q;
	vector<double> L(n1), R(n2);

	for (i = 0; i < n1; i++)
	{
		L[i] = (*A)[p + i];
	}

	for (j = 0; j < n2; j++)
	{
		R[j] = (*A)[q + j + 1];
	}
	i = 0, j = 0;

	for (k = p; i < n1 && j < n2; k++)
	{
		if (L[i] < R[j])
		{
			(*A)[k] = L[i++];
		}
		else
		{
			(*A)[k] = R[j++];
		}
	}

	while (i < n1)
	{
		(*A)[k++] = L[i++];
	}

	while (j < n2)
	{
		(*A)[k++] = R[j++];
	}
}

void merge_sort(vector<double>* A, int p, int r)
{
	int q;
	if (p < r)
	{
		q = (p + r) / 2;
		merge_sort(A, p, q);
		merge_sort(A, q + 1, r);
		merge(A, p, q, r);
	}
}

int main() {
	mt19937 engine(23);
	uniform_real_distribution<double> real_dist(0, 10000);
	ofstream f;
	for (size_t k = 500; k < 15001; k += 500)
	{

		vector<double> unsorted;
		double tmp;

		for (size_t i = 0; i < k; i++)
		{
			double r1 = real_dist(engine);
			unsorted.push_back(r1);
		}

		vector<double> a = unsorted;


		{
			int comparisons = 0;
			int swaps = 0;

			f.open("bubble.txt", ios::app);
			auto start = chrono::high_resolution_clock::now();

			for (size_t i = 0; i < a.size() - 1; i++)
			{
				for (size_t j = 0; j < a.size() - i - 1; j++)
				{
					if (a[j] > a[j + 1] and ++comparisons)
					{
						tmp = a[j];
						a[j] = a[j + 1];
						a[j + 1] = tmp;
						swaps++;
					}
				}
			}

			auto end = chrono::high_resolution_clock::now();
			auto nsec = end - start;

			std::cout << k << ' ';
			f << k << "\t" << nsec.count() << '\t' << comparisons << '\t' << swaps << endl;

			f.close();
		}

		{
			int comparisons = 0;
			int swaps = 0;
			f.open("choice.txt", ios::app);
			a = unsorted;
			auto start = chrono::high_resolution_clock::now();

			for (size_t start = 0; start < a.size() - 1; ++start)
			{
				int ind = start;
				for (size_t current = start + 1; current < a.size(); ++current)
				{
					if (a[current] < a[ind] and ++comparisons)
					{
						ind = current;
					}
				}
				tmp = a[ind];
				a[ind] = a[start];
				a[start] = tmp;
				swaps++;
			}

			auto end = chrono::high_resolution_clock::now();
			auto nsec = end - start;
			f << k << "\t" << nsec.count() << '\t' << comparisons << '\t' << swaps << endl;
			f.close();
			std::cout << k << ' ';
		}
		{
			int comparisons = 0;
			int swaps = 0;
			f.open("insertion.txt", ios::app);
			a = unsorted;
			auto start = chrono::high_resolution_clock::now();

			int j;
			double value;

			for (int i = 1; i < a.size(); i++)
			{
				value = a[i];
				j = i - 1;

				while (j >= 0 and a[j] > value and ++comparisons)
				{
					a[j + 1] = a[j];
					j = j - 1;
					swaps++;
				}
				a[j + 1] = value;
				swaps++;
			}

			auto end = chrono::high_resolution_clock::now();
			auto nsec = end - start;
			f << k << "\t" << nsec.count() << '\t' << comparisons << '\t' << swaps << endl;
			f.close();
			std::cout << k << ' ';
		}
			
		{
			f.open("merge.txt", ios::app);
			a = unsorted;
			auto start = chrono::high_resolution_clock::now();

			merge_sort(&a, 0, a.size() - 1);

			auto end = chrono::high_resolution_clock::now();
			auto nsec = end - start;
			f << k << "\t" << nsec.count() << endl;
			f.close();
			std::cout << k << endl;
		}
		
	}
}