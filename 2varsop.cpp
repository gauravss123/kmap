#include<iostream>
using namespace std;
void main()
{
clrscr();
int v=0,a[2][2],c=0,p[4],i,j,l,m,q=1,s[2][2],r=0;//s=0;
for(i=0;i<2;i++)
{

for(j=0;j<2;j++)
{
cout<<"Enter 0 or 1 for "<<j+c+1<<"minterm\n";
cin>>a[i][j];
s[i][j]=0;
p[j+c]=0;
if(a[i][j]==0)
{
q=0;
++v;
}
}
c=2;
}
if(v==4)
cout<<"Solution is 0\n";
else if(q==1)
{
cout<<"Grouping of 0,1,2,3\n Solution is 1";
}
else
{
for(i=0;i<2;i++)//to detect single element
{
for(j=0;j<2;j++)
{int c;
int l=i,m=j,p=i,q=j;
if(a[i][j]==1)
{
if(++m==2)
m=0;
if(++p==2)
p=0;
if(a[l][m]==0&&a[p][q]==0)
s[i][j]=1;

}
}
}

for(i=0;i<2;i++)//to detect pair
{
for(j=0;j<1;j++)
{
if(a[i][j]==1)
{
if(a[i][j+1]==1)
p[r]=1;
if(i==0)
{
if(a[i+1][j]==1)
p[r+1]=1;

}	}
r=2;
if(i==1)
{
{
if(a[i][j+1]==1&&a[i-1][j+1]==1)
p[r+1]=1;
}
}
}
}


//display
cout<<"Solution is \n";
if(p[0]==1)//grouping
cout<<"0 and 1\t";
if(p[1]==1)//grouping
cout<<"0 and 2\t";
if(p[2]==1)//grouping
cout<<"2 and 3\t";
if(p[3]==1)//grouping
cout<<"1 and 3\t";
cout<<"\n\n";
if(s[0][0]==1)//grouping
cout<<"0\t";
if(s[0][1]==1)//grouping
cout<<"1\t";
if(s[1][0]==1)//grouping
cout<<"2\t";
if(s[1][1]==1)//grouping
cout<<"3\t";

if(p[0]==1)//answer
cout<<"a' + ";
if(p[1]==1)//grouping
cout<<"b' + ";
if(p[2]==1)//grouping
cout<<"a + ";
if(p[3]==1)//grouping
cout<<"b + ";

if(s[0][0]==1)//grouping
cout<<"a'b' + ";
if(s[0][1]==1)//grouping
cout<<"a'b +  ";
if(s[1][0]==1)//grouping
cout<<"ab' + ";
if(s[1][1]==1)//grouping
cout<<"ab + ";


}

}

