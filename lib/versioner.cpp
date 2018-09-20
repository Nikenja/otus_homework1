#include "versioner.h"

string Versioner::getVersion() {
    return PROJECT_VERSION_MAJOR + "." + PROJECT_VERSION_MINOR + "." + PROJECT_VERSION_PATCH;
}
