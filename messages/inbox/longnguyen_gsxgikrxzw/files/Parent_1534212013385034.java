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
public class Parent extends Person {

    private Child[] con;

    public Parent() {
    }

    public Parent(Child[] con, String hoTen, int namSinh, boolean gioiTinh) {
        super(hoTen, namSinh, gioiTinh);
        this.con = con;
    }

    public int demConKT() {
        int d = 0;
        for (Child con1 : con) {
            if (con1.tinhTongLuong() > 4000000) {
                d = d + 1;
            }
        }
        return d;
    }

    public double tinhMucKT() {
        if (super.tinhTuoi() > 60 && super.isGioiTinh() == true) {
            return 1600000 / demConKT();
        } else {
            if (super.tinhTuoi() > 55 && super.isGioiTinh() == false) {
                return 1600000 / demConKT();
            } else {
                return 0;
            }
        }
    }

    @Override
    public String toString() {
        return super.toString() + " ; Mức khấu trừ: " + tinhMucKT();
    }
}
