#include<bits/stdc++.h>
using namespace std;

int main()
{
    cout<<"Enter the Logical Address : "<<endl;
    int Logical_Address;
    cin>>Logical_Address;
    vector<int>Page_table({5, 6, 1, 2});
    int page_size;
    cout<<"Enter the Page Size : "<<endl;
    cin>>page_size;
    int page_no = Logical_Address/page_size;
    int frame_no = Page_table[page_no];
    int offset = Logical_Address%page_size;
    int physical_address = frame_no*page_size + offset;
    cout<<"Physical Address is : "<<endl;
    cout<<physical_address<<endl;
}