# coding=utf-8

from django.shortcuts import render,render_to_response
from django.http	import HttpResponse
from django.template import loader,Context,Template
import json,time,sys
import pytz, datetime
from models import Person,BagManager
from django.template import RequestContext
# Create your views here.


reload(sys)
sys.setdefaultencoding('utf8')

logPath = 'log.txt'


"""
python manage.py createsuperuser
python manage.py runserver
"""

def index(req):
	print "ip : %s"%req.META
	d = {'req':req,'d':datetime.datetime.now(),"title":"python","name":"guest","list":[1,2,3,4,5,6,7],"l":['States', ['Kansas', ['Lawrence', 'Topeka'], 'Illinois']]}
	return render_to_response('index.html',d,RequestContext(req))


def getNowTime():
	return time.strftime('%Y-%m-%d %H:%M:%S',time.localtime())

def log(req):
	print req.GET['i']
	if 'i' in req.GET:
		f = open(logPath,'a')
		f.write(req.GET['i'] +  '              time:' + getNowTime()+ "\n<br>")
		f.close()
		print "write success"
	dic = {"ret":True}

	return HttpResponse(json.dumps(dic))	

def readLog(req):
	f = open(logPath,'r')
	log = f.read()	
	return HttpResponse(log)


def register(req):
	u = req.GET["u"]
	pwd = req.GET["p"]

	ret = {"ret":True}

	plist = Person.objects.filter(name=u)
	if len(plist) == 0:
		Person.objects.create(name=u,password=pwd,age=30)
		ret["msg"] = r"用户名 %s 创建成功"%u
	else:
		ret["ret"] = False
		ret["msg"] = r"用户名 %s 已经存在"%u		

	return HttpResponse(json.dumps(ret,ensure_ascii=False))		



def main(req):
	action = req.GET["action"]
	if action == "register":
		return register(req)
	elif action == "login":
		return login(req)	
	elif action == "log":
		log(req)		
	ret = {"msg":"undefin action  %s"%action}
	return HttpResponse(json.dumps(ret,ensure_ascii=False))	

def wel(req):
	ret = "";
	for k in req.GET:
		ret += k + ":" + req.GET[k] + "</br>"

	t = Template("<h1>{{user.name}} welcome to my page</h1>");	
	c = Context({"user":{"name":"ysjwdaypm"}})
	# return HttpResponse(t.render(c))

	users = []
	for user in Person.objects.all():
		users.append({"name":user.name,"password":user.password})

	BagManager.addItem(123);	

	return HttpResponse(json.dumps({"users":users},ensure_ascii=True))	

def login(req):
	u = req.GET['u']
	pwd = req.GET['p']

	ret = {"ret":True}
	plist = Person.objects.filter(name=u)
	if len(plist) == 0 or not plist[0].password == pwd:
		ret["ret"] = False
		ret["msg"] = " 帐号或密码错误"


	return HttpResponse(json.dumps(ret,ensure_ascii=False))	
