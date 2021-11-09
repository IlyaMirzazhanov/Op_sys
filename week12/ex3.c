#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/input.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
//author Ilya Mirzazhanov
static const char *const evval[2] = {
    "RELEASED",
    "PRESSED "
};
// array for letters. Ther's 26 in alphabet.
int pressed[26] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const int PE[2] = { 2, 9 };
const int CAP[3] = { 21, 10, 9 };
const int REN[3] = { 3, 2, 24}; // R + E + N combination

void detect_comb(const int* combination, char* m, int L) {
	for (int i = 0; i < L; i++) if (!pressed[combination[i]]) return;
	printf("\n %s \n", m);
}

int main(void) {
    const char *dev = "/dev/input/by-path/platform-i8042-serio-0-event-kbd";
    struct input_event ev;
    int b1 = 16, b2 = 25, b3 = 30, b4 = 38, b5 = 20, b6 = 44, b7 = 50; // borders for letters code
    int fd = open(dev, O_RDONLY);


	if (fd == -1) {
	  printf("Error while opening file %s\n", dev);
	  return EXIT_FAILURE;
	}
	
	while (1) {
		read(fd, &ev, sizeof(ev));

	if (ev.type == EV_KEY && ev.value >= 0 && ev.value < 2) {
	if (b1 <= ev.code && ev.code <= b2) pressed[ev.code - b1] = ev.value;
	if (b3 <= ev.code && ev.code <= b4) pressed[ev.code - b5] = ev.value;
	if (b6 <= ev.code && ev.code <= b7) pressed[ev.code - b2] = ev.value;
	
	detect_comb(PE, "I passed the Exam!", 2);
	detect_comb(CAP,"Get some cappuccino!", 3);
	detect_comb(REN, "Hurray!", 3);
      }

    }
  
    return 0;
}
