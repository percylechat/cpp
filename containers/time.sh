#!/bin/bash
now="$(date +%s%3N)"
echo "IN MILLISEC"
echo "now :"
echo $now
./container stack
after="$(date +%s%3N)"
echo "after:"
echo $after
echo "operation time"
echo $(expr $after - $now)

now="$(date +%s%3N)"
echo "IN MILLISEC"
echo "now :"
echo $now
./container_std stack
after="$(date +%s%3N)"
echo "after:"
echo $after
echo "operation time"
echo $(expr $after - $now)