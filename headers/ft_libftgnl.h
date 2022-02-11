#ifndef FT_LIBFTGNL_H
# define FT_LIBFTGNL_H

/*
* Allocates and returns a line that has been read from 'fd' file descriptor
* returns NULL if nothing was read
* calls 'exit' if 'read' fails
*/
char *get_next_line(int fd);

#endif /* FT_LIBFTGNL_H */
