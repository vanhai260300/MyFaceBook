<?php
session_start();
require_once('connection.php');
$query =  "SELECT * from books";

$result = $conn->query($query);

$data = array();

while ($row = $result->fetch_assoc()) {
    $data[] = $row;
}

?>
<!DOCTYPE html>
<html>

<head>
    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <title>DXD</title>
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
        <h3 align="center">Danh sách sản phẩm</h3>
        <a href="giohang.php" type="button" class="btn btn-primary">Xem giỏ hàng</a>
        <hr>
        <table class="table" id="example">
            <thead>
                <tr>
                    <th scope="col">ID</th>
                    <th scope="col">Tên sách</th>
                    <th scope="col">Tác giả</th>
                    <th scope="col">Gía sách</th>
                    <th scope="col"></th>
                </tr>
            </thead>
            <tbody>
            <?php foreach ($data as $row) { ?>
                <tr>
                    <th scope="row"><?=$row['id']?></th>
                    <td><?=$row['title']?></td>
                    <td><?=$row['author']?></td>
                    <td><?=$row['price']?></td>
                    <td>
                        <a href="add_sp.php?id=<?=$row['id']?>" type="button" class="btn btn-default">Thêm vào giỏ hàng</a>
                    </td>
                </tr>
            <?php } ?>
            </tbody>
        </table>
        <script>
            $(document).ready(function() {
                $('#example').DataTable();
            });
        </script>
    </div>
</body>

</html>