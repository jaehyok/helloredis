//
//  helloRedis.cpp
//  helloRedis
//
//  Created by jaehyok on 7/13/16.
//  Copyright © 2016 jaehyok. All rights reserved.
//

#include "helloRedis.hpp"

helloRedis::helloRedis()
{
	
}

helloRedis::~helloRedis()
{
	
}

string helloRedis::getUUID()
{
	uuid_t id;
	char uuid_s[37] = {0,};
	uuid_generate_time(id);
	uuid_unparse(id, uuid_s);
	
	string uuid = uuid_s;
	return uuid;
}
