#include<string.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

char ** parse_args(char *line) {
	char **args = calloc(sizeof(char*), 6);
	char placeholder[3] = "hi";
	args[0] = placeholder;
	int i = 0;
	while (*(args + i)) {
		args[i++] = strsep(&line, " ");
	}
	return args;
}

int main() {
	char line[100] = "ls -a -l";
	char **args = parse_args(line);
	execvp(args[0], args);
}

