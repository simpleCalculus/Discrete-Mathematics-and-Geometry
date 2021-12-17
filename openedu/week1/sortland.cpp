#include <fstream>
#include <vector>

using namespace std;

int main()
{
	ifstream fin("input.txt");
    ofstream fout("output.txt");
	int n;
	fin >> n;
	vector<double> a(n), b(n);
	for (int i = 0; i < n; i++) 
	{
		fin >> a[i];
		b[i] = i + 1;
	}
	for (int i = 1; i < n; i++)
	{
		if (a[i] < a[i - 1])
		{
			int j = i;
			double x = a[i];
			int y = b[i];
			while (j > 0 && x < a[j - 1])
			{
				a[j] = a[j - 1];
				b[j] = b[j - 1];
				j--;
			}
			a[j] = x;
			b[j] = y;
		} 
	}
	fout << b[0] << " " << b[n / 2] << " " << b[n - 1];
	return 0;
}
