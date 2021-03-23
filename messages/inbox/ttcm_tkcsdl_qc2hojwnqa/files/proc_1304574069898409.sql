--PRO
--1.Viết thủ tục hiển thị danh sách sinh viên thuộc từng lớp
use QLDoAnSV
create proc prDanhSachSV
@lop varchar(10)
as
select maSinhVien,tenSinhVien,gioiTinh,ngaySinh,queQuan,diaChi,email,maLop
from tblSinhVien
where maLop= @lop

exec prDanhSachSV '18T1'

--2.Viết thủ tục đếm số lượng lớp của từng khoa

create proc prDemSLLop
@khoa varchar(10)
as	
select tblLop.maLop, count(*) as SoLuong 
from tblLop,tblKhoa
where tblKhoa.maKhoa=tblLop.maKhoa and tblLop.maKhoa=@khoa
group by tblLop.maLop

exec prDemSLLop 'DDT'

--3.Tạo thủ thủ tục hiển thị thông  tin sinh viên( mã sinh viên, tên sinh viên, giới tính, ngày sinh,quê quán, địa chỉ,email,mã lớp),
--theo mã sinh viên

create proc prThongTinSV 
@maSV char(13)
as
	select maSinhVien,tenSinhVien,gioiTinh,ngaySinh,queQuan,diaChi,email,maLop
	from tblSinhVien
	where tblSinhVien.maSinhVien=@maSV

exec prThongTinSV '1811505210221'

--4.Viết thủ tục tìm kiếm sinh viên theo tên

create proc prSearchSV
@tenSV nvarchar(50)
as
begin
	select *
	from tblSinhVien
	where tenSinhVien like '%' + @tenSV +'%'
end

exec prSearchSV N'Vân'

--FUNCTION
--1.Tạo function cho biết số lượng sinh viên của một lớp ,với mã lớp là tham số
drop function fnDemSLSV
create function fnDemSLSV 
(
  @maLop char(10)
)
returns int as
begin
	declare @dem int;
	select @dem = count (tblSinhVien.maLop)
	from tblSinhVien 
	where tblSinhVien.maLop=@maLop
	return @dem;
end

select *from tblSinhVien
select dbo.fnDemSLSV('18T1') as SoLuongSinhVien

--2.Tạo function cho biết số lượng sinh viên thuộc từng tỉnh thành,queQuan là tham số

create function fnSLSVtheoQueQuan
(
 @queQuan nvarchar(50)
)
returns int as
begin
	declare @dem int;
	select @dem = count (tblSinhVien.queQuan)
	from tblSinhVien
	where tblSinhVien.queQuan=@queQuan
	return @dem;
end

select *from tblSinhVien
select dbo.fnSLSVtheoQueQuan(N'Quảng Trị') as SoLuongSinhVien

--TRIGGER
--1.Hãy viết trigger để tự động cập nhật lại Số SV (cộng thêm 1) của 1 lớp ở bảng Lớp khi
--thêm 1 sinh viên của lớp đó vào  bảng Sinhvien. 
create trigger trgLopInsert
on tblSinhVien
after Insert
as
begin
	declare @maSV char(13),
			@tenSV nvarchar(50),
			@gioitinh nvarchar(5),
			@ngaySinh datetime,
			@queQuan nvarchar(50),
			@diaChi nvarchar(50),
			@email varchar(50),
			@maLop varchar(10)
	select @maSv=maSinhVien,@tenSV=tenSinhVien,@gioitinh=gioiTinh,@ngaySinh=ngaySinh,@queQuan=queQuan,@diaChi=diaChi,@email=email,@maLop=maLop
	from Inserted

	update tblLop
	set soSinhVien=soSinhVien + 1
	where maLop=@maLop
end

insert into tblSinhVien
values
	('1811505210505',N'Nguyễn Văn Tùng','Nam','03-03-2000',N'Quảng Trị',N'12 Ông Ích Khiêm','nvt2000@gmail.com','18T2'), 
	('1811505210515',N'Nguyễn Thị Mai',N'Nữ','03-03-2000',N'Quảng Trị',N'12 Ông Ích Khiêm','ntm2000@gmail.com','18T2'),
	('1811505210516',N'Nguyễn Thị Quỳnh',N'Nữ','03-03-2000',N'Quảng Trị',N'12 Ông Ích Khiêm','ntq2000@gmail.com','18T2')

select * from tblLop




