/*************************************************************************
	> File Name: 1084.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2016年02月29日 星期一 15时05分08秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
using namespace std;

char pp[1000086];

int main()
{
    int count = 0;
    while(1)
    {
        char t;
        cin>>t;
        if(t != 'E') 
        {
            pp[count++] = t;
        }
        else break;
    }
//    if(pp[0] == 'E') return 0;

    int count_w = 0, count_l = 0;
    for(int i = 0; pp[i] != 'E' && i < count; i++)
    {
        if(pp[i] == 'W') count_w++;
        else             count_l++;
        
        if((count_w >= 11 || count_l >= 11) && (count_w - count_l >=2 || count_l - count_w >=2))
        {
            cout<<count_w<<":"<<count_l<<endl;
            count_w = count_l = 0;
        }
        
    }
///    if(!(count_w == 0 && count_l == 0))
 //   {
        cout<<count_w<<":"<<count_l<<endl;
  //  }
    cout<<endl;


    
    count_w = count_l = 0;
    for(int i = 0; pp[i] != 'E' && i < count; i++)
    {
        if(pp[i] == 'W') count_w ++;
        else             count_l ++;
        
        if((count_w >= 21 || count_l >= 21) && (count_w - count_l >=2 || count_l - count_w >=2))
        {
            cout<<count_w<<":"<<count_l<<endl;
            count_w = count_l = 0;
        }
        
    }

    //if(!(count_w == 0 && count_l == 0))
    //{
        cout<<count_w<<":"<<count_l<<endl;
    //}
    
    return 0;
}
