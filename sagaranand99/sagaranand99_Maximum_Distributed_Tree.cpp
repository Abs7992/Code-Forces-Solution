ll n;
ll find_nodes(ll start)
{
    vis[start]=1;
    ll child=0,total_child=0;
    for(int i=0; i<v[start].size(); i++)
    {
        ll u=v[start][i];
        if(vis[u]==0)
        {
            child=find_nodes(u);  
            av.push_back(child*(n-child));  
            total_child+=child;  
        }
    }
    return 1+total_child;
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll t;
    cin>>t;
    while(t--)
    {
        ll a,b,ans=0;
        cin>>n;
        for(int i=1; i<n; i++)
        {
            cin>>a>>b;    
            v[a].push_back(b);
            v[b].push_back(a);
        }
        ll m;
        cin>>m;
        for(int i=1; i<=m; i++)  
        {
            cin>>a;
            fv.push_back(a);
        }
        if(m<n-1)  
        {
            while(m!=n-1)
            {
                fv.push_back(1);
                m++;
            }
            sort(fv.begin(),fv.end());  
        } 
        else  
        {
            sort(fv.begin(),fv.end());  
            while(m>n-1)
            {
                a=fv[fv.size()-1]; 
                fv.pop_back();
                b=fv[fv.size()-1];
                fv.pop_back();
                fv.push_back((a*b)%mod); 
                m--;
            }
        }
        find_nodes(1); 
        sort(av.rbegin(),av.rend()); 
        reverse(fv.begin(),fv.end()); 
        for(int i=0; i<fv.size(); i++)  
        {
            ans+=(av[i]*fv[i])%mod;
            ans%=mod;
        }
        cout<<ans<<endl;
         
        for(int i=1; i<=n; i++)
        {
            v[i].clear();
        }
        av.clear();
        fv.clear();
        memset(vis,0,sizeof(vis));
    }
 
    return 0;
}