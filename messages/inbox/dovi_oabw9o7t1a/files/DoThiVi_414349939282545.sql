create table Customer(
CustID char(7) primary key not null,
CustName nvarchar(50) not null,
CustAddress nvarchar(50) default N'Da Nang' check(CustAddress In('Da Nang','Ho Chi Minh','Quang Nam')) ,
TelNo varchar(11),
Email varchar(50) check (Email like '[A-Za-z]@gmail.com' or Email like '[A-Za-z]@ute.udn.vn' or Email like '[A-Za-z]@ahoo.com') ,
Balance money not null,
)
go
create table Supplier(
SuppID char(6) primary key not null,
SuppName nvarchar(50) not null,
SuppAddress nvarchar(50)  default N'Da Nang' check(SuppAddress In('Da Nang','Ho Chi Minh','Quang Nam')) ,
TelNo varchar(11),
ContactPerson nvarchar(50),
)
go
create table ReceiptNote(
RepID char(7) primary key not null,
RepDate datetime,
RepTotalMoney money not null,
SuppNo char(11) not null,
)
go 
create table OrderInvoice(
OrderID char(7) primary key not null,
OrderDate datetime check(OrderDate<=getdate()),
OrderTotalMoney money,
TelNo varchar(11),
CustNo char(7) not null,
EmpNo char(7),
InvNo char(11),
InvDate datetime check(InvDate<=OrderDate),
DatePaid datetime,
DelDate datetime check(DelDate<=getdate() and DelDate>=InvDate),
DelStatusReceived char(2),
)
go
create table Employee(
EmpID char(7) primary key not null,
EmpName nvarchar(50) ,
TelNo varchar(11),
Email nvarchar(50) check (Email like '[A-Za-z]@gmail.com' or Email like '[A-Za-z]@ute.udn.vn' or Email like '[A-Za-z]@ahoo.com'),
Postion nvarchar(30),
Gender char(7) default 'F' check(Gender In('F','M')),
DoB date check (DoB>=18),
Salary money,
)
go
create table Product(
ProductID char(7) primary key not null,
Name nvarchar(50) not null,
UnitPrice money not null,
QtyOnHand int not null,
RecorderLevel int not null,
)
go
create table OrderInvoiceDetail(
OrderID char(7) primary key not null,
OrderDate datetime not null,
OrderAddress nvarchar(50) not null,
OrderTotalMoney money,
TelNo varchar(11),
CustNo char(7) not null,
EmpNo char(7) not null,
InvNo char(11),
InvDate datetime,
DatePaid datetime,
DelDate datetime,
DelStatusRecived char(2),
)
go
create table ReceiptNoteDetail(
RepID char(7) not null foreign key references ReceiptNote(RepID),
ProductID char(7) foreign key references Product(ProductID),
QtyReceipted int,
RepPrice int,
)






 