#ifndef UTIL_H
#define UTIL_H

#include "Types.h"
#include <zlib.h>

// save game
typedef struct {
  void *address;
  int size;
} variable_desc;

bool utilIsGBAImage(const char *);
bool utilLoad(const char *, bool (*)(const char*), u8 *, int &);

void utilPutDword(u8 *, u32);
void utilPutWord(u8 *, u16);
void utilWriteData(gzFile, variable_desc *);
void utilReadData(gzFile, variable_desc *);
int utilReadInt(gzFile);
void utilWriteInt(gzFile, int);
gzFile utilGzOpen(const char *file, const char *mode);
int utilGzWrite(gzFile file, const voidp buffer, unsigned int len);
int utilGzRead(gzFile file, voidp buffer, unsigned int len);
int utilGzClose(gzFile file);
z_off_t utilGzSeek(gzFile file, z_off_t offset, int whence);

#endif // UTIL_H
