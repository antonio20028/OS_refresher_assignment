a1=assignment_01
a2=assignment_02
a3=assignment_03
make:
	gcc -o $(a1)/question_03 $(a1)/question_03.c
	gcc -o $(a1)/question_04 $(a1)/question_04.c
	gcc -o $(a1)/question_05 $(a1)/question_05.c
	gcc -o $(a2)/question_2a $(a2)/question_2a.c
	gcc -o $(a2)/question_3 $(a2)/question_3.c -lm
	gcc -o $(a2)/question_5 $(a2)/question_5.c
	gcc -o $(a3)/question_03a $(a3)/question_03a.c
	gcc -o $(a3)/question_4 $(a3)/question_4.c
req:
	sudo apt update
	sudo apt-get install jq -y
permission:
	chmod +x $(a1)/question_03.c
	chmod +x $(a1)/question_04.c
	chmod +x $(a1)/question_05.c
	chmod +x $(a2)/question_2a.c
	chmod +x $(a2)/question_3.c
	chmod +x $(a2)/question_5.c
	chmod +x $(a3)/question_03a.c
	chmod +x $(a3)/question_4.c
	chmod +x $(a3)/question_01.sh
	chmod +x $(a3)/question_02.sh
