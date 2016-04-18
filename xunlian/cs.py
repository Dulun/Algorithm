#!/usr/bin/env python
# encoding: utf-8
# coding=utf-8
# -*- coding:utf-8 -*-
import sys
import urllib
import urllib2
import re
reload(sys)
sys.setdefaultencoding('utf-8')
# 伪装成浏览器
headers = {
    'User-Agent': 'Mozilla/5.0 (Windows NT 6.1) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/31.0.1650.57 Safari/537.36'}
# 指定url并发送请求
req = urllib2.Request(
    # ******为你的博客名
    'http://blog.csdn.net/dextrad_ihacker?viewmode=list', headers=headers)
# 服务端响应来自客户端的请求
response = urllib2.urlopen(req)
lines = ''.join(response.read())
# 正则表达式得到链接
regex = r'href="(.*?)"'
L = []
#count用来记数，因为根据此正则规则从源码找出的有重复
count = 1
for m in re.findall(regex, lines):
    if len(m) == 35 and count % 2 == 1 and "category" not in m and m not in L:
    	L.append(m)
    count = count + 1
#开始拼接每一个url并循环访问url
print "get url:"+'\n'
print len(L)
a = 0
for mm in L:
	url = 'http://blog.csdn.net/' + mm
	print url
	headers = {
    'User-Agent': 'Mozilla/5.0 (Windows NT 6.1) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/31.0.1650.57 Safari/537.36'}
	#每个url循环1000次,可以设置更多
	for num in range(1,1001):
		req_url = urllib2.Request(url, headers=headers)
		response_url = urllib2.urlopen(req_url)
	print "crawling success"
print "ok"
