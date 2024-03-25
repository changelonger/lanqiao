#include <stdio.h>
#include <stdlib.h>

int M, N, d[52][52];

void dfs_sea(int i, int j)
{
    if ((i >= 0 && i <= M + 1) && (j >= 0 && j <= N + 1))
    {
        if (d[i][j] == 0)
        {
            d[i][j] = 2;//��ǳ��⺣
            //�˸����� 
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
            d[i][j] = 3;//�������ĵ��첻������ 
            dfs_island(i + 1, j);//�� 
            dfs_island(i - 1, j);//�� 
            dfs_island(i, j + 1);//�� 
            dfs_island(i, j - 1);//�� 
        }
    }
}

int main(int argc, char* argv[])
{
    // ���ڴ��������Ĵ���
    int T;
    scanf_s("%d", &T);
    while (T--)
    {
        scanf_s("%d %d", &M, &N);
        //��亣ˮ
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
        //����ͼ 
        for (int i = 1; i < M + 1; i++)
        {
            for (int j = 1; j < N + 1; j++)
            {
                scanf_s("%1d", &d[i][j]);
            }
        }

        dfs_sea(0, 0); //�ҳ������⺣ 

        int count;//���㵺������ 
        count = 0;
        for (int i = 0; i < M + 2; i++)
        {
            for (int j = 0; j < N + 2; j++)
            {
                if (d[i][j] == 1 && d[i - 1][j] == 2)//ֻ�ܴ��⺣�������죬���Ե���ǰһ�����⺣��2��
                {
                    dfs_island(i, j);//�������� 
                    count++;
                }
            }
        }
        printf("%d\n", count);
        //���´�����Դ�ӡ��������ͼ
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