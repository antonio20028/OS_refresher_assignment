#! /bin/bash

args=$@
#all the aruments passed are stored in args


#function to divide. NOTE: use sudp apt install jq before
function div {
	#if the second number is not equal to 0, divide
	if [[ $num_2 -ne 0 ]]
	then
		#divide using jq library
		echo $num_1/$num_2 | jq -nf /dev/stdin		
	else
		echo "Error! Can't divide by 0"
	fi
}

#function to mult
function mul {
	local res=1
	for n in $args;
	do
		if (( $n != "mul" ))
		then
		(( res = res * n))
		fi  
	done

	echo $res	
}

function add {
	local res=0
	
	for n in $args;
	do
		((res = res + n))
	done
	echo $res
	
}

function sub {

	array=($args)
	aux=${array[1]}
	tmp=0
	res=${array[1]}
	
	for n in $args;
	do
		(( res -= n ))
	done
	
	(( tmp = res + aux ))
	
	echo $tmp	
}

function exp {
	local res=0
	
	((res = num_1**num_2 ))
	
	
	echo $res	
}

op=$1
case "$op" in
	"add" )
		if [[ $(( $# - 1 )) -ge 2 ]]
		then
			add
		else
			echo "This operation requires at least two operands, but " $(( $# - 1 )) " was given"
		fi ;;
	"mul" )
		if [[ $(( $# - 1 )) -ge 2 ]]
		then
			mul
			echo $?
		else
			echo "This operation requires at least two operands, but " $(( $# - 1 )) " was given"
		fi ;;
	"div" )
		num_1=$2
		num_2=$3
		
		if [[ $(( $# - 1 )) -eq 2 ]]
		then
			div $num_2 $num_1
		else
			echo "This operation requires operands only, but " $(( $# - 1 )) " was given"
		fi ;;
	"exp" )
		num_1=$2
		num_2=$3
		
		if [[ $(( $# - 1 )) -eq 2 ]]
		then
			exp $num_2 $num_1
		else
			echo "This operation requires at least two operands, but " $(( $# - 1 )) " was given"
	fi ;;
	"sub")
		sub 
		;;
		
	*)
		echo "No operator found or incorrect operator" ;;
esac
