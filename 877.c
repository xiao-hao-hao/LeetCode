//ʯ����Ϸ
//dp[i][j].first��ʾ����piles[i...j]�ⲿ��ʯͷ�ѣ������ܻ�õ���߷���
//dp[i][j].second��ʾ����piles[i...j]�ⲿ��ʯͷ�ѣ������ܻ�õ���߷���
//��������Ĵ������ֵ����ŵ÷ֺͺ��ֵ����ŵ÷�֮�Ҳ����dp[0][n-1].first-dp[0][n-1].second
//״̬����ʼ������i������������j����ǰ�ֵ�����
//����ÿ��״̬����������ѡ����������ѡ������ߵ��Ƕ�ʯͷ����ѡ�����ұߵ��Ƕ�ʯͷ
//dp[i][j].first = max(piles[i] + dp[i+1][j].second, piles[j] + dp[i][j-1].second)
//dp[i][j].first = max(ѡ������ߵ�ʯͷ��,ѡ�����ұߵ�ʯͷ��)
//���ͣ�����Ϊ���֣���� piles[i...j] ʱ��������ѡ��
//Ҫô��ѡ������ߵ���һ��ʯͷ��Ȼ����� piles[i+1...j],���Ǵ�ʱ�ֵ��Է����൱���ұ���˺��֣�
//Ҫô��ѡ�����ұߵ���һ��ʯͷ��Ȼ����� piles[i...j-1],���Ǵ�ʱ�ֵ��Է����൱���ұ���˺��֡�
//if ����ѡ�����:dp[i][j].second = dp[i+1][j].first
//if ����ѡ���ұ�:dp[i][j].second = dp[i][j-1].first
class Solution {
public:
	bool stoneGame(vector<int>& piles)
	{
		int n = piles.size();
		vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n));
		//base case
		for (int i = 0; i < n; ++i)
		{
			dp[i][i].first = piles[i];
			dp[i][i].second = 0;
		}
		for (int i = n - 2; i >= 0; --i)//���µ��ϴ����ҽ��б���
		{
			for (int j = i + 1; j < n; ++j)
			{
				//����ѡ����ߵķ���������ѡ���ұߵķ���
				int left = piles[i] + dp[i + 1][j].second;
				int right = piles[j] + dp[i][j - 1].second;
				if (left > right)
				{
					dp[i][j].first = left;
					dp[i][j].second = dp[i + 1][j].first;
				}
				else
				{
					dp[i][j].first = right;
					dp[i][j].second = dp[i][j - 1].first;
				}
			}
		}
		return dp[0][n - 1].first > dp[0][n - 1].second;
	}
};


/*
//�Ż�
class Solution {
public:
bool stoneGame(vector<int>& piles)
{
int n = piles.size();
vector<pair<int, int>> dp(n);
//base case
for (int i = 0; i < n; ++i)
{
dp[i].first = piles[i];
dp[i].second = 0;
}
for (int i = n-2; i >= 0; --i)//���µ��ϴ����ҽ��б���
{
for (int j = i+1; j < n; ++j)
{
//����ѡ����ߵķ���������ѡ���ұߵķ���
int left = piles[i] + dp[j].second;
int right = piles[j] + dp[j-1].second;
if (left > right)
{
dp[j].second = dp[j].first;
dp[j].first = left;
}
else
{
dp[j].first = right;
dp[j].second = dp[j-1].first;
}
}
}
return dp[n-1].first > dp[n-1].second;
}
};
*/