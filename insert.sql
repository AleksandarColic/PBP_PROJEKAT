use prodaja_polovnih_stvari_preko_interneta;

insert into korisnik values
(1,'Aleksandar','Colic','Sevojno','Milivoja Marica'),
(2,'Milos','Dumanjic','Uzice','Marka Todorovica'),
(3,'Veljko','Pesic','Raska','Petra Ivkovica');

insert into stvar values
(1,'jakna',5,3000,now(),1),
(2,'patike',3,3000,now(),1),
(3,'pantalone',5,3000,now(),2),
(4,'dukserica',1,3000,now(),2),
(5,'majica',5,3000,now(),2),
(6,'naocare',1,3000,now(),3);

insert into ostalo values
('naocare',3,6);

insert into odeca values
(34,'majica','plava','pamuk',5),
(34,'dukserica','plava','pamuk',4),
(34,'pantalone','plava','teksas',3),
(34,'jakna','crna','koza',1);

insert into obuca values
(34,'patike','crne','koza',2);

insert into sajt_za_prodaju values
('www.sajt1.rs','Prodaja polovnih stvari',45),
('www.sajt2.rs','Kupujem Prodajem',150),
('www.sajt3.rs','Polovno',12345);

insert into dobavljac values
(1,'Marko','Ivkovic','PostExpress'),
(2,'Petar','Ilic','BrzaPosta'),
(3,'Filip','Maric','Isporuka poste');

insert into kupac values
(1,'Mirko','Maric','Uzice','Takovska',31000,null),
(2,'Mirko','Maric','Uzice','Takovska',31000,null);


insert into isporuka values
(1,1,'24.3.2016','dostavljen','karticom'),
(2,1,'24.3.2016','na cekanju','karticom');


insert into izlozena values
(1,'www.sajt1.rs'),
(2,'www.sajt2.rs');

insert into prodata values
(2000,1,1),
(3000,2,1);




