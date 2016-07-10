#include <stdio.h>
#include "arg.h"
#include "log.h"
#include "dep.h"
/*#include "generator.h"*/
#include "tmpasm_scconfig.h"

/* Runs when a custom command line argument is found
 returns true if no furhter argument processing should be done */
int hook_custom_arg(const char *key, const char *value)
{
	return 0;
}


/* Runs before anything else */
int hook_preinit()
{
	return 0;
}

/* Runs after initialization */
int hook_postinit()
{
	report("Scconfig self test.\n");
	logprintf(0, "Scconfig self test.\n");
	return 0;
}

/* Runs after all arguments are read and parsed */
int hook_postarg()
{
	return 0;
}

/* Runs when things should be detected for the host system */
int hook_detect_host()
{
	return 0;
}

/* Runs when things should be detected for the target system */
int hook_detect_target()
{
	/* if there was no custom requirement from the command line, run all requirements in non-fatal mode */
	if (num_custom_reqs < 1)
		require_all(0);
	return 0;
}

#ifdef GENCALL
/* If enabled, generator implements ###call *### and generator_callback is
   the callback function that will be executed upon ###call### */
void generator_callback(char *cmd, char *args)
{
	printf("* generator_callback: '%s' '%s'\n", cmd, args);
}
#endif

/* Runs after detection hooks, should generate the output (Makefiles, etc.) */
int hook_generate()
{
	printf("Generation (./Makefile.in -> ./Makefile): %d\n", tmpasm(NULL, "Makefile.in", "Makefile"));
	return 0;
}

/* Runs before everything is uninitialized */
void hook_preuninit()
{
}

/* Runs at the very end, when everything is already uninitialized */
void hook_postuninit()
{
}

