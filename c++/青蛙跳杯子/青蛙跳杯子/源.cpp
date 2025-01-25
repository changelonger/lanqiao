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


//补全BFS函数,百分之八十都是模板了，直接背(狗头)
int bfs()
{
    //声明一个队列
    queue<string> q;
    //将当前的状态入队
    q.push(st_str);

    ans[st_str] = 0;

    //当队列不为空的时候
    while (q.size())
    {
        //取出队头
        string ss = q.front();
        q.pop();

        int cnt = ans[ss];

        int x = ss.find('*');

        //拓展六个方向
        for (int i = 0; i < 6; i++)
        {
            int z = x + d[i];

            //判断出来的距离，是合法的
            if (z >= 0 && z < n)
            {
                swap(ss[x], ss[z]); //交换青蛙和当前空杯子的位置
                if (!ans.count(ss)) //用count来判断当前字符串是否在哈希表中出现过
                {
                    ans[ss] = cnt + 1;
                    //符合结果，输入
                    if (ss == end_str) return ans[ss];
                    q.push(ss);

                }

                //还原现场
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