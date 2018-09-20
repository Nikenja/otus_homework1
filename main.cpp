#include <iostream>
#include "versioner.h"

using namespace std;

int main() {
    cout << "Hello, World!" << endl;
    cout << "Version: " << Versioner::getVersion() << endl;
    return 0;
}
