#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <stdlib.h>
#include <getopt.h>

#define HAVE_PWD_H
#ifdef HAVE_PWD_H
# include <pwd.h>
# include <grp.h>
#include <time.h>
#endif

#include "sttData.h"
#include "db_fonctions.h"
#include "../log.h"

/*Programme de lecture d'une ligne avec l'ID "r" dans la base de donnée test_sqlite.db, et mesure de performance de lecture*/
int main(int argc, char *argv[]) {

	dbg("Dossier : src/database - Fichier read_rows.c");



	struct passwd *user = NULL;
	struct group *grp = NULL;

	const char *dbpath = "test_sqlite.db";
	const char *username = NULL;

	int c ;

  char *cvalue = NULL;

	int fd;
	void *arg = NULL;

	int id_row_opt;

	db_connect(&arg, dbpath);

	db_init(arg);

	do
	{
		c = getopt(argc, argv, "r:");
		switch (c)
		{
			case 'r':
				id_row_opt = optarg;
			break;
	 }

 int index;
 for ( index = optind; index < argc; index++ )
	 printf ("Non-option argument %s\n", argv[index]);

	} while (c != -1);

	int count_insert = 0;
	int rcv = 0;

	struct timespec gettime_start;
	clock_gettime(CLOCK_REALTIME, &gettime_start);

	int id_row = atoi(id_row_opt);
	count_insert = db_one_row_read_test(arg, id_row);

	struct timespec gettime_after;
	clock_gettime(CLOCK_REALTIME, &gettime_after);
	if (gettime_after.tv_nsec > gettime_start.tv_nsec)
		printf("Read rows : Total time taken by CPU : %u.%u\n",
					gettime_after.tv_sec - gettime_start.tv_sec,
					gettime_after.tv_nsec - gettime_start.tv_nsec);
	else
		printf("Read rows : Total time taken by CPU : %u.%u\n",
					gettime_after.tv_sec - gettime_start.tv_sec + 1,
					gettime_start.tv_nsec - gettime_after.tv_nsec);

	db_disconnect(arg);
	return 0;
}
