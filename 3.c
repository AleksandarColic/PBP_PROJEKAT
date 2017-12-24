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
  
  char query[MAX_QUERY_LEN];
 
  

    printf("\nSTANJE PRE PRVOG UPITA\n\n\n");

    
    
    sprintf (query, "select * from stvar");

  /* Pokusava se sa izvrsavanjem upita. */
  if (mysql_query (konekcija, query) != 0)
    printf("greska\n");

  /* Preuzima se rezultat. */
  rezultat = mysql_use_result (konekcija);

  
  /* Ispisuju se vrednosti. */
  while ((red = mysql_fetch_row (rezultat)) != 0)
    printf ("%s %s %s %s %s %s\n", red[0],red[1],red[2],red[3],red[4],red[5]);
  printf ("\n");

  /* Oslobadja se trenutni rezultat, posto nam vise ne treba. */
  mysql_free_result (rezultat);

  printf("\n\n");

    printf("unesi id stvari koja ce biti prodata kupcu \n");

  int id_stvari;

  scanf("%d",&id_stvari);
  

  sprintf (query, "select * from stvar");

  /* Pokusava se sa izvrsavanjem upita. */
  if (mysql_query (konekcija, query) != 0)
    printf("greska\n");

  /* Preuzima se rezultat. */
  rezultat = mysql_use_result (konekcija);

  int id_kupca;
  int cena;
  /* Ispisuju se vrednosti. */
  while ((red = mysql_fetch_row (rezultat)) != 0){
    if(atoi(red[0])==id_stvari){
      id_kupca = atoi(red[5]);
      cena = atoi(red[3]);
      break;
    }
  }
  
  printf ("\n");

  /* Oslobadja se trenutni rezultat, posto nam vise ne treba. */
  mysql_free_result (rezultat);
  printf("%d %d %d \n",cena,id_stvari,id_kupca);
  sprintf(query, "insert into prodata values(%d,%d,%d)",cena,id_stvari,id_kupca);
  rezultat = executeQuery(konekcija, query);

    printf("Uspesno ste dodali stvar\n");
  

     printf("\nSTANJE POSLE PRVOG UPITA \n\n\n");

  sprintf (query, "select * from stvar");


  if (mysql_query (konekcija, query) != 0)
    printf("greska\n");


  rezultat = mysql_use_result (konekcija);

  
 
  while ((red = mysql_fetch_row (rezultat)) != 0)
    printf ("%s %s %s %s %s %s\n", red[0],red[1],red[2],red[3],red[4],red[5]);
    printf ("\n");


  mysql_free_result (rezultat);

    

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

