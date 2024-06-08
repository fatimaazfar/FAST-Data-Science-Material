--Abdul Saboor 20L-1113
--Fatima Azfar 20L-1027
--Komal Akhlaq 20L-1278
--Mohammad Anas 20L-1289

-- Queries for creating databases and relations
-- creating database
create database DoccPlus1
go

-- changing scope
use DoccPlus1

-- creating tables

use DoccPlus1
create table subscription(
    subID int not null primary key,
    tierName varchar(20) not null,
    description varchar(100) not null,
    cost float not null
)

use DoccPlus1
create table doctor(
    docID int not null primary key,
    firstName varchar(20) not null,
    lastName varchar(20) not null,
    CNIC int not null unique,
    phoneNum int not null,
    address varchar(100) not null,
    gender bit not null,
    specialization varchar(100) not null,
    education varchar(100) not null,
    Experience int not null,
    availability bit not null,
    numberOfCases int not null,
    subscription int foreign key references [subscription](subID),
    approvedStatus bit not null,
)

use DoccPlus1
create table patient(
    patientID int not null primary key,
    firstName varchar(20) not null,
    lastName varchar(20) not null,
    CNIC int not null unique,
    phoneNum int not null,
    DOB date not null,
    gender bit not null,
    subscription int not null foreign key references [subscription](subID),
    medicalHistory varchar(500) not null,
)

use DoccPlus1
create table caseHistory(
    caseID int not null primary key,
    docID int not null foreign key references [doctor](docID),
    patientID int not null foreign key references [patient](patientID),
    diagnosis varchar(500),
    date date not null,
    curedStatus bit not null,
    likedDoc bit not null,
    rating int not null,
    bpLow float not null,
    bpHigh float not null,
    sugarLevel float not null,
    prescription varchar(500) not null,
    dComments varchar(256),
    pComments varchar(256),
    meetingLink varchar(100) not null
)

use DoccPlus1
create table credentials(
    id int not null primary key,
    username varchar(50) not null unique,
    password varchar(50) not null unique,
    user_status bit not null
)
create table appointments(
    docID int not null foreign key references [doctor](docID),
    patientID int not null foreign key references [patient](patientID),
    status int not null -- 1 for confirm, 2 for cancel
)


-- create a view for verified patients
-- create a view for verified doctors
-- create a procedure for verifying credentials from credentials table
-- create a procedure for updating credentials

--views
--view # 1 : creating a view for verified patients credentials
create view verified_patients
as
    select * from credentials where id in (select P.patientID from patient P)

--view # 2 : creating a view for verified doctors
create view verified_doctors
as
    select * from credentials where id in (select D.docID from doctor D where D.approvedStatus=1)

--view # 3 : creating a view to see top rated doctors
create view top_doctors
as
	select doctor.docID, doctor.firstName, doctor.lastName, caseHistory.rating from doctor join caseHistory on doctor.docID = caseHistory.docID where rating > 4

--procedures
--procedure # 1 : creating a procedure for verifying credentials
create procedure verify_credentials
@username varchar(50), @password varchar(50), @status bit output
as
begin
    if(exists(select * from credentials C where C.username=@username and C.password=@password))
    begin
        set @status=1
    end
    else
    begin
        set @status=0
    end
end

--procedure # 2 : creating a procedure for changing password
create procedure change
@username varchar(50), @opassword varchar(50), @npassword varchar(50), @status bit output
as
begin
    if(exists(select * from credentials C where C.username=@username and C.password=@opassword))
    begin
        update credentials
        set password=@npassword
        where username=@username and password=@opassword
        set @status=1
    end
    else
    begin
        set @status=0
    end
end

--procedure # 3 : procedure to cancel an appointment
create procedure cancel_appointment
@docid int, @patientid int
as
if(exists(select * from appointments a where a.docID = @docid and a.patientID = @patientid))
begin update appointments set status = 2 where appointments.docID = @docid and appointments.patientID = @patientid end
else begin print 'This Appointment does not exist' end


--triggers
--trigger # 1 : in case of confirmation of appointment
create trigger confirmation on [dbo].[appointments]
AFTER INSERT
AS 
BEGIN
     SET NOCOUNT ON;
	 DECLARE @customerid int
	 select @customerid=inserted.patientID
	 FROM INSERTED
	 DECLARE @Drid int
	 select @Drid=inserted.docID
	 FROM INSERTED
      if(exists(select * from [dbo].[appointments] ap where ap.status=1))
    begin
        print 'Patient Confirms the Appointment with id:' + CAST(@customerid AS  VARCHAR(5)) 
    end
    else
    begin
        print 'Doctor confirms the Appointment with id:'+ CAST(@Drid AS  VARCHAR(5))
    end
end


--trigger # 2
create trigger cancellation on [dbo].[appointments]
AFTER UPDATE
AS 
BEGIN
     SET NOCOUNT ON;
	 DECLARE @customerid int
	 select @customerid=inserted.patientID
	 FROM INSERTED
	 DECLARE @Drid int
	 select @Drid=inserted.docID
	 FROM INSERTED
      if(exists(select * from [dbo].[appointments] ap where ap.status=2))
    begin
        print 'Patient has cancelled the Appointment with id:' + CAST(@customerid AS  VARCHAR(5)) 
    end
    else
    begin
        print 'Doctor has cancelled the Appointment with id:'+ CAST(@Drid AS  VARCHAR(5))
    end
end

--trigger # 3
--A trigger when a new doctor registers (we need to verify status)
create trigger newdoc on [dbo].[doctor]
instead of INSERT
AS 
BEGIN
     
	 DECLARE @Drid int
	 select @Drid=inserted.docID
	 FROM INSERTED
        if(exists(select * from [dbo].[doctor] C where C.approvedStatus=1))
        begin
		    print 'Successfully added a new doctor'
            insert into [dbo].[doctor] values((select docID from inserted),(select firstName from inserted),(select lastName from inserted),(select CNIC from inserted),(select phoneNum from inserted),(select address from inserted),(select gender from inserted),(select specialization from inserted),(select education from inserted),(select numberOfCases from inserted),(select availability from inserted),(select Experience from inserted),(select subscription from inserted),(select approvedStatus from inserted))
        end
            else
        begin
		     print 'Status was not approved of doctor with id: ' + CAST(@Drid AS  VARCHAR(5)) 

        end
    end
    

