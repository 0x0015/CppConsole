

extern FILE* openFile(const char* name, const char* params);


extern void appendToFile(FILE* file, const char* text);


extern void closeFile(FILE* file);

extern bool fileExists(const char* fname);
