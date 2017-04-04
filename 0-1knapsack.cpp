#include<iostream>
#include <vector>
using namespace std;

int max(int a, int b) 
{
	return (a > b) ? a : b;
}
/*
	DP 函数是0-1背包问题的解决方案
	参数说明：
		V: 各个物品的体积(size 为n+1)
		P: 各个物品的价值(size 为n+1)
		n: 物品的个数
		c：背包的容量
	算法说明：
		采用一维数组的方式节省空间，状态转移方程为：dp[i][j]=max(dp[i-1][j],dp[i-1][j-V[i]]+P[i])
*/
int DP(vector<int> V, vector<int> P, int c, int n)
{
	vector<int> dp(c + 1, 0);
	for (int i = 1; i < n + 1; i++)//填n次表格
		for (int j = c; j >= V[i]; j--) //注意当下标有物理意义的时候，应该从1开始，型号也应为最大值+1，此处 i 代表第 i 件物品，j 代表背包容量，逆序记得j--（不是j++）
			dp[j] = max(dp[j], dp[j - V[i]] + P[i]);
	return dp[c];
}

/*
	驱动程序，测试0-1背包问题
*/
int main() 
{
	int n = 0, c = 0;
	cin >> n;
	vector<int>V(n + 1, 0);
	vector<int>P(n + 1, 0);
	for (int i = 0; i < n; i++) 
		cin >> V[i + 1] >> P[i + 1];
	cin >> c;
	int p = DP(V, P, c, n);
	cout << p;
	while (1);
	return 0;
}