use QLDoAnSV
go

 ---đếm số sv được hướng dẫn bỡi các gvhd
  CREATE FUNCTION fn_DemSoSinhVien(@magv char(10)) 
RETURNS int AS 
BEGIN 
 DECLARE @ret int; 
 SELECT @ret = count(*) 
 FROM tblChiTietHuongDan 
 WHERE maGiangVien = @magv; 
 IF (@ret IS NULL) 
   SET @ret = 0; 
 RETURN @ret; 
END
select dbo.fn_DemSoSinhVien('GV01')
---đếm số sv thực tập tại mỗi đơn vị
CREATE FUNCTION fn_DemSoSinhVien22(@madv char(10)) 
RETURNS int AS 
BEGIN 
 DECLARE @ret int; 
 SELECT @ret = count(*) 
 FROM tblChiTietHuongDan 
 WHERE maDonVi = @madv 
 IF (@ret IS NULL) 
   SET @ret = 0; 
 RETURN @ret; 
END
select dbo.fn_DemSoSinhVien22('FPT')
---hiển thị danh sách thông tin của sinh viên theo gvhd
CREATE FUNCTION fn_DanhSachSinhVien (@magv char(10)) 
RETURNS TABLE AS RETURN 
( 
 SELECT * 
 FROM tblChiTietHuongDan 
 WHERE  maGiangVien= @magv 
);
select * from dbo.fn_DanhSachSinhVien('GV01')
---hiển thị danh sách thông tin của sinh viên theo đơn vị
CREATE FUNCTION fn_DanhSachSinhVien22 (@madv char(10)) 
RETURNS TABLE AS RETURN 
( 
 SELECT   tenSinhVien, maLop, maDeTai
 FROM  tblChiTietHuongDan,tblSinhVien
 WHERE  maDonVi= @madv AND tblChiTietHuongDan.maSinhVien=tblSinhVien.maSinhVien
);
select * from dbo.fn_DanhSachSinhVien22('FPT')