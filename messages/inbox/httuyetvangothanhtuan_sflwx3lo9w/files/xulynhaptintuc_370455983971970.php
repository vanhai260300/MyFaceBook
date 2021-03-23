<?php
require("../connect/connect.php");

// thêm mới tin tức
if(isset($_POST['btn_addtt'])){
	$ngaynhap = date('Y-m-d');	
    $file_name=$_FILES['txt_AnhTinTuc']['name'];
	$file_path=$_FILES['txt_AnhTinTuc']['tmp_name'];
	if($file_name!=''){
	$new_path="./images/".$file_name;
	$uploaded_file=move_uploaded_file($file_path,$new_path);
	}
    $tieude = $_POST['txt_tieude'];
    $noidung = $_POST['txt_noidung'];
    $trangthai = $_POST['txt_trangthai'];
    $sql_insert_tt = "insert into tbl_tintuc (MaTT, NgayNhap, AnhTinTuc, TieuDe, NoiDungTT, TrangThai) 
    values (null, '$ngaynhap', '$new_path', '$tieude', '$noidung', '$trangthai')";
	if(mysqli_query($con, $sql_insert_tt))
	{
		echo "<script language='javascript'>alert('Thêm thành công');";
		echo "location.href='index.php?nc=tintuc';</script>";

	}
	else
	{
		echo 'Lỗi: ',mysqli_error($link);
	}

}

// sửa tin tức
if(isset($_POST['btn_updatett'])){
    $matt_update = $_POST['txt_matt'];
	$ngaynhap = date('Y-m-d');

	$file_name=$_FILES['txt_AnhTinTuc']['name'];
	$file_path=$_FILES['txt_AnhTinTuc']['tmp_name'];
	if($file_name!=''){
	$new_path="./images/".$file_name;
	$uploaded_file=move_uploaded_file($file_path,$new_path);
	}
    $tieude = $_POST['txt_tieude'];
    $noidung = $_POST['txt_noidung'];
    $trangthai = $_POST['txt_trangthai'];
    $sql_update_tt = "update tbl_tintuc set NgayNhap = '$ngaynhap', AnhTinTuc = '$new_path',  TieuDe = '$tieude', NoiDungTT = '$noidung', TrangThai = '$trangthai' where MaTT='$matt_update'";
	if(mysqli_query($con, $sql_update_tt))
	{
		echo "<script language='javascript'>alert('sửa thành công');";
		echo "location.href='index.php?nc=tintuc';</script>";

	}
	else
	{
		echo 'Lỗi: ',mysqli_error($link);
	}
}

// xóa tin tức
if (isset($_GET["action"])) {
	if ($_GET["action"] == "delete") {
		$id_item = $_GET["matt"];
		$sql = "DELETE from tbl_tintuc where MaTT=" . $id_item . "";
		if(mysqli_query($con, $sql))
		{
			echo "<script language='javascript'>alert('xóa thành công');";
			echo "location.href='index.php?nc=tintuc';</script>";

		}
		else
		{
			echo 'Lỗi: ',mysqli_error($link);
		}
			
		}
}
?>