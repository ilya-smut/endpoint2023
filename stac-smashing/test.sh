#!/bin/bash

counter=25
while [ $counter -le 50 ]
do
	echo $counter
	./smash $(python3 -c "print('A'*$counter)")
	((counter++))
done

