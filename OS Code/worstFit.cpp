#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>block_size = {100, 500, 200, 300, 600};
    vector<int>process_size = {212, 417, 112, 426};
    int n = process_size.size();
    int m = block_size.size();
    vector<int>alloc(n, -1);
    for(int i = 0; i<n; i++)
    {
        int worstIndex = -1;
        for(int j = 0; j<m; j++)
        {
            if(block_size[j]>process_size[i])
            {
                if(worstIndex == -1 || block_size[j]>block_size[worstIndex])
                {
                    worstIndex = j;
                }
            }
        }
        if(worstIndex != -1)
        {
            alloc[i] = worstIndex+1;
            block_size[worstIndex]-=process_size[i];
        }
    }
    cout<<"Process\tSize\tBlock"<<endl;
    for(int i = 0; i<n; i++)
    {
        cout<<"P"<<i+1<<"\t";
        cout<<process_size[i]<<"\t";
        if(alloc[i] == -1)
        {
            cout<<"NOT Allocated"<<endl;
        }
        else cout<<alloc[i]<<endl;
    }
}