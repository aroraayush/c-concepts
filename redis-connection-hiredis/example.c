/* ------ This is a example program to connect redis with C client library (hiredis) ------ */

// Complete the setup before (the README in the current directory) to run the below program

#include <stdlib.h>

# include "hiredis/hiredis.h"


int main(int argc, char **argv) {
    
    const char *hostname = (argc > 1) ? argv[1] : "127.0.0.1";
    int port = (argc > 2) ? atoi(argv[2]) : 6379;
    unsigned isunix = 0;

    redisContext *c = redisConnect(hostname,port);
    
    struct timeval timeout = { 1, 500000 }; // 1.5 seconds
    if (isunix) {
        c = redisConnectUnixWithTimeout(hostname, timeout);
    } else {
        c = redisConnectWithTimeout(hostname, port, timeout);
    }
    if (c == NULL || c->err) {
        if (c) {
            printf("Connection error: %s\n", c->errstr);
            redisFree(c);
        } else {
            printf("Connection error: can't allocate redis context\n");
        }
        exit(1);
    }
    printf("Connected to redis\n");
    return 0;
}

