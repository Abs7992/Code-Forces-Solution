int main()
{
 
 
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,div=0;
        cin>>n;
        string s;
        cin>>s;
        vector<ll>last_zero;
        vector<ll>last_one;
        vector<ll>ans;
        for(int i=0; i<n; i++)
        {
            if(s[i]=='0')
            {
                if(last_one.size()==0)
                {
                    last_zero.push_back(div);
                    ans.push_back(div);
                    div++;
                }
                else
                {
                    ans.push_back(last_one[last_one.size()-1]);
                    last_zero.push_back(last_one[last_one.size()-1]);
                    last_one.pop_back();
                }
            }
            else
            {
                if(last_zero.size()==0)
                {
                    last_one.push_back(div);
                    ans.push_back(div);
                    div++;
                }
                else
                {
                    ans.push_back(last_zero[last_zero.size()-1]);
                    last_one.push_back(last_zero[last_zero.size()-1]);
                    last_zero.pop_back();
                }
            }
        }
        cout<<div<<endl;
        for(int i=0; i<ans.size(); i++)
        {
            cout<<ans[i]+1<<" ";
        }
        cout<<endl;
    }
 
    return 0;
}