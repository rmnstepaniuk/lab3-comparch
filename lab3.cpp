#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>

/*
Lab 3
IV-91
Stepaniuk Roman
*/

int main(int argc, char* argv[]) {

	const char* short_options = "hvs::f:";

	const struct option long_options[] = {
		{"help",no_argument,NULL,'h'},
		{"version",no_argument,NULL,'v'},
		{"size",optional_argument,NULL,'s'},
		{"file",required_argument,NULL,'f'},
		{NULL,0,NULL,0}
	};

	int rez;
	int check_h = 1;
	int check_v = 1;
	int check_s = 1;
	int check_f = 1;
	int option_index;

	opterr = 0;
	while ((rez = getopt_long(argc, argv, short_options,
		long_options, &option_index)) != -1) {

		switch (rez) {
		case 'h': {
			if (check_h > 0) {
				printf("Usage:\n\trun <command> [options]\n\nCommands:\n\tversion\t\t\tShow version.\n\n\thelp\t\t\tShow help for commands.\n");
			}
			check_h--;
			break;
		};
		case 'v': {
			if (check_v > 0) {
				printf("run 1.0.1");
			}
			check_v--;
			break;
		};
		case '?': default: {
			printf("Usage:\n\trun <command> [options]\n\nno such option");
			break;
		};
		};
	};
	return 0;
};