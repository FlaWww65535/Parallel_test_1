#include <bits/stdc++.h>
#include<windows.h>
using namespace std;

const int MAXN=5000;
const int runtimes=10;

double a[MAXN+2][MAXN+2];
double b[MAXN+2];
double c[MAXN+2];
double res[MAXN+2];

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

class Trivial
{
public:
    void calculate()
    {
        CTimer timer;
        bool flag=1;
        double timecnt=0;
        for(int k=0;k<runtimes;k++)
        {
            memset(c,0,sizeof c);
            timer.time_in();
            for(int i=0;i<MAXN;i++)
            {
                for(int j=0;j<MAXN;j++)
                {
                    c[i]+=a[j][i]*b[i];
                }
            }
            timecnt+=timer.time_out();
            for(int i=0;i<MAXN;i++)
            {
                flag=c[i]==res[i];
            }
        }
        printf("Run 10 times,time cost:%lf\n",timecnt);
        if(flag)printf("Result correct\n");
    }
}trivial;

class Cache_optimized
{
public:
    void calculate()
    {
        CTimer timer;
        bool flag=1;
        double timecnt=0;
        for(int k=0;k<runtimes;k++)
        {
            memset(c,0,sizeof c);
            timer.time_in();
            for(int j=0;j<MAXN;j++)
            {
                for(int i=0;i<MAXN;i++)
                {
                    c[i]+=a[j][i]*b[i];
                }
            }
            timecnt+=timer.time_out();
            for(int i=0;i<MAXN;i++)
            {
                flag=c[i]==res[i];
            }
        }
        printf("Run 10 times,time cost:%lf\n",timecnt);
        if(flag)printf("Result correct\n");
    }
}
cache_opt;

void read()
{
    for(int i=0;i<MAXN;i++)
    {
        for(int j=0;j<MAXN;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=0;i<MAXN;i++)
    {
        cin>>b[i];
    }
    for(int i=0;i<MAXN;i++)
    {
        cin>>res[i];
    }
}

int main()
{
    freopen("input.dat","r",stdin);
    read();
    trivial.calculate();
    cache_opt.calculate();
    return 0;
}
