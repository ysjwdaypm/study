# -*- coding: utf-8 -*-
# Generated by Django 1.11 on 2016-07-04 03:16
from __future__ import unicode_literals

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('blog', '0004_auto_20160126_0711'),
    ]

    operations = [
        migrations.CreateModel(
            name='BagItem',
            fields=[
                ('id', models.AutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('item_id', models.IntegerField()),
            ],
            options={
                'indexes': [],
            },
        ),
    ]
