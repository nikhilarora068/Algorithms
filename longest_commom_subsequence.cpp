#include<bits/stdc++.h>
using namespace std;

int max(int a,int b)
{
    return (a > b) ? a : b;
}
int main()
{
    char str1[]="ABCDAF";
    char str2[]="ACBCF";
    int i,j,k;
    int n=strlen(str1);
    int m=strlen(str2);
    int a[m+1][n+1];

    for(i=0;i<=m;i++)
    {
        for(j=0;j<=n;j++)
        {
            if(i==0 || j==0)
                a[i][j]=0;

            else if(str1[j-1] == str2[i-1])
                    a[i][j]=a[i-1][j-1]+1;

            else
                a[i][j]=max(a[i-1][j], a[i][j-1]);
        }
    }

for(i=0;i<=m;i++)
    {
        for(j=0;j<=n;j++)
            cout<<a[i][j]<<" ";
        cout<<"\n";
    }


    cout<<a[m][n]<<"\n";

vector <char> v;
i=m,j=n;

while(a[i][j]!=0)
{
        if(str1[j-1]==str2[i-1])
        {
            v.push_back(str1[j-1]);
            i--;
            j--;
        }
        else if(a[i][j] == a[i-1][j])
        {
            i--;
        }
        else if(a[i][j] == a[i][j-1])
        {
            j--;
        }
}

for(i=v.size()-1;i>=0;i--)
    cout<<v[i];

cout<<"\n";
}

