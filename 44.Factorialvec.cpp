#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

#define rapid_io() ios::sync_with_stdio(false);cin.tie(0);
#define endl '\n'
#define pb push_back
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()

int main()
{
    rapid_io();
    int n;
    cin>>n;
    vi ans;
    ans.pb(n);
    int carry=0;
    for(int i=n-1;i>=2;i--)
    {
        carry=0;
        for(int j=ans.size()-1;j>=0;j--)
        {
            ans[j]=ans[j]*i+carry;
            carry=ans[j]/10;
            ans[j]=ans[j]%10;
        }
        while(carry>0)
        {
            ans.insert(ans.begin(),carry%10);
            carry/=10;
        }

    }
    for(auto u:ans)
    {
        cout<<u;
    }
    cout<<endl;


    return 0;
}



