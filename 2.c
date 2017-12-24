#include <stdio.h>
#include <stdlib.h>
#include <mysql.h>
#define MAX_QUERY_LEN 1000
#define MAX_STRING_ATT_LEN 45

void error(char* s);
MYSQL_RES* executeQuery(MYSQL*,char*);


int main(){
  MYSQL* konekcija;
  MYSQL_ROW red;
  MYSQL_RES* rezultat;
  konekcija = mysql_init(NULL);
  if (mysql_real_connect(konekcija, "localhost", "root", "sevojno", "prodaja_polovnih_stvari_preko_interneta", 0, NULL, 0) == NULL)
    error("mysql_real_connect failed");
  printf("Unesite zeljenu opciju\n");
  printf("1 - Dodaj novog korisnika\n");
  printf("2 - Izbrisi postojeceg korisnika\n");
  printf("3 - Kraj\n");
  int opcija;
  char query[MAX_QUERY_LEN];
  scanf("%d", &opcija);

  if (opcija == 1){
    printf("\nSTANJE PRE PRVOG UPITA\n\n\n");

    sprintf (query, "select * from korisnik");

  /* Pokusava se sa izvrsavanjem upita. */
  if (mysql_query (konekcija, query) != 0)
    printf("greska\n");

  /* Preuzima se rezultat. */
  rezultat = mysql_use_result (konekcija);

  
  /* Ispisuju se vrednosti. */
  while ((red = mysql_fetch_row (rezultat)) != 0)
    printf ("%s %s %s %s %s \n", red[0],red[1],red[2],red[3],red[4]);
  printf ("\n");

  /* Oslobadja se trenutni rezultat, posto nam vise ne treba. */
  mysql_free_result (rezultat);
    
    
    printf("unesite jmbg,ime,prezime,mesto,ulica\n");
    char jmbg[MAX_STRING_ATT_LEN];
    char ime[MAX_STRING_ATT_LEN];
    char prezime[MAX_STRING_ATT_LEN];
    char mesto[MAX_STRING_ATT_LEN];
    char ulica[MAX_STRING_ATT_LEN];
    scanf("%s%s%s%s%s", jmbg ,ime, prezime, mesto, ulica);
    int jmbg1 = atoi(jmbg);

      sprintf(query, "insert into korisnik values(%d, \"%s\", \"%s\", \"%s\", \"%s\")", jmbg1, ime, prezime,mesto, ulica);
    
    rezultat = executeQuery(konekcija, query);
    printf("Uspesno ste dodali korisnika\n");


     printf("\nSTANJE POSLE PRVOG UPITA \n\n\n");

  sprintf (query, "select * from korisnik");

  /* Pokusava se sa izvrsavanjem upita. */
  if (mysql_query (konekcija, query) != 0)
    printf("greska\n");

  /* Preuzima se rezultat. */
  rezultat = mysql_use_result (konekcija);

  
  /* Ispisuju se vrednosti. */
  while ((red = mysql_fetch_row (rezultat)) != 0)
    printf ("%s %s %s %s %s\n", red[0],red[1],red[2],red[3],red[4]);
  printf ("\n");

  /* Oslobadja se trenutni rezultat, posto nam vise ne treba. */
  mysql_free_result (rezultat);

    
  }
  else if (opcija == 2){

    printf("\nSTANJE PRE PRVOG UPITA\n\n\n");

    sprintf (query, "select * from korisnik");

  /* Pokusava se sa izvrsavanjem upita. */
  if (mysql_query (konekcija, query) != 0)
    printf("greska\n");

  /* Preuzima se rezultat. */
  rezultat = mysql_use_result (konekcija);

  
  /* Ispisuju se vrednosti. */
  while ((red = mysql_fetch_row (rezultat)) != 0)
    printf ("%s %s %s %s %s \n", red[0],red[1],red[2],red[3],red[4]);
  printf ("\n");

    
    printf("Unesite ime i prezime korisnika kog zelite da obrisete\n");
    char ime[MAX_STRING_ATT_LEN];
    char prezime[MAX_STRING_ATT_LEN];
    scanf("%s%s", ime, prezime);
    sprintf(query, "delete from korisnik where ime = \"%s\" and prezime = \"%s\" ", ime, prezime);
    rezultat = executeQuery(konekcija, query);
    printf("Uspesno ste obrisali korisnika\n");

        printf("\nSTANJE POSLE PRVOG UPITA\n\n\n");

    sprintf (query, "select * from korisnik");

  /* Pokusava se sa izvrsavanjem upita. */
  if (mysql_query (konekcija, query) != 0)
    printf("greska\n");

  /* Preuzima se rezultat. */
  rezultat = mysql_use_result (konekcija);

  
  /* Ispisuju se vrednosti. */
  while ((red = mysql_fetch_row (rezultat)) != 0)
    printf ("%s %s %s %s %s \n", red[0],red[1],red[2],red[3],red[4]);
  printf ("\n");


  }
  else if (opcija == 3)
    exit(EXIT_SUCCESS);
  else 
    error("invalid option");
  return 1;
}


void error( char* s){
  perror(s);
  exit(EXIT_FAILURE);
}
 
 
MYSQL_RES* executeQuery(MYSQL* konekcija,char* query){
  if (mysql_query(konekcija, query) != 0)
    error("invalid query");
  MYSQL_RES* rezultat = mysql_use_result(konekcija);
  return rezultat;
}

