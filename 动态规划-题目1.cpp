// 动态规划-题目1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
#define M 50
#define N 50


int MIS_Dynamic(int* seq, int n)
{
	int now_sum = seq[0];
	int max_sum = now_sum;
	for (int i = 1;i < n; i++) {
		now_sum > 0 ? now_sum += seq[i] : now_sum = seq[i];
		if (max_sum < now_sum)
			max_sum = now_sum;
	}
	return max_sum;
}

int main()
{
    int row, col, tmp, max_sum;
    cin >> row >> col;
    int** mat = new int* [row];
    for (int i = 0; i < row; i++) {
        mat[i] = new int[col];
        for (int j = 0; j < col; j++) {
            cin >> mat[i][j];
        }
    }

    int* arr = new int[col];
    for (int i1 = 0; i1 < row; i1++) {
        for (int j = 0; j < col; j++)  arr[j] = 0;
        for (int i2 = i1; i2 < row; i2++) {
            for (int j = 0; j < col; j++)  arr[j] += mat[i2][j];
            tmp = MIS_Dynamic(arr, col);
            if (i1 == 0 && i2 == 0) {  //第一次初始赋值
                max_sum = tmp;
            }
            if (max_sum < tmp) {
                max_sum = tmp;
            }
        }
    }

    printf("%d \n", max_sum);

    delete[] arr;
    for (int i = 0; i < row; i++) delete[] mat[i];\
        delete[] mat;
    return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
