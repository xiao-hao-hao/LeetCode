//N皇后

//i.second==col 第i个皇后与当前这几个点在同一列
//i.first_i.second==row+col第i个皇后与当前点在撇上，横坐标+纵坐标值相等
//i.first-i.second==row-col第i个皇后与当前点在捺上，横坐标-纵坐标值相等
class Solution {
public:

	vector<vector<string>> transResult(vector<vector<pair<int, int>>>& solutions, int n)
	{
		//把每一种解决方案都转换为string形式即最终结果
		vector<vector<string>> ret;
		for (auto solution : solutions)
		{
			vector<string> solutionString(n, string(n, '.'));
			for (pair<int, int> &e : solution)
				solutionString[e.first][e.second] = 'Q';
			ret.push_back(solutionString);
		}
		return ret;
	}
	bool isValid(vector<pair<int, int>>& solution, int row, int col)
	{
		//判断当前行尝试的皇后位置是否和前面几行的皇后位置有冲突
		for (auto &e : solution)
		{
			if (e.second == col || e.first + e.second == row + col || e.first - e.second == row - col)
				return false;
		}
		return true;
	}
	void dfs(vector<vector<pair<int, int>>>& solutions, vector<pair<int, int>>& solution, int curRow, int n)
	{
		if (curRow == n)
		{
			solutions.push_back(solution);
			return;
		}
		//尝试当前行的每一个位置是否可以放置一个皇后
		for (int col = 0; col < n; ++col)
		{
			if (isValid(solution, curRow, col))
			{
				solution.push_back(make_pair(curRow, col));
				dfs(solutions, solution, curRow + 1, n);
				//回溯，删除当前位置，尝试当前行的其他位置
				solution.pop_back();
			}
		}
	}
	vector<vector<string>> solveNQueens(int n)
	{
		//按坐标位置存放所有解决方案
		vector<vector<pair<int, int>>> solutions;
		//存放一种解决方案中的所有皇后的位置
		vector<pair<int, int>> solution;
		dfs(solutions, solution, 0, n);
		//把坐标位置转换成string
		return transResult(solutions, n);
	}
};