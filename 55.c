//55. ��Ծ��Ϸ

//�������治������ֵ�������Ը�һ��
//����ͨ����Ŀ�е���Ծ�������������Զ
//����ܹ�Խ�����һ�񷵻�true�����򷵻�false
//���ַ��������ݵĺ������ԣ����һ��λ���ܹ����
//��ô���λ���������λ�ö��ܵ�� �뵽��һ�㣬�ⷨ�ͺ�֮������
//https://leetcode-cn.com/problems/jump-game/solution/55-by-ikaruga/
class Solution {
public:
	bool canJump(vector<int>& nums)
	{
		int n = nums.size();
		int farthest = 0;
		for (int i = 0; i < n; ++i)
		{
			if (i > farthest)
				return false;
			farthest = max(farthest, i + nums[i]);
		}
		return true;
	}
};