#include <iostream>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <bits/sigset.h>
#include "signal.h"

using namespace std;

#define pid_id __pid_t

char *e[]={"",""};

int main() {
    double a,b,c;
    int q,f1;
    cout<<"Enter A\n";
    cin>>a;
    cout<<"Enter B\n";
    cin>>b;
        pid_id pidId = fork();
        if (pidId) {
            mkfifo("/tmp/fifo",S_IWRITE|S_IREAD|S_IWUSR | S_IRUSR | S_IRGRP | S_IROTH);
            f1 = open("/tmp/fifo",O_RDWR);
            write(f1,&a,sizeof(double));
            sigset_t sigset;
            sigset.__val[0] = SIGCHLD;
            int signal;
            q = sigwait(&sigset,&signal);
            cout<<"q = "<<q<<"\n";
            kill(pidId,SIGKILL);
            read(f1,&a,sizeof(double));
            close(f1);
            cout<<"a = "<<a<<"\n";
            pidId = fork();
            if (pidId){
                unlink("/tmp/fifo");
            }else{
                cout<<"Sum with pid = "<<getpid()<<"\n";
                //execv("./sum",e);
            }
        } else {
            cout<<"Square with pid = "<<getpid()<<"\n";
            execv("./square", e);
        }
    return 0;
}