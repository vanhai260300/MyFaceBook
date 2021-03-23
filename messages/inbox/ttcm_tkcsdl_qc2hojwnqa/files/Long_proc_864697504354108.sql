use QLDoAnSV
go

--Hiện thông tin của đề tài
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

--Đếm số đề tài mỗi chủ đề
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

--Tìm kiếm theo đề tài
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

--Tìm kiếm theo chủ đề
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