#include<iostream>
using namespace std;
#include<vector>
#include<set>
#include<queue>
#include<string>
void Initqueue(queue<char>& q);
void play(queue<char>& q, string& s, set<char>& se, int* e);
int is_seam(queue<char>q, set<char>se);
int main()
{
	set<char>se;
	string s;
	queue<char>A; queue<char>B;
	int flag = 1;
	Initqueue(A);
	Initqueue(B);
	while (!A.empty()&&!B.empty ())
	{
		switch (flag)
		{
		case 1:
			play(A, s, se,&flag);
			break;
		case 0:
			play(B, s, se, &flag);
			break;
		}
	}

	while (A.empty() == 0)
	{
		cout << A.front();
		A.pop();
	}
	while (B.empty() == 0)
	{
		cout << B.front();
		B.pop();
	}

	return 0;
}





void Initqueue(queue<char>& q)
{
	char a;
	while (1)
	{
		a = cin.get();
		if (a == '\n')
			return;
		q.push(a);
	}
}
void play(queue<char>& q, string& s, set<char>& se, int* flag)
{
	char a = q.front();
	
	set<char>::iterator it = se.find(a);
	if (is_seam(q, se))
	{
		q.pop();
		s.push_back(a);
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == *it)
			{
				for (int j = s.length()-1; j>=i; j--)
				{
					it = se.find(s[j]);
					q.push(s[j]);
					s.erase(j, 1);
					if (it != se.end())
						se.erase(it);
				}
				
				return;
			}
		}
	}
	else
	{
		q.pop();
		se.insert(a);
		s.push_back(a);
		(*flag) = !(*flag);
	}
}
int is_seam(queue<char>q, set<char>se)
{
	set<char>::iterator it = se.find(q.front());
	if (it == se.end())
		return 0;
	else
		return 1;
}