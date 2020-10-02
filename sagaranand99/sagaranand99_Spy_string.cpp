ll m,done=0;  

map<pair<ll,ll>,string>dp;  

string make(int pos)

{

    int f=0;

    if(pos==m)  

    {

        done=1; 

        return "";

    }

    if(dp[make_pair(pos,1)].size()>0)  

        return dp[make_pair(pos,1)];      

    for(int i=0; i<v.size(); i++)

    {

        ll cnt=0;  

        for(int j=0; j<v.size(); j++)

            if(v[i][pos]!=v[j][pos])

            {

                B[j]++; 

                if(B[j]>=2) 

                    cnt=1;

            }

        if(cnt==0&&done==0)  

        {

            if(pos==m-1)   

                f=1;      

            dp[make_pair(pos,f)]=v[i][pos]+make(pos+1); 

        }

        for(int j=0; j<v.size(); j++)

        {

            if(v[i][pos]!=v[j][pos])

                B[j]--;   

        }

    }

    return dp[make_pair(pos,f)];

}

int main()

{

    ios::sync_with_stdio(false);

    cin.tie(nullptr);

 

 

    ll t;

    cin>>t;

    while(t--)

    {

        ll n;

        cin>>n>>m;

        string s;

        for(int i=1; i<=n; i++)

        {

            cin>>s;

            v.push_back(s);

        }

        s=make(0);

        if(s.size()<m) 

            cout<<-1<<endl;

        else

            cout<<s<<endl;

            done=0;

        dp.clear();

        v.clear();

    }

    return 0;

}