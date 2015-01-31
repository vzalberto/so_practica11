#include <stdio.h>
#include <signal.h>

void tratar_alarma(int signum){
    printf("Alarma activada\n");
    printf("Numero de señal: %d\n", signum);
}

int main(void){
    struct sigaction act;
    sigset_t mask;

    act.sa_handler = tratar_alarma;
    act.sa_flags = 0;

    sigemptyset(&mask);
    sigprocmask(SIG_SETMASK, &mask, NULL);
    sigaction(SIGALRM, &act, NULL);

    if(sigismember(&mask, SIGQUIT))
        sigdelset(&mask, SIGQUIT);

    for(;;){
        //ualarm(500000, 0);
        alarm(3);
        pause();
    }
}
