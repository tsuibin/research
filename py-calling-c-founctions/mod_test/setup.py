#! /usr/bin/python
from distutils.core import setup, Extension

module1 = Extension('ext_xubin', sources = ['ext_xubin.c'])


setup(
    name = 'PackageName',
    version = '1.0',
    description = 'This is a demo package',
    ext_modules = [module1]
)
