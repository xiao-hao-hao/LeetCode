/*
// Definition for Employee.
class Employee {
public:
int id;
int importance;
vector<int> subordinates;
};
*/
/*
class Solution {
public:
void dfs(unordered_map<int, Employee*> &info, int &sum, int id)
{
//这里无需判断边界，for循环就是一个边界，下属为空，直接结束
sum += info[id]->importance;
for (const auto &subid : info[id]->subordinates)
dfs(info, sum, subid);
}
int getImportance(vector<Employee*> employees, int id)
{
if (employees.empty())
return 0;
unordered_map<int, Employee*> info;
//把员工信息用map存储，方便后面的使用
for (const auto &e : employees)
info[e->id] = e;
int sum = 0;
dfs(info, sum, id);
return sum;
}
};
*/

class Solution {
public:
	int dfs(unordered_map<int, Employee*> &info, int id)
	{
		int curImpo = info[id]->importance;
		for (const auto &subid : info[id]->subordinates)
			curImpo += dfs(info, subid);
		return curImpo;
	}
	int getImportance(vector<Employee*> employees, int id)
	{
		if (employees.empty())
			return 0;
		unordered_map<int, Employee*> info;
		//把员工信息用map存储，方便后面的使用
		for (const auto &e : employees)
			info[e->id] = e;
		int sum = 0;
		return dfs(info, id);
	}
};