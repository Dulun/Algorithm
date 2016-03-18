/*************************************************************************
	> File Name: 单增子序列2.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2016年02月29日 星期一 19时16分10秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
using namespace std;

int array[50008];
int liss[50008];
int pre[50008];
 
int main()
{
    int length;
    cin>>length;
    for(int i = 0 ; i < length; i++)
    {
        cin>>array[i];
        pre[i] = i;
    }

  unsigned int i, j, k, l, max; 
    liss[0] = 0;  
  
    for(i = 0; i < length; ++i)  
    {  
        pre[i] = i;  
    }  
  
    for(i = 1, max = 1; i < length; ++i)  
    {  
        //找到这样的j使得在满足array[liss[j]] > array[i]条件的所有j中，j最小  
        j = 0, k = max - 1;  
  
        while(k - j > 1)  
        {  
            l = (j + k) / 2;  
  
            if(array[liss[l]] < array[i])  
            {  
                j = l;  
            }  
            else  
            {  
                k = l;  
            }  
        }  
  
        if(array[liss[j]] < array[i])  
        {  
            j = k;  
        }  
  
        //array[liss[0]]的值也比array[i]大的情况  
        if(j == 0)  
        {  
            //此处必须加等号，防止array中存在多个相等的最小值时，将最小值填充到liss[1]位置  
            if(array[liss[0]] >= array[i])  
            {  
                liss[0] = i;  
                continue;  
            }  
        }  
  
                //array[liss[max -1]]的值比array[i]小的情况  
                if(j == max - 1)  
        {  
            if(array[liss[j]] < array[i])  
            {  
                pre[i] = liss[j];  
                liss[max++] = i;  
                continue;  
            }  
        }  
  
        pre[i] = liss[j - 1];  
        liss[j] = i;  
    }  
  

  
    printf("%d\n", max); 

}
