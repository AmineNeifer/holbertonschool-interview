#ifndef __SLIDE_LINE_H__
#define __SLIDE_LINE_H__

#define SLIDE_LEFT -1
#define SLIDE_RIGHT 1
#include <stdlib.h>

int slide_line(int *line, size_t size, int direction);
void slide_all(int *line, size_t size, int direction);
void treat_line(int *line, size_t size, int direction);

#endif /* __SLIDE_LINE_H__ */
