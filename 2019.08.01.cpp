#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    int n;
    while(getline(cin,str))
    {
        cin>>n;
        cin.get();
        unsigned long long len=str.length();//用int会溢出
        if(len<n)
            cout<<"-1"<<endl;
        else
        {
            cout<<str.substr(0,n);
            for(int i=1;i+n<=len;++i)
            {
                cout<<' '<<str.substr(i,n);
            }
            cout<<endl;
        }
    }
    return 0;
}