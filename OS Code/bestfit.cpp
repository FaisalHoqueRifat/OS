#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int>block_size = {100, 500, 200, 300, 600};
    vector<int>process_size = {212, 417, 112, 426};
    int n = block_size.size();
    int m = process_size.size();
    vector<int>alloc(m, -1);
    for(int i = 0; i<m; i++)
    {
        int bestIdx = -1;
        for(int j = 0; j<n; j++)
        {
            if(block_size[j]>=process_size[i])
            {
                if(bestIdx == -1 || block_size[j]<block_size[bestIdx])
                {
                    bestIdx = j;
                }
            }
        }
        if(bestIdx!=-1)
        {
            alloc[i] = bestIdx+1;
            block_size[bestIdx]-=process_size[i];
        }
    }
    cout<<"Process\tSize\tAllocation"<<endl;
    for(int i = 0; i<m; i++)
    {
        cout<<"P"<<i+1<<"\t";
        cout<<process_size[i]<<"\t";
        if(alloc[i]==-1) cout<<"NOT Allocated"<<endl;
        else cout<<alloc[i]<<endl;
    }
    return 0;
}