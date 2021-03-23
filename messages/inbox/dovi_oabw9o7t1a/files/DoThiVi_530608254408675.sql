create table Customer
(
	CustID char(7) not null primary key,
	CustName nvarchar(50) not null,
	CustAddress nvarchar(50) default N'Da Nang' check (CustAddress In('Da Nang','Ho Chi Minh','Quang Nam')),
	TelNo varchar(11) unique check(TelNo like('[0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9]') 
		or TelNo like('[0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9]')),
	Email varchar(50) unique check(Email like'[a-Za-z]%@[a-z]%.[a-z]%'),
	Balance money check (Balance > 0)
)
go
create table Supplier
(
	SuppID char(6) not null primary key,
	SuppName nvarchar(50) not null,
	SuppAddress nvarchar(50) default N'Da Nang' check (SuppAddress In('Da Nang','Ho Chi Minh','Quang Nam')),
	TelNo varchar(11) unique check(TelNo like('[0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9]') 
		or TelNo like('[0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9]')),
	ContactPerson nvarchar(50)
)
go
create table RepceiptNote
(
	RepID char(7) not null primary key,
	RepDate datetime default getdate(),
	RepToalMoney money,
	SuppNo char(6) not null foreign key references Supplier(SuppID)
)
go
create table OderInvoice
(
	OderID char(7) not null primary key,
	OderDate datetime not null default getdate() check (OderDate<=getdate()),
	OderAddress nvarchar(50) ,
	OderTotalMoney money check(OderTotalMoney > 0 ),
	TelNo varchar(11) unique check(TelNo like('[0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9]') 
		or TelNo like('[0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9]')),
	CustNo char(7) not null foreign key references Customer(CustID),
	EmpNo char(6) not null,
	InvNo varchar(11),
	InvDate datetime default getdate() check ((InvDate<=getdate()) and (InvDate >= OderDate)),
	DatePaid datetime,
	DelDate datetime null default getdate() check((DelDate<=getDate())and(DelDate>=InvDate)),
	DelStatusReceived char(2) default 'BT' check(DelStatusReceived In('BT','ER','LL'))
)
go
create table Employee
(
	EmpID char(6) not null primary key,
	EmpName nvarchar(50) not null,
	TelNo varchar(11) unique check(TelNo like('[0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9]') 
		or TelNo like('[0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9]')),
	Email varchar(50) unique check(Email like'[a-Za-z]%@[a-z]%.[a-z]%'),
	Postion nvarchar(30),
	Gender char(1) default  'F' check(Gender In('F','M')),
	Dob date check(dateDiff(year,Dob,getdate())>=18),
	Salary money check (Salary > 0)
)
go
create table Product
(
	ProductID char(7) not null primary key,
	ProductName nvarchar(50) not null,
	UnitPrice money check(UnitPrice > 0),
	QtyOnHand money check(QtyOnHand > 0),
	RecorderLevel money check(RecorderLevel > 0)
)
go
create table OderInvoiceDetail
(
	OderID char(7) not null foreign key references OderInvoice(OderID),
	ProductID char(7) not null foreign key references Product(ProductID),
	QtyOdered money check(QtyOdered > 0),
	Amount money check(Amount > 0)
)
go
create table ReceiptNoteDetail
(
	RepID char(7) not null foreign key references RepceiptNote(RepID),
	ProductID char(7) not null foreign key references Product(ProductID),
	QtyReceipted money,
	RepPrice money
)


