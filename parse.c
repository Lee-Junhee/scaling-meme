#include<string.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

char ** parse_args(char *line) {
	char **args = calloc(sizeof(char*), 6);
	int i;
	for(i=0;i<6;i++){
		args[i] = strsep(&line, " ");
		if (!args[i]) {
			break;
		}
	}
	return args;
}

int main() {
	char line[100] = "ls -a -l";
	char **args = parse_args(line);
	execvp(args[0], args);
}

