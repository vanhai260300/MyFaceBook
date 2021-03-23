/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author E6410
 */
public class XeOTo implements IXe{
    private String ma;
    private String hangXe;
    private double giaXeCanBan;

    public XeOTo() {
    }

    public XeOTo(String ma, String hangXe, double giaXeCanBan) {
        this.ma = ma;
        this.hangXe = hangXe;
        this.giaXeCanBan = giaXeCanBan;
    }

    public String getMa() {
        return ma;
    }

    public void setMa(String ma) {
        this.ma = ma;
    }

    public String getHangXe() {
        return hangXe;
    }

    public void setHangXe(String hangXe) {
        this.hangXe = hangXe;
    }

    public double getGiaXeCanBan() {
        return giaXeCanBan;
    }

    public void setGiaXeCanBan(double giaXeCanBan) {
        this.giaXeCanBan = giaXeCanBan;
    }

    @Override
    public String toString() {
        return "ma=" + ma + ", hangXe=" + hangXe + ", giaXeCanBan=" + giaXeCanBan;
    }
    

    @Override
    public double giaTien() {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }
    
}
