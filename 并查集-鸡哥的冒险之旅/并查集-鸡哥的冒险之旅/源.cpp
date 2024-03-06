#include <iostream>
using namespace std;
int n, m;
#define Y(a,b) (a)*m+b
int pre[100000]; int arr[100000];
/*
ע�������õ���һά���飬��Ҫ�ĵ���ά���飬����Ҫת��
����궨����������ҵ�����

*/
int find(int x)
{
    while (x != pre[x])
        x = pre[x];
    return x;
}
//���鼯�е�find������Ŀ�����ҵ���
int main()
{
    cin >> n >> m;
    //��ʼ�����鼯���ҳ�������
    for (int a = 0; a < n; a++)
    {
        for (int b = 0; b < m; b++)
        {
            pre[Y(a, b)] = Y(a, b);
            cin >> arr[Y(a, b)];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (find(Y(i, j)) == Y(i, j))//���(i,j)��Ӧ��pre�������������ʹ������Ԫ��û���ҵ����ĸ�
            {
                int x = Y(i, j);//�õ���һλ�����е�����

                for (int a = -1; a <= 1; a++)
                {
                    for (int b = -1; b <= 1; b++)
                        //�ҵ���Χ��8��Ԫ��
                    {
                        if (i + a < 0 || i + a >= n || j + b < 0 || j + b >= m)
                            continue;
                        //�ڱ���
                        if (arr[x] > arr[Y(i + a, j + b)])
                            x = Y(i + a, j + b);
                        //�ҵ���С�ĵȼ���Ӧ���±�
                    }
                }
                pre[Y(i, j)] = find(pre[x]);//��ʱ����������pre�����Ӧֵ����Ϊx���pre����ĸ�
            }
        }
    }
    memset(arr, 0, sizeof(arr));
    for (int i = 0; i < n * m; i++)
        arr[find(i)]++;
    //һֱ�ҵ���������������++
    for (int i = 0; i < n * m; i++) {
        cout << arr[i] << ((i + 1) % m == 0 ? '\n' : ' ');
    }
    return 0;
}
