#include <iostream>
#include <unistd.h>
#include <math.h>
#include <fcntl.h>
#include "signal.h"

using namespace std;

int main() {
    int q,f2;
    double a=0;
    f2 = open("/tmp/fifo",O_RDWR);
    read(f2,&a,sizeof(double));
    cout<<a<<"^2"<<"\n";
    a=pow(a,2);
    write(f2,&a,sizeof(double));
    close(f2);
    exit(0);
}