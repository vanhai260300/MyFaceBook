<?php
session_start();
unset($_SESSION['sanpham'][$_GET['id']]);
header('Location: giohang.php');
?>