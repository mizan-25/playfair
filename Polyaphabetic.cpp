#include<bits/stdc++.h>
using namespace std;

int main()
{
    ///wearediscoveredsaveyourself
    ///deceptive
    string pt,key;
    cout<<"Enter plain text: ";
    cin>>pt;
    cout<<"Enter key: ";
    cin>>key;
    if(key.size() < pt.size())
    {
        ///Make the plaintext size and key size equal
        int l=key.size();
        int j=0;
        while(1)
        {
            key+=key[j];
            if(j==l-1)
                j=0;
            else
                j++;

            l++;
            if(l==pt.size())
            break;
        }
    }
        ///Encryption
        ///Ci=(Pi+Ki)mod 26
        string encrypt;
        for(int i=0;i<pt.size();i++)
        {
            int val=((pt[i]-'a')+(key[i]-'a'))%26;
            //cout<<val<<endl;
            encrypt+='A'+val;
        }
        cout<<"CipherText: "<<encrypt<<endl;

        ///Decryption
        ///Pi=(Ci-Ki)mod 26
        string decrypt;
        for(int i=0;i<encrypt.size();i++)
        {
            int val=((encrypt[i]-'a')-(key[i]-'a')+32)%26;
            if(val<0)
                val+=26;
            //cout<<val<<endl;
            decrypt+='a'+val;
        }
        cout<<"PlainText: "<<decrypt<<endl;


    return 0;
}


