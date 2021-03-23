use VDHL_24
go
--Bai 1
create function fnBai1
(
	@ID char(7)
)
returns money
begin
	declare @amount money
	set @amount = (select sum(amount) from tblOrderInvoiceDetail where OrderID = @ID group by OrderID)
return @amount
end
go
select dbo.fnBai1('OI001')
go
--Bai 2
create function fnBai2
(
	@ID char(7),
	@qty int,
	@discount dec(4,2)
)
returns money
begin
	declare @amount money
	set @amount =   (select @qty * P.UnitPrice * (1 -@discount) 
					from tblProduct as P 
					where P.ProductID = @ID)
	return @amount
end
go
select dbo.fnbai2('PT001', 2, 0.3)
go
--Bai3
create function fnBai3
(
	@month int,
	@year int
)
returns money
begin
	declare @amount money
	set @amount = (select sum(O.OrderTotalMoney) 
				  from tblOrderInvoice as O
				  where year(O.DatePaid) = @year and month(O.DatePaid) = @month)
	return @amount
end
go
select dbo.fnBai3(11,2019)
go
