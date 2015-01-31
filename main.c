#include <stdio.h>
#include <signal.h>

void tratar_alarma(int signum){
    printf("Alarma activada\n");
    printf("Numero de señal: %d\n", signum);
}

void tratar_SIGTSTP(int signum){
    printf("La señal %d me ha intentado detener. Ilusa.\n", signum);
}

void cant_touch_this(int signum){
    printf("Don't. Stop. Me. Now. Cause I'm having a good time.\n");
}

int main(void){
    struct sigaction act, act2, act3;
    sigset_t mask;

    act.sa_handler = tratar_alarma;
    act.sa_flags = 0;

    act2.sa_handler = tratar_SIGTSTP;
    act2.sa_flags = 0;

    act3.sa_handler = cant_touch_this;
    act3.sa_flags = 0;

    printf("PID: %d\n", getpid());

    sigemptyset(&mask);

    sigprocmask(SIG_SETMASK, &mask, NULL);

    sigaction(SIGALRM, &act, NULL);
    sigaction(18, &act2, NULL);

    for(;;){
        alarm(3);
        pause();
    }
}
