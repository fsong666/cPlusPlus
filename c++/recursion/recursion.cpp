/*
分治－递归
分－递推－即调用递归函数前的代码
治－回归－即递归函数之后的代码
*/

#include <iostream>
#include <vector>
using namespace std;

int rec(int n) {
	if (n <= 1) {
		return 1;
	}else {
		return n*rec(n-1);
	}
}

int recFor(int n) {
	if (n <= 1) {
		return 1;
	}else {
		for( int i = n; i < 5; i++ ) {
			return n*rec(n-1);
		}
	}
}

static int count = 0;
void recur(int i, int n)
{   
    count++;
    printf("B>");
    for(i; i <= n; i++){
        printf("I>");
        recur(i + 1, n);
        printf("R>");    
    }
}

void swap(int &a,int &b) {
	int temp;
    temp = a;
    a = b;
    b = temp;
}
//单递归，结构是个双向链表
//带for递归，整个结构是个树，总共有ｎ层，n*n个节点，
//每层循环次数在递减, 直到有一个数（收敛），否则无限递归, 所以递归停止条件即是收敛停止条件
//n排列，　是个树，有n*n个节点，　也即ｎ*n的矩阵
void perm(vector<int> list, int k , int m ) {
	if ( k == m) {
		 for(int i=0; i<=m; i++) 
            cout<< list[i] << "   ";
        cout<<endl;
        return;
	}
	//每层循环次数不断减小，
	for (int i = k; i <= m; i++) {
		swap(list[k], list[i]);//从ｋ位置到头开始排列
		perm(list, k+1, m);//k+1，减小下一层的循环次数
		swap(list[k], list[i]);//保持输入数组为最开始的顺序
	}

}

void comSum(vector<int>& candidates, int target, int start, vector<int>& out, vector<vector<int>>& res) {
    if (target < 0) return;
    if (target == 0) {
        res.push_back(out);
		for (auto n : out) {
			cout<< n << "   ";
		}
		cout<<endl;
        return;
    }
    for (int i = start; i < candidates.size(); i++) {
        out.push_back(candidates[i]);
        //start更新很重要，如果没有target - candidates[i]收敛条件，
        //start=0,不变，子层循环次数不减，就无法收敛，导致无限递归
        comSum(candidates, target - candidates[i], start, out, res );
        out.pop_back();
    }
}

void comDFS(vector<vector<int> >& out, const vector<int>& nums, vector<int>& path, const int start, const int target) {
    if (target < 0) return;
    if (target == 0) {
        out.push_back(path);
        for (auto n : path) {
			cout<< n << "   ";
		}
		cout<<endl;
        return;
    }
    for (int i = start; i < nums.size(); i++) {
        path.push_back(nums[i]);
        comDFS(out, nums, path, i , target - nums[i]);
        path.pop_back();
    }
}

int main(int argc, char const *argv[])
{
	int resl = rec(4);
	cout <<"resl= " << resl << endl;
	int n = 4;
	recur(0, 3);
    printf(" COUNT= %d\n", count);//2*2*2... = 2^n
    vector<int> list = {1,2,3,4,5};
    perm(list, 0, 4);

    cout <<"---------------------" << endl;
    int target = 8;
    vector<int> candidates = {2,3,5};
    vector<int> out;
    vector<vector<int>> res;
    comSum(candidates,target, 0, out, res );

    cout <<"---------------------" << endl;
	vector<int> path;
	vector<int> nums = {1,2,3};
    vector<vector<int> > out2;
    comDFS(out2, nums, path, 0, 4);
return 0;
}