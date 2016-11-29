#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include "signal.h"

using namespace std;
int main(){
    int q,f2;
    double a=0;
    double b=0;
    f2 = open("/tmp/fifo",O_RDWR);
   read(f2,&a,sizeof(double));
   read(f2,&b,sizeof(double));
   cout<<a<<"+"<<b<<"\n";
    double c = a+b;
    write(f2,&c,sizeof(double));
    close(f2);
    exit(0);
}

