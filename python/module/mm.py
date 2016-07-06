__author__ = 'CQC'
#coding:utf-8
 

import urllib
import urllib2
import re
 
class Spider:
 
    def __init__(self):
        # self.siteURL = 'https://mm.taobao.com/631300490.htm'
        self.siteURL = 'http://image.baidu.com/'
 
    def getPage(self,pageIndex):
        url = self.siteURL + "?page=" + str(pageIndex)
        print url
        request = urllib2.Request(url)
        try:
            response = urllib2.urlopen(request)
            return response.read()
        except urllib2.URLError as e:
            print e   

        return "nothing"     
 
    def getContents(self,pageIndex):
        page = self.getPage(pageIndex)
        print page
        pattern = re.compile('<div class="list-item".*?pic-word.*?<a href="(.*?)".*?<img src="(.*?)".*?<a class="lady-name.*?>(.*?)</a>.*?<strong>(.*?)</strong>.*?<span>(.*?)</span>',re.S)
        items = re.findall(pattern,page)
        for item in items:
            print item[0],item[1],item[2],item[3],item[4]
 
spider = Spider()
spider.getContents(1)