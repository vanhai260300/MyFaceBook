/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author E6410
 */
public class XeNhapKhau extends XeOTo{
    private double giaPhuThu;
    private double giaKemThue;

    public XeNhapKhau() {
    }

    public XeNhapKhau(double giaPhuThu, double giaKemThue, String ma, String hangXe, double giaXeCanBan) {
        super(ma, hangXe, giaXeCanBan);
        this.giaPhuThu = giaPhuThu;
        this.giaKemThue = giaKemThue;
    }

    public double getGiaPhuThu() {
        return giaPhuThu;
    }

    public void setGiaPhuThu(double giaPhuThu) {
        this.giaPhuThu = giaPhuThu;
    }

    public double getGiaKemThue() {
        return giaKemThue;
    }

    public void setGiaKemThue(double giaKemThue) {
        this.giaKemThue = giaKemThue;
    }
    
    public double giaTien(){
        return super.getGiaXeCanBan()+this.giaKemThue+this.giaPhuThu;
    }

    @Override
    public String toString() {
        return "=>XeNhapKhau{ " +super.toString() + " giaPhuThu=" + giaPhuThu + ", giaKemThue=" + giaKemThue + '}'+"\n +Tong gia tien phai tra : "+giaTien()+" nghin";
    }
}
