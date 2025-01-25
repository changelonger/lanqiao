#include <iostream>
using namespace std;
int main() {
    int N;
    cin >> N;
    int matrix[10][10];
    //读入矩阵
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> matrix[i][j];
        }
    }
    int maxSum = 0;
    for (int l = 0; l < N; l++) {
        //列起始量
        int sum = 0;
        for (int r = 0; r < N; r++) {
            //对角线扫描
            sum += matrix[(r + l) % N][r];
        }
        if (sum > maxSum) {
            maxSum = sum;
        }

    }
    cout << maxSum;
    return 0;
}

/*注意矩阵的特点
主对角线的分布：
 1 1 1 1 1 1 1
 1 1 1 1 1 1 1
 1 1 1 1 1 1 1
 1 1 1 1 1 1 1
 1 1 1 1 1 1 1
 1 1 1 1 1 1 1
 1 1 1 1 1 1 1
 对于这个矩阵来说
主对角线最大值就是每一组可能成为对角线的所有元素之和的最大值
比如，第一次调用
 0 1 1 1 1 1 1
 1 0 1 1 1 1 1
 1 1 0 1 1 1 1
 1 1 1 0 1 1 1
 1 1 1 1 0 1 1
 1 1 1 1 1 0 1
 1 1 1 1 1 1 0

 第二次
 1 1 1 1 1 1 0
 0 1 1 1 1 1 1
 1 0 1 1 1 1 1
 1 1 0 1 1 1 1
 1 1 1 0 1 1 1
 1 1 1 1 0 1 1
 1 1 1 1 1 0 1
 按照这样，如果超过数组的长度，就直接从头开始，也类似队列的知识；
 */