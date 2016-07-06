#!/usr/bin/env python
import os
import sys

if __name__ == "__main__":
    os.system('python manage.py makemigrations && python manage.py migrate')
