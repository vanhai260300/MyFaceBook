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
public class Child extends Person {

    private boolean diHoc;
    private Income[] thuNhaps;

    public Child() {
    }

    //con phải thêm thu nhập để biết thu nhập có trên 4 tr hay ko.Nếu có thì sẽ chia phần khấu trừ cho tổng số con lương >4tr
    //Nếu con còn đi học hoặc dưới 18 thì nhập vào lương = 0
    public Child(boolean diHoc, Income[] thuNhaps, String hoTen, int namSinh, boolean gioiTinh) {
        super(hoTen, namSinh, gioiTinh);
        this.diHoc = diHoc;
        this.thuNhaps = thuNhaps;
    }

    public boolean isDiHoc() {
        return diHoc;
    }

    public void setDiHoc(boolean diHoc) {
        this.diHoc = diHoc;
    }

    public Income[] getThuNhaps() {
        return thuNhaps;
    }

    public void setThuNhaps(Income[] thuNhaps) {
        this.thuNhaps = thuNhaps;
    }
//Hàm trả về mức khấu trừ:
    public double tinhMucKT() {
        if (super.tinhTuoi() < 18) {
            return 1600000;
        } else if (diHoc == true) {
            return 1600000;
        } else {
            return 0;
        }
    }

    public double tinhTongLuong() {
        double s = 0;
        for (Income thuNhap : thuNhaps) {
            s += thuNhap.getSoTien();
        }
        return s;
    }

    @Override
    public String toString() {
        return super.toString() + " ; Đi học: " + diHoc + " ; Mức khấu trừ: " + tinhMucKT();
    }
}
