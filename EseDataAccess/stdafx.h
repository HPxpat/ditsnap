#pragma once
#define WIN32_LEAN_AND_MEAN		
#include <stdio.h>
#include <tchar.h>
#include <vector>
#include <string>
#include <memory>
#include <sstream>
#include <iomanip>
#include "windows.h"
#include "esent.h"
#include "atlbase.h"


using std::vector;
using std::string;
using std::wstring;
using std::runtime_error;
using std::to_string;
using std::to_wstring;
using std::unique_ptr;

typedef unsigned int uint;

#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
TypeName(const TypeName&);                 \
void operator=(const TypeName&)
