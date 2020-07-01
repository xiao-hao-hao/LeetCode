//N�ʺ�

//i.second==col ��i���ʺ��뵱ǰ�⼸������ͬһ��
//i.first_i.second==row+col��i���ʺ��뵱ǰ����Ʋ�ϣ�������+������ֵ���
//i.first-i.second==row-col��i���ʺ��뵱ǰ�������ϣ�������-������ֵ���
class Solution {
public:

	vector<vector<string>> transResult(vector<vector<pair<int, int>>>& solutions, int n)
	{
		//��ÿһ�ֽ��������ת��Ϊstring��ʽ�����ս��
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
		//�жϵ�ǰ�г��ԵĻʺ�λ���Ƿ��ǰ�漸�еĻʺ�λ���г�ͻ
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
		//���Ե�ǰ�е�ÿһ��λ���Ƿ���Է���һ���ʺ�
		for (int col = 0; col < n; ++col)
		{
			if (isValid(solution, curRow, col))
			{
				solution.push_back(make_pair(curRow, col));
				dfs(solutions, solution, curRow + 1, n);
				//���ݣ�ɾ����ǰλ�ã����Ե�ǰ�е�����λ��
				solution.pop_back();
			}
		}
	}
	vector<vector<string>> solveNQueens(int n)
	{
		//������λ�ô�����н������
		vector<vector<pair<int, int>>> solutions;
		//���һ�ֽ�������е����лʺ��λ��
		vector<pair<int, int>> solution;
		dfs(solutions, solution, 0, n);
		//������λ��ת����string
		return transResult(solutions, n);
	}
};