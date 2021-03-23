
import java.util.ArrayList;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author E6410
 */
public class DSXeOTo {
    private ArrayList<XeNhapKhau> l1=new ArrayList<>();
    private ArrayList<XeNoiDia> l2=new ArrayList<>();
    public void createListOto(){
        while(true){
            System.out.println("Ban muon nhap oto Xe nhap khau (1) hay Xe noi dia (2) : ");
            int a=Validation.checkInputLimit(1, 2);
            if(a==1)
            {
                System.out.println("Moi nhap ma xe : ");
                String ma=Validation.checkInputString();
                System.out.println("Moi nhap hang xe : ");
                String hangxe=Validation.checkInputString();
                System.out.println("Moi nhap gia xe can ban : ");
                double giaXeCanBan=Validation.checkInputDouble();
                System.out.println("Moi nhap gia phu thu : ");
                double giaPhuThu=Validation.checkInputDouble();
                System.out.println("Moi nhap gia kem thue : ");
                double giaKemThue=Validation.checkInputDouble();
                l1.add(new XeNhapKhau(giaPhuThu,giaKemThue,ma,hangxe,giaXeCanBan));
                System.out.println("Da them thanh cong ");
            }
            if(a==2)
            {
                System.out.println("Moi nhap ma xe : ");
                String ma=Validation.checkInputString();
                System.out.println("Moi nhap hang xe : ");
                String hangxe=Validation.checkInputString();
                System.out.println("nhap gia xe can ban : ");
                double giaXeCanBan=Validation.checkInputDouble();
                System.out.println("Nhap cong lap rap : ");
                double congLapRap=Validation.checkInputDouble();
                System.out.println("Nhap so ngay  : ");
                int soNgay=Validation.checkInputInt();
                l2.add(new XeNoiDia(congLapRap,soNgay,ma,hangxe,giaXeCanBan));
                System.out.println("da them thanh cong ");
            }
             System.out.print("Do you want to continue : y/n: ");
            if (!Validation.checkInputYN()) {
                return;
            }
        }
    }
    public void report(){
        for(XeNhapKhau ls1:l1)
            System.out.println(ls1);
        for(XeNoiDia ls2:l2)
            System.out.println(ls2);
    }
}
