---Hiển thị 5 sản phẩm bán chạy nhất
select top 5 *
from tblReceiptNoteDetail
order by QtyReceipted desc
---Hiển thị những sản phẩm chưa từng bán được
select *
from tblProduct
where ProductID not in ( select ProductID from tblOrderInvoiceDetail )
---Hiển thị những đơn hàng đã giao thành công, thông tin  cụ thể
select distinct c.CustID, c.CustAddress, c.Email
from tblCustomer as c, tblOderInvoice as o
where DelStatusReceived like N'Bình Thường'and o.CustNo = c.CustID
---Hiển thị những đơn hàng của khách hàng ở Đà Nẵng, Quảng Nam
select c.CustAddress,c.CustID,c.CustName
from tblCustomer as c, tblOderInvoice as O
where c.CustAddress in (N'Đà Nẵng', N'Quảng Nam')and o.CustNo = c.CustID
---Hiển thị những đơn hàng có giá 500000 và nhỏ hơn 2 triệu
select OrderID 
from tblOderInvoice
where OrderTotalMoney > 500000 and OrderTotalMoney < 2000000
---Hiển thị những nhà cung cấp đã từng cung cấp hàng
select *
from tblSupplier
where SuppID in (select SuppNo from tblReceiptNote)
---Hiển thị 2 phiếu nhập có tổng tiền cao nhất
select top 2 *
from tblReceiptNote
order by RepTotalMoney desc
---Hiển thị tổng tiền nhập hàng trong tháng 8/2019
select SUM(RepTotalMoney) as 'Tổng tiền' 
from tblReceiptNote
where MONTH(RepDate)= 8
---Hiển thị tổng số lượng từng sản phẩm đã nhập về
select ProductID, SUM(QtyReceipted) as 'Tổng Số lượng'
from tblReceiptNoteDetail
group by ProductID