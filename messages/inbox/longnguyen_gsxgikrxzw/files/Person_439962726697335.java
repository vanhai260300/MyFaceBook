/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package BaiTap;

import java.util.Calendar;

/**
 *
 * @author khoatran
 */
public class Person {

    private String hoTen;
    private int namSinh;
    private boolean gioiTinh;

    public Person() {
    }

    public Person(String hoTen, int namSinh, boolean gioiTinh) {
        this.hoTen = hoTen;
        this.namSinh = namSinh;
        this.gioiTinh = gioiTinh;
    }

    public String getHoTen() {
        return hoTen;
    }

    public void setHoTen(String hoTen) {
        this.hoTen = hoTen;
    }

    public int getNamSinh() {
        return namSinh;
    }

    public void setNamSinh(int namSinh) {
        this.namSinh = namSinh;
    }

    public boolean isGioiTinh() {
        return gioiTinh;
    }

    public void setGioiTinh(boolean gioiTinh) {
        this.gioiTinh = gioiTinh;
    }

    public double tinhMucKhauTru() {
        return 0;
    }
    Calendar year = Calendar.getInstance();
//Hàm Tính tuổi
    public int tinhTuoi() {
        return year.get(Calendar.YEAR) - namSinh;
    }

    @Override
    public String toString() {
        return " Họ và tên: " + hoTen + " ; Năm sinh: " + namSinh + " ; Giới tính: " + gioiTinh + " \n Tuổi: " + tinhTuoi();
    }
}
