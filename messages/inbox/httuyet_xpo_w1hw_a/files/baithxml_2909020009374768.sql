Create database QLPhongMay
go
use QLPhongMay
go 
Create Table PhongMay
(
	MaPM char(3) primary key
		check (MaPM like'PM[0-9]'),
	TenPM nvarchar(30) not null,
	Vitri nvarchar(100) not null,
	Soluong int not null,
	NgayHD date default getdate()

)
insert into PhongMay
values('PM1',N'Phong Máy 1','A201',5,default),
('PM2',N'Phong Máy 2','A202',7,default),
('PM3',N'Phong Máy 3','A203',5,default)
Create table GiaoVien
(
	MaGV char(8) primary key,
	check(MaGV like'[a-z]%'),
	TenGV nvarchar(50)not null,
	Email varchar(50) null 
		check((Email like'[A-Za-z]%@gmail.com')or(Email like '[A-Za-z]%@yahoo.com')or(Email like '[A-Za-z]%@ute.udn.vn'))unique,
	SDT char(11),
	DiaChi nvarchar(100),
)
insert into GiaoVien
values('G01',N'Nguyễn thị A','a1@gmail.com','0337987824',N'Đà Nẵng'),
('G02',N'Nguyễn thị B','a2@gmail.com','0337987844',N'Đà Nẵng'),
('G03',N'Nguyễn thị C','a3@gmail.com','0337987864',N'Đà Nẵng');
Create table GV_PhongMay
(
	MaGV char(8)foreign key references GiaoVien,
	MaPM char (3)foreign key references PhongMay,
	Thu nvarchar(30)
		check (thu in(N'Thứ 2',N'Thứ 3',N'Thứ 4',N'Thứ 5',N'Thứ 6',N'Thứ 7')),
	Tutiet int,
	Dentiet int,
	primary key(MaGV,MaPM)
)
insert into GV_PhongMay
values('G01','PM1',N'thứ 2',1,2),
('G01','PM2',N'thứ 5',1,2),
('G02','PM3',N'thứ 6',1,2)