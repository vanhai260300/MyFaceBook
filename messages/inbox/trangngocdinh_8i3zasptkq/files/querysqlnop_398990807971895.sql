﻿
CREATE DATABASE QLHocVien
GO
USE QLHocVien
GO
CREATE TABLE HocVien(
	maHV char(4) PRIMARY KEY CHECK([maHV] LIKE'[HV[0-9][0-9]%'),
	tenHV nvarchar(50) NULL,
	Diachi nvarchar(100) NULL,
	email nchar(50) NULL check([email] like '%_@__%.__%'),
	sdt nchar(10) NULL unique,
	Gioitinh VARCHAR(10) NOT NULL CHECK (Gioitinh IN('nam', 'nu')) default 'nam'
)

GO

INSERT INTO HocVien(maHV,tenHV,Diachi,email,sdt,Gioitinh)
  VALUES('HV01',N'Đinh Ngọc Trang',N'Quảng Bình','dinhngoctrang@gmail.com',0337102561,DEFAULT),
  ('HV02',N'Nguyễn Văn Hải',N'Quảng Trị','nguyenvanhai@gmail.com',0337102581,DEFAULT),
  ('HV03',N'Trương Văn Huy',N'Hà Tĩnh','truongvanhuy@gmail.com',0337102562,DEFAULT)
		

GO

CREATE TABLE Lop(
	maLop char(3)  PRIMARY KEY CHECK  (([maLop] like '[a-z][0-9][0-9]')) ,
	tenlop nvarchar(50) NOT NULL,
	soluong int CHECK  (([soluong]>(0))),
)

GO

INSERT INTO Lop(maLop,tenlop,soluong)

	VALUES ('A01',N'Lập Trình java nâng cao',3),
		('A02',N'Lập Trình C',5),
		('B01',N'TH Lập Trình C',6)

GO

CREATE TABLE HV_Lop(
	maHV char(4)  FOREIGN KEY([maHV])REFERENCES HocVien ([maHV]),
	maLop char(3)  FOREIGN KEY([maLop])REFERENCES Lop ([maLop]),
	ngaydangki datetime NULL,
	tiendatra decimal NULL,
	Description nvarchar(50) NULL
)

GO
INSERT INTO HV_Lop(maHV,maLop,ngaydangki,tiendatra,Description)
	VALUES ('HV01','A01',2020/12/27,680000,N'Đã Thanh Toán'),
	('HV02','A01',2020/12/27,680000,N'Đã Thanh Toán'),
	('HV03','B01',2020/12/27,680000,N'Đã Thanh Toán')
Go

			