compile: main.c 
	 gcc main.c -o sleep

run: sleep
	 ./sleep
   
clean: sleep
	 rm sleep