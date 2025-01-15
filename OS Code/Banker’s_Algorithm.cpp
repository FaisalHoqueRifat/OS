#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    n = 5;
    m = 3;
    int alloc[n][m] = {{0, 1, 0},{2, 0, 0},{3, 0, 2},{2, 1, 1},{0, 0, 2}};
    int max[n][m] = {{7, 5, 3}, {3, 2, 2}, {9, 0, 2}, {2, 2, 2}, {4, 3, 3}};
    int need[n][m];
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
        {
            need[i][j] = max[i][j]-alloc[i][j];
        }
    }
    int avail[m]={3, 3, 2};
    int ans[n],f[n], index = 0;
    for(int i = 0; i<n; i++)
    {
        f[i] = 0;
    }
    for(int k = 0; k<n; k++)
    {
        for(int i = 0; i<n; i++)
        {
            if(f[i] == 0)
            {
                int flag = 0;
                for(int j = 0; j<m; j++)
                {
                    if(need[i][j]>avail[j])
                    {
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0)
                {
                    ans[index] = i;
                    index++;
                    for(int j = 0; j<m; j++)
                    {
                        avail[j]+=alloc[i][j];
                    }
                    f[i] = 1;
                }
            }
        }
    }
    int flag = 1;
    for(int i = 0; i<n; i++)
    {
        if(f[i] == 0)
        {
            flag = 0;
            break;
        }
    }
    if(flag == 0)
    {
        cout<<"NOT in safe state"<<endl;
    }
    else
    {
        for(int i = 0; i<n-1; i++)
        {
            cout<<"P"<<ans[i]<<"->";
        }
        cout<<"P"<<ans[n-1]<<endl;
    }
    return 0;
}
