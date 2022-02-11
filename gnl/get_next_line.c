#include <unistd.h>
#include "ft_libftstring.h"
#include "ft_libftmemory.h"
#include "ft_libftgnl.h"
#include "ft_libftprint.h"
#ifndef OPEN_MAX
# define OPEN_MAX 1000
#endif
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10000
#endif

static int read_into_buffer(int fd, char **buffer)
{
    /* read into the buffer and null terminate it */
    int read_ret = read(fd, *buffer, BUFFER_SIZE);
    if (read_ret == -1) { /* read failed */
        ft_dprintf(STDERR_FILENO, "read failed in get_next_line\n");
        free(*buffer);
        *buffer = NULL;
        exit(EXIT_FAILURE);
    }
    if (read_ret == 0) { /* immediate EOF */
        free(*buffer);
        *buffer = NULL;
        return (1);
    }
    /* EOF might have been reached, null terminate the buffer at the correct position */
    (*buffer)[read_ret] = '\0';
    return (0);
}

char *get_next_line(int fd)
{
    static char *buffers[OPEN_MAX] = { 0 };

    if (fd < 0 || fd >= OPEN_MAX)
        return (NULL);
    /* first time we use the specific buffer */
    if (buffers[fd] == NULL)
    {
        /*
        * +1 for the null terminating character
        * this also let's us track the end of the string
        */
        buffers[fd] = malloc(BUFFER_SIZE + 1);
        if (buffers[fd] == NULL)
        {
            ft_dprintf(STDERR_FILENO, "malloc failed in get_next_line\n");
            exit(EXIT_FAILURE);
        }
        if (read_into_buffer(fd, buffers + fd))
            return (NULL);
    }
    /* if we have nothing in the buffer then read into it, return NULL on immediate EOF */
    if (buffers[fd][0] == '\0' && read_into_buffer(fd, buffers + fd))
        return (NULL);
    /* check to see if we have a newline in the string */
    char *newline_index = ft_strchr(buffers[fd], '\n');
    if (newline_index == NULL) /* no newline in the string */
    {
        /* return the concatanation of the string and gnl()
        * handle the buffer first to prepare for the next call
        */
        char *tmp = ft_strdup(buffers[fd]);
        buffers[fd][0] = '\0';
        char *next_line = get_next_line(fd);
        return (ft_strjoin_free(tmp, next_line));
    }
    /* there is a newline in the string
    * rearrange buffer
    * then return the line up to the newline included
    */
    char *cur_line = ft_substr(buffers[fd], 0, newline_index - buffers[fd] + 1);
    ft_memmove(buffers[fd], newline_index + 1, BUFFER_SIZE - (newline_index - buffers[fd]));
    return (cur_line);
}
