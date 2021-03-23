use Accel_3
go
--bai 1 insert
create trigger trgBai1Insert
on tblOrderInvoiceDetail
after insert
as 
begin
	update tblOrderInvoice
	set OrderTotalMoney = (select sum(amount) from tblOrderInvoiceDetail where OrderID = i.OrderID)
	from inserted as i
	where tblOrderInvoice.OrderID = i.OrderID
	update tblProduct
	set QtyOnhand = QtyOnhand - i.QtyOrdered
	from inserted as i
	where tblProduct.ProductID = i.ProductID
	update tblOrderInvoiceDetail
	set Amount = p.UnitPrice * i.QtyOrdered
	from tblProduct as p, inserted as i
	where p.ProductID = i.ProductID and tblOrderInvoiceDetail.OrderID = i.OrderID and tblOrderInvoiceDetail.ProductID = i.ProductID
	if exists(select * from tblProduct where QtyOnHand < 0)
		rollback transaction
end
go
-- Bai 1 delete
create trigger trgBai1Delete
on tblOrderInvoiceDetail
after delete
as 
begin
	update tblProduct
	set QtyOnhand = QtyOnhand + d.QtyOrdered
	from deleted as d
	where tblProduct.ProductID = d.ProductID
	update tblOrderInvoice
	set OrderTotalMoney = (select sum(amount) from tblOrderInvoiceDetail where OrderID = d.OrderID)
	from deleted as d
	where tblOrderInvoice.OrderID = d.OrderID
	if exists(select * from tblProduct where QtyOnHand < 0)
		rollback transaction
end
go
--Bai 1 update
create trigger trgBai1Update
on tblOrderInvoiceDetail
after update
as
begin
	update tblProduct
	set QtyOnhand = QtyOnhand + d.QtyOrdered - i.QtyOrdered
	from inserted as i, deleted as d
	where tblProduct.ProductID = i.ProductID
	update tblOrderInvoiceDetail
	set Amount = i.QtyOrdered * p.UnitPrice
	from inserted as i, tblProduct as p, deleted as d
	where tblOrderInvoiceDetail.ProductID = d.ProductID and tblOrderInvoiceDetail.OrderID = d.OrderID and p.ProductID = d.ProductID
	update tblOrderInvoice
	set OrderTotalMoney = (select sum(amount) from tblOrderInvoiceDetail where OrderID = d.OrderID)
	from deleted as d
	where tblOrderInvoice.OrderID = d.OrderID
	if exists(select * from tblProduct where QtyOnHand < 0)
		rollback transaction
end
go
--Bai 2 insert
create trigger trgBai2Insert
on tblReceptNoteDetail
after insert
as
begin
	update tblProduct
	set QtyOnHand = QtyOnHand + i.Qtyrecepted, UnitPrice = i.RepPrice * 1.3
	from inserted as i
	where tblProduct.ProductID = i.ProductID
	update tblReceptNote
	set RepTotalMoney = (select sum(Qtyrecepted * RepPrice) from tblReceptNoteDetail where RepID = i.RepID )
	from inserted as i
	where tblReceptNote.RepID = i.RepID
end
go
--Bai 2 delete
create trigger trBai2Delete
on tblReceptNoteDetail
after delete
as
begin
	update tblProduct
	set QtyOnHand = QtyOnHand - d.Qtyrecepted 
	from deleted as d
	where tblProduct.ProductID = d.ProductID
	update tblReceptNote
	set RepTotalMoney = (select sum(Qtyrecepted * RepPrice) from tblReceptNoteDetail where RepID = d.RepID )
	from deleted as d
	where tblReceptNote.RepID = d.RepID
end
go
--Bai 2 update
create trigger trgBai2Update
on tblReceptNoteDetail
after update
as 
begin
	update tblProduct
	set QtyOnHand = QtyOnHand - d.Qtyrecepted + i.Qtyrecepted, UnitPrice = i.RepPrice * 1.3
	from deleted as d, inserted as i
	where tblProduct.ProductID = i.ProductID
	update tblReceptNote
	set RepTotalMoney = (select sum(Qtyrecepted * RepPrice) from tblReceptNoteDetail where RepID = d.RepID )
	from deleted as d
	where tblReceptNote.RepID = d.RepID
end
go
--check
select * from tblReceptNoteDetail
select * from tblReceptNote
select * from tblProduct
select * from tblOrderInvoice
select * from tblOrderInvoiceDetail
go