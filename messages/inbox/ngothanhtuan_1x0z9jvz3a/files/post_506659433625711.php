<?php 
    function formatNumber($numberFloat) {
        $symbol = 'đ';
        $symbol_thousand = '.';
        $decimal_place = 0;
        $price = number_format($numberFloat, $decimal_place, '', $symbol_thousand);
        return $price.$symbol;
    }
    
    function calcalatorTaxi($soKm) {
        if (is_numeric($soKm)) {
            if ($soKm == 1) {
                return formatNumber(13000); 
            } else if ($soKm > 1 && $soKm <= 30) {
                return formatNumber($soKm * 12000);
            } else {
                return formatNumber($soKm * 11000);
            }
        } else {
            echo("Khong duoc nhap chuoi ki tu");
        }
       
    }

    echo(calcalatorTaxi($_POST["soKm"]));
?>