#!/bin/bash

MAXCOUNT=10
NC='\033[0m'

one_test () {
	count=1

	while [ "$count" -le $MAXCOUNT ]; do
		number[$count]=$RANDOM
		let "count += 1"
	done
	echo "TEST : $MAXCOUNT"
	echo "------------------------"
	nums=$( printf '%s ' "${number[@]}" )

	./push_swap $nums | ./checker $nums | grep OK
	./push_swap $nums | ./checker $nums | grep Error
	./push_swap $nums | ./checker $nums | grep KO
	if [ "$?" -eq 0 ]
	then
		exit $?
	fi
	echo -ne "${NC}"
	echo -n "operations n: " ; ./push_swap $nums | wc -l
	echo "------------------------"
}

while [ "$MAXCOUNT" -le 100 ]; do
	one_test
	let "MAXCOUNT += 1"
done
