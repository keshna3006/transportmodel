#include<bits/stdc++.h>
using namespace std;
int main()
{
	int supply[3]={300,400,500};
	int demand[4]={250,350,400,200};
	int cost[3][4]={{3,1,7,4},{2,6,5,9},{8,3,3,2}};
	int startrow=0;
	int startcol=0;
	int ans=0;
	
	while(startrow!=3 && startcol!=4)
	{
		if(supply[startrow]<demand[startcol])
		{
			ans=ans+cost[startrow][startcol]*supply[startrow];
			demand[startcol]=demand[startcol]-supply[startrow];
			startrow=startrow+1;
		}
		else
		{
			ans=ans+cost[startrow][startcol]*demand[startcol];
			supply[startrow]=supply[startrow]-demand[startcol];
			startcol=startcol+1;
		}
	}
	cout<<ans;
}
