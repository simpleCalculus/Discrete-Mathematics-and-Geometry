#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	int **arr = new int *[n + 1];
	double **dp = new double *[n + 1];
	for (int i = 0; i <= n; ++i)
	{
		arr[i] = new int[m + 1];
		dp[i] = new double[m + 1];
	}
	for (int i = 0; i <= n; ++i)
	{
		dp[i][0] = i * 100.0;
	}
	for (int i = 0; i <= m; ++i)
	{
		dp[0][i] = i * 100.0;
	}
	for (int i = 0; i <= n; ++i)
	{
		for (int j = 0; j <= m; ++j)
		{
			arr[i][j] = 0;
		}
	}
	for (int i = 0; i < k; ++i)
	{
		int x, y;
		cin >> x >> y;
		arr[x][y] = 1;
	}
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			dp[i][j] = min(dp[i-1][j] + 100.0, dp[i][j-1] + 100.0);
			if (arr[i][j] == 1)
			{
				dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + sqrt(20000));
			}
		}
	}
	
	printf("%d", (int)(dp[n][m] + 0.5));
	
	for (int i = 0; i <= n; ++i)
	{
		delete[] arr[i];
		delete[] dp[i];
	}
  delete[] arr;
  delete[] dp;
}
