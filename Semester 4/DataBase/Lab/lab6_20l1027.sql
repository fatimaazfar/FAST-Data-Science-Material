--Task 1--

create procedure allusers
as
select * from [User]

exec allusers

--Task 2--

create procedure userdetails
@name varchar(50)
as
select * from [User]
where name = @name

exec userdetails 'Ali'

--Task 3--

create procedure cardinput
@card varchar(50)
as
select name, phoneNum, city
from [UserCard] JOIN [User]
ON [User].userid = UserCard.userID
where cardNum = @card

exec cardinput '1324327436569'

--Task 4--

create procedure minbalance
@balance float output
as
select @balance = min(balance) from Card

declare @minbalance float
exec minbalance @minbalance output
select @minbalance as MinBalance

--Task 5--

create procedure numofcards
@id int, @name varchar(20), @numofcards int output
as
select @numofcards = count(cardNum)
from UserCard
where userID = @id

declare @numcard int
exec numofcards '1','Ali',@numcard output
select @numcard as NumOfCards

--Task 6--

create procedure login
@cardnum varchar(20), @pin varchar(4), @status int output
as
declare @card varchar(20)
declare @p varchar(4)
select @card = cardNum, @p = PIN from Card
where @cardnum = cardNum and @pin = PIN
if (@cardnum = @card and @pin = @p)
begin
set @status = 1
end
else
begin
set @status = 0
end

declare @stat int
exec login '1324327436569','1770', @stat output
select @stat as Status

--Task 7--

create procedure updatepin
@cardnum varchar(20), @oldpin varchar(4), @newpin varchar(4)
as
declare @card varchar(20)
declare @p varchar(4)
declare @status int
select @card = cardNum, @p = PIN from Card
where @cardnum = cardNum and @oldpin = PIN
if (@cardnum = @card and @oldpin = @p)
begin
set @status = 1
end
else
begin
set @status = 0
end
if(@status = 1)
begin
update Card
set PIN = @newpin
where cardNum = @cardnum
print 'PIN Updated!'
end
else
begin
print 'PIN Not updated!'
end

declare @stat int
exec updatepin '1324327436569','1870','1239'

--Task 8--

create procedure withdraw
@cardnum varchar(20), @pin varchar(4), @transamount int
as
declare @status int
declare @transid int
exec login @cardnum,@pin,@status output
if(@status = 1)
begin
select @transid = max(transId) from [Transaction]
insert into [Transaction] (transId,transDate,cardNum,amount,transType)
values (@transid+1,getdate(),@cardnum,@transamount,1)
update Card
set balance = balance+@transamount
where cardNum = @cardnum
print 'Transaction Successful!'
end
else
begin
select @transid = max(transId) from [Transaction]
insert into [Transaction] (transId,transDate,cardNum,amount,transType)
values (@transid+1,getdate(),@cardnum,@transamount,4)
print 'Transaction Failed!'
end

exec withdraw '1324327436569','1672','1000'