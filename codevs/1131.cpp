/*************************************************************************
	> File Name: 1131.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2015年11月17日 星期二 21时57分29秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;

int main()
{
    string a[1000];
    string world;
    cin>>world;
    int start = -1;
    int count = 0;
    int num = 0;
    for(int i = 0; i < 1000; i++)
    {
        cin>>a[i];
        num++;
    }
    for(int i = 0; i <= num; i++)
    {
        if(count == 0 && a[i] == world)
        {
            start = i;
        }
        if(a[i] == world)
        {
            count++;
        }
    }
    cout<<start<<" "<<count;
}
