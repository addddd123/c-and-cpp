#include<iostream>
using namespace std;
#include<conio.h>

class C;
class B;
class A
{
	int a[5];
	public:
	void f1();
       friend C;
};
void A::f1()
{
	int i=0;
	cout<<"enter 5 elements\n";
	for(i=0;i<5;i++)
	cin>>a[i];
}
class B
{
	int b[5];
	public:
	void f2();
	friend C ;
};
void B::f2()
{      int  i=0;
	cout<<"enetr 5 elements\n";
	for(i=0;i<5;i++)
	cin>>b[i];
}
class C
{     int  c[5];
	public:
	void f3(A x,B y);
};
void C::f3(A x,B y)
{      int  i=0;
	cout<<"elements after addtion are";
	for(i=0;i<5;i++)
	{
		c[i]=x.a[i]+y.b[i];
		cout<<" "<<c[i];
	}
}
int main()
{      // clrscr();
	A l;
	B m;
	C n;
	l.f1();
	m.f2();
	n.f3(l,m);
	getch();
}


