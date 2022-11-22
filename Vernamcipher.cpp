#include<bits/stdc++.h>
using namespace std;

int main()
{
    string ptext,key,encrypt,decrypt;
    cout<<"Enter plain text: ";
    cin>>ptext;
    cout<<"Enter key: ";
    cin>>key;
    map<int,int>mp;
    for(int i=0;i<ptext.size();i++)
    {
        int val=((ptext[i]-'a')^(key[i]-'a'));
        if(val>26)
        {
            mp[i]=1;
            val=val-26;
        }
        //cout<<val<<endl;
        encrypt+='a'+val;

    }
    string trans=encrypt;
    transform(trans.begin(), trans.end(), trans.begin(), ::toupper);
    cout<<"The CipherText is: "<<trans<<endl;

    for(int i=0;i<encrypt.size();i++)
    {
        int val=0;
        if(mp[i]==1){
        val=((encrypt[i]-'a'+26)^(key[i]-'a'));
        }
        else
        val=((encrypt[i]-'a')^(key[i]-'a'));
        //cout<<val<<endl;
        decrypt+='a'+val;

    }
    cout<<"The plainText is: "<<decrypt<<endl;


    return 0;
}


