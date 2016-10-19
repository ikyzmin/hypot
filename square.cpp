#include <iostream>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

int main() {
    cout<<"\nhello from pid = "<<getpid();
    return 0;
}