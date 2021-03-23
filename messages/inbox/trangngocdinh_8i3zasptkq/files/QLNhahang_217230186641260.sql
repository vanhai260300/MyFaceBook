						﻿
CREATE DATABASE QLNhaHang
GO
USE QLNhaHang
GO
CREATE TABLE Ban(
	maBan char(4) PRIMARY KEY CHECK([maban] LIKE'[a-z][a-z][0-9][0-9]'),
	vitri nvarchar(50) NULL,
	soghe int NULL check  (([soghe]>(0))),
	trangthai VARCHAR(10) NOT NULL CHECK (trangthai IN('C', 'K')) default 'K'
)

GO

INSERT INTO Ban(maBan,vitri,soghe,trangthai)
  VALUES('MB01',N'Sân ',6,DEFAULT),
  ('MB02',N'Sân',2,DEFAULT),
  ('MB03',N'Sân ',1,DEFAULT)
	
GO


CREATE TABLE Monan(
	Mamonan char(3)  PRIMARY KEY CHECK  (([mamonan] like '[a-z][0-9][0-9]')) ,
	tenmon nvarchar(50) NOT NULL,
)


INSERT INTO Monan(Mamonan,tenmon)

	VALUES ('C01',N'Cá lóc chiên xù'),
	 ('B01',N'Rau muống xào tỏi'),
	  ('K01',N'Thịt bò kho khế'
)
	



CREATE TABLE HD_Datmon(
	Madatmon char(4)  PRIMARY KEY CHECK  (([Madatmon] like '[a-z][0-9][0-9][0-9]')) ,
	ngaydat datetime not NUll,
	tongtien decimal,
	ghichu  nvarchar(50) NUll,
	maBan char(4) FOREIGN KEY([maBan])REFERENCES Ban([maBan]),
)

GO

INSERT INTO HD_Datmon(Madatmon,ngaydat,tongtien,ghichu,maBan)

	VALUES ('A001',2020/27/12,300000,'MB01'),
	('A002',2020/27/12,300000,'MB02'),
	('A003',2020/27/12,300000,'MB03')
		
GO

CREATE TABLE Chitietdatmon(
	Madatmon char(4)  FOREIGN KEY([Madatmon])REFERENCES HD_Datmon ([Madatmon]),
	Mamonan char(3)  FOREIGN KEY([Mamonan])REFERENCES Monan ([Mamonan]),
	giatien decimal NULL,
	soluong int
)

GO
INSERT INTO Chitietdatmon(Madatmon,Mamonan,giatien,soluong)
	VALUES ('A001','C01',60000,3),
	('A002','B01',60000,3),
	('A003','K01',60000,3)	
Go