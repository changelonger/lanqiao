#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#include <queue>

using namespace std;
string st_str, end_str;
int n;
int d[6] = { -3,-2,-1,1,2,3 };
map<string, int> ans;


//��ȫBFS����,�ٷ�֮��ʮ����ģ���ˣ�ֱ�ӱ�(��ͷ)
int bfs()
{
    //����һ������
    queue<string> q;
    //����ǰ��״̬���
    q.push(st_str);

    ans[st_str] = 0;

    //�����в�Ϊ�յ�ʱ��
    while (q.size())
    {
        //ȡ����ͷ
        string ss = q.front();
        q.pop();

        int cnt = ans[ss];

        int x = ss.find('*');

        //��չ��������
        for (int i = 0; i < 6; i++)
        {
            int z = x + d[i];

            //�жϳ����ľ��룬�ǺϷ���
            if (z >= 0 && z < n)
            {
                swap(ss[x], ss[z]); //�������ܺ͵�ǰ�ձ��ӵ�λ��
                if (!ans.count(ss)) //��count���жϵ�ǰ�ַ����Ƿ��ڹ�ϣ���г��ֹ�
                {
                    ans[ss] = cnt + 1;
                    //���Ͻ��������
                    if (ss == end_str) return ans[ss];
                    q.push(ss);

                }

                //��ԭ�ֳ�
                swap(ss[x], ss[z]);
            }
        }
    }

    return -1;
}

int main()
{

    cin >> st_str >> end_str;
    n = st_str.size();

    cout << bfs() << endl;

    return 0;
}