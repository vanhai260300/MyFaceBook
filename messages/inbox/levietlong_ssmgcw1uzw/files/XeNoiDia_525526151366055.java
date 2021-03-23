/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author E6410
 */
public class XeNoiDia extends XeOTo {
    private double congLapRap;
    private int soNgay;

    public XeNoiDia() {
    }

    public XeNoiDia(double congLapRap, int soNgay, String ma, String hangXe, double giaXeCanBan) {
        super(ma, hangXe, giaXeCanBan);
        this.congLapRap = congLapRap;
        this.soNgay = soNgay;
    }

    public double getCongLapRap() {
        return congLapRap;
    }

    public void setCongLapRap(double congLapRap) {
        this.congLapRap = congLapRap;
    }

    public int getSoNgay() {
        return soNgay;
    }

    public void setSoNgay(int soNgay) {
        this.soNgay = soNgay;
    }
    public double giaTien(){
        return this.congLapRap*this.soNgay+super.getGiaXeCanBan();
    }

    @Override
    public String toString() {
        return "=>XeNoiDia{ " +super.toString()+" congLapRap=" + congLapRap + ", soNgay=" + soNgay + '}'+"\n +Tong gia tien phai tra : "+giaTien()+" nghin";
    }
    
}
