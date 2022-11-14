#include<bits/stdc++.h>
using namespace std;

int main()
{
    ///attackpostponeduntiltwoam
    ///4312567
    string pt,key,decrypt;
    cout<<"Enter plain text :";
    cin>>pt;
    cout<<"Enter key :";
    cin>>key;
    int szp=pt.size();
    int szk=key.size();
    int sz=(szp/szk);
    if(sz*szk<szp)
        sz++;
    vector<char>v[szk+1];
    int l=0;
    int las=0;
    for(int i=0;i<szp;i++)
    {
        char ch=key[l];
        int ind=(int)(key[l]-'0');
        char chh=pt[i];
        v[ind].push_back(chh);
        if(i==(szp-1))
        {
            las=l;
        }
        if(l==6)
            l=0;
        else
            l++;
    }
    las++;
    int kk=sz*szk-(pt.size());
    int k1=kk;
    int chz=26-(kk);
    for(int i=0;i<kk;i++)
    {
        v[key[las]-'0'].push_back(chz+'a');
        las++;
        chz++;
    }
    string ss;
    for(int i=0;i<sz;i++)
    {
       for(int j=1;j<=key.size();j++)
       {
           cout<<v[key[(j-1)]-'0'][i]<<" ";
       }
       cout<<endl;
    }

    for(int i=0;i<sz;i++)
    {
       for(int j=1;j<=key.size();j++)
       {
           ss+=v[key[(j-1)]-'0'][i];
       }
    }
    while(k1)
    {
        ss.pop_back();
        k1--;
    }
    cout<<endl<<"CipherText :";
    for(int i=1;i<=7;i++)
    {
        for(auto u:v[i])
        {
            cout<<u;
        }
    }
    cout<<endl;
  ///Performing Decryption from matrix
    for(int i=0;i<sz;i++)
    {
        for(int j=0;j<key.size();j++){
        int xx=key[j]-'0';
        decrypt+=v[xx][i];
//        if(((i+1)*(j+1))==(szk*sz))
//            break;
      }
    }
    cout<<"After Decryption: "<<decrypt<<endl;




    return 0;
}



