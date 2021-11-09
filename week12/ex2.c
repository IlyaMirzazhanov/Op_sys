#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/input.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
//author Ilya Mirzazhanov BS20-06
static const char *const evval[3] = {
    "RELEASED",
    "PRESSED ",
    "SPAMMED"
};

int main(void) {
    const char *dev = "/dev/input/by-path/platform-i8042-serio-0-event-kbd";
    struct input_event ev;
    int fd;

    fd = open(dev, O_RDONLY);
 	while (1) {
        read(fd, &ev, sizeof ev);

         if (ev.type == EV_KEY && ev.value >= 0 && ev.value <= 2) {
         	printf("%s 0x%04x (%d)\n", evval[ev.value], (int)ev.code, (int)ev.code);
         }

    }
    return 0;
}
