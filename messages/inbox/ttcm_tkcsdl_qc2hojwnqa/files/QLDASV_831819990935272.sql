drop database QLDoAnSV
create database QLDoAnSV
use QLDoAnSV


create table tblKhoa
(
	maKhoa char(10) primary key,
	tenKhoa nvarchar(50) not null,
)

insert into tblKhoa
values
	('DDT',N'Khoa Điện-Điện Tử'),
	('HMT',N'Khoa Hóa Học Môi Trường'),
	('CK',N'Khoa Cơ Khí'),
	('XD',N'Khoa Xây Dựng'),
	('SP',N'Khoa Sư Phạm Công Nghiệp')

create table tblLop
(
	maLop char(10) primary key,
	tenLop nvarchar(10) not null,
	maKhoa char(10) foreign key references tblKhoa(maKhoa),
	soSinhVien int default 0
		check(soSinhVien >= 0)
)

insert into tblLop
values
	('18T1',N'Lớp 18T1','DDT',50),
	('18T2',N'Lớp 18T2','DDT',50),
	('17D1',N'Lớp 17D1','DDT',40),
	('17DT2',N'Lớp 17DT2','DDT',45),
	('18HTP1',N'Lớp 18HTP1','HMT',60),
	('17SU2',N'Lớp 17SU2','HMT',55),
	('18N1',N'Lớp 18N1','CK',50),
	('18XD1',N'Lớp 18XD1','XD',50),
	('18XD2',N'Lớp 18XD2','DDT',53),
	('18SK1',N'Lớp 18SK1','SP',50)

create table tblChuDe
(
	maChuDe char(10) primary key,
	maKhoa char(10) foreign key references tblKhoa(maKhoa),
	tenChuDe nvarchar(50) not null
)

insert into tblChuDe
values
	('CDXDW','DDT',N'Xây dựng website'),
	('CDQTVTB','SP',N'Quá trình và thiết bị'),
	('CDTKVCTM','CK',N'Thiết kế và chế tạo máy'),
	('CDBTCT','XD',N'Bê tông cốt thép')

create table tblDeTai
(
	maDeTai char(10) primary key,
	tenDeTai nvarchar(100) not null,
	maChuDe char(10) foreign key references tblChuDe(maChuDe),
	soSVThamGia int default 0
		check(soSVThamGia >= 0),
	trangThai nvarchar(50) check (trangThai in (N'Được duyệt',N'Chưa duyệt')) default N'Chưa duyệt'
)

insert into tblDeTai
values
	('DTXDWBH',N'Xây dựng website bán hàng online','CDXDW',4,N'Được duyệt'),
	('DTXDWQL',N'Xây dựng website quản lý kí túc xá trường ĐH Sư Phạm Kỹ Thuật','CDXDW',10,N'Được duyệt'),
	('DTTKHT',N'Thiết kế hệ thống sấy băng tải để sấy chè xanh','CDQTVTB',7,N'Được duyệt'),
	('DTTKMHG',N'Thiết kế và chế tạo máy hủy giấy','CDTKVCTM',5,N'Được duyệt'),
	('DTTKMTN',N'Thiết kế và chế tạo máy tách ngô','CDTKVCTM',9,N'Chưa duyệt'),
	('DTTKMTH',N'Thiết kế và chế tạo máy thái hành củ','CDTKVCTM',4,N'Chưa duyệt'),
	('DTKCT',N'Đồ án kết cấu thép','CDBTCT',8,N'Được duyệt'),
	('DTCBT',N'Đồ án cầu bê tông cốt thép','CDBTCT',6,N'Được duyệt')

create table tblDonViThucTap
(
	maDonVi char(10) primary key,
	tenDonVi nvarchar(100) not null,
)

insert into tblDonViThucTap
values
	('SUN',N'Tập đoàn Sun*'),
	('FPT',N'FPT Software'),
	('AA',N'Axon Active')

create table tblSinhVien
(
	maSinhVien char(13) primary key,
	tenSinhVien nvarchar(100) not null,
	gioiTinh nvarchar(5) check  (gioiTinh in ('Nam', N'Nữ')) default 'Nam',
	ngaySinh datetime,
	queQuan nvarchar(100),
	diaChi nvarchar(100),
	email varchar(100) unique,
	maLop char(10) foreign key references tblLop(maLop),
)

insert into tblSinhVien
values
	('1811505210221',N'Nguyễn Văn Hải','Nam','03-03-2000',N'Quảng Trị',N'120 Ông Ích Khiêm','nvh2000@gmail.com','18T2'),
	('1811505210123',N'Lê Văn An','Nam','05-03-2000',N'Huế',N'85 Bắc Đẩu','anle0503@gmail.com','18T1'),
	('1811505210134',N'Nguyễn Tấn Bình','Nam','09-07-2000',N'Quảng Nam',N'12 Thanh Sơn','tanbinh09@gmail.com','18T1'),
	('1811505210235',N'Nguyễn Thị Lan',N'Nữ','07-02-2000',N'Quảng Bình',N'120 Ông Ích Khiêm','ntl0702@gmail.com','18T2')

create table tblGiangVien
(
	maGiangVien char(10) primary key,
	tenGiangVien nvarchar(100) not null,
	gioiTinh nvarchar(5) check  (gioiTinh in ('Nam', N'Nữ')) default 'Nam',
	ngaySinh datetime,
	email varchar(100) unique,
	soDienThoai char(11),
	diaChi nvarchar(100),
	maKhoa char(10) foreign key references tblKhoa(maKhoa),
	chucVu nvarchar(50)
)

set dateformat dmy
insert into tblGiangVien
values
	('GV01',N'Nguyễn Văn Phát','Nam','02/02/1987','nvpute@gmail.com','0897562485','12 Lê Duẫn','DDT',N'Giảng Viên'),
	('GV02',N'Lê Vũ','Nam','02/10/1985','lvute@gmail.com','090123456','26 Lê Lợi','DDT',N'Giảng Viên')

create table tblChiTietHuongDan
	(
		maSinhVien char(13) foreign key references tblSinhVien(maSinhVien),
		maGiangVien char(10) foreign key references tblGiangVien(maGiangVien),
		maDonVi char(10) foreign key references tblDonViThucTap(maDonVi),
		maDeTai char(10) foreign key references tblDeTai(maDeTai),
		nhanXet nvarchar(100),
		diemSo int default 0	
			check(diemSo >= 0 and diemSo <= 10),
		ngayBatDau datetime,
		ngayKetThuc datetime
	)

set dateformat dmy
insert into tblChiTietHuongDan
values
	('1811505210221','GV01','SUN','DTXDWBH',N'Tốt',8,'19/10/2020','19/12/2020'),
	('1811505210123','GV01','FPT','DTXDWQL',N'Khá',9,'19/10/2020','19/12/2020'),
	('1811505210134','GV02','FPT','DTXDWBH',N'Khá',9,'19/10/2020','19/12/2020'),
	('1811505210235','GV02','AA','DTCBT',N'Khá',8,'19/10/2020','19/12/2020')



	






	