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
public class ThueCaNhanDriver {

    public static void main(String[] args) {
        Income tt3 = new Income("còn học", 0);
        Income tt4 = new Income("còn học", 0);
        Income[] tt0 = {tt3, tt4};//lương của con đi học=0

        Income tt1 = new Income("tiền lương", 1000000);
        Income tt2 = new Income("bán hàng", 10000000);
        Income[] tt = {tt1, tt2}; //lương của con đi làm

        Child c5 = new Child(false, tt, "Minh", 1999, true);
        Child c6 = new Child(false, tt, "Kiet", 1998, true);
        Child c7 = new Child(false, tt, "Mai", 1996, true);
        Child[] cc = {c5, c6, c7};//con của Parent

        Child c1 = new Child(true, tt0, "Trần Minh Khoa", 2000, true);
        Child c2 = new Child(false, tt, "Trần Minh Kha", 1999, true);
        Child c3 = new Child(true, tt0, "Trần Văn Long", 2010, true);
        Child c4 = new Child(true, tt0, "Trần Văn Tài", 2001, true);

        Child[] c = {c3, c4};//con của Texpayer
        Child[] con = {c1, c2, c3, c4};//con của Texpayer

        Parent p1 = new Parent(cc, "Lý Thành Long", 1988, true);
        Parent p2 = new Parent(cc, "Nguyễn Thị Tuyết", 1986, false);
        System.out.println("số con: " + p1.demConKT());
        TaxPayer pay = new TaxPayer(tt, con, p1, p2, "Trần Minh Chiến", 1988, true);
        System.out.println(c1.toString());
        System.out.println("\nTổng thu nhập là: " + pay.tinhTongLuong());
        System.out.println("\nTổng KT cho con là: " + pay.tinhKTChild());
        System.out.println("\nTổng KT cho ba mẹ là: " + pay.tinhKTParent());
        System.out.println("\nTổng thuế: " + pay.tinhThue());
    }
}
