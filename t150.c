//150. 逆波兰表达式求值
class Solution {
public:
	int evalRPN(vector<string>& tokens)
	{
		stack<int> numbers;
		int left = 0, right = 0;
		for (int i = 0; i < tokens.size(); ++i)
		{
			if (tokens[i][1] == '\0' && (tokens[i][0] == '+' || tokens[i][0] == '-' || tokens[i][0] == '*' || tokens[i][0] == '/'))
			{
				right = numbers.top();
				numbers.pop();
				left = numbers.top();
				numbers.pop();
				switch (tokens[i][0])
				{
				case '+': numbers.pusah(left + right); break;
				case '-': numbers.push(left - right); break;
				case '*': numbers.push(left * right); break;
				case '/': numbers.push(left / right); break;
				default: break;
				}
			}
			else
			{
				numbers.push(atoi(tokens[i].c_str()));
			}

		}
		return numbers.top();
	}
};