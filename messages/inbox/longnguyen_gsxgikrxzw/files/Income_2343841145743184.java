/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package BaiTap;

/**
 *
 * @author khoatran
 */
public class Income {

    private String ndThuNhaps;
    private double soTien;

    public Income() {
    }

    public Income(String ndThuNhaps, double soTien) {
        this.ndThuNhaps = ndThuNhaps;
        this.soTien = soTien;
    }

    public String getNdThuNhaps() {
        return ndThuNhaps;
    }

    public void setNdThuNhaps(String ndThuNhaps) {
        this.ndThuNhaps = ndThuNhaps;
    }

    public double getSoTien() {
        return soTien;
    }

    public void setSoTien(double soTien) {
        this.soTien = soTien;
    }

}
