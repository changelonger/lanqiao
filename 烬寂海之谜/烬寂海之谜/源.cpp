#include <iostream>
#include <string>
using namespace std;

int Sreach(string s, string t)
{
    int count = 0;
    int i = 0, j = 0;
    while (i < s.length())
    {
        if (s[i] != t[j])
        {
            i++;
            j = 0;
        }
        else
        {
            i++; j++;
            if (j = t.length())
            {
                count++;
                j = 0;
            }
        }
    }
    return count;
}

int main()
{
    string S;
    getline(cin, S);
    int n = 0;
    cin >> n;
    string p[500];
    int count[500] = { 0 };
    for (int i = 0; i < n; i++)
    {
        cin.ignore(); // ºöÂÔ»»ÐÐ·û
        cin >> p[i];
    }
    for (int i = 0; i < n; i++)
    {
        count[i] = Sreach(S, p[i]);
    }
    for (int i = 0; i < n; i++)
    {
        cout << count[i] << endl;
    }
    return 0;
}

