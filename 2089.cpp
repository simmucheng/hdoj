#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int mask[50];
int dp[50][3];
int dfs(int len,int sta,int lim)
{
    int cnt=0;
    if(len==-1)return sta==0;
    if((!lim)&&dp[len][sta]!=-1)
        return dp[len][sta];
    int en=lim?mask[len]:9;
    for(int ii=0;ii<=en;ii++)
    {
        int ss;
        if(sta==0)ss=0;
        else if(ii==4)ss=0;
        else if(sta==1&&ii==2)ss=0;
        else if(ii==6)ss=1;
        else ss=2;
        cnt+=dfs(len-1,ss,lim&&(ii==en));
    }
    return lim?cnt:dp[len][sta]=cnt;
}
int get_ans(int nn)
{
    int uu=0;
    int len=0;
    while(nn)
    {
        mask[uu++]=nn%10;
        nn/=10;
        len++;
    }
    int an=dfs(len-1,2,1);
    return an;
}

int main()
{
    int i,j,m,n;
    while(scanf("%d%d",&m,&n),m||n)
    {
        memset(dp,-1,sizeof(dp));
        int t1=get_ans(m-1);
        int t2=get_ans(n);
        printf("%d\n",(n-m+1)-t2+t1);
    }
    return 0;
}
