#! /bin/bash


#Format of the date dd-mm-yyyy
date=$1 #the first argument passed
month=${date:3:2} #extract the month from the given date
year=${date:6:8}  #extract the year from the given date

function validateMonth  {
	#this function validade the month
	#if the month is between 1 to 12, it is valid, else, it is not. using 0 to denote truem and 1 to denote false
	for m in {1..12};
	do
		if [ $m -eq $month ]
		then
			return 0
		else
			return 1
		fi
	done
}
#invoke the function and pass month above defined as the argument. the value is stored in to $?
validateMonth $month


#if the length of the month is 10, then it must be a correct date
if [ ${#date} -eq 10 ] 
then
	#if the month is valid (0, for true) 
	if [ $? -eq 0 ]
	then
		cal -m $month $year
	else
		echo "Not a valid  month"
	fi
else
	echo "Not a valid date"
fi
