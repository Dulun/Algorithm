/*************************************************************************
	> File Name: 1099_字串变换.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2016年03月11日 星期五 13时19分48秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<string.h>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;
 
const int N = 5086;
struct Node
{
    char s[30];//过程中的字符串
    char dep;//深度
};

Node list1[N], list2[N];

char a[7][30] , b[7][30]; //两个数组，表示变换规则

int n;//变换规则数

bool IsSame(char *s1, char *s2) //判断两是否相同
{
    int t = strlen(s1);
    if(t != strlen(s2)) return false;
    for(int i = 0; i < t; i++)
    {
        if(s1[i] != s2[i]) return false;
    }
    return true;
}
/*
bool check(char * s1, char * s2)
{
    if(strlen(s1) != strlen(s2)) return false;
    for(int i = 0; i < strlen(s1); i++)
    if(s1[i] != s2[i]) return false;
    return true;
}

bool pan1(char *s, int i, int x)
{
    for(int j = i; j < i+strlen(a[x]); j++)
        if(s[j] != a[x][j-i]) return false;
    return true;
}
bool pan2(char *s, int i, int x)
{
    for(int j = i; j < i+strlen(b[x]); j++)
        if(s[j] != b[x][j-i]) return false;
    return true;
}
*/
bool IsIn(char * tmp, int cnt, int flag) //判断当前字符串从下标为start开始，是否与第cnt个变换规则相同
{
    char * cmp;
  //  printf("DEbug: %s\n", tmp);
    if(flag == 1) cmp = a[cnt];
    else          cmp = b[cnt];

    for(int i = 0; i < strlen(cmp);i++)
    {
        if(cmp[i] != tmp[i]) return false;
    }
    return true;
}


void bfs() //双向bfs，从起点向终点，从终点向起点
{
    int head1, tail1, head2, tail2, k;
    head1 = head2 = tail1 = tail2 = 1;
    while(head1 <= tail1 && head2 <= tail2) //
    {
        if(list1[head1].dep + list2[head2].dep > 10)
        {//步数大于10返回
            printf("NO ANSWER!\n");
            return ;
        }
        
        //从起点向终点向终点变换
        for(int i = 0; i < strlen(list1[head1].s); i++)
        for(int j = 1; j <= n; j++)
        {
            if(IsIn(list1[head1].s+i, j, 1))
            //if(pan1(list1[head1].s, i, j))
            {
                tail1++;
                for(k = 0; k < i; k++)//写入没被规则替换的前半部分
                {
                    list1[tail1].s[k] = list1[head1].s[k];   
                }
                for(int l = 0; l < strlen(b[j]); l++, k++)//写入被规则替换过得部分
                {
                    list1[tail1].s[k] = b[j][l];
                }
                for(int l = i+strlen(a[j]); l <= strlen(list1[head1].s) ; l++, k++)//写入没被替换的后半部分
                {
                    list1[tail1].s[k] = list1[head1].s[l];
                }
                //善后工作
                list1[tail1].s[k] = 0;
                list1[tail1].dep = list1[head1].dep+1;
                //判断首尾是否呼应
                for(k = 1; k <= tail1; k++)
                {
                    if(IsSame(list1[tail1].s, list2[k].s))
                   // if(check(list1[tail1].s, list2[k].s))
                    {
                        printf("%d\n", list1[tail1].dep + list2[k].dep);
                        return;
                    }
                }
            }
        }
       
        for(int i = 0; i < strlen(list2[head2].s); i++)
        for(int j = 1; j <= n; j++)
        {
            if(IsIn(list2[head2].s+i, j, 2))
          //  if(pan2(list2[head2].s, i, j))
            {
                tail2++;
                for(k = 0; k < i; k++)//写入没被规则替换的前半部分
                {
                    list2[tail2].s[k] = list2[head2].s[k];   
                }
                for(int l = 0; l < strlen(a[j]); l++, k++)//写入被规则替换过得部分
                {
                    list2[tail2].s[k] = a[j][l];
                }
                for(int l = i+strlen(b[j]); l <= strlen(list2[head2].s) ; l++, k++)//写入没被替换的后半部分
                {
                    list2[tail2].s[k] = list2[head2].s[l];
                }
                //善后工作
                list2[tail2].s[k] = 0;
                list2[tail2].dep = list2[head2].dep+1;
                //判断首尾是否呼应
                for(k = 1; k <= tail1; k++)
                {
                    if(IsSame(list2[tail2].s, list1[k].s))
                    //if(check(list1[k].s, list2[tail2].s))
                    {
                        printf("%d\n", list1[k].dep + list2[tail2].dep);
                        return;
                    }
                }
            }
        }
        head1++; head2++;   
    }
    printf("NO ANSWER!\n");
}

int main()
{
    scanf("%s%s", list1[1].s, list2[1].s);
    n = 1;
    while(scanf("%s%s", a[n], b[n]) != EOF) n++;//最后一次+1要减掉
    n--;
    
    list1[1].dep = list2[1].dep = 0;
    bfs();
    return 0;
}
