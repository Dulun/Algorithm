/*************************************************************************
	> File Name: 1013.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2015年11月28日 星期六 19时15分21秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
char inorder[1000];
char postorder[1000];

//分治
void build(int l1, int r1, int l2, int r2)
{
    int mid = strchr(inorder, postorder[r2]) - inorder;
    cout<<inorder[mid];
    if(mid > l1) build(l1, mid - 1, l2, l2 + mid - l1 - 1);
 // if(mid < r1) build(mid + 1, r1, r2 + mid - r1, r2 - 1);
    
    if(mid < r1) build(mid + 1, r1, l2+mid-l1, r2 - 1);
}

int main()
{

    cin>>inorder>>postorder;

    int len = strlen(inorder);
    build(0, len-1, 0, len-1);
    return 0;
}
