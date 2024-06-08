use master
go

create database lab8
go

use lab8
go

create table SAILOR
(
	SailorID int primary key,
	SailorName varchar(50),
	Phone varchar(50),
	City varchar(50)
)

create table OWNER
(
	OwnerID int primary key,
	OwnerName varchar(50),
	Phone varchar(50),
	City varchar(50),
	Country varchar(50)
)

create table BOAT
(
	BoatName varchar(50) primary key,
	BoatType varchar(50),
	Price int,
	OwnerID int,
	Foreign key (OwnerID) references [dbo].[OWNER](OwnerID)
)

create table RESERVATION
(
	ReserveID int primary key,
	SailorID int,
	BoatName varchar(50),
	Date date,
	[Day] varchar(25),
	Foreign key (SailorID) references SAILOR(SailorID),
	Foreign key (BoatName) references BOAT(BoatName)
)

create table RESERVATION_DAYS
(
	ID int primary key identity(1,1),
	WeekDay varchar(25)
)

Insert into SAILOR(SailorID, SailorName, Phone, City) VALUES (1, 'Salar But', '123-123-123', 'Lahore' )
Insert into SAILOR(SailorID, SailorName, Phone, City) VALUES (2, 'Ahmad Jabbar' , '123-123-123', 'Karachi' )
Insert into SAILOR(SailorID, SailorName, Phone, City) VALUES (3, 'Sumair Tayyab', '123-123-123', 'Karachi' )
Insert into SAILOR(SailorID, SailorName, Phone, City) VALUES (4, 'Bilal Ahmad', '123-123-123', 'Sialkot' )
Insert into SAILOR(SailorID, SailorName, Phone, City) VALUES (5, 'Ali Hafiz', '123-123-123', 'Lahore' )

Insert into OWNER (OwnerID, OwnerName, Phone, City, Country) VALUES (1,'John Silver','123-123-123','Birmingham','England')
Insert into OWNER (OwnerID, OwnerName, Phone, City, Country) VALUES (2,'Shane Micheal','123-123-123','Bradford','England')
Insert into OWNER (OwnerID, OwnerName, Phone, City, Country) VALUES (3,'Ahmad Jabbar','123-123-123','Multan','Pakistan')
Insert into OWNER (OwnerID, OwnerName, Phone, City, Country) VALUES (4,'Furqan Ali','123-123-123','Sakkhar','Pakistan')
Insert into OWNER (OwnerID, OwnerName, Phone, City, Country) VALUES (5,'Faheem Abid','123-123-123','Lahore','Pakistan')
 
Insert into BOAT (BoatName, BoatType, Price, OwnerID) VALUES ('Hang Loose','Cabin_cruise',5000000,1)
Insert into BOAT (BoatName, BoatType, Price, OwnerID) VALUES ('Southern Comfort','Motor_boat',1000000,1)
Insert into BOAT (BoatName, BoatType, Price, OwnerID) VALUES ('Kitty Crew','Motor_boat',6000000,1)
Insert into BOAT (BoatName, BoatType, Price, OwnerID) VALUES ('Lounge Lizard','Motor_boat',2000000,1)
Insert into BOAT (BoatName, BoatType, Price, OwnerID) VALUES ('Safe Seamen','Raft',5000000,2)
Insert into BOAT (BoatName, BoatType, Price, OwnerID) VALUES ('Double Dollars','Cabin_cruise',5000000,3)
Insert into BOAT (BoatName, BoatType, Price, OwnerID) VALUES ('Titanic','Cabin_cruise',8000000,3)
Insert into BOAT (BoatName, BoatType, Price, OwnerID) VALUES ('Wet Dream','Airboat',700000,3)
Insert into BOAT (BoatName, BoatType, Price, OwnerID) VALUES ('Crew Lounge','Fishing',300000,4)
Insert into BOAT (BoatName, BoatType, Price, OwnerID) VALUES ('Aga','Fishing',100000,4)
Insert into BOAT (BoatName, BoatType, Price, OwnerID) VALUES ('A Fish Too Far ','Cabin_cruise',8000000,4)

Insert into RESERVATION (ReserveID, SailorID, BoatName, Date, [day]) VALUES (1,1,'A Fish Too Far','10-06-2014', 'Thursday')
Insert into RESERVATION (ReserveID, SailorID, BoatName, Date, [day]) VALUES (2,1,'Hang Loose','06-07-2014', 'Monday')
Insert into RESERVATION (ReserveID, SailorID, BoatName, Date, [day]) VALUES (3,1,'Double Dollars','02-08-2014', 'Sunday')
Insert into RESERVATION (ReserveID, SailorID, BoatName, Date, [day]) VALUES (4,2,'Crew Lounge','03-08-2014', 'Thursday')
Insert into RESERVATION (ReserveID, SailorID, BoatName, Date, [day]) VALUES (5,3,'Wet Dream','10-09-2014', 'Sunday')
Insert into RESERVATION (ReserveID, SailorID, BoatName, Date, [day]) VALUES (6,4,'Titanic','10-09-2014', 'Saturday')
Insert into RESERVATION (ReserveID, SailorID, BoatName, Date, [day]) VALUES (7,4,'Aga','10-09-2014', 'Thursday')

Insert into RESERVATION_DAYS(weekday) VALUES ('Sunday')
Insert into RESERVATION_DAYS(weekday) VALUES ('Monday')
Insert into RESERVATION_DAYS(weekday) VALUES ('Tuesday')
Insert into RESERVATION_DAYS(weekday) VALUES ('Wednesday')
Insert into RESERVATION_DAYS(weekday) VALUES ('Thursday')
Insert into RESERVATION_DAYS(weekday) VALUES ('Friday')
Insert into RESERVATION_DAYS(weekday) VALUES ('Saturday')



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