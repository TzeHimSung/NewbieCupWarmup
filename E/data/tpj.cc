#include <bits/stdc++.h>
#include "testlib.h"
#define ull unsigned long long
#define ll long long

#define lb long double
ll ksc(ull x, ull y, ll p)
{
    return (x * y - (ull)((lb)x / p * y) * p + p) % p;
}

ll ksm(ll x, ll y, ll p)
{
    ll res = 1;
    while (y)
    {
        if (y & 1)
            res = ksc(res, x, p);
        x = ksc(x, x, p);
        y >>= 1;
    }
    return res;
}

bool mr(ll x, ll p)
{
    if (ksm(x, p - 1, p) != 1)
        return 0;
    ll y = p - 1, z;
    while (!(y & 1))
    {
        y >>= 1;
        z = ksm(x, y, p);
        if (z != 1 && z != p - 1)
            return 0;
        if (z == p - 1)
            return 1;
    }
    return 1;
}

bool prime(ll x)
{
    if (x < 2)
        return 0;
    if (x == 2 || x == 3 || x == 5 || x == 7 || x == 43)
        return 1;
    return mr(2, x) && mr(3, x) && mr(5, x) && mr(7, x) && mr(43, x);
}
int flag;
int check()
{ 
    ll n = inf.readLong();
    ll a = ouf.readLong();
    ll b = ouf.readLong();
   
    if (a<=1||b<=1||a>1e18||b>1e18 ) {
        flag = 1;
        return 0;
    }
    else if ((prime(a) == true) && (prime(b) == false))
    {
        if ((a ^ b) == n)
        {
            ;
        }
        else
        {
            flag =2;
            // quitf(_wa,"Wrong Answer!");
        }
    }
    else
    {
        flag = 1;
        // quitf(_wa,"Wrong Answer!");
    }

    return 0;
}
int main(int argc, char *argv[])
{

    registerTestlibCmd(argc, argv);
    flag = 0;
    int t = inf.readInt();
    for (int i = 0; i < t; i++)
    {
        check();
    }
    if (flag)
        quitf(_wa, "Wrong Answer!");
    else
        quitf(_ok, "Correct!");
    return 0;
}
