#! /usr/bin/env python
# -*- coding=utf-8 -*-
# encoding: utf-8
# coding=utf-8

import time
import urllib2
#url="http://pythontab.com"
url = "http://blog.csdn.net/dextrad_ihacker/article/details/50820018"
#url="http://blog.csdn.net/dextrad_ihacker/article/details/51143400"
#url =  "http://blog.csdn.net/dextrad_ihacker/article/details/51121731"
req_header = {'User-Agent':'Mozilla/5.0 (Windows NT 6.1) AppleWebKit/537.11 (KHTML, like Gecko) Chrome/23.0.1271.64 Safari/537.11',
'Accept':'text/html;q=0.9,*/*;q=0.8',
'Accept-Charset':'ISO-8859-1,utf-8;q=0.7,*;q=0.3',
'Accept-Encoding':'gzip',
'Connection':'close',
'Referer':None #注意如果依然不能抓取的话，这里可以设置抓取网站的host
}

for x in range(1000) :
    time.sleep(1)
    req_timeout = 10000
    req = urllib2.Request(url,None,req_header)
    resp = urllib2.urlopen(req,None,req_timeout)
    html = resp.read()
    print(x)

