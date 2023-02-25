#!/usr/bin/bash

rm -rf /d/share/embnao/teachernote/teachernote.tar.gz

tar -zcvf teachernote.tar.gz /d/share/embnao/teachernote/

git add /d/share/embnao/teachernote.tar.gz

git commit -m "autoup"

git push -f origin master
