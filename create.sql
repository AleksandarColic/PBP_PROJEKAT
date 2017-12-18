
create database if not exists prodaja_polovnih_stvari_preko_interneta
character set=utf8
collate=utf8_bin;

use prodaja_polovnih_stvari_preko_interneta;

create table korisnik(
       jmbg BIGINT primary key not null,
       ime varchar(45) not null,
       prezime varchar(45) not null,
       grad varchar(45) not null,
       ulica_stanovanja varchar(45) not null
); /*ok*/


create table stvar(
       id int not null primary key,
       naziv VARCHAR(45) not null,
       kolicina int not null,
       cena int not null,
       datum_postavke date not null,
       korisnik_jmbg BIGINT not null,
       FOREIGN KEY (korisnik_jmbg)
       REFERENCES korisnik(jmbg)
       on delete cascade
);/*ok*/



create table ostalo(
       tip_proizvoda varchar(45) not null,
       starost int not null,
       stvar_id int primary key not null,
       foreign key(stvar_id)
       references stvar(id)
       on delete cascade
);/*ok*/



create table odeca(
       broj int not null,
       tip varchar(45) not null,
       boja varchar(45) not null,
       materijal varchar(45) not null,
       stvar_id int primary key not null,
       foreign key (stvar_id)
       references stvar(id)
       on delete cascade
);/*ok*/


create table obuca(
       broj int not null,
       tip varchar(45) not null,
       boja varchar(45) not null,
       materijal varchar(45) not null,
       stvar_id int primary key not null,
       foreign key (stvar_id)
       references stvar(id)
       on delete cascade
);/*ok*/



create table sajt_za_prodaju(
       web_adresa varchar(45) primary key not null,
       naziv varchar(45) not null,
       broj_korisnika int not null
);/*ok*/


create table dobavljac(
       id int not null primary key,
       ime varchar(45) not null,
       prezime varchar(45) not null,
       ime_firme varchar(45) not null
);


create table isporuka(
       broj int not null primary key,
       dobavljac_id int not null,
       vreme date not null,
       status varchar(45) not null,
       nacin_placanja varchar(45) not null,
       foreign key (dobavljac_id) references dobavljac(id)
);/*ok*/



create table kupac(
       jmbg BIGINT not null,
       ime varchar(45) not null,
       prezime varchar(45) not null,
       grad varchar(45) not null,
       ulica varchar(45) not null,
       postanski_broj int not null,
       isporuka_broj int  not null,
       primary key(jmbg)
);


create table izlozena(
       stvar_id int not null,
       sajt_za_prodaju_web_adresa varchar(45) not null,
       key k_stvar_id(stvar_id),
       key k_sajt_za_prodaju_web_adresa(sajt_za_prodaju_web_adresa),
       foreign key (stvar_id) references stvar(id) on delete cascade,
       foreign key (sajt_za_prodaju_web_adresa) references sajt_za_prodaju(web_adresa)
       on delete cascade

);/*ok*/



create table prodata(
       cena int not null,
       izlozena_stvar_id int primary key,
       kupac_jmbg bigint not null,
       foreign key (izlozena_stvar_id) references izlozena(stvar_id) on delete cascade
);



