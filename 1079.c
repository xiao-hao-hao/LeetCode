//����ӡˢ
//��Ȼ������ÿһ��λ�õ��ַ��������ֻ�ܳ���һ�Σ�����tiles�п�������ͬ���ַ�
//������Ҫ�����ظ�����϶�unordered_set������Ȼȥ�أ���������ȥ��
class Solution {
public:
	void dfs(string& tiles, string curStr, vector<int>& book, unordered_set<string>& totalString)
	{
		if (!curStr.empty())
			totalString.insert(curStr);
		//��Ǳ�֤����λ������֮��ͽ�����
		for (int i = 0; i < tiles.size(); ++i)
		{
			//��ǰλ�õ��ַ����ù�ֱ������
			if (book[i])
				continue;
			book[i] = 1;
			dfs(tiles, curStr + tiles[i], book, totalString);
			book[i] = 0;
		}
	}
	int numTilePossibilities(string tiles)
	{
		if (tiles.empty())
			return 0;
		//��Ȼȥ��
		unordered_set<string> totalString;
		//���ȫ����ʼ��Ϊδʹ��
		vector<int> book(tiles.size(), 0);
		dfs(tiles, "", book, totalString);
		return totalString.size();
	}
};