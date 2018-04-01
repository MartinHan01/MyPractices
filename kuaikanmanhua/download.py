#! /usr/bin/env python
# -*- coding: utf-8 -*-

import sys
from urllib import request
import json
import file_util
import joint_util

def loop_save_comic(comic_id):
    if comic_id == None:
        return 
    comic_url = "https://api.kkmh.com/v2/comic/%s?is_preview=1"
    first_comic_url = comic_url % comic_id
    print(first_comic_url)

    with request.urlopen(first_comic_url) as f:
        data = f.read()
        #print("response:%s" % data)
        reponse_data = json.loads(data)
        if reponse_data['code'] != 200:
            print("request error code %s" % reponse_data['code'])
            exit()
        
        json_data = reponse_data['data']
        title = json_data['title']
        images = json_data['images']
        print('saving %s' % title)

        root_dir = json_data['topic']['title']
        file_util.save_files(root_dir,title, images)
        print('merging images')

        joint_util.merge_images("./%s/%s/" % (root_dir, title),title,"%s-result" % root_dir)

        next_comic_id = json_data['next_comic_id']
        loop_save_comic(next_comic_id)

if __name__ == '__main__':
    comic_id = sys.argv[1]
    loop_save_comic(comic_id)

    

        
