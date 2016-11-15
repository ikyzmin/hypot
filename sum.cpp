#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include "signal.h"

using namespace std;
int main(){
    int q,f2;
    double a=0;
    double b=0;
   // f2 = open("/tmp/fifo",O_RDONLY);
   //read(f2,&a,sizeof(double));
   //read(f2,&b,sizeof(double));
   cout<<"read from fifo in sum = "<<q<<"\n";
    //close(f2);
    cout<<a<<" + "<<b<<" = "<<a+b;
    exit(0);
}

