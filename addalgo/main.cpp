#include <bits/stdc++.h>
#include<windows.h>
using namespace std;

const int MAXN=524288;
//const int MAXN=4;
const int runtimes=100;
long long a[MAXN];
long long b[MAXN];
long long res;

class CTimer
{
public:
	CTimer(void);
	~CTimer(void);

	void time_in();
	double time_out();

private:
	LARGE_INTEGER litmp;
	LONGLONG qt1, qt2;
	double dft, dff, dfm;
};

CTimer::CTimer(void)
{
}


CTimer::~CTimer(void)
{
}

void CTimer::time_in()
{
	QueryPerformanceFrequency(&litmp);
	dff = (double)litmp.QuadPart;
	QueryPerformanceCounter(&litmp);
	qt1 = litmp.QuadPart;
	return;
}

double CTimer::time_out()
{
	QueryPerformanceCounter(&litmp);
	qt2 = litmp.QuadPart;

	dfm = (double)(qt2 - qt1);
	dft = dfm / dff;

	return dft;
}

class Trivial{
public:
    void calculate()
    {
        double timecnt=0;
        bool flag=1;
        for(int i=0;i<runtimes;i++)
        {
        long long ans=0;
        CTimer timer;
        timer.time_in();
        for(int i=0;i<MAXN;i++)
        {
            ans+=a[i];
        }
        timecnt+=timer.time_out();
        flag=res==ans;
        }
        printf("Run %d times.time cost:%lf\n",runtimes,timecnt);
        if(flag)printf("Correct\n");
    }
}trivial;

class DoubleLine{
public:
    void calculate()
    {
        double timecnt=0;
        bool flag=1;
        for(int i=0;i<runtimes;i++)
        {
        long long ans1=0,ans2=0;
        CTimer timer;
        timer.time_in();
        for(int i=0;i<MAXN;i+=2)
        {
            ans1+=a[i];
            ans2+=a[i+1];
        }
        long long ans=ans1+ans2;
        timecnt+=timer.time_out();
        flag=res==ans;
        }
        printf("Run %d times.time cost:%lf\n",runtimes,timecnt);
        if(flag)printf("Correct\n");
    }
}doubleLine;

class LogAlgo{
public:
    void calculate()
    {
        double timecnt=0;
        bool flag=1;
        for(int i=0;i<runtimes;i++)
        {
            long long ans=0;
            for(int i=0;i<MAXN;i++)b[i]=a[i];
            CTimer timer;
            timer.time_in();
            for(int m=MAXN;m>1;m>>=1)
            {
                for(int i=0;i<m/2;i++)
                {
                    b[i]=b[i<<1]+b[(i<<1)+1];
                }
            }
            ans=b[0];
            timecnt+=timer.time_out();
            flag=res==ans;
        }
        printf("Run %d times.time cost:%lf\n",runtimes,timecnt);
        if(flag)printf("Correct\n");
    }
}logAlgo;

void read()
{
    freopen("input.dat","r",stdin);
for(int i=0;i<MAXN;i++)
{

    cin>>a[i];
}
cin>>res;
}

int main()
{
    read();
   trivial.calculate();
   doubleLine.calculate();
   logAlgo.calculate();
}
