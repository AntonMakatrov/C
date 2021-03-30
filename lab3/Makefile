task: task.c
	gcc -ansi -pedantic -Wall -O3 -g task.c -o task
task_test: task_test.c task.c
	gcc -ansi -pedantic -Wall -O3 -g task_test.c task.c -o task_test -D TEST