#include <stdlib.h>

#include "hiredis/hiredis.h"

int main(int argc, char **argv) {
    
    /* Connecting to redis */
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

    // redisFree(c);

    /* 2 - PING server */
    redisReply *reply;  /* Temporary reply pointer */
    reply = redisCommand(c,"PING");
    printf("PING: %s\n", reply->str);

    /* 3 - Set a key */
    reply = redisCommand(c,"SET %s %s", "foo", "hello world");
    printf("SET %s %s \t| %s\n", "foo", "hello world", reply->str);
    freeReplyObject(reply);     // Free a reply object

    /* 3 - Get a key */
    reply = redisCommand(c,"GET %s","foo");
    printf("GET %s \t\t| ","foo");
    printf("%s\n",reply->str);
    freeReplyObject(reply);

    /* Set a key using binary safe API */
    // reply = redisCommand(c,"SET %b %b", "bar", (size_t) 3, "hello", (size_t) 5);
    // printf("SET (binary API): %s\n", reply->str);
    // freeReplyObject(reply);
    redisFree(c);

    return 0;
}
