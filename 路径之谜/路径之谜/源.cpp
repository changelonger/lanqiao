#include <iostream>
using namespace std;

#define SIZE 4

int n;
int map[SIZE][SIZE];//map������
int row[SIZE];//���ż�
int cel[SIZE];//���ż�
int r[SIZE];//��¼���ŵļ�
int c[SIZE];//��¼���ŵļ�
int arr[SIZE * SIZE];//��¼�����ĵ�
int v[SIZE][SIZE];//�����û���߹�
int res = 0;//�ܹ��ļ� 
int Next[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };//��������
int flag = 0;//�����û�м��������
void df(int x, int y, int sum)
{
    

    if (sum== res/2&&x>=n&&y==n-1)
    {
        //����߹��ĵ������ڼ���������x>=n����Ϊ���������£���y==n-1
        for (int i = 0; i < res/2; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl; // �������·������
        return;
    }

    if (x < 0 || x >= n || y < 0 || y >= n)
    {
        flag = 0;//���û���߹�
        return;
    }

    if (v[x][y] == 0)
    {
        flag = 1;
        v[x][y] = 1;
        arr[sum] = map[x][y];
        r[y]++;
        c[x]++;//����
        if (r[y] > row[y] || c[x] > cel[x])
        {
            flag = 1;//�����ϼ���

            return;
        }
        else
        {
            for (int k = 0; k < 4; k++)
            {
                df(x + Next[k][0], y + Next[k][1], sum + 1);//��������
                if (flag)//��������������
                {
                    r[y + Next[k][1]]--;
                    c[x + Next[k][0]]--;
                    v[x + Next[k][0]][y + Next[k][1]] = 0;
                    arr[sum + 1] = 0;//����
                }
            }
            flag = 1;
            return;
           
        }
    }
    flag = 0;
    return;
}

int main()
{
    cin >> n;
    int count = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            map[i][j] = count++;
    if (n == 0)
        cout << 0;
    else if (n == 1)
        cout << 1;
    else
    {
        for (int i = 0; i < n; i++)
        {
            cin >> row[i];
            res += row[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> cel[i];
            res += cel[i]; // Ӧ���ۼ�cel�����ֵ��������row����
        }
        df(0, 0, 0);
    }
    return 0;
}
