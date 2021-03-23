use VDHL_22
go
--Thiet lap Identity
create proc prCauA
	@key char(6) output
as
BEGIN
	set @key = 'NUM' + format((select top 1 (RIGHT(C.CustID, 3) + 1)
							  from tblCustomer as C order by C.CustID DESC),'D3')
END;
declare @maxpaine char(6)
exec prCauA @maxpaine output
print @maxpaine 
GO

--Thong ke cac san pham ban chay 
create proc prCaub
	@top int 
as
BEGIN
	select top (@top) ProductID, sum(QtyOrdered) as SL
	from tblOrderInvoiceDetail
	group by ProductID
	order by sum(QtyOrdered) DESC
END;
exec prCaub 5
GO

--Nhung thang co doanh thu tren 200.000
create proc prCauC
	@tien money 
as
BEGIN
	select month(OrderDate), sum(OrderTotalMoney) as TongTien
	from tblOrderInvoice
	group by month(OrderDate)
	having sum(OrderTotalMoney) >= @tien
END;
exec prCauC 200000
GO

--Thong ke khach theo tung thanh pho, sap xep giam dan
create proc prCauD
as
BEGIN
	select TT.maTT, TT.tenTT, count(*) as SLKhach
	from tblCustomer as C
	join tblPhuongXa as PX on PX.maPX = C.CustAddress
	join tblQuanHuyen as QH on QH.maQH = PX.thuocQuanHuyen
	join tbltinhThanh as TT on TT.maTT = QH.thuocTinhThanh 
	group by TT.maTT, TT.tenTT
	order by count(*) DESC
END;
exec prCauD 
GO

--Thong ke gia trung binh/ min/ max o cac phieu nhap hang cho moi san pam
--max
create proc prCauE1
as
BEGIN
	select P.ProductID, P.Name, max(R.RepPrice)
	from tblReceptNoteDetail as R 
	join tblProduct as P
	on P.ProductID = R.ProductID
	group by P.ProductID, P.Name
	order by max(R.RepPrice) DESC
END;
exec prCauE1 
GO

--min
create proc prCauE2
as
BEGIN
	select P.ProductID, P.Name, min(R.RepPrice)
	from tblReceptNoteDetail as R 
	join tblProduct as P
	on P.ProductID = R.ProductID
	group by P.ProductID, P.Name
	order by max(R.RepPrice) DESC
END;
exec prCauE2 
GO

--average
create proc prCauE3
as
BEGIN
	select P.ProductID, P.Name, avg(R.RepPrice)
	from tblReceptNoteDetail as R 
	join tblProduct as P
	on P.ProductID = R.ProductID
	group by P.ProductID, P.Name
	order by max(R.RepPrice) DESC
END;
exec prCauE3 
GO

--thong ke so lan khach hang mua hang
create proc prCauF
as
BEGIN
	select C.CustID, C.CustName, count(*) as 'So lan mua hang'
	from tblOrderInvoice as O
	join tblCustomer as C
	on C.CustID = O.CustNo
	group by C.CustID, C.CustName
	order by count(*) DESC
END;
exec prCauF 
GO