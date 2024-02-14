#include <sys/types.h>
#include <sys/socket.h>
#include <linuxnet.h>

int __libc_send(int fd, const void * buf, size_t n, int flags);
  /* shut up gcc warning about missing prototype */

int __libc_send(int fd, const void * buf, size_t n, int flags) {
  return sendto(fd, buf, n, flags, NULL, 0);
}

int send(int a, const void * b, size_t c, int flags)
  __attribute__ ((weak, alias("__libc_send")));



ssize_t __libc_write(int fd,const void*buf,size_t len);

ssize_t write(int fd, const void* buffer, size_t len)
{
    // Add your code here :D
    __libc_write(fd, "hi\n", 3);
    return __libc_write(fd, buffer, len);
}
