#include<bits/stdc++.h>
using namespace std;
int mincostindex(int a[][4],int n)
{
	int min=9999;
	int index=-1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<4;j++)
		{
			if(min>a[i][j] && a[i][j]!=0)
			{
				min=a[i][j];
				
			}
		}
	}
	return min;
}
int main()
{
	int supply[3]={15,25,10};
	int demand[4]={5,15,15,15};
	int cost[3][4]={{10,2,20,11},{12,7,9,20},{4,14,16,18}};
	int ans=0;
	int minvalue=mincostindex(cost,3);

	int iminindex,jminindex;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<4;j++)
		{
			if(minvalue==cost[i][j])
			{
				iminindex=i;
				jminindex=j;
			}
		}
	}
	
	if(supply[iminindex]<demand[jminindex])
	{
		ans=ans+cost[iminindex][jminindex]*supply[iminindex];
		demand[jminindex]=demand[jminindex]-supply[iminindex];
	}
	else
	{
		ans=ans+cost[iminindex][jminindex]*demand[jminindex];
		supply[iminindex]=supply[iminindex]-demand[jminindex];
	}
	cost[iminindex][jminindex]=0;
	int minvalue1=mincostindex(cost,3);
	cout<<minvalue1;
}
