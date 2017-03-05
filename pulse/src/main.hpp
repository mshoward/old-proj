#pragma once
#define PULSE_DEBUG
#include "includes.hpp"

void pmsg(std::string str);

//class declarations
#include "defs.hpp"

//class headers
#ifdef PULSE_DEBUG
#include "client/test.hpp"
#endif

#include "structures/structures.hpp"
#include "config/config.hpp"
#include "sock_int/sock_int.hpp"
#include "MYSQL_Int/MYSQL_Int.hpp"
#include "dataBucket/dataBucket.hpp"
#include "scheduler/scheduler.hpp"
#include "control/control.hpp"




//class definitions
#ifdef PULSE_DEBUG
//#include "client/test.cpp"

#endif

#include "structures/structures.cpp"
#include "config/config.cpp"
#include "control/control.cpp"
#include "dataBucket/dataBucket.cpp"
#include "MYSQL_Int/MYSQL_Int.cpp"
#include "scheduler/scheduler.cpp"
#include "sock_int/sock_int.cpp"
