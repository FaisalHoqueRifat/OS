#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int>ref_string({7,0,1,2,0,3,0,4,2,3,0,3,0,3,2,1,2,0,1,7,0,1});
    int frames = 3;
    queue<int>memory;
    set<int>st;
    set<int>second_chance;
    int page_fault = 0;
    for(int i = 0; i<ref_string.size(); i++)
    {
        if(st.count(ref_string[i]) == 0)
        {
            page_fault++;
            if(memory.size() == frames)
            {
                while (true)
                {
                    int remove = memory.front();
                    memory.pop();
                    if(second_chance.count(remove) == 1)
                    {
                        second_chance.erase(remove);
                        memory.push(remove);
                    }
                    else
                    {
                        st.erase(remove);
                        break;
                    }
                }
            }
        memory.push(ref_string[i]);
        st.insert(ref_string[i]);
        }
        else
        {
            second_chance.insert(ref_string[i]);
        }
    }
    cout<<page_fault<<endl;
    return 0;
}