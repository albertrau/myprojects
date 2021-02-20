#!/bin/bash
fmlkshk="/etc/nginx/sites-available/default"
on="autoindex on"
off="autoindex off"
if [ "$1" == "on" ]
then
    sed -i "s/$off/$on/g" "$fmlkshk"
else
    sed -i "s/$on/$off/g" "$fmlkshk"
fi
service nginx restart