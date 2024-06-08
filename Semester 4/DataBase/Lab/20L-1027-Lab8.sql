------TASK 1------

use lab8

create view owned_boats
as
select BoatName,BoatType,Price,OwnerName,BOAT.OwnerID,Phone,City,Country
from BOAT join OWNER on BOAT.OwnerID = OWNER.OwnerID

select * from owned_boats

------TASK 2------

create view reserved_boats
as
select ReserveID,RESERVATION.SailorID,BoatName,Date,Day,SailorName,Phone,City
from RESERVATION JOIN SAILOR ON RESERVATION.SailorID = SAILOR.SailorID

SELECT * FROM reserved_boats

------TASK 3------

create procedure num_of_boats_owned
as
select count(t.BoatName) as Num_Of_Owned_Boats,t.OwnerName
from (select * from owned_boats)as t
group by OwnerName

execute num_of_boats_owned

------TASK 4------

create view owner_2 
as
select* from OWNER

insert into owner_2 values(87, 'Komal', '2678299111', 'New York', 'America')

------TASK 5------

create trigger stop_procedure on database
for drop_procedure
as begin
print('Alert! Someone tried to drop a procedure on date and time')
end

drop procedure num_of_boats_owned

create trigger stop_create_procedure on database
for create_procedure
as begin
print('Alert! Someone tried to create a procedure on date and time')
end

create procedure abcd

------TASK 6------

create trigger insert_view on owner_2
instead of insert as
select * from owner_2