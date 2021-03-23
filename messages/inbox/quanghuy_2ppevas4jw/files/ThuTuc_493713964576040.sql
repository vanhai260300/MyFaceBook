--Viết các thủ tục:
--1. Tăng tự động các column ID cho tất cả các table được  sinh từ thực thể mạnh
select * from tblProduct
create proc prAutoProduct
	@c char(6)  out
as
begin
	set @c = (select top 1 ('MSP' + format((right(ProductID,3)+1),'D3'))
	from tblProduct
	order by ProductID desc)
end;

declare @c char(6)
exec prAutoProduct  @c out
print @c

--2. Thống kê các sản phảm bán chạy (có tham số vào)
select * from tblOrderInvoice
create proc prBestSale
	@top int
as
begin
	select top(@top) ProductID,sum(QtyOrdered) as SLB
	from tblOrderInvoice
	group by ProductID
	order sum(QtyOrdered) desc
end;
exec prBestSale 3
--3. Những tháng có danh thu trên 200000(có tham số vào là định mức tiền)
create proc prtolalMoney
	@m money 
as
begin
	select month(OrderDate),sum(OrderTotalMoney)  
	from tblOderInvoice
	group by month(OrderDate)
	having sum(OrderTotalMoney)  > (@m)
end;
exec prtolalMoney 20000
--4. Thống kê số lượng khách mua hàng theo từng Tỉnh/Thành phố(Sắp xếp giảm dẫn)
create proc prCustNo
as
begin
	select count(CustNo) as SL,OrderAddress
	from tblOderInvoice
	group by OrderAddress
	order by SL desc
end;
exec prCustNo
--5. Thống kê giá TB,giá max, giá min ở các phiếu nhập hàng cho mỗi SP
create proc prMinMax
as
begin
	select max(RepPrice) as giaMax, min(RepPrice) as giaMin,avg(RepPrice) as TB
	from tblReceiptNoteDetail
	group by ProductID
end;
exec prMinMax
select *
from tblReceiptNoteDetail
--6. Thống kê số lần khách hàng mua hàng (sắp xếp giảm dần)
create proc prAmount_Buy 
	
as
BEGIN
	select COUNT(CustNo) as SLMua, CustNo
	from tblOrderInvoice
	group by CustNo
	order by  SLMua desc
END;
exec prAmount_Buy
