import urllib.request
import urllib.parse
import time
from PyQt5 import QtCore, QtGui, QtWidgets
from PyQt5.QtCore import pyqtSignal
from bs4 import BeautifulSoup

#抓取网页的类
class Grab():
    url = ''
    soup = None
    #读取当前网页的源代码数据返回
    def GetPage(self, url):
        self.url = url
        req = urllib.request.Request(url, headers={'User-Agent' : "Magic Browser"})
        try:page = urllib.request.urlopen(req)
        except:return
        tem = page.read()
        if not tem:
            print('GetPage failed!')
            sys.exit()
        return tem

    def ExtractInfo(self,buf):
        try:
            from bs4 import BeautifulSoup
            self.soup = BeautifulSoup(buf,'html.parser')
        except:return
        try:items = self.soup.findAll(attrs={'class':'link_title'})
        except:return
        links = []
        titles = []
        for item in items:
            title = item.get_text().strip()
            titles.append(title)
            linkobj = item.findAll('a')
            for it in linkobj:
                link = it['href']
                links.append('http://blog.csdn.net'+link)
        return links,titles

    def GetPageUrl(self,buf):
        pages = set()
        self.soup = BeautifulSoup(buf,'html.parser')
        pageInfo=self.soup.find(attrs={'id':'papelist'})
        #当前文章数量只有一页
        if not pageInfo:
            return None
        pagelinks = pageInfo.findAll('a')
        for link  in pagelinks:
            pages.add('http://blog.csdn.net/'+link['href'])
        return pages

    def GetCurViewerPoint(self,buf):
        self.soup = BeautifulSoup(buf,'html.parser')
        pointobj = self.soup.find(attrs={'class':'link_view'})
        title = self.soup.find(attrs={'class':'link_title'})
        return title.get_text().strip()+'  '+pointobj.get_text()



#界面类
class Ui_Form(object):
    def setupUi(self, Form):
        Form.setObjectName("Form")
        self.label = QtWidgets.QLabel(Form)
        self.label.setGeometry(QtCore.QRect(20, 30, 81, 21))
        self.label.setObjectName("label")
        self.username = QtWidgets.QPlainTextEdit(Form)
        self.username.setGeometry(QtCore.QRect(110, 20, 341, 41))
        self.username.setObjectName("username")
        self.label_2 = QtWidgets.QLabel(Form)
        self.label_2.setGeometry(QtCore.QRect(30, 80, 61, 31))
        self.label_2.setObjectName("label_2")
        self.times = QtWidgets.QPlainTextEdit(Form)
        self.times.setGeometry(QtCore.QRect(110, 80, 151, 41))
        self.times.setObjectName("times")
        self.beginBtn = QtWidgets.QPushButton(Form)
        self.beginBtn.setGeometry(QtCore.QRect(300, 80, 61, 41))
        self.beginBtn.setObjectName("beginBtn")
        self.progressBar = QtWidgets.QProgressBar(Form)
        self.progressBar.setGeometry(QtCore.QRect(30, 350, 461, 41))
        self.progressBar.setProperty("value", 0)
        self.progressBar.setObjectName("progressBar")
        self.listWidget = QtWidgets.QListWidget(Form)
        self.listWidget.setGeometry(QtCore.QRect(30, 180, 431, 151))
        self.listWidget.setObjectName("listWidget")
        self.info = QtWidgets.QLabel(Form)
        self.info.setGeometry(QtCore.QRect(30, 140, 421, 31))
        self.info.setText("")
        self.info.setObjectName("info")
        self.exitBtn = QtWidgets.QPushButton(Form)
        self.exitBtn.setGeometry(QtCore.QRect(390, 80, 61, 41))
        self.exitBtn.setObjectName("exitBtn")

        self.thread=MyThread()
        self.thread.sinOut.connect(self.handler)

        self.retranslateUi(Form)
        self.exitBtn.clicked.connect(Form.close)
        self.beginBtn.pressed.connect(self.mainFunc)
        QtCore.QMetaObject.connectSlotsByName(Form)

    def handler(self,type,text,content):
        if type == 1:
            self.listWidget.addItems(content)
        elif type == 2:
            self.progressBar.setProperty("value", float(text))
        elif type == 3:
            self.info.setText(text)


    def mainFunc(self):
        username = self.username.toPlainText().strip()
        times = self.times.toPlainText().strip()
        if username and times:
            self.thread.setVal(username,times)
            self.thread.start()

    def retranslateUi(self, Form):
        _translate = QtCore.QCoreApplication.translate
        Form.setWindowTitle(_translate("Form", "Blog作弊器"))
        self.label.setText(_translate("Form", " CSDN用户名"))
        self.label_2.setText(_translate("Form", "设置次数"))
        self.beginBtn.setText(_translate("Form", "Start"))
        self.exitBtn.setText(_translate("Form", "Exit"))


#子线程
class MyThread(QtCore.QThread):
    sinOut = pyqtSignal(int,str,set)
    articles = set()
    def __init__(self):
        super(MyThread,self).__init__()
        self.username=''
        self.times=''

    def setVal(self,username,times):
        self.username=username
        self.times=times

    def run(self):
        #发射信号
        grab = Grab()
        buf = grab.GetPage('http://blog.csdn.net/'+self.username)
        pages = ['http://blog.csdn.net/'+self.username,]
        tem = grab.GetPageUrl(buf)
        content = set()
        links = []
        titles = []
        if not tem:pass
        else: pages+=tem
        for page in pages:
            buf = grab.GetPage(page)
            link,title = grab.ExtractInfo(buf)
            links+=link
            titles+=title
        titles=zip(links,titles)
        for link in links:
            self.articles.add(link)
        for title in titles:
            tem = ''
            for val in title:
                tem+=val+' '
            content.add(tem)

        self.sinOut.emit(1,'',content)
        sumRes = len(self.articles)*int(self.times)
        cur = 1
        for url in self.articles:
            for i in range(0,int(self.times)):
                buf=grab.GetPage(url)
                self.sinOut.emit(2,str(cur/sumRes*100),content)
                self.sinOut.emit(3,grab.GetCurViewerPoint(buf),content)
                cur+=1
                time.sleep(0.1)


if __name__=='__main__':
    import sys
    app=QtWidgets.QApplication(sys.argv)
    widget=QtWidgets.QWidget()
    ui=Ui_Form()
    ui.setupUi(widget)
    widget.show()
    sys.exit(app.exec_())
