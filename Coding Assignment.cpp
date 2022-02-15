int main()
{
    int t;
    cin>>t;
    char c;
    cin.get(c);
    while(t--)
    {
        char pat[1000],txt[100000];
        cin>>pat>>txt;

        int lp = strlen(pat);
        int lt = strlen(txt);

        int pat_abc[26] = {0};
        int f = 0;
        for(int i=0;i<lp;i++)
            pat_abc[pat[i]-'a']++;

        int checker_abc[26] = {0};

        for(int i=0;i<lp;i++)
        {
            checker_abc[txt[i]-'a']++;
        }

        for(int i=lp;i<lt;i++)
        {
            int found = 1;
            for(int k=0;k<26;k++)
            {
                if(pat_abc[k] != checker_abc[k])
                {
                    found = 0;break;
                }
            }
            if(found)
            {
                f=1;break;
            }

            checker_abc[txt[i-lp]-'a']--;
            checker_abc[txt[i]-'a']++;
        }
        int found = 1;
        for(int k=0;k<26 && !f;k++)
            {
                if(pat_abc[k] != checker_abc[k])
                {
                    found = 0;break;
                }
            }
            if(found) f=1;

        if(!f)
        cout<<"NO"<<endl;
        else
        cout<<"YES"<<endl;
    }
    return 0;
}