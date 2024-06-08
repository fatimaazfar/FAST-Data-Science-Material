-- Queries for creating databases and relations

use master
--drop database doccPlus
go

-- creating database
create database doccPlus
go

-- changing scope
use doccPlus

-- creating tables

use doccPlus
create table subscription(
    subID int not null primary key,
    tierName varchar(20) not null,
    description varchar(100) not null,
    cost float not null
)

use doccPlus
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

use doccPlus
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

use doccPlus
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

use doccPlus
create table patientLogin(
	patientID int references [patient](patientID),
	patient_username varchar(50),
	patient_password varchar(50)
)

use doccPlus
create table doctorLogin(
	docID int references [doctor](docID),
	doctor_username varchar(50),
	doctor_password varchar(50)
)

--Project Deliverable 3

--Group members:

--Komal Akhlaq (20L-1278)
--Abdul Saboor (20L-1113)
--Mohammed Anas (20L-1289)
--Fatima Azfar (20L-1027)

--Procedures:

--Procedure to verify log in credentials

create procedure patient_login_verification
@username varchar(50), @password varchar(50)
as
select * from patientLogin as p
where p.patient_username = @username and p.patient_password = @password
if(p.patient_username = @username and p.patient_password = @password)
	begin print('Successfully Logged in!') end
else
	begin print('Log in Failed!') end

insert into patient(patientID, firstName, lastName, CNIC, phoneNum, DOB, gender, subscription, medicalHistory)
values(1,'fatima','azfar','76423168461947','039992627181',2022-12-13,1,1,'wieufgqieufgqyeikdg')

insert into patientLogin(patientID, patient_username, patient_password) values(1,'fatima','fatima381160')


--Procedure to verify credentials and change password
--Procedure to verify parameters for adding a new case

--Views:

--A patient gets to view his cases ordered by date (doctor first name, doctor last name, doctor Id, diagnosis, date, cured status)
--Doctor gets to view his patients' cases ordered by date/cured then not cured (patient first name, patient last name, patient Id, diagnosis, date, cured status, medical history, gender)
--A view of top-rated doctors based on combined ratings from all patients

--Triggers:

--A trigger to send a message to the doctor and patient of a confirmed or canceled appointment.
--A trigger to tell a doctor of verification status
--A trigger when a new doctor registers (we need to verify status)
--A trigger to (nested call for procedure 3) when adding a new record in the case
