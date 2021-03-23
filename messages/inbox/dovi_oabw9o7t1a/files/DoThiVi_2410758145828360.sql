creare database BaiTapTH
use database BaiTapTH
create table tblCustomer
(
	CustID char(7) not null primary key,
	CustName nvarchar(50) not null,
	CustAddress nvarchar(50), 
	TelNo varchar(11) unique,
	Email varchar(30) unique, 
	Balance money 
)
go
create table tblEmployee
(
	EmpID char(7)not null primary key,
	EmpName nvarchar(50) not null,
	TelNo varchar(11) unique,	
	Email varchar(50) unique, 
	Postion nvarchar(30),
	Gender char(1), 
	Dob date, 
	Salary money 
)
go
create table tblProduct
(
	ProductID char(7) not null primary key,
	ProductName nvarchar(50) not null,
	UnitPrice money,
	QtyOnHand int,
	RecorderLevel int
)
go
create table tblSupplier
(
	SuppID char(6) not null primary key,
	SuppName nvarchar(50) not null,
	SuppAddress nvarchar(50),
	TelNo varchar(11) unique ,
	ContactPerson nvarchar(50)
)
go
create table tblOderInvoice
(
	OderID char(7) not null primary key,
	OderDate datetime not null default getdate(), 
	OderAddress nvarchar(50) ,
	OderTotalMoney money,
	TelNo varchar(11) unique,
	CustNo char(7) not null foreign key references tblCustomer(CustID),
	EmpNo char(7) not null foreign key references tblEmployee(EmpID),
	InvNo char(11),
	InvDate datetime default getdate(),
	DatePaid char(10),
	DelDate datetime null default getdate(),
	DelStatusReceived char(2)
)
go
create table tblRepceiptNote
(
	RepID char(8) not null primary key,
	RepDate datetime default getdate(),
	RepToalMoney money,
	SuppNo char(6) not null foreign key references tblSupplier(SuppID)
)
go
create table tblOderInvoiceDetail
(
	OderID char(7) not null foreign key references tblOderInvoice(OderID),
	ProductID char(7) not null foreign key references tblProduct(ProductID),
	QtyOdered money,
	Amount money
)
go
create table tblReceiptNoteDetail
(
	RepID char(8) not null foreign key references tblRepceiptNote(RepID),
	ProductID char(7) not null foreign key references tblProduct(ProductID),
	QtyReceipted money,
	RepPrice money
)
go
--Cau a:
alter table tblCustomer
	add constraint Email1_ck check(Email like'[a-Za-z]%@[a-z]%.[a-z]%')
alter table tblEmployee
	add constraint Email2_ck check(Email like'[a-Za-z]%@[a-z]%.[a-z]%')
--Cau b:
alter table tblEmployee
	add constraint Dob_ck check(dateDiff(year,Dob,getdate())>=18)
alter table tblOderInvoice
--Cau d:
	add constraint Date1_ck check(OderDate<=getdate())
--Cau e:
alter table tblOderInvoice
	add constraint Date2_ck check ((InvDate <= getdate()) and (InvDate >= OderDate))
--Cau f:
alter table tblOderInvoice
	add constraint Date3_ck check((DelDate <= getDate()) and (DelDate >= InvDate))
--Cau g:
alter table tblCustomer
	add constraint Addr1_df default N'Đà Nẵng' for CustAddress,
		constraint Addr1_1CK check(CustAddress In(N'Đà Nẵng',N'Hồ Chí Minh',N'Quảng Nam'))
alter table tblSupplier
	add constraint Addr2_df default N'Đà Nẵng' for SuppAddress,
		constraint Addr2_CK check(SuppAddress In(N'Đà Nẵng',N'Hồ Chí Minh',N'Quảng Nam'))
--Cau h:
alter table tblEmployee
	add constraint GT_df default 'F' for Gender,
		constraint GT_ck check(Gender In('F','M'))
--Cau i:
alter table tblCustomer
	add constraint Bal_ck check(Balance >= 0)
alter table tblEmployee
	add constraint Sal_ck check(Salary >= 0)
alter table tblOderInvoice
	add constraint Ord_ck check(OderTotalMoney >= 0)
alter table tblOderInvoiceDetail
	add constraint QO_ck check(QtyOdered >= 0),
		constraint Am_ck check(Amount>=0)
alter table tblProduct
	add constraint QO_ck check(QtyOnHand >= 0),
		constraint UP_ck check(UnitPrice >=0),
		constraint RL_ck check(RecorderLevel>=0)
--Cau k:
alter table tblOderInvoice
	add constraint Del_df default 'BT'  for DelStatusReceived,
		constraint Del_ck check(DelStatusReceived In('BT','ER','LL'))
--NHAP DU LIEU VAO BANG
insert into tblCustomer
	values	('1815140','Nguyen Mi Du',N'Hồ Chí Minh','0536789811','nguyenmidu@gmail.com',90000),
			('1815141',N'Do Thi Vi',N'Đà Nẵng','0354788841','dovi@gmail.com',50000000),
		    ('1815142',N'Nguyen Van A',N'Hồ Chí Minh','0387452122','nguyena@gmail.com',10000),
		    ('1815143',N'Phan Van Duc',N'Quảng Nam','0986754357','vanduc@ahoo.com',2000),
		    ('1815144',N'Do Dinh Tu',Default,'03587990090','dodinhtu@gmail.com',4000000),
		    ('1815145',N'Hoang Thi Van',Default,'0167895432','hoangthivan@gmail.com',150000),
		    ('1815146',N'Nguyen Van B',N'Quảng Nam','077345689','nguyenvanb@gmail.com',60000),
		    ('1815147',N'Phan Dinh Phung',N'Hồ Chí Minh','0865312490','phandinhphung@gmail.com',80000),
		    ('1815148',N'Chuong Minh Thanh',Default,'0445428661','chuongminh@gmail.com',256000),
		    ('1815149',N'Pham Thi C',N'Đà Nẵng','0987654312','phamthic@gmail.com',45000);
set dateformat dmy
insert into tblEmployee
	values ('EMPL001',N'Do Thi Vi','0354788841','dothivi@gmail.com','Giam Doc','M','08/07/2000',90000000),
		   ('EMPL002',N'Nguyen Chung','0998765432','nguyenchung@gmail.com','Nhan Vien','F','09/08/1990',5000),
		   ('EMPL003',N'Phan Van D','0345678901','phanvand@gmail.com','Bao Ve',Default,'10/10/1990',30000),
		   ('EMPL004',N'Ca Tron','0987654321','catron@gmail.com','Nhan Vien',Default,'02/01/1995',4600),
		   ('EMPL005',N'Nguyen Nam Thu','0976528187','nguyennamthu@gmail.com','Nhan Vien','F','12/10/1997',4600),
		   ('EMPL006',N'Thai Tu','0785643219','thaitu@ahoo.com','Thu Quy','M','13/05/2000',8900),
		   ('EMPL007',N'Tin Tin','09876554333','tintin@ute.udn.vn','Pho Phong','F','20/12/1998',9000),
		   ('EMPL008',N'Nguyen Van F','0234567890','nguyenvanf@gmail.com','Truong phong','M','25/01/1999',10000),
		   ('EMPL009',N'Trung Gia Nhan','0564327890','trunggia@gmail.com','Nhan Vien','M','30/03/1999',500000),
		   ('EMPL010',N'Cao Binh','045678920','caobinh@gmail.com','Nhan Vien','F','12/12/2000',7800);
insert into tblSupplier
	values ('SPL001',N'Do Thi Vi',N'Đà Nẵng','0354788841',N'Do Dinh Tuong'),
			('SPL002',N'Ca Na',N'Hồ Chí Minh','0234356789',N'Ca Na Na'),
			('SPL003',N'Lu Bo',Default,'0987654321',N'Van Heo'),
			('SPL004',N'Nguyen Nam Thu', Default,'0987123456',N'Nguyen Thanh Nam'),
			('SPL005',N'Nguyen Trung Thanh',Default,'0876544432',N'Nguyen Van Tuat'),
			('SPL006',N'Ho Duy Nam',N'Quảng Nam','0777543641',N'Ho Tan Tai'),
			('SPL007',N'Ly Thai To',Default,'0999887667',N'Ly Thai Nhan'),
			('SPL008',N'Cao Ba Hung',N'Đà Nẵng','0876547899',N'Cao Ba Quat'),
			('SPL009',N'Chu Van An',Default,'0876544499',N'Chu Van Lai'),
			('SPL010',N'Tran Thanh',N'Đà Nẵng','0981123475',N'Truong Giang');
insert into tblRepceiptNote
	values  ('18115410',default,290000,'SPL001'),
			('18115411',default,300000,'SPL002'),
			('18115412',default,400000,'SPL003'),
			('18115413',default,500000,'SPL004'),
			('18115414',default,600000,'SPL005'),
			('18115415',default,200000,'SPL006'),
			('18115416',default,100000,'SPL007'),
			('18115417',default,400000,'SPL008'),
			('18115418',default,40000,'SPL009'),
			('18115419',default,90000,'SPL010');

insert into tblOderInvoice
	values  ('KHOr001','08/06/2019',N'Quảng Nam',87200,'0345678884','1815140','EMPL010','4000','09/09/2019','09/09/2019',default,'BT');
insert into tblOderInvoice
          values ('KHOr002','08/07/2019',N'Quảng Nam',87200,'0987654311','1815141','EMPL009','8000','09/07/2019','08/09/2019',default,default),
			('KhOr003','08/07/2019',N'Hồ Chí Minh',87200,'0780234315','1815142','EMPL008','5000','08/07/2019','08/08/2019','08/08/2019','ER'),
			('KHOr004','08/07/2019',N'Quảng Nam',87200,'0558976543','1815144','EMPL007','5000','08/07/2019','08/07/2019',default,default),
			('KHOr005','08/07/2019',N'Quảng Nam',87200,'0971234567','1815145','EMPL006','5000','08/07/2019','08/08/2019',default,default),
			('KHOr006','08/07/2019',N'Quảng Nam',87200,'0998398700','1815146','EMPL005','5000','08/07/2019','08/08/2019',default,default),
			('KHOr007','08/07/2019',N'Đà Nẵng',87200,'0982564721','1815147','EMPL004','5000','08/07/2019','08/07/2019','08/07/2019','ER'),
			('KhOr008','08/07/2019',N'Hồ Chí Minh',87200,'0731233771','1815148','EMPL002','5000','08/07/2019','08/07/2019','08/07/2019',default),
			('KhOr009','08/07/2019',N'Quảng Nam',87200,'0881234512','1815149','EMPL003','5000','08/07/2019','08/07/2019',default,'LL');
insert into tblProduct
	values  ('KHPR001',N'Lenovo',2000,3000,4000),
			('KHPD002',N'DELL ',2000,3000,4000),
			('KHPR003',N'BMW ',2000,3000,4000),
			('KHPR004',N'DELL',2000,3000,4000),
			('KHPR005',N'Iphone X',2000,3000,4000),
			('KHPR006',N'BMW ',2000,3000,4000),
			('KHPR010',N'DELL',2000,3000,4000),
			('KHPR007',N'BMW ',2000,3000,4000),
			('KHPR008',N'Iphone X',2000,3000,4000),
			('KHPR009',N'Lenovo',2000,3000,4000);
insert into tblReceiptNoteDetail
	values  ('18115410','KHPR009',5600,6200),
			('18115411','KHPR008',5200,5620),
			('18115412','KHPR005',9600,3210),
			('18115413','KHPR007',5600,3210),
			('18115414','KHPR006',5600,6110),
			('18115415','KHPR004',8600,3210),
			('18115416','KHPD002',6600,8010),
			('18115417','KHPR001',4600,8110),
			('18115418','KHPR003',3600,3210),
			('18115419','KHPR001',5600,9110);
insert into tblOderInvoiceDetail
	values  ('KhOr003','KHPR009',2300,6500),
			('KHOr004','KHPD002',2300,6500),
			('KHOr005','KHPR007',2300,6500),
			('KHOr006','KHPR006',2300,6500),
			('KHOr007','KHPR005',2300,6500),
			('KHOr008','KHPR004',2300,6500),
			('KHOr009','KHPR003',2300,6500),
			('KHOr001','KHPR001',2300,6500),
			('KHOr002','KHPR008',2300,6500),
			('KHOr009','KHPR010',2300,6500);





 
 
 
 
 
 
 
 
