<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>De Chan</title>
</head>
<body>
    <?php 
        
        function soThapPhan($number) {
            if (is_numeric($number)) {
               return bindec($number);
            } else if ($number == "") {
                return("Khong duoc de trong");
            } else {
                return("Khong cho nhap ki tu");
            }
        }

        echo("Ket qua chuyen doi la: " . soThapPhan($_POST["number"]));
    ?>
</body>
</html>