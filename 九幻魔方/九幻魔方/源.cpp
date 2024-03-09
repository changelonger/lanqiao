#include<iostream>
using namespace std;
int vis[10], a[5][5], ans[5][5];
int n, cnt;
pair<int, int>p[10];
/*
    ��һ�Σ�
    a��3x3�ľ���p��������Ϊ0������ԣ�vis�Ǵ�����Щ�����Ѿ��ھ����г�����
    n�Ǵ����м�����û�б��cnt ��Ŀ�����
    */
bool check()
{
    int sum = a[1][1] + a[2][2] + a[3][3];
    if (sum != a[1][3] + a[2][2] + a[3][1]) return false;
    for (int i = 1; i <= 3; i++) {
        int tmp1 = 0, tmp2 = 0;
        for (int j = 1; j <= 3; j++)tmp1 += a[i][j], tmp2 += a[j][i];//�к��еĺ���� 
        if (tmp1 != sum || tmp2 != sum) return false;
    }
    return true;
}
void dfs(int now)
{
    //now�����������Ѿ���ĸ���������n�Ƚ�
    if (now > n) 
    {
        //��ʱ�����е�ȫ��Ԫ���Ѿ��������ˣ�
        if (check()) 
        {
            cnt++;
            for (int i = 1; i <= 3; i++)
                for (int j = 1; j <= 3; j++)
                    ans[i][j] = a[i][j];
            //ans��Ŀ�ľ���
        }
        return;
    }
    int x = p[now].first, y = p[now].second;
    //�õ���û�б���ĵ�һ����������
    for (int k = 1; k <= 9; k++)
    {
        if (vis[k])continue;//���������Ѿ����ˣ�����һ����
        a[x][y] = k;//��ֵ����ȥ
        vis[k] = 1;//������������Ѿ��ù���
        dfs(now + 1);//����������nowҪ����
        a[x][y] = 0;//��һ���Ǻ����Ѿ���������˵Ĳ������Ѹ���ֵȫ������
        vis[k] = 0;//�����õ���������
    }
}
int main()
{
    for (int i = 1; i <= 3; i++)
        for (int j = 1; j <= 3; j++) 
        {
            cin >> a[i][j];
            if (!a[i][j])p[++n] = make_pair(i, j);
            vis[a[i][j]] = 1;
        }
    
    dfs(1);//���ص㡣
    if (cnt == 1) 
    {
        for (int i = 1; i <= 3; i++)
            for (int j = 1; j <= 3; j++)
                cout << ans[i][j] << " \n"[j == 3];
    }
    else cout << "Too Many\n";
    return 0;
}