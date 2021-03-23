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
public class TaxPayer extends Person {

    private Income[] thuNhaps;
    private Child[] cacCon;
    private Parent papa, mama;

    public TaxPayer() {
    }

    public TaxPayer(Income[] thuNhaps, Child[] cacCon, Parent papa, Parent mama, String hoTen, int namSinh, boolean gioiTinh) {
        super(hoTen, namSinh, gioiTinh);
        this.thuNhaps = thuNhaps;
        this.cacCon = cacCon;
        this.papa = papa;
        this.mama = mama;
    }

    public Income[] getThuNhaps() {
        return thuNhaps;
    }

    public void setThuNhaps(Income[] thuNhaps) {
        this.thuNhaps = thuNhaps;
    }

    public Child[] getCacCon() {
        return cacCon;
    }

    public void setCacCon(Child[] cacCon) {
        this.cacCon = cacCon;
    }

    public Parent getPapa() {
        return papa;
    }

    public void setPapa(Parent papa) {
        this.papa = papa;
    }

    public Parent getMama() {
        return mama;
    }

    public void setMama(Parent mama) {
        this.mama = mama;
    }

    public Calendar getYear() {
        return year;
    }

    public void setYear(Calendar year) {
        this.year = year;
    }
//Hàm tổng thu nhập:
    public double tinhTongLuong() {
        double s = 0;
        for (int i = 0; i < thuNhaps.length; i++) {
            s += thuNhaps[i].getSoTien();
        }
        return s;
    }

    public double tinhKTParent() {
        return papa.tinhMucKT() + mama.tinhMucKT();
    }

    public double tinhKTChild() {
        double s = 0;
        for (int i = 0; i < cacCon.length; i++) {
            s += cacCon[i].tinhMucKT();
        }
        if (s > 3200000) {
            return 3200000;
        }
        return s;
    }
//Hàm tổng khấu trừ:
    public double tinhTongKT() {

        return tinhKTParent() + tinhKTChild() + 4000000;
    }

    public double tinhThue() {
        double s = tinhTongLuong() - tinhTongKT();
        if (s < 0) {
            return 0;
        }
        if (s < 2000000) {
            return s * 5.0 / 100;
        } else {
            return s * (((s - 2000000) / 1000000.0) + 5) / 100;
        }
    }

    public void inBke() {

    }

    public void addIncome(Income a) {
        a.getSoTien();
        a.getNdThuNhaps();
    }

    public void updateParentInfoP(Parent p) {
        this.papa = p;
    }

    public void updateParentInfoM(Parent m) {
        this.papa = m;
    }

    public void updateChildren(Child[] con) {
        this.cacCon = con;
    }
}
