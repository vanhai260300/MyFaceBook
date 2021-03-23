create database QLNHATRE3
go
use QLNHATRE3
go
create table giaovien
(
	magv char(10) not null primary key,
	hoten nvarchar(50) not null,
	sdt char(11) not null,
	giotinh nchar(6) not null default N'nữ',
	diachi nvarchar(50) not null
);
create table khoahoc
(
	makhoa char(10)not null primary key,
	nambatdau int,
	namketthuc int
);
create table lophoc
(
	malop char(10) not null primary key,
	tenlop nvarchar(15) not null,
	makhoahoc char(10)not null foreign key references khoahoc(makhoa)
);
create table hocsinh
(
	mahs char(10) not null,
	malop char(10)not null foreign key references lophoc(malop),
	hoten nvarchar(50) not null,
	ngaysinh varchar(50),
	giotinh nchar(6) not null default N'nữ',
	diachi nvarchar(50) not null,
	dantoc nvarchar(30) not null,
	tongiao nvarchar(10)not null,
	doituonguutien nvarchar(10),
	primary key (mahs)
);
create table phuhuynh
(
	maph char(10) not null primary key,
	hoten nvarchar(50) not null,
	sdt char(11) not null,
	mahs char(10)not null foreign key references hocsinh
);
create table phutrach
(
	malop char(10)not null foreign key references lophoc(malop),
	magv char(10)not null foreign key references giaovien,
	primary key(malop,magv)
);
create table suckhoe
(
	mahs char(10)not null foreign key references hocsinh primary key,
	chieucao int default 0,
	cannang int default 0,
	ngaykham varchar(50)
	
);
create table ketqua
(
	mahs char(10)not null foreign key references hocsinh primary key,
	tongdiem float(2) ,
	hocluc nvarchar(10)
);

create table dangnhap
(
	magv char(10)not null foreign key references giaovien,
	mk char(30) ,
	primary key(magv)
)


insert into giaovien
values
	('gv01',N'Lê Thị Thu Hiền','0337987824',N'nữ',N'32 Đống Đa-Đà Nẵng'),
	('gv02',N'Trần Thị Hương','0337987123',N'nữ',N'38 Lý Tự Trọng-Đà Nẵng'),
	('gv03',N'Phan Thị nhung','0337987855',N'nữ',N'33 Đống Đa-Đà Nẵng'),
	('gv04',N'Nguyễn Duy Tráng','0337987345',N'nam',N'32 Bạch Đằng-Đà Nẵng'),
	('gv05',N'Hồ Lâm Khang','0337987456',N'nam',N'44 Cao Thắng-Đà Nẵng'),
	('gv06',N'Hồ Thị Thi','0337987567',N'nữ',N'718 Trần Cao Vân-Đà Nẵng');
insert into khoahoc
values
	('k18',2018,2021),
	('k19',2019,2022),
	('k20',2020,2023);
insert into lophoc
values
	('08M1',N'mầm 1','K18'),
	('08M2',N'mầm 2','K18'),
	('08M3',N'mầm 3','K18'),
	('09M1',N'mầm 1','K19'),
	('09M2',N'mầm 2','K19'),
	('09M3',N'mầm 3','K19'),
	('20M1',N'mầm 1','K20'),
	('20M2',N'mầm 2','K20'),
	('20M3',N'mầm 3','K20');

insert into hocsinh
values
	('hs01','08M1',N'Hồ Thị Thi','01/02/2007',N'nữ',N'Đà Nẵng',N'Kinh',N'Không',N'Không'),
	('hs02','08M1',N'hồ Thi Nhân','01/02/2007',N'nữ',N'Đà Nẵng','Kinh',N'không',N'không'),
	('hs03','08M1',N'hồ Thị Hiền','01/02/2007',N'nữ',N'Đà Nẵng','Kinh',N'không',N'không'),
	('hs04','08M1',N'hồ văn Lan','01/02/2007',N'nam',N'Đà Nẵng','Kinh',N'không',N'không');
insert into phuhuynh
values
	('PH01',N'trần thị Hà','0123456789','hs01'),
	('PH02',N'trần thị Hoà','0123456723','hs03'),
	('PH03',N'trần thị Lan','0123456734','hs03'),
	('PH04',N'trần thị Liễu','0123456745','hs01');
insert into phutrach
values
	('08M1','gv01'),
	('08M2','gv02'),
	('08M3','gv03');
insert into suckhoe
values
	('hs01',123,20,'01/02/2020'),
	('hs02',124,27,'01/02/2020'),
	('hs03',124,27,'01/02/2020'),
	('hs04',111,20,'01/02/2020');
insert into ketqua
values
	('hs01',10,N'giỏi'),
	('hs02',7,N'khá'),
	('hs03',5,N'Trung Bình'),
	('hs04',8,N'khá');
insert into dangnhap
values
('gv01','gv01'),
('gv02','gv02'),
('gv03','gv03'),
('gv04','gv04'),
('gv05','gv05')