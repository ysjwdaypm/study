#encoding=utf-8

import smtplib,sys
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart
from email.mime.image import MIMEImage
from_mail='ysjwdaypm@163.com'
to_mail='393433696@qq.com'

conent = "你所知道的那些事，我也不知道该说些什么，你认为的好与不好我也不知道该如何的评定"
title = "关于事件报告的信息收集"

if len(sys.argv) == 3:
	title = sys.argv[1]
	conent = sys.argv[2]

msg=MIMEText(conent,_charset='utf-8')
# msg['From']=from_mail
# msg['To']=to_mail
msg['Subject']=title
# content=MIMEText('<b>I am come 126,i with attach<b>','html')
# msg.attach(content)
# attac=MIMEImage(file('/opt/25343674.png','rb').read())
# attac['Content-Type']='application/octet-stream'
# attac.add_header('content-disposition','attachment',filename='/opt/25343674.png')
# msg.attach(attac)
server=smtplib.SMTP('smtp.163.com')
# print 'server',server
# server.docmd('ehlo',from_mail)
if server.login(from_mail,'1986912'):
	# print "\n*******************************\n",msg.as_string(),"\n************************************************\n"
	print "start to send mail title = ",title ,"\n content: ",conent
	server.sendmail(from_mail,to_mail,msg.as_string())
	print 'send successful'
else:
	print "login fail"	

server.quit()