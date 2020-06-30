//活字印刷
//虽然此题中每一个位置的字符在组合中只能出现一次，但是tiles中可能有相同的字符
//所以需要考虑重复的组合而unordered_set可以天然去重，可以用其去重
class Solution {
public:
	void dfs(string& tiles, string curStr, vector<int>& book, unordered_set<string>& totalString)
	{
		if (!curStr.empty())
			totalString.insert(curStr);
		//标记保证所有位都用完之后就结束了
		for (int i = 0; i < tiles.size(); ++i)
		{
			//当前位置的字符已用过直接跳过
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
		//天然去重
		unordered_set<string> totalString;
		//标记全部初始化为未使用
		vector<int> book(tiles.size(), 0);
		dfs(tiles, "", book, totalString);
		return totalString.size();
	}
};