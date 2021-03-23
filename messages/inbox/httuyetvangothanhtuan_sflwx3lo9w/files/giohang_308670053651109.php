<?php session_start(); ?>
<!DOCTYPE html>
<html>

<head>
  <meta charset="utf-8">
  <meta http-equiv="X-UA-Compatible" content="IE=edge">
  <title>Zent - Education And Technology Group</title>
  <!-- Latest compiled and minified CSS -->
  <link rel="stylesheet" href="http://netdna.bootstrapcdn.com/bootstrap/3.1.1/css/bootstrap.min.css">

   <!-- Data table -->
   <link type="text/css" rel="stylesheet" href="https://cdn.datatables.net/1.10.20/css/jquery.dataTables.min.css">
  <script src="https://code.jquery.com/jquery-3.3.1.js"></script>
  <script src="https://cdn.datatables.net/1.10.20/js/jquery.dataTables.min.js"></script>
  <!-- Optional theme -->
  <link rel="stylesheet" href="http://netdna.bootstrapcdn.com/bootstrap/3.1.1/css/bootstrap-theme.min.css">

  <!-- Latest compiled and minified JavaScript -->
  <script src="http://netdna.bootstrapcdn.com/bootstrap/3.1.1/js/bootstrap.min.js"></script>

</head>

<body>
  <div class="container">
    <h3 align="center">DXD</h3>
    <a href="index.php" type="button" class="btn btn-primary">Thêm mới</a>
    <hr>
    <?php if(isset($_COOKIE['msg']))
        echo $_COOKIE['msg'];
        //session_destroy();
    ?>
    <table class="table" id="example">
      <thead>
        <tr>
          <th scope="col">ID</th>
          <th scope="col">Tên SP</th>
          <th scope="col">Số lượng</th>
          <th scope="col">Đơn giá</th>
          <th scope="col">Thành tiến</th>
          <th scope="col"></th>
        </tr>
      </thead>
      <tbody>
        <?php
        $count =0;
        $so = 0;
        
         foreach ($_SESSION['sanpham'] as $sanpham)
        { 
          $count = $count +   $sanpham['thanhtien'] ;
          $so = $so + 1;
          ?>
          <tr>
            <th scope="row"><?= $sanpham['id'] ?></th>
            <td><?= $sanpham['title'] ?></td>
            <td><?= $sanpham['soluong'] ?></td>
            <td><?= $sanpham['price'] ?></td>
            <td><?= $sanpham['thanhtien'] ?></td>
            <td>
            <a href="delete.php?id=<?= $sanpham['id'] ?>"  type="button" class="btn btn-warning">Xóa</a>
            <a href="update.php?id=<?= $sanpham['id'] ?>"  type="button" class="btn btn-warning">Thêm</a>
            <a href="delete_all.php?id=<?= $sanpham['id'] ?>" onclick="return confirm('Bạn có thật sự muốn xóa sản phẩm ?');" type="button" class="btn btn-warning">Xóa Hết</a>
            </td>
          </tr>
        <?php }
        echo "Tổng tiền: ".$count."<br>";
        echo "Số sản phẩm: ".$so;
        ?>
      </tbody>
    </table>
    <script>
      $(document).ready(function() {
        $('#example').DataTable();
      });
    </script>
  </div>
</body>
?>
</html>