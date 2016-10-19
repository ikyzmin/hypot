#include <iostream>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

#define pid_id __pid_t

char *e[]={"",""};

int main() {
    for (int i=0;i<10;i++) {
        pid_id pidId = fork();
        if (pidId) {
           // cout << "main";
        } else {
            execv("./square", e);
        }
    }
    return 0;
}