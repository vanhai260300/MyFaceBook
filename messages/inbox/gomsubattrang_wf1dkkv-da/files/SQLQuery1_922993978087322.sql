create table SinhVien
(
	MaSV	char(13) not null primary key,
	HoTen	nvarchar(100)not null,
	DoB		date not null,
	Passwords	nchar(10) not null,
	MaNganh	char(5),
	DiaChi	nvarchar(100),
	SDT		char(11),
	CMND	char(9),
)
create table SVLHP
(
	IDStudent	char(13) not null,
	IDLHP		char(10) not null,
	primary key(IDStudent,IDLHP),
	Diem		decimal(3,1),
)
create table LopHP
(
	TenLHP	char(10) not null primary key,
	MaHP	char(7) not null,
	MaGV	char(7) not null,
	Phong	char(4) not null,
	Thu		int not null,
	Tu		int not null,
	Den		int,
	SSMax	int,
	SSDangKy int,
	MaHK	int,
)
create table HocPhan
(
	MaHP	char(7) not null primary key,
	TenHP	nvarchar(100) not null,
	SoTC	int not null, 
)