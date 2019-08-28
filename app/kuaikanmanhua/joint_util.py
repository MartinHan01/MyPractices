#! /usr/bin/env python
# -*- coding: utf-8 -*-

from os import listdir
from PIL import Image
import os
import sys
from pathlib import Path

def merge_images(dir_name, file_name,save_dir):
    p = Path(save_dir)
    if p.exists() == False:
        p.mkdir()
    files = os.scandir(dir_name)
    result_width = 0
    result_height = 0
    images = []
    for i, file in enumerate(files):
        image = Image.open("%s%s.jpg" % (dir_name, i))
        images.append(image)
        result_width = image.width
        result_height += image.height
        #print("%s %s-%s" % (file.path , image.width, image.height))

    print("all size %s %s" % (result_width, result_height))
    result_img = Image.new(images[0].mode, (result_width, result_height)) 
    has_fill_height = 0
    for i, image in enumerate(images):    
        result_img.paste(image, box=(0, has_fill_height))
        has_fill_height += image.height
    result_img.save("%s/%s.png" % (save_dir, file_name))


