#coding=utf-8
from __future__ import unicode_literals
from django.db import models

import sys,os
reload(sys)
sys.setdefaultencoding("utf-8")

# os.environ['DJANGO_SETTINGS_MODULE'] = 'st01.settings'

#python manage.py shell


class BagItem(models.Model):
	item_id = models.IntegerField();


class BagManager(object):

	@staticmethod
	def addItem(_id):
		tt = BagItem.objects.filter(item_id=_id)
		if not tt:
			t = BagItem.objects.create(item_id=_id);
			t.save()
		else:
			print("%d has exists"%_id)	

	@staticmethod	
	def getItem(_id):
		t = BagItem.objects.filter(item_id=_id)
		return t	


class Person(models.Model):
	name = models.CharField(max_length=30)
	password = models.CharField(max_length=30,default="123456")
	age = models.IntegerField()

	def __str__(self):
		return self.name

# p = Person.objects.get_or_create(name="ysj")[0]
# p.password = "1986912"
# p.save()		

# # Create your models here.
# class Person(models.Model):
# 	name = models.CharField(max_length=30)
# 	password = models.CharField(max_length=30,default="123456")
# 	age = models.IntegerField()


# 	def update(self,age=0,password=""):
# 		if not age == 0:
# 			self.age = age

# 		if not password == "":
# 			self.password = password

# 		self.save()			

# 	def __unicode__(self):
# 		return self.name

# class Group(models.Model):
# 	name = models.CharField("group name",max_length=30)	
# 	memberlist = []

# 	def addMember(self,m):
# 		gm = GroupMember.objects.get_or_create(name=m,group=self)[0]
# 		self.memberlist.append(gm)

# 	def __unicode__(self):
# 		return self.name





# class GroupMember(models.Model):

# 	group = models.ForeignKey(Group,on_delete=models.CASCADE)
# 	name = models.CharField("member name",max_length=30)		

# 	"""  ForeignKey PrimaryKey """
# 	def __str__(self):
# 		return self.name
