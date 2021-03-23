create trigger dbo.ReceiptNoteDetail_INSERT_ONLY_ALLOW_ONE_REPID_PER_INSERT
on tblReceiptNoteDetail
after insert
as
BEGIN
	IF (select count(R.ID) from (select RepID as ID from inserted group by RepID) as R)=1
	BEGIN
		update tblReceiptNote
		set RepTotalMoney = (
							select sum(RepPrice*QtyReceipted)
							from tblReceiptNoteDetail as rnd
							where rnd.RepID = i.RepID
							)
		from inserted as i
			join tblReceiptNoteDetail as rnd
			on i.RepID = rnd.RepID
		where i.RepID = tblReceiptNote.RepID and i.RepID = rnd.RepID
		update tblProduct
		set UnitPrice = i.RepPrice*1.3,
			QtyOnHand = QtyOnHand + i.QtyReceipted
		from inserted as i
			join tblReceiptNoteDetail as rnd
			on i.ProductID = rnd.ProductID and i.RepID = rnd.RepID
		where tblProduct.ProductID = i.ProductID and i.ProductID = rnd.ProductID
	END
	ELSE ROLLBACK TRANSACTION
END

--drop trigger dbo.ReceiptNoteDetail_INSERT
GO
--Trigger bình thường (chỉ khi thay đổi những record của cùng 1 RepID)
create trigger dbo.ReceiptNoteDetail_UPDATE_ONLY_ALLOW_ONE_REPID_PER_UPDATE
on tblReceiptNoteDetail
after update
as
BEGIN
	IF (select count(R.ID) from (select RepID as ID from inserted group by RepID) as R)=1
	BEGIN
		update tblReceiptNote
		set RepTotalMoney = (
							select sum(RepPrice*QtyReceipted)
							from tblReceiptNoteDetail as rnd
							where rnd.RepID = i.RepID
							)
		from inserted as i
			join tblReceiptNoteDetail as rnd
			on i.RepID = rnd.RepID
		where i.RepID = tblReceiptNote.RepID and i.RepID = rnd.RepID

		update tblProduct
		set UnitPrice = i.RepPrice*1.3,
			QtyOnHand = QtyOnHand + i.QtyReceipted - d.QtyReceipted
		from inserted as i
			join tblReceiptNoteDetail as rnd on i.ProductID = rnd.ProductID and i.RepID = rnd.RepID
			join deleted as d on d.ProductID = rnd.ProductID and d.RepID = rnd.RepID
		where tblProduct.ProductID = i.ProductID and i.ProductID = rnd.ProductID
	END
	ELSE ROLLBACK TRANSACTION
END
GO

--drop trigger dbo.ReceiptNoteDetail_DELETE_ONLY_ALLOW_ONE_REPID_PER_DELETE
create trigger dbo.ReceiptNoteDetail_DELETE_ONLY_ALLOW_ONE_REPID_PER_DELETE
on tblReceiptNoteDetail
after delete
as
BEGIN
	IF (select count(R.ID) from (select RepID as ID from deleted group by RepID) as R)=1
	BEGIN
		update tblReceiptNote
		set RepTotalMoney = (
							select sum(RepPrice*QtyReceipted)
							from tblReceiptNoteDetail as rnd
							where rnd.RepID = d.RepID
							)
		from deleted as d
			join tblReceiptNoteDetail as rnd
			on d.RepID = rnd.RepID
		where d.RepID = tblReceiptNote.RepID and d.RepID = rnd.RepID
		update tblProduct
			set QtyOnHand = QtyOnHand - i.QtyReceipted
		from deleted as i
		where tblProduct.ProductID = i.ProductID
		IF EXISTS (select * from tblProduct where QtyOnHand < 0) ROLLBACK TRANSACTION
	END
	ELSE ROLLBACK TRANSACTION
END
