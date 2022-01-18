// Sort an array of 0s, 1s and 2s
// Time Complexity - O(n)
// Space Complexity - O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void sort012(int a[], int n)
    {
        // number of zeros ones and twos in the array
        int z = 0, o = 0, t = 0;
        for (int i = 0; i < n; i++)
        {
            switch (a[i])
            {
            case 0:
                z++;
                break;
            case 1:
                o++;
                break;
            case 2:
                t++;
                break;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (i < z)
            {
                a[i] = 0;
            }
            else if (i < z + o)
            {
                a[i] = 1;
            }
            else
            {
                a[i] = 2;
            }
        }
    }
};

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }

        cout << endl;
    }
    return 0;
}