#include <stdio.h>
#include <stdlib.h>

int M, N, d[52][52];

void dfs_sea(int i, int j)
{
    if ((i >= 0 && i <= M + 1) && (j >= 0 && j <= N + 1))
    {
        if (d[i][j] == 0)
        {
            d[i][j] = 2;//标记出外海
            //八个方向 
            dfs_sea(i, j + 1);
            dfs_sea(i, j - 1);
            dfs_sea(i + 1, j);
            dfs_sea(i + 1, j + 1);
            dfs_sea(i + 1, j - 1);
            dfs_sea(i - 1, j);
            dfs_sea(i - 1, j + 1);
            dfs_sea(i - 1, j - 1);
        }
    }
}

void dfs_island(int i, int j)
{
    if ((i >= 0 && i <= M + 1) && (j >= 0 && j <= N + 1))
    {
        if (d[i][j] == 1)
        {
            d[i][j] = 3;//搜索过的岛屿不再搜索 
            dfs_island(i + 1, j);//右 
            dfs_island(i - 1, j);//左 
            dfs_island(i, j + 1);//上 
            dfs_island(i, j - 1);//下 
        }
    }
}

int main(int argc, char* argv[])
{
    // 请在此输入您的代码
    int T;
    scanf_s("%d", &T);
    while (T--)
    {
        scanf_s("%d %d", &M, &N);
        //填充海水
        for (int i = 0; i < N + 2; i++)
        {
            d[0][i] = 0;
            d[M + 1][i] = 0;
        }
        for (int i = 1; i < M + 1; i++)
        {
            d[i][0] = 0;
            d[i][N + 1] = 0;
        }
        //输入图 
        for (int i = 1; i < M + 1; i++)
        {
            for (int j = 1; j < N + 1; j++)
            {
                scanf_s("%1d", &d[i][j]);
            }
        }

        dfs_sea(0, 0); //找出所有外海 

        int count;//计算岛屿数量 
        count = 0;
        for (int i = 0; i < M + 2; i++)
        {
            for (int j = 0; j < N + 2; j++)
            {
                if (d[i][j] == 1 && d[i - 1][j] == 2)//只能从外海搜索岛屿，所以岛屿前一定是外海“2”
                {
                    dfs_island(i, j);//搜索岛屿 
                    count++;
                }
            }
        }
        printf("%d\n", count);
        //以下代码可以打印出处理后的图
            /*for (int i = 0; i < M + 2; i++)
            {
                for (int j = 0; j < N + 2; j++)
                {
                    printf("%1d", d[i][j]);
                    if (j == N + 1)
                    printf("\n");
                }
            }*/
    }
    return 0;
}