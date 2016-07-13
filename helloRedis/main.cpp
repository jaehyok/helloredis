//
//  main.cpp
//  helloRedis
//
//  Created by jaehyok on 2016. 7. 12..
//  Copyright © 2016년 jaehyok. All rights reserved.
//

#include <iostream>
#include "hiredis.h"

using namespace std;


int main(int argc, const char * argv[]) {
	// insert code here...
	cout << "Hello, World!\n";
	
	redisContext *c = NULL;
	redisReply *reply = NULL;
	struct timeval timeout = { 1, 500000 }; // 1.5 seconds
	c = redisConnectWithTimeout("127.0.0.1", 6379, timeout);
	if (c == NULL || c->err) {
		if (c) {
			printf("Connection error: %s\n", c->errstr);
			redisFree(c);
		} else {
			printf("Connection error: can't allocate redis context\n");
		}
		exit(1);
	}
	
	/* PING server */
	reply = (redisReply *)redisCommand(c,"PING");
	printf("PING: %s\n", reply->str);
	freeReplyObject(reply);
	
	
	
	/* Disconnects and frees the context */
	redisFree(c);
	
	return 0;
}
