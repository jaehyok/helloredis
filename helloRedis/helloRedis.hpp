//
//  helloRedis.hpp
//  helloRedis
//
//  Created by jaehyok on 7/13/16.
//  Copyright © 2016 jaehyok. All rights reserved.
//

#ifndef helloRedis_hpp
#define helloRedis_hpp

#include <string>
#include <map>

#include "hiredis.h"
#include "uuid/uuid.h"

using namespace std;

class helloRedis
{
public:
	helloRedis();
	~helloRedis();
	
	int push(map<string,string> value);
	map<string,string> pop(string &uuid);
	int del(string uuid);
	int size();

private:
	string getUUID();
	
	int setHash(string uuid, map<string,string> value);
	int enList(string uuid);
	
	string deList(); //return: uuid
	map<string,string> getHash(string uuid);
	int delList(string uuid);
	int delHash(string uuid);

};

#endif /* helloRedis_hpp */
