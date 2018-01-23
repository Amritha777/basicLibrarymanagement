#include<iostream>
using namespace std;
#include<stdio.h>
#include<conio.h>

int main()
{
	int t,n;
	int x=1;
	int arr[100],cc[100],flag=0;
	cin>>t;
	if(t<=100&&t>=1)
	{   while(x<=t)
        {


            for(int i=1;i<=t;i++)
            {

                cin>>n;
                if(n<=100&&n>=7)
                {
                    for(int k=0;k<n;k++)
                    {
                        cin>>arr[k];
                        cc[n-1-k]=arr[k];
                    }
                    if(arr[0]==1)
                    {
                    for(int l=1;l<n/2;l++)
                    {
                        if(arr[l]>=1&&arr[l]<=10)
                        {
                            if(arr[l]==(arr[l-1]+1)||arr[l]==arr[l-1])
                            {
                                if(arr[l]==cc[l])
                                { continue;}
                                else
                                { 	flag++; break;}
                            }
                            else
                            { 	flag++; break;}

                        }
                        else
                        { 	flag++; break;}
                    }
                    }

                    if(flag==0)
                    cout<<"yes"<<endl;
                    else cout<<"no"<<endl;


                }
            }

        }
        x++;
	}
	return 0;
}
