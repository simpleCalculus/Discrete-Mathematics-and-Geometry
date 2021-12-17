#include <fstream>
#include <vector>

using namespace std;

int main()
{
	ifstream fin("input.txt");
    ofstream fout("output.txt");
	int n;
	fin >> n;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) 
		fin >> a[i];
	b[0] = 1;
	for (int i = 1; i < n; i++)
	{
		if (a[i] < a[i - 1])
		{
			int j = i;
			int x = a[i];
			while (j > 0 && x < a[j - 1])
			{
				a[j] = a[j - 1];
				j--;
			}
			a[j] = x;
			b[i] = j + 1;
		} else b[i] = i + 1; 
	}
	for (int i = 0; i < n; i++)
	{
		fout << b[i] << " ";
	}
	fout << "\n";
	for (int i = 0; i < n; i++)
	{
		fout << a[i] << " ";
	}
	return 0;
}
