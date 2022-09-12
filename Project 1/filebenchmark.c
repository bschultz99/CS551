#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <wait.h>
#include <sys/time.h>
#include <fcntl.h>
#include <sys/types.h>


#define MSG "* running filebenchmark with %s process(es)\n"

#define USAGE "usage: ./filebenchmark <num_procs> \n" \
"     - num_procs: 1 - 100 \n" \

int main(int argc, char **argv)
{
    int buffer_num = 5000;
    int n, toRead, process;
    int files[100];
    struct timeval start, end;
    pid_t pid, wpid;
    int status = 0;
    long micros;

    if (argc != 2) {
        printf(USAGE);
        exit(1);
    } else {
        printf(MSG, argv[1]);
    }

    char *buf = (char *)malloc(buffer_num);
    process = atoi(argv[1])
    files[0] = open("1.bin", O_RDWR);
    toread = write(files[0], buf, buffer_num);
    printf(toread);
    return 0;
}