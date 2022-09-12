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
    process = atoi(argv[1]);
    gettimeofday(&start, NULL);
    for (int i = 0; i < process; i++) {
        files[i] = open(i +".bin", O_RDWR);
        if((pid = fork()) == 0){
            write(files[i], buf, buffer_num);
            exit(0);
        }
    }
    while((wpid = wait(&status)) > 0);
    gettimeofday(&end, NULL);
     micros = ((end.tv_sec - start.tv_sec) * 1000000);
     printf("%li", micros);
    //printf("%i", toRead);
    return 0;

}