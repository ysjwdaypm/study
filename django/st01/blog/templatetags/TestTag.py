

from django import template

register = template.Library()


class TestTagItem(template.Node):

	def __init__(self,nav_path,nav_displaytext):
		self.path = nav_path
		self.displaytext = nav_displaytext


	def render(self,context):
		# cur_path = context["request"].path
		print "context : %s"%context
		print "-------------"

		cur_path = ''
		current = False

		if self.path == "/":
			current = cur_path == "/"
		else:
			current = cur_path.startswith(self.path)


		cur_id = ""

		if current:
			cur_id = 'id="current"'		

		return '<li><a %s href="%s">%s</a></li>'%(cur_id,self.path,self.displaytext)
		


# @register.tag(name="TestTag")
def tagitem(parser,token):
	try:
		tag_name,nav_path,nav_text = token.split_contents()

	except ValueError as e:
		raise e				

	return TestTagItem(nav_path,nav_text)	

register.tag("TestTag",tagitem)		