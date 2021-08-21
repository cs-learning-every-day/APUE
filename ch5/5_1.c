#include "apue.h"


void    mysetbuf(FILE *restrict fpt, char *restrict buf);
void	pr_stdio(const char *, FILE *);
int		is_unbuffered(FILE *);
int		is_linebuffered(FILE *);
int		buffer_size(FILE *);


int main() {
    pr_stdio("stdin", stdin);
    
    mysetbuf(stdin, NULL);
    pr_stdio("stdin", stdin);

    char buf[10];
    mysetbuf(stdin, buf);
    pr_stdio("stdin", stdin);
    return 0;
}

void mysetbuf(FILE *restrict fpt, char *restrict buf) {
    int res = -1;

    if (buf == NULL) {
        res = setvbuf(fpt, NULL, _IONBF, 0);   
    } else {
        res = setvbuf(fpt, buf, _IOFBF, BUFSIZ);
    }

    if (res != 0) {
        perror("setvbuf error\n");
    }
}

void
pr_stdio(const char *name, FILE *fp)
{
	printf("stream = %s, ", name);
	if (is_unbuffered(fp))
		printf("unbuffered");
	else if (is_linebuffered(fp))
		printf("line buffered");
	else /* if neither of above */
		printf("fully buffered");
	printf(", buffer size = %d\n", buffer_size(fp));
}

// 不可移植代码

int
is_unbuffered(FILE *fp)
{
	return(fp->_flags & _IO_UNBUFFERED);
}

int
is_linebuffered(FILE *fp)
{
	return(fp->_flags & _IO_LINE_BUF);
}

int
buffer_size(FILE *fp)
{
	return(fp->_IO_buf_end - fp->_IO_buf_base);
}