#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int>ref_string({7,0,1,2,0,3,0,4,2,3,0,3,0,3,2,1,2,0,1,7,0,1});
    int frames = 3;
    queue<int>memory;
    set<int>st;
    int page_fault = 0;
    cout<<ref_string.size()<<endl;
    for(int i = 0; i<ref_string.size(); i++)
    {
        if(st.count(ref_string[i]) == 0)
        {
            page_fault++;
            if(memory.size() == frames)
            {
                int remove = memory.front();
                memory.pop();
                st.erase(remove);
            }
            memory.push(ref_string[i]);
            st.insert(ref_string[i]);
        }
    }
    cout<<page_fault<<endl;
}