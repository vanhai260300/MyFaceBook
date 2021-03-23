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
	tenChuDe nvarchar(50) not null,
	soLuongDeTai int default 0
		check(soLuongDeTai >= 0)
)

insert into tblChuDe
values
	('CDXDW','DDT',N'Xây dựng website', 2),
	('CDQTVTB','SP',N'Quá trình và thiết bị', 1),
	('CDTKVCTM','CK',N'Thiết kế và chế tạo máy', 3),
	('CDBTCT','XD',N'Bê tông cốt thép', 2)

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
	('1811505210235',N'Nguyễn Thị Lan',N'Nữ','07-02-2000',N'Quảng Bình',N'120 Ông Ích Khiêm','ntl0702@gmail.com','18T2'),
	('1811505210226',N'Hoàng Thị Cẩm Vân',N'Nữ','03-03-2000',N'Quảng Trị',N'120 Ông Ích Khiêm','nvv2000@gmail.com','18T2'),
	('1811505210127',N'Lê Hữu Quỳnh','Nam','05-03-2000',N'Huế',N'85 Bắc Đẩu','anlq0503@gmail.com','18T1'),
	('1811505210138',N'Võ ĐÌnh Hoàng Long',N'Nam','09-07-2000',N'Quảng Nam',N'12 Thanh Sơn','vdhll@gmail.com','18T1'),
	('1811505210139',N'Lê Thanh Hiếu',N'Nam','09-07-2000',N'Quảng Nam',N'12 Thanh Sơn','vdhl1@gmail.com','18T1'),
	('1811505210110',N'Vân Hoàng',N'Nữ','09-07-2000',N'Quảng Nam',N'12 Thanh Sơn','vdhl2@gmail.com','18T1'),
	('1811505210113',N'Phan Hải',N'Nam','09-07-2000',N'Quảng Nam',N'12 Thanh Sơn','vdhl4@gmail.com','18T1'),
	('1811505210239',N'Nguyễn Văn A',N'Nữ','07-02-2000',N'Quảng Bình',N'120 Ông Ích Khiêm','vdhl5@gmail.com','18T2'),
	('1811505210200',N'Nguyễn Văn B',N'Nam','07-02-2000',N'Quảng Bình',N'02 Thanh Sơn','vdhl6@gmail.com','18T1'),
	('1811505210201',N'Nguyễn Văn C',N'Nữ','07-02-2000',N'Quảng Bình',N'120 Ông Ích Khiêm','vdhl7@gmail.com','18T2'),
	('1811505210202',N'Nguyễn Văn D',N'Nam','07-02-2000',N'Quảng Bình',N'120 Ông Ích Khiêm','vdhl8@gmail.com','18T1'),
	('1811505210301',N'Nguyễn Văn E',N'Nữ','07-02-2000',N'Quảng Bình',N'120 Ông Ích Khiêm','vdhl74@gmail.com','18T1'),
	('1811505210302',N'Nguyễn Văn F',N'Nam','07-02-2000',N'Quảng Bình',N'120 Ông Ích Khiêm','vdhl83@gmail.com','18T2')

create  table tblGiangVien
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

create  table tblChiTietHuongDan
	(
		maSinhVien char(13) foreign key references tblSinhVien(maSinhVien),
		maGiangVien char(10) foreign key references tblGiangVien(maGiangVien),
		maDonVi char(10) foreign key references tblDonViThucTap(maDonVi),
		maDeTai char(10) foreign key references tblDeTai(maDeTai),
		nhanXet nvarchar(100),
		diemSo int default 0	
			check(diemSo >= 0 and diemSo <= 10),
		ngayBatDau datetime,
		ngayKetThuc datetime,
		primary key(maSinhVien)
	)

set dateformat dmy
insert into tblChiTietHuongDan
values
	('1811505210221','GV01','SUN','DTXDWBH',N'Tốt',8,'19/10/2020','19/12/2020'),
	('1811505210123','GV01','SUN','DTXDWQL',N'Khá',7,'19/10/2020','19/12/2020'),
	('1811505210134','GV01','SUN','DTXDWBH',N'Tốt',9,'19/10/2020','19/12/2020'),
	('1811505210235','GV01','SUN','DTCBT',N'Khá',6,'19/10/2020','19/12/2020'),
	('1811505210226','GV01','FPT','DTXDWBH',N'Khá',7,'19/10/2020','19/12/2020'),
	('1811505210127','GV01','FPT','DTCBT',N'Tốt',9,'19/10/2020','19/12/2020'),
	('1811505210138','GV01','FPT','DTXDWBH',N'Khá',7,'19/10/2020','19/12/2020'),
	('1811505210139','GV01','FPT','DTCBT',N'Tốt',9,'19/10/2020','19/12/2020'),
	('1811505210110','GV02','FPT','DTXDWBH',N'Khá',8,'19/10/2020','19/12/2020'),
	('1811505210113','GV02','FPT','DTXDWBH',N'Tốt',9,'19/10/2020','19/12/2020'),
	('1811505210239','GV02','AA','DTXDWBH',N'Khá',7,'19/10/2020','19/12/2020'),
	('1811505210200','GV02','AA','DTXDWBH',N'Tốt',9,'19/10/2020','19/12/2020'),
	('1811505210201','GV02','AA','DTXDWBH',N'Khá',7,'19/10/2020','19/12/2020'),
	('1811505210202','GV02','AA','DTCBT',N'Tốt',9,'19/10/2020','19/12/2020'),
	('1811505210301','GV02','AA','DTCBT',N'TB',5,'19/10/2020','19/12/2020'),
	('1811505210302','GV02','AA','DTCBT',N'TB',5,'19/10/2020','19/12/2020')

----------------------------------------------------------------------
-- Hải
-- Nhập Mã đề tài để biết có bao nhiêu đề tài đc thực hiện
CREATE function fnSoLuongDeTai
(
	@Id char(10)
)
returns money
BEGIN
	declare @sl int
	set @sl = (Select count(@Id) from tblChiTietHuongDan where @Id = maDeTai)
	return @sl
END;
SELECT dbo.fnSoLuongDeTai('DTXDWBH')

---- Nhập Mã GV để biết có bao nhiêu sinh viên đc GV Hướng dẫn
CREATE function fnGVHDSoSinhVien
(
	@Id char(10)
)
returns money
BEGIN
	declare @sl int
	set @sl = (Select count(@Id) from tblChiTietHuongDan where @Id = maGiangVien)
	return @sl
END;

SELECT dbo.fnGVHDSoSinhVien('GV01')

-- Thống kê điểm top của SV
CREATE PROC prTopDiem
	@n int
	as 
	BEGIN
		SELECT top (@n)  c.diemSo, c.maSinhVien,c.maGiangVien,c.maDonVi
		FROM tblChiTietHuongDan as c
		GROUP BY c.diemSo,c.maSinhVien,c.maGiangVien,c.maDonVi
		ORDER BY c.diemSo desc
	END;
exec prTopDiem 16

-- Nhập mã sinh viên để biết chi tiết 

CREATE PROC prChiTietSinhVien
  @maSv char(13)
  as
  BEGIN
	SELECT * FROM tblChiTietHuongDan WHERE @maSv = tblChiTietHuongDan.maSinhVien
	END;
exec prChiTietSinhVien '1811505210139'

--- Thống kê số sinh viên tham gia đề tài
CREATE PROC prDeTaiCoSoSV
	as
	BEGIN 
		SELECT a.maDeTai,  count(a.maDeTai) from tblChiTietHuongDan as a 
		GROUP BY a.maDeTai
		ORDER by a.maDeTai desc
	END;
exec prDeTaiCoSoSV
--- Số sinh viên được mỗi DV hướng dẫn
CREATE PROC prDonViCoSoSV
	as
	BEGIN 
		SELECT a.maDonVi,  count(a.maDonVi) from tblChiTietHuongDan as a 
		GROUP BY a.maDonVi
		ORDER by a.maDonVi desc
	END;
	exec prDonViCoSoSV

--- Số sinh viên thực tập tại đơn vị
CREATE PROC prGiangVienCoSoSV
	as
	BEGIN 
		SELECT a.maGiangVien,  count(a.maGiangVien) from tblChiTietHuongDan as a 
		GROUP BY a.maGiangVien
		ORDER by a.maGiangVien desc
	END;
	exec prGiangVienCoSoSV

-- Trigger cho bảng chi tiết hướng dẫn

CREATE TRIGGER dbo.tblChiTietHuongDan_Insert
on tblChiTietHuongDan
after insert 
as 
BEGIN 
	update tblDeTai 
	set soSVThamGia = (SELECT count(c.maDeTai) FROM tblChiTietHuongDan as c Where c.maDeTai = i.maDeTai)
	FROM inserted as i join tblChiTietHuongDan  on i.maDeTai = tblChiTietHuongDan.maDeTai
	WHERE i.maDeTai = tblChiTietHuongDan.maDeTai and i.maDeTai = tblDeTai.maDeTai
END;

CREATE TRIGGER dbo.tblChiTietHuongDan_Update
on tblChiTietHuongDan
after update 
as 
BEGIN 
	update tblDeTai 
	set soSVThamGia = (SELECT count(c.maDeTai) FROM tblChiTietHuongDan as c Where c.maDeTai = i.maDeTai)
	FROM inserted as i join tblChiTietHuongDan  on i.maDeTai = tblChiTietHuongDan.maDeTai
	WHERE i.maDeTai = tblChiTietHuongDan.maDeTai and i.maDeTai = tblDeTai.maDeTai

	update tblDeTai 
	set soSVThamGia = (SELECT count(c.maDeTai) FROM tblChiTietHuongDan as c Where c.maDeTai = d.maDeTai)
	FROM deleted as d join tblChiTietHuongDan  on d.maDeTai = tblChiTietHuongDan.maDeTai
	WHERE d.maDeTai = tblChiTietHuongDan.maDeTai and d.maDeTai = tblDeTai.maDeTai

END;

CREATE TRIGGER dbo.tblChiTietHuongDan_Delete
on tblChiTietHuongDan
after delete 
as 
BEGIN 
	update tblDeTai 
	set soSVThamGia = (SELECT count(c.maDeTai) FROM tblChiTietHuongDan as c Where c.maDeTai = i.maDeTai)
	FROM deleted as i join tblChiTietHuongDan  on i.maDeTai = tblChiTietHuongDan.maDeTai
	WHERE i.maDeTai = tblChiTietHuongDan.maDeTai and i.maDeTai = tblDeTai.maDeTai
END;
---------------------------------------------------------
-- Long
-- Hiện thông tin của đề tài
drop PROCEDURE showDeTai
GO

create proc showDeTai
as
BEGIN
	select DT.maDeTai ,DT.tenDeTai, CD.maChuDe, CD.tenChuDe, K.tenKhoa
	from tblDeTai as DT
	join tblChuDe as CD on CD.maChuDe = DT.maChuDe
	join tblKhoa as K on K.maKhoa = CD.maKhoa
END;
exec showDeTai 
GO

-- Đếm số đề tài mỗi chủ đề
drop PROCEDURE countDeTai
GO

create proc countDeTai
as
BEGIN
	select CD.maChuDe, CD.tenChuDe, count(*) as SoLuongDeTai
	from tblDeTai as DT
	join tblChuDe as CD on CD.maChuDe = DT.maChuDe
	group by CD.maChuDe,  CD.tenChuDe
	order by count(*) DESC
END;
exec countDeTai 
GO

-- Tìm kiếm theo đề tài
drop PROCEDURE findDeTai
GO

create proc findDeTai
	@inputName nvarchar(50) 
as
BEGIN
	select DT.maDeTai ,DT.tenDeTai, CD.maChuDe, CD.tenChuDe, K.tenKhoa
	from tblDeTai as DT
	join tblChuDe as CD on CD.maChuDe = DT.maChuDe
	join tblKhoa as K on K.maKhoa = CD.maKhoa
	where DT.tenDeTai LIKE '%' + @inputName + '%'
END;
exec findDeTai 'online'
GO

-- Tìm kiếm theo chủ đề
drop PROCEDURE findChuDe
GO

create proc findChuDe
	@inputName nvarchar(50) 
as
BEGIN
	select DT.maDeTai ,DT.tenDeTai, CD.maChuDe, CD.tenChuDe, K.tenKhoa
	from tblDeTai as DT
	join tblChuDe as CD on CD.maChuDe = DT.maChuDe
	join tblKhoa as K on K.maKhoa = CD.maKhoa
	where CD.tenChuDe LIKE '%' + @inputName + '%'
END;
exec findChuDe 'website'
GO

-- insert tblDeTai
create trigger insertDeTai
on tblDeTai
after insert
as 
begin
	update tblChuDe
	set soLuongDeTai = (select count(*) from tblDeTai where tblDeTai.maChuDe = i.maChuDe)
	from inserted as i
	where tblChuDe.maChuDe = i.maChuDe
end
go

--Test Trigger
insert into tblDeTai
values ('DTCBT6',N'Đồ án cầu bê tông cốt thép6','CDBTCT',6,N'Được duyệt')
select * from tblChuDe
select * from tblDeTai






	