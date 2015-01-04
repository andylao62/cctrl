#!/bin/sh

pkill -9 crawler
pkill -9 crawler-filter
pkill -9 search
pkill -9 client
#pkill -9 logsvr

sleep 1

# 删除共享内存
list=`ipcs -m | grep -v 'dest' | awk '{ if ($6 == 0) { print $2 }}'`
for shm in $list
do
    ipcrm -m $shm
done

# 显示共享内存
ipcs -m | grep -v 'dest' | awk '{ print $0 }'

redis-cli FLUSHALL