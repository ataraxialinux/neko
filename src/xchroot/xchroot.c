#define _GNU_SOURCE
#include <sys/types.h>
#include <sys/utsname.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <err.h>
#include <errno.h>
#include <paths.h>
#include <sched.h>
#include <bsd.h>

#define STACK_SIZE (1024 * 1024)

void usage(void) {
	fprintf(stderr, "usage: xchroot newroot [command]\n");
	exit(1);
}

static int child_chroot(char *arg[]) {
	struct utsname uts;
	char *shell;
	char randname[15] = "chroot-";
    	for(int i = 0; i < 8; i++){
      		char randomchar = 'a' + arc4random_uniform(26);
      		randname[7+i] = randomchar;
    	}
	char *hostname = (char*) randname;

	sethostname(hostname, strlen(hostname));

	if (chdir(arg[0]) || chroot(".")) {
		err(1, "%s", arg[0]);
	}

	if (arg[1]) {
		execvp(arg[1], &arg[1]);
		err(1, "%s", arg[1]);
	}

	if (!(shell = getenv("SHELL")))
		shell = _PATH_BSHELL;
	execlp(shell, shell, "-i", NULL);
	err(1, "%s", shell);

	return 0;
}

int main(int argc, char *argv[]) {
	int ch;
	int nonet = 0;
	int container = (SIGCHLD|CLONE_NEWPID|CLONE_NEWIPC|CLONE_NEWNS|CLONE_NEWUTS);
	char *stack;
	char *stacktop;
	pid_t pid;

	while ((ch = getopt(argc, argv, "n")) != EOF) {
		switch(ch) {
			case 'n':
				nonet = 1;
				break;
			case '?':
			default:
				usage();
		}
	}

	argc -= optind;
	argv += optind;

	if (argc < 1) {
		usage();
	}

	if(geteuid() != 0) {
		(void)fprintf(stderr, "You're not root user\n");
		exit(1);
	}

	if (nonet >= 1) {
		container |= CLONE_NEWNET;
	}

	stack = malloc(STACK_SIZE);
	if (stack == NULL) {
		(void)fprintf(stderr, "malloc");
	}
	stacktop = stack + STACK_SIZE;

	pid = clone(child_chroot, stacktop, container, argv);

	waitpid(pid, NULL, 0);

	free(stack);

	return 0;
}
