/*************************************************************************
	> File Name: gas_station.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2015年12月17日 星期四 21时24分14秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
using namespace std;

int gas[] = {31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30};
int cost[] = {36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35};


bool yes(int s, int n, int left[])
{
    int have = left[s];
    int i;

    if(s == n-1) i = 0;
    else i = s+1;

    while(i != s)
    {
        have += left[i];
        if(have < 0) return -1;
     
        if(i == n-1) i = 0;
        else i++;
    }
    return 1;
}

int main()
{
    int n = sizeof(gas) / sizeof(int);
    int left[1000] = {0};

    int station = -1;
    for(int i = 0; i < n; i++)
    {
        left[i] = gas[i] - cost[i];
    }

    for(int i = 0; i < n; i++)
    {
        if(left[i] < 0) continue;
        if(yes(i, n, left) == 1) {station = i; break;}
    }
    cout<<station;
}
