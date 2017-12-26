
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include </usr/include/mysql/mysql.h>
#include <stdarg.h>
#include <errno.h>


#define QUERY_SIZE 256

#define BUFFER_SIZE 80

/* Funkcija error_fatal() ispisuje poruku o gresci i potom prekida program. */
static void error_fatal (char *format, ...);

int
main (int argc, char **argv)
{

  MYSQL *konekcija;	/* Promenljiva za konekciju. */
  MYSQL_RES *rezultat;	/* Promenljiva za rezultat. */
  MYSQL_ROW red;	/* Promenljiva za jedan red rezultata. */
 	

  char query[QUERY_SIZE];	/* Promenljiva za formuaciju upita. */
 

  /* Incijalizuje se promenljiva koja ce predstavljati konekciju. */
  konekcija = mysql_init (NULL);
  
  /* Pokusava se sa konektovanjem na bazu. */
  if (mysql_real_connect
      (konekcija, "localhost", "root", "sevojno", "prodaja_polovnih_stvari_preko_interneta", 0, NULL,
       0) == NULL)
      error_fatal ("Greska u konekciji. %s\n", mysql_error (konekcija));

  printf("PRVI UPIT\n");
  /* Ispisati id,naziv i cenu stvari koje su prodate kupcu a kostale su vise od 2000 dinara */
  sprintf (query, "select id,naziv,stvar.cena from stvar join prodata on id=izlozena_stvar_id where stvar.cena >2000");

  /* Pokusava se sa izvrsavanjem upita. */
  if (mysql_query (konekcija, query) != 0)
    error_fatal ("Greska u upitu %s\n", mysql_error (konekcija));

  /* Preuzima se rezultat. */
  rezultat = mysql_use_result (konekcija);

  
  /* Ispisuju se vrednosti. */
  while ((red = mysql_fetch_row (rezultat)) != 0)
    printf ("%s %s %s\n", red[0],red[1],red[2]);
  printf ("\n");

  /* Oslobadja se trenutni rezultat, posto nam vise ne treba. */
  mysql_free_result (rezultat);

  printf("------------------------------------------------------------------------\n");

  printf("Pritiskom na enter izvrsi drugi upit. \n");

  char c;

  while((c=getchar())!='\n');

  
  printf("DRUGI UPIT \n");

  printf("STANJE PRE DRUGOG UPITA\n" );
  
      sprintf (query, "select * from stvar");

  /* Pokusava se sa izvrsavanjem upita. */
  if (mysql_query (konekcija, query) != 0)
    error_fatal ("Greska u upitu %s\n", mysql_error (konekcija));

  /* Preuzima se rezultat. */
  rezultat = mysql_use_result (konekcija);

  
  /* Ispisuju se vrednosti. */
  while ((red = mysql_fetch_row (rezultat)) != 0)
    printf ("%s %s %s %s %s %s\n", red[0],red[1],red[2],red[3],red[4],red[5]);
  printf ("\n");

  /* Oslobadja se trenutni rezultat, posto nam vise ne treba. */
  mysql_free_result (rezultat);


  sprintf (query, "delete from stvar where id=2");

    /* Pokusava se sa izvrsavanjem upita. */
  if (mysql_query (konekcija, query) != 0)
    error_fatal ("Greska u upitu %s\n", mysql_error (konekcija));
  
  printf("STANJE POSLE DRUGOG UPITA \n");

  sprintf (query, "select * from stvar");

  /* Pokusava se sa izvrsavanjem upita. */
  if (mysql_query (konekcija, query) != 0)
    error_fatal ("Greska u upitu %s\n", mysql_error (konekcija));

  /* Preuzima se rezultat. */
  rezultat = mysql_use_result (konekcija);

  
  /* Ispisuju se vrednosti. */
  while ((red = mysql_fetch_row (rezultat)) != 0)
    printf ("%s %s %s %s %s %s\n", red[0],red[1],red[2],red[3],red[4],red[5]);
  printf ("\n");

  /* Oslobadja se trenutni rezultat, posto nam vise ne treba. */
  mysql_free_result (rezultat);

  printf("-------------------------------------------\n" );

  printf("Pritiskom na enter izvrsi treci upit. \n");

    while((c=getchar())!='\n');
  
  printf("TRECI UPIT \n");

  printf("STANJE PRE TRECEG UPITA\n" );
  
      sprintf (query, "select * from dobavljac");

  /* Pokusava se sa izvrsavanjem upita. */
  if (mysql_query (konekcija, query) != 0)
    error_fatal ("Greska u upitu %s\n", mysql_error (konekcija));

  /* Preuzima se rezultat. */
  rezultat = mysql_use_result (konekcija);

  
  /* Ispisuju se vrednosti. */
  while ((red = mysql_fetch_row (rezultat)) != 0)
    printf ("%s %s %s \n", red[0],red[1],red[2]);
  printf ("\n");

  /* Oslobadja se trenutni rezultat, posto nam vise ne treba. */
  mysql_free_result (rezultat);


  sprintf (query, "insert into dobavljac values(15,'Marko','Milic','BrzaPosta')");

    /* Pokusava se sa izvrsavanjem upita. */
  if (mysql_query (konekcija, query) != 0)
    error_fatal ("Greska u upitu %s\n", mysql_error (konekcija));
  
  printf("STANJE POSLE TRECEG UPITA \n");

  sprintf (query, "select * from dobavljac");

  /* Pokusava se sa izvrsavanjem upita. */
  if (mysql_query (konekcija, query) != 0)
    error_fatal ("Greska u upitu %s\n", mysql_error (konekcija));

  /* Preuzima se rezultat. */
  rezultat = mysql_use_result (konekcija);

  
  /* Ispisuju se vrednosti. */
  while ((red = mysql_fetch_row (rezultat)) != 0)
    printf ("%s %s %s \n", red[0],red[1],red[2]);
  printf ("\n");

  /* Oslobadja se trenutni rezultat, posto nam vise ne treba. */
  mysql_free_result (rezultat);

  printf("-------------------------------------------\n" );
  printf("CETVRTI UPIT\n");

       sprintf (query, "insert into stvar values(13,'novcanik',6,5000,'5.1.2017',1)");

  /* Pokusava se sa izvrsavanjem upita. */
  if (mysql_query (konekcija, query) != 0)
    error_fatal("%s\n", mysql_error (konekcija));
  
  /* Preuzima se rezultat. */
  rezultat = mysql_use_result (konekcija);

  
  /* Ispisuju se vrednosti. */
  while ((red = mysql_fetch_row (rezultat)) != 0)
    printf ("%s \n", red[0]);
  printf ("\n");

  /* Oslobadja se trenutni rezultat, posto nam vise ne treba. */
  mysql_free_result (rezultat);

  
  
  
  /* Zatvara se konekcija. */
  mysql_close (konekcija);

  /* Zavrsava se program */
  exit(EXIT_SUCCESS);
}

static void
error_fatal (char *format, ...)
{
  va_list arguments;		/* Lista argumenata funkcije. */

  /* Stampa se string predstavljen argumentima funkcije. */
  va_start (arguments, format);
  vfprintf (stderr, format, arguments);
  va_end (arguments);

  /* Prekida se program. */
  exit (EXIT_FAILURE);
}
