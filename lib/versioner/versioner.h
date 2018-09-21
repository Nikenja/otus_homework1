#pragma once

#include <string>
#include "version.h"

using namespace std;

class Versioner {
public:
    static string getVersion();
    static string getRevision();
};
