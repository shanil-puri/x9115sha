#!/bin/bash


i=5
c=$(($i%5))
if [ "$c" -eq "0" ];
	then 
		echo "true"
fi
