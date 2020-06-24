#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <stdlib.h>

void rek_mkdir(char *path) {
	char *sep = strrchr(path, '/');
	if(sep != NULL) {
		*sep = 0;
		rek_mkdir(path);
		*sep = '/';
	}
	if(mkdir(path, 0777) && errno != EEXIST)
		printf("error while trying to create '%s'\n%m\n", path);
}

FILE *fopen_mkdir(char *path, char *mode) {
	char *sep = strrchr(path, '/');
	if(sep) {
		char *path0 = strdup(path);
		path0[ sep - path ] = 0;
		rek_mkdir(path0);
		free(path0);
	}
	return fopen(path,mode);
}


FILE* openFile(const char* name, const char* params) {
	//printf("opening file name %s\n", name);
	char n[100];
	char p[100];
	//printf("filename, %s paramaters %s", name,params);
	strcpy(n, name);
	strcpy(p, params);
	//printf("filename, %s paramaters %s", n,p);
	return(fopen_mkdir(n, p));
}

void appendToFile(FILE* file, const char* text) {
	//printf("appending %s to file\n", text);
	fprintf(file, "%s", text);
}

void closeFile(FILE* file) {
	//printf("closing file\n");
	fclose(file);
}

bool fileExists(const char* fname){
	if( access( fname, F_OK ) != -1 ) {
    return(true);
} else {
    return(false);
}
}