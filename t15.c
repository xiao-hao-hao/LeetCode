//15. 三数之和
//大体思路就是：由三个元素组成的三元组，将三个元素按小到大的顺序排列(三个元素一定是会有顺序的)，这样便于
//得到没有重复的三元组，做法就是将nums排序，然后先确定第一个元素，后两个元素一定在这个元素后面，第三个元
//素一定在第二个元素后面，我们只要把所有可能的三元组遍历完就可以了
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