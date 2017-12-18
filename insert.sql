use prodaja_polovnih_stvari_preko_interneta;
insert into korisnik values
(1111111111111,'Aleksandar','Colic','Sevojno','Milivoja Marica'),
(2222222222222,'Milos','Dumanjic','Uzice','Marka Todorovica'),
(3333333333333,'Veljko','Pesic','Raska','Petra Ivkovica');

insert into stvar values
(1,'jakna',5,3000,'15.12.2016',1111111111111),
(2,'patike',3,3000,'15.12.2016',1111111111111),
(3,'pantalone',5,3000,'15.12.2016',2222222222222),
(4,'dukserica',5,3000,'15.12.2016',2222222222222),
(5,'majica',5,3000,'15.12.2016',2222222222222),
(6,'naocare',1,3000,'15.12.2016',3333333333333);

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

insert into isporuka values
(1,1,'24.3.2016','dostavljen','karticom'),
(2,1,'24.3.2016','na cekanju','karticom');

insert into kupac values
(11111111111,'Mirko','Maric','Uzice','Takovska',31000,1),
(22222222222,'Mirko','Maric','Uzice','Takovska',31000,2);

insert into izlozena values
(1,'www.sajt1.rs'),
(2,'www.sajt2.rs');

insert into prodata values
(2000,1,1111111111111),
(3000,2,1111111111111);

delimiter //

create trigger triger1 before insert on stvar
for each row
begin
declare msg varchar(255);
if(date(new.datum_postavke)!=date(now())) THEN SET msg='Datum postavke na sajt treba da bude danasnji datum!';
signal sqlstate '45000' set message_text=msg;
end if;
end//



create trigger triger2 before insert on ostalo
for each row
begin
declare msg varchar(255);
if(new.starost>10) then set msg='Na sajtu se ne mogu naci predmeti stariji od 10 godina.';
signal sqlstate '45000' set message_text=msg;
end if;
end//

delimiter ;
