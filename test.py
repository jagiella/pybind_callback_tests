#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Apr 26 22:54:18 2022

@author: nick
"""

from example import equal, cpp_callback1, cpp_callback2


def py_callback1():
    print('py_callback1 called')


def py_callback2():
    print('py_callback2 called')


print(equal(cpp_callback1, cpp_callback1))
print(equal(cpp_callback1, cpp_callback2))
print(equal(py_callback1, py_callback1))
print(equal(py_callback1, py_callback2))
