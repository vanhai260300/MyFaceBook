<?php 
    session_start();
    require_once('connection.php');
    $arr = array();
    $id = $_GET['id'];
    $query =  "SELECT * from books where id = $id";

    $result = $conn->query($query);
    
    
    $data = $result->fetch_assoc();

    if(isset($_SESSION['sanpham'][$_GET['id']])){
        $arr = $_SESSION['sanpham'][$_GET['id']];
        $arr['soluong'] = $arr['soluong']+1;
        $arr['thanhtien'] = $arr['soluong']*$arr["price"];
        $_SESSION['sanpham'][$_GET['id']] = $arr;
    }else{
    $arr['id'] = $data['id'];
    $arr['title'] = $data['title'];
    $arr['price'] = $data['price'];
    $arr['author']= $data['author'];
    $arr['soluong'] = 1;
    $arr['thanhtien'] = $data['price'];
    $_SESSION['sanpham'][$_GET['id']] = $arr;
    }
    header('Location:giohang.php');
?>