/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package QuanLyOTo;

import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author DUY
 */
public class DSXeOTo {

    ArrayList<XeOTo> oto = new ArrayList<>();
    public static final Scanner in = new Scanner(System.in);

    public DSXeOTo() {
    }
    public void themXe() {
        while (true) {
            System.out.println("Do you want to create  Noi Dia (D) or  Nhap Khau (K) Oto: ");
            System.out.println("Enter your choice: ");
            String choice = Validation.checkInputString();
            if (choice.equalsIgnoreCase("D")) {
                System.out.print("Enter Cong Lap Rap: ");
                double Conglr = Validation.checkInputDouble();
                System.out.print("Enter number day: ");
                int day = in.nextInt();
                System.out.print("Enter ma: ");
                String ma = Validation.checkInputString();
                System.out.print("Enter hang xe: ");
                String hangxe = Validation.checkInputString();
                System.out.print("Enter gia xe can ban: ");
                double giaxe = Validation.checkInputDouble();
                oto.add(new XeNoiDia(Conglr, day, ma, hangxe, giaxe));
            } else {
                System.out.print("Enter gia Phu Thu: ");
                double phuthu = Validation.checkInputDouble();
                System.out.print("Enter gia Kem Thue: ");
                double kemthue = Validation.checkInputDouble();
                System.out.print("Enter ma: ");
                String ma = Validation.checkInputString();
                System.out.print("Enter hang xe: ");
                String hangxe = Validation.checkInputString();
                System.out.print("Enter gia xe can ban: ");
                double giaxe = Validation.checkInputDouble();
                oto.add(new XeNhapKhau(phuthu, kemthue, ma, hangxe, giaxe));

            }
            System.out.println("Add Oto success.");
            System.out.print("Do you want to continue : y/n: ");
            if (!Validation.checkInputYN()) {
                return;
            }
        }
    }

    public void hienThiDanhSach() {
        for (XeOTo oto : oto) {
            System.out.println(oto);
        }
    }

    public ArrayList<XeOTo> getOto() {
        return oto;
    }

    public void setOto(ArrayList<XeOTo> ot) {
        this.oto = oto;
    }

}
