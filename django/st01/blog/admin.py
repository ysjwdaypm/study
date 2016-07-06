from django.contrib import admin

# Register your models here.

from models import Person

class PersonAdmin(admin.ModelAdmin):
	list_display = ['age','name','password']

admin.site.register(Person,PersonAdmin)
# admin.site.register(Person)
