#! /usr/bin/env python
# -*- coding: utf-8 -*-

import os
from pathlib import Path
import urllib


def save_files(root_dir, dir_name, file_name_array):
    root_dir = Path('./%s' % root_dir)
    if root_dir.exists() == False:
        root_dir.mkdir()
    os.chdir('./%s' % root_dir)
    q = Path('./%s' % dir_name)
    if q.exists():
        del_dir_tree(q.name) 
    q.mkdir()
    os.chdir('./%s' % dir_name)
    i = 0
    for pic_url in file_name_array:
        urllib.request.urlretrieve(pic_url, "%s.jpg" % i)
        i = i + 1
    
    os.chdir('../../')

def del_dir_tree(path):
    ''' 递归删除目录及其子目录,　子文件'''
    if os.path.isfile(path):
        try:
            os.remove(path)
        except Exception as e:
            print(e)
    elif os.path.isdir(path):
        for item in os.listdir(path):
            itempath = os.path.join(path, item)
            del_dir_tree(itempath)
        try:
            os.rmdir(path)  
        except Exception as e:
            print(e)