# -*- coding: utf-8 -*-
# Generated by Django 1.10 on 2016-01-26 07:11
from __future__ import unicode_literals

from django.db import migrations


class Migration(migrations.Migration):

    dependencies = [
        ('blog', '0003_group_groupmember'),
    ]

    operations = [
        migrations.RemoveField(
            model_name='groupmember',
            name='group',
        ),
        migrations.DeleteModel(
            name='Group',
        ),
        migrations.DeleteModel(
            name='GroupMember',
        ),
    ]
