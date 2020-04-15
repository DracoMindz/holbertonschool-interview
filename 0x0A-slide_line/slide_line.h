#ifndef SLIDE_LINE_H
#define SLIDE_LINE_H

#define SLIDE_LEFT 0
#define SLIDE_RIGHT 1


int slide_line(int *line, size_t size, int direction);
int dirLeft(int *line, size_t size);
int comLeft(int *line, size_t size);
int dirRight(int *line, size_t size);
int comRight(int *line, size_t size);

#endif /* SLIDE_LINE_H */