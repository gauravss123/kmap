#include<iostream>
using namespace std;
void main()
{
clrscr();
int o=1,z=0,k,v,t[2][4],q[2][4]={NULL},p[2][4]={NULL},s[2][4]={NULL},s1[8]={NULL},p1[12][2]={NULL},q1[6][4]={NULL},i,j,l,m=0,n,a,b,c,e,f,g;

for(i=0;i<2;i++)
{
k=0;
m=4;
int l;
for(j=0;j<4;j++)
{
if(j==2)
k=1;
if(j==3)
k=-1;
cout<<"Enter 0 or 1 for "<<(i*m)+j+1<<" minterm \n";

cin>>l
if(l==1)
t[i][j+k]=0;
else if(l==0)
t[i][j+k]=1;
if(t[i][j+k]==1)
{
o=0;
++z;
}
}
}

if(z==8)
cout<<"Solution is 0\n";
else if(o==1)
cout<<"Solution is 1\n";
else
{
i=0;
a=0;
e=0;
for(i=0;i<2;i++)
{
if(t[i][0]==0)
{
int f=1;
for(j=1;j<4;j++)
{
if(t[i][j]==0)
++f;
}
if(f==4)
{
e=1;
for(j=0;j<4;j++)
{
q1[a][j]=((4*i)+j);
q[i][j]+=1;
}
a++;	}
}
}
i=0;
for(j=0;j<4;j++)
{

if(t[i][j]==0)
{
m=i+1;
n=j+1;
if(n==4)//t[i][j] in last column
n=0;
if(t[i][n]==0&&t[m][n]==0&&t[m][j]==0)
{
e=1;
k=0;
q1[a][k]=j;
q1[a][k+1]=n;
q1[a][k+2]=n+4;
q1[a][k+3]=j+4;
q[i][j]+=1;
q[i][n]+=1;
q[m][n]+=1;
q[m][j]+=1;
a++;
}
}
}

//pair horizontal
f=0;
int b=0;//flag for pair exists
for(i=0;i<2;i++)
{
for(j=0;j<4;j++)
{
if(t[i][j]==0)
{
m=j+1;
if(m==4)
m=0;
if(t[i][m]==0)
{
if(q[i][j]==0||q[i][m]==0)
{
b=1;
p[i][j]+=1;
p[i][m]+=1;
p1[f][0]=((i*4)+j);
p1[f++][1]=((i*4)+m);
}
}
}
}
}
//pair vertical
i=0;
for(j=0;j<4;j++)
{
if(t[i][j]==0)
{
if(t[i+1][j]==0)
{
if(q[i][j]==0||q[i+1][j]==0)
{
b=1;
p[i][j]+=1;
p[i+1][j]+=1;
p1[f][0]=((i)+j);
p1[f++][1]=(((i+1)*4)+j);
}
}
}
}

cout<<"Solution is\n";
///*

if(e==1)
{
i=0;
j=0;
while(i<a)
{
if(q1[i][j]==0&&q1[i][3]==3)
cout<<"a * ";
if(q1[i][j]==0&&q1[i][3]==4)
cout<<"b * ";
if(q1[i][j]==4&&q1[i][3]==7)
cout<<"a' * ";
if(q1[i][j]==1)
cout<<"b' * ";
if(q1[i][j]==2)
cout<<"c' * ";
if(q1[i++][j]==3)
cout<<"c * ";

}
}
if(b==1)
{
i=0;
j=0;
while(i<f)
{
if(p1[i][0]==0&&p1[i][1]==4)
cout<<"b+c * ";
if(p1[i][0]==1&&p1[i][1]==5)
cout<<"b+c' * ";
if(p1[i][0]==2&&p1[i][1]==6)
cout<<"b'+c' * ";
if(p1[i][0]==3&&p1[i][1]==7)
cout<<"b'+c * ";
if(p1[i][0]==0&&p1[i][1]==1)
cout<<"a+b * ";
if(p1[i][0]==1&&p1[i][1]==2)
cout<<"a+c' * ";
if(p1[i][0]==2&&p1[i][1]==3)
cout<<"a+b' * ";
if(p1[i][0]==3&&p1[i][1]==0)
cout<<"a+c * ";
if(p1[i][0]==4)
cout<<"a'+b * ";
if(p1[i][0]==5)
cout<<"a'+c' * ";
if(p1[i][0]==6)
cout<<"a'+b' * ";
if(p1[i++][0]==7)
cout<<"a'+c * ";
}
}
//print if no grouping but lone element
if(t[0][0]==1&&q[0][1]==0&&p[0][1]==0&&q[1][0]==0&&p[1][0]==0&&q[0][3]==0&&p[0][3]==0)
cout<<"a+b+c * ";
if(t[0][1]==1&&q[0][2]==0&&p[0][2]==0&&q[1][1]==0&&p[1][1]==0&&q[0][0]==0&&p[0][0]==0)
cout<<"a+b+c' * ";
if(t[0][2]==1&&q[0][3]==0&&p[0][3]==0&&q[1][2]==0&&p[1][2]==0&&q[0][1]==0&&p[0][1]==0)
cout<<"a+b'+c' * ";
if(t[0][3]==1&&q[0][0]==0&&p[0][0]==0&&q[1][3]==0&&p[1][3]==0&&q[0][2]==0&&p[0][2]==0)
cout<<"a+b'+c * ";
if(t[1][0]==1&&q[1][1]==0&&p[1][1]==0&&q[0][1]==0&&p[0][0]==0&&q[1][3]==0&&p[1][3]==0)
cout<<"a'+b+c * ";
if(t[1][1]==1&&q[1][2]==0&&p[1][2]==0&&q[0][1]==0&&p[0][1]==0&&q[1][0]==0&&p[1][0]==0)
cout<<"a+b'+c * ";
if(t[1][2]==1&&q[1][3]==0&&p[1][3]==0&&q[0][2]==0&&p[0][2]==0&&q[1][1]==0&&p[1][1]==0)
cout<<"a'+b'+c' * ";
if(t[1][3]==1&&q[1][0]==0&&p[1][0]==0&&q[0][3]==0&&p[0][3]==0&&q[1][2]==0&&p[1][2]==0)
cout<<"a'+b'+c * ";

}

}
