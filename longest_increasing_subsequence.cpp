#include<bits/stdc++.h>
#define n 8
using namespace std;

int main()
{
    int i,j,max=0;
    int a[n]={10,22,9,33,21,50,41,60};
    int lis[n];

for(i=0;i<n;i++)
    lis[i]=1;

for(i=1;i<n;i++)
{
    for(j=0;j<i;j++)
    {
        if(a[j]<a[i] && lis[i]<lis[j]+1)
        {
            lis[i]=lis[j]+1;
        }
    }
}
for(i=0;i<n;i++)
{
    cout<<lis[i]<<" ";

    if(lis[i]>max)
        max=lis[i];
}

cout<<"\n"<<max<<"\n";
}
