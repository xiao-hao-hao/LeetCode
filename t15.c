//15. ����֮��
//����˼·���ǣ�������Ԫ����ɵ���Ԫ�飬������Ԫ�ذ�С�����˳������(����Ԫ��һ���ǻ���˳���)����������
//�õ�û���ظ�����Ԫ�飬�������ǽ�nums����Ȼ����ȷ����һ��Ԫ�أ�������Ԫ��һ�������Ԫ�غ��棬������Ԫ
//��һ���ڵڶ���Ԫ�غ��棬����ֻҪ�����п��ܵ���Ԫ�������Ϳ�����
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums)
	{
		sort(nums.begin(), nums.end());
		vector<vector<int>> res;
		if (nums.size() < 3) return res;
		for (int k = 0; k < nums.size() - 2; ++k)
		{
			if (nums[k] > 0) break;
			if (k>0 && nums[k] == nums[k - 1]) continue;
			int i = k + 1, j = nums.size() - 1;
			while (i < j)
			{
				int sum = nums[k] + nums[i] + nums[j];
				if (sum < 0)
				{
					while (i<j && nums[i] == nums[++i]);
				}
				else if (sum > 0)
				{
					while (i<j && nums[j] == nums[--j]);
				}
				else
				{
					vector<int> tmp = { nums[k], nums[i], nums[j] };
					res.push_back(tmp);
					while (i<j && nums[i] == nums[++i]);
					while (i<j && nums[j] == nums[--j]);
				}
			}
		}
		return res;
	}
};