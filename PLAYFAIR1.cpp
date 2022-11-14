/**
***Source Code of PlayFair Encryption and Decryption Technique

Author:Md.Mizanur Rahman
Language: C++
Date: 14-11-22
ID: 180625
**/
#include<bits/stdc++.h>
using namespace std;

char arr[5][5];
int main()
{
    string msg,key,cipher,plain;
    cout<<"Enter a message: ";
    cin>>msg;
    cout<<"Enter key: ";
    cin>>key;
    ///Covert Uppercase String
    transform(msg.begin(), msg.end(), msg.begin(), ::toupper);
    transform(key.begin(), key.end(), key.begin(), ::toupper);
    ///Make a initial array for matrix
    vector<char>v;
    map<char,int>mp; ///to count the character in matrix
        int l=0;
        ///push the character of key
    for(int i=0;i<key.size();i++)
    {

        if(mp[key[l]]==0){
       v.push_back(key[l]);
       mp[key[l]]++;
       l++;
        }
        else
        {
            l++;
        }
    }
    ///push the remaining alphabet
    int ch=0;
    char chh='A';
    int ind=v.size();
    int lp=ind;
    for(int i=ind;;i++)
    {
        if(mp[chh]==0)
        {
            v.push_back(chh);
            mp[chh]++;
            ind++;
            if(ind==26)
                break;
        }
            ch++;
            chh=ch+'A';
            if(chh=='J'){
                ch++;
                chh=ch+'A';
            }

    }
    ///create a 5x5 matrix
    int k=0;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            arr[i][j]=v[k];
            k++;
        }
    }
        ///check whether the pair is in same row or same column or different row and different column
        for(int i=0;i<msg.size()-1;i+=2)
        {
            int f=find(v.begin(),v.end(),msg[i])-v.begin();
            int l=find(v.begin(),v.end(),msg[i+1])-v.begin();
            int row1=f/5;
            int col1=f%5;
            int row2=l/5;
            int col2=l%5;
            if(row1==row2)
            {
                  cipher+=arr[row1][(col1+1)%5];
                  cipher+=arr[row2][(col2+1)%5];
            }
            else if(col1==col2)
            {
               cipher+=arr[(row1+1)%5][col1];
               cipher+=arr[(row2+1)%5][col2];
            }
            else
            {

                cipher+=arr[row1][col2];
                cipher+=arr[row2][col1];
            }
        }
        cout<<"After Encryption the cipher text is: "<<cipher<<endl;

        ///Decryption

        for(int i=0;i<cipher.size()-1;i+=2)
        {
            int f=find(v.begin(),v.end(),cipher[i])-v.begin();
            int l=find(v.begin(),v.end(),cipher[i+1])-v.begin();
            int row1=f/5;
            int col1=f%5;
            int row2=l/5;
            int col2=l%5;
            if(row1==row2)
            {
                if((col1-1)<0 )
                {
                    col1=5;
                }
                if((col2-1)<0 )
                {
                    col2=5;
                }
                  plain+=arr[row1][(col1-1)%5];
                  plain+=arr[row2][(col2-1)%5];
            }
            else if(col1==col2)
            {
                if((row1-1)<0 )
                {
                    row1=5;
                }
                if((row2-1)<0 )
                {
                    row2=5;
                }

               plain+=arr[(row1-1)%5][col1];
               plain+=arr[(row2-1)%5][col2];
            }
            else
            {

                plain+=arr[row1][col2];
                plain+=arr[row2][col1];
            }
        }
        cout<<"After Decryption the plain text is: "<<plain<<endl;



    return 0;
}





