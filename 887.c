//鸡蛋掉落

//dp[K][N]=x表示有K个鸡蛋，N层楼，确定F的值的最小移动次数是x
//base case 如果N为0，不需要扔鸡蛋；如果K为1，需要线性扫描所有楼层
//超时
/*
class Solution {
public:
int superEggDrop(int K, int N)
{
vector<vector<int>> dp(K+1, vector<int>(N+1, INT_MAX));
//base case
for (int i = 0; i <= N; ++i)
dp[0][i] = -1;
for (int i = 0; i <= K; ++i)
dp[i][0] = 0;
for (int i = 0; i <= N; ++i)
dp[1][i] = i;
for (int i = 1; i <= N; ++i)
{
for (int j = 2; j <= K; ++j)
{
for (int m = 1; m <= i; ++m)//第一次在第m层扔
{
dp[j][i] = min(dp[j][i], max(dp[j-1][m-1], dp[j][i-m])+1);
}
}
}
return dp[K][N];
}
};
*/

//dp[k][m]=n表示当前有k个鸡蛋，可以尝试扔m次鸡蛋
//这个状态下最坏情况最多能确切测试一栋n层的楼
/*
class Solution {
public:
int superEggDrop(int K, int N)
{
//鸡蛋扔0次可以测试0层楼
vector<vector<int>> dp(K+1, vector<int>(N+1, 0));
int m = 0;
while (dp[K][m] < N)
{
++m;
for (int k = 1; k <= K; ++k)
dp[k][m] = dp[k][m-1] + dp[k-1][m-1] + 1;
}
return m;
}
};
*/

/*
2 100  两个鸡蛋100层楼，第一次从第几层楼扔
dp[2][10] = dp[2][9] + dp[1][9] = 1+...+9 = ((1+9)/2)*9;
((1+x)/2)*x>=100  x=14  d第一次应该从第dp[1][13]+1层楼扔,也就是第14层楼
在第一次没碎的情况下，相当于两个鸡蛋可以扔13次，从15楼开始到100楼，第二次dp[1][12]+1+14=27楼扔
在第一次碎的情况下，遍历
*/
//优化
class Solution {
public:
	int superEggDrop(int K, int N)
	{
		//0个鸡蛋或者鸡蛋扔0次可以测试0层楼
		vector<int> dp(K + 1, 0);
		int m = 0;
		while (dp[K] < N)
		{
			++m;
			int pre = dp[0], cur = 0;
			for (int k = 1; k <= K; ++k)
			{
				cur = dp[k];
				dp[k] = dp[k] + pre + 1;
				pre = cur;
			}
		}
		return m;
	}
};


/*
解释一下最后一种解法中的递推公式是怎么来的。
dp[k][m] 表示用 k 个鸡蛋移动 m 步可以“保证求解”的最大楼层数。
我们先解释一下定义中的几个概念：
所谓“求解”，意思就是给定楼层 N，我们能否找到临界楼层 F(F <= N)，使得鸡蛋从 F 层掉落刚好不会被摔碎。所谓“保证求解”，意思就是即使每次丢鸡蛋的结果都很差，最终仍能求解。
比如，给定 1 个鸡蛋移动 1 步，那么可以求解的最大楼层数为 1，即从 1 楼丢下，如果鸡蛋碎了，求得 F=0，如果鸡蛋没碎，求得 F=1。在这种情况下，假如我们给出一个 2 层的楼，就无法保证求解了，因为无论从哪一层丢出鸡蛋，都没有十足的把握能够一次求得 F，换句话说，虽然我们仍有一定的机会能够求解，但无法“保证求解”。
下面回到正题：
假设我们有 k 个鸡蛋可以移动 m 步，考虑某一步 t 应该在哪一层丢鸡蛋？一个正确的选择是在 dp[k-1][t-1] + 1 层丢鸡蛋，结果分两种情况：
如果鸡蛋碎了，我们首先排除了该层以上的所有楼层（不管这个楼有多高），而对于剩下的 dp[k-1][t-1] 层楼，我们一定能用 k-1 个鸡蛋在 t-1 步内求解。因此这种情况下，我们总共可以求解无限高的楼层。可见，这是一种非常好的情况，但并不总是发生。
如果鸡蛋没碎，我们首先排除了该层以下的 dp[k-1][t-1] 层楼，此时我们还有 k 个蛋和 t-1 步，那么我们去该层以上的楼层继续测得 dp[k][t-1] 层楼。因此这种情况下，我们总共可以求解 dp[k-1][t-1] + dp[k][t-1] + 1 层楼。
容易想象，在所有 m 步中只要有一次出现了第一种情况，那么我们就可以求解无限高的楼层。但“保证求解”的定义要求我们排除一切运气成分，因此我们只得认为每次移动都遇到第二种情况。于是得到递推公式：
dp[k][t] = dp[k-1][t-1] + dp[k][t-1] + 1
基本的问题已经解决了，但是我们还遗留了一个问题：为什么要选择在 dp[k-1][t-1] + 1 层丢鸡蛋？
现在我们已经知道，如果我们每一步都在 dp[k-1][t-1] + 1 层丢鸡蛋，最终是一定能够求解的。但如果我们选择在更低的层或者更高的层丢鸡蛋会怎样呢？我们分两种情况讨论：
在更低的楼层丢鸡蛋。同样能够“保证求解”，但最终得到的并不是“最大”楼层数，我们没有充分挖掘鸡蛋数和移动次数的潜力，最终求解时会剩余一定量的鸡蛋或移动次数。
在更高的楼层丢鸡蛋。不妨假设高了一层，即在第 dp[k-1][t-1] + 2 层丢鸡蛋。如果鸡蛋碎掉了，我们仍然可以排除该层以上的所有楼层（不管这个楼有多高），但接下来就不好办了，因为我们剩下的 k-1 个鸡蛋在 t-1 步内只能“保证求解” dp[k-1][t-1] 的楼层，而现在剩余的楼层却是 dp[k-1][t-1] + 1，多了一层，因此无法“保证求解”！
综上，我们用排除法证明了每一步都应该在第 dp[k-1][t-1] + 1 层丢鸡蛋。
*/