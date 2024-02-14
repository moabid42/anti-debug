#pragma once

#include "../dietlibc.h"

ssize_t write_intermediate(const void *buf, int fd, size_t count)
{
    ssize_t ret;

    ret = __libc__write(fd, buf, count);
    if (ret == -1)
        return (-1);
    return (ret);
}


/* NONONONONONO
ssize_t __libc_write(int fd,const void*buf,size_t len);

ssize_t __libc_write_wrapper(int fd, const void* buffer, size_t len)
{
    // Add your code here :D
    __libc_write(fd, "hi\n", 3);
    return __libc_write(fd, buffer, len);
}
*/
