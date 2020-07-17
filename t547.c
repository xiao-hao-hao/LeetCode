//547. ����Ȧ
/*
//ʱ�临�Ӷȣ�O(n^2),��������Ҫ������,��СΪn^2
//�ռ临�Ӷȣ�O(n),visited����Ĵ�С
class Solution {
public:
void dfs(vector<vector<int>> &M, vector<int> &visited, int i)
{
for (int j = 0; j < M.size(); ++j)
{
if (M[i][j]==1 && visited[j]==0)
{
visited[j] = 1;
dfs(M, visited, j);
}
}
}
int findCircleNum(vector<vector<int>>& M)
{
vector<int> visited(M.size(), 0);
int count = 0;
for (int i = 0; i < M.size(); ++i)
{
if (visited[i] == 0)
{
dfs(M, visited, i);
++count;
}
}
return count;
}
};
*/

class Solution {
public:
	int findCircleNum(vector<vector<int>>& M)
	{
		vector<int> visited(M.size(), 0);
		int count = 0;
		queue<int> q;
		for (int i = 0; i < M.size(); ++i)
		{
			if (visited[i] == 0)
			{
				q.push(i);
				while (!q.empty())
				{
					int s = q.front();
					q.pop();
					visited[s] = 1;
					for (int j = 0; j < M.size(); ++j)
					{
						if (M[s][j] == 1 && visited[j] == 0)
							q.push(j);
					}
				}
				++count;
			}
		}
		return count;
	}
};