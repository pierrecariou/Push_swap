#!/bin/bash

MAXCOUNT=400
NC='\033[0m'

one_test () {
	count=1

	while [ "$count" -le $MAXCOUNT ]; do
		number[$count]=$RANDOM
		let "count += 1"
	done
	echo "TEST : $MAXCOUNT digits"
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
	echo -n "op : " ; ./push_swap $nums | wc -l
	echo "------------------------"
}

while [ "$MAXCOUNT" -le 500 ]; do
	one_test
	let "MAXCOUNT += 1"
done
