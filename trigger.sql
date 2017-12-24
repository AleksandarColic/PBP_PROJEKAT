use prodaja_polovnih_stvari_preko_interneta;

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

create trigger triger3 before insert on prodata
for each row
begin
declare kolicina1 INT;
set kolicina1 = (select kolicina from stvar s where new.izlozena_stvar_id=s.id);
if(kolicina1 >= 1)
then
update stvar
set kolicina = kolicina - 1
where new.izlozena_stvar_id = id;
else
SIGNAL SQLSTATE '45000' SET message_text = 'Greska: Datu stvar nije moguce prodati jer je njena kolicina trenutno 0.';
end if;
end//



create trigger triger4 after insert on prodata
for each row
begin
declare kolicina1 INT;
set kolicina1 = (select kolicina from stvar s where new.izlozena_stvar_id=s.id);
if(kolicina1 <= 0)
then
delete from stvar
where id = new.izlozena_stvar_id;
delete from obuca
where stvar_id = new.izlozena_stvar_id;
delete from odeca
where stvar_id = new.izlozena_stvar_id;
delete from ostalo
where stvar_id = new.izlozena_stvar_id;
end if;
end//
