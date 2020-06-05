//45����Ծ��Ϸ2

/*
//�Զ����µĵݹ鶯̬�滮
//���壺������p�������һ��������Ҫdp(nums,p)��
//������Ҫ�Ľ������dp(nums, p)
//base case���ǵ�p�����������һ��ʱ����Ҫ��Ծ
class Solution {
public:
int jump(vector<int>& nums)
{
int n = nums.size();
//����¼����ʼ��Ϊn���൱��INT_MAX
//��Ϊ��0����n-1���n-1��
memo = vector<int>(n, n);
return dp(nums, 0);
}
int dp(vector<int>& nums, int p)
{
int n = nums.size();
//base case
if (p >= n - 1)
return 0;
//�������Ѿ������
if (memo[p] != n)
return memo[p];
int steps = nums[p];
//����ѡ����1����2��...
for (int i = 1; i <= steps; ++i)
{
//���ÿһ��ѡ�񣬼���ÿһ��������Ľ��
int subProblem = dp(nums, p+i);
//��ȡ������С����Ϊ���ս��
memo[p] = min(memo[p], subProblem+1);
}
return memo[p];
}
private:
vector<int> memo;
};
*/
/*
//dp[n]��ʾ������n�������һ��������Ҫdp[n]��
//������Ҫ�Ľ������dp[0]
//base case���ǵ�p�����������һ��ʱ����Ҫ��Ծ
//dp[nums.size()-1] = 0
class Solution {
public:
int jump(vector<int>& nums)
{
int n = nums.size();
//����¼����ʼ��Ϊn���൱��INT_MAX
//��Ϊ��0����n-1���n-1��
vector<int> dp(n, n);
dp[n-1] = 0;
for (int i = n-2; i >= 0; --i)
{
int steps = nums[i];
for (int j = 1; j <= steps; ++j)
{
if (i+j == n-1)
dp[i] = 1;
else if (i+j < n-1)
dp[i] = min(dp[i], dp[i+j]+1);
else
break;
}
}
return dp[0];
}
};
*/

//̰���㷨
//https://leetcode-cn.com/problems/jump-game-ii/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-10/
//jumps��¼����Ծ�Ĵ���
//farthest��������п�ѡ����Ծ����[i...end]���ܹ���������Զ����
//end����˱�����Ծ�����ķ�Χ
class Solution {
public:
	int jump(vector<int>& nums)
	{
		int n = nums.size();
		int end = 0, farthest = 0, jumps = 0;
		for (int i = 0; i < n - 1; ++i)
		{
			//����������Զ��λ�õ��±�
			farthest = max(nums[i] + i, farthest);
			//�����߽磬�͸��±߽�(˵����������)�����Ҳ�����һ
			if (end == i)
			{
				++jumps;
				end = farthest;
			}
		}
		return jumps;
	}
};
