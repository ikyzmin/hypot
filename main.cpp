#include <iostream>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <bits/sigset.h>
#include <wait.h>
#include "signal.h"

using namespace std;

#define pid_id __pid_t

char *e[]={"",""};
int status;

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
            waitpid(pidId,&status,0);
            if ((status & 0xff) == 0) {
                read(f1,&a,sizeof(double));
                cout<<"a = "<<a<<"\n";
                close(f1);
            }

            pidId = fork();
            if (pidId){
                f1 = open("/tmp/fifo",O_RDWR);
                write(f1,&b,sizeof(double));
                waitpid(pidId,&status,0);
                if ((status & 0xff) == 0) {
                    read(f1,&b,sizeof(double));
                    close(f1);
                    cout<<"b = "<<b<<"\n";
                }
                pidId = fork();
                if (pidId){
                    f1 = open("/tmp/fifo",O_RDWR);
                    write(f1,&a,sizeof(double));
                    write(f1,&b,sizeof(double));
                    waitpid(pidId,&status,0);
                    if ((status & 0xff) == 0) {
                        read(f1,&c,sizeof(double));
                        close(f1);
                        cout<<"c = "<<c<<"\n";
                    }
                    pidId = fork();
                    if (pidId){
                        f1 = open("/tmp/fifo",O_RDWR);
                        write(f1,&c,sizeof(double));
                        waitpid(pidId,&status,0);
                        if ((status & 0xff) == 0) {
                            read(f1,&c,sizeof(double));
                            close(f1);
                            cout<<"c = "<<c<<"\n";
                        }
                    }else{
                        execv("./square", e);
                    }
                }else{
                    execv("./sum", e);
                }
            }else{
                execv("./power", e);
            }
        } else {
            execv("./power",e);
        }
    return 0;
}