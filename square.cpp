#include <iostream>
#include <unistd.h>
#include <math.h>
#include <fcntl.h>
#include "signal.h"

using namespace std;

int main() {
    int q,f2;
    double a=0;
    //kill(0,SIGCHLD);
    f2 = open("/tmp/fifo",O_RDWR);
    read(f2,&a,sizeof(double));
    cout<<"square("<<a<<")"<<"\n";
    a=sqrt(a);
    write(f2,&a,sizeof(double));
    close(f2);
    exit(0);
}