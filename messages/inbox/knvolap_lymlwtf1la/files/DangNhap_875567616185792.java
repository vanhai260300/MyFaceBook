/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package GPTB2;

import java.awt.BorderLayout;
import java.awt.FlowLayout;
import java.awt.HeadlessException;
import java.awt.event.*;
import java.sql.*;
import java.sql.DriverManager;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.*;

/**
 *
 * @author Admin
 */
public class DangNhap extends JFrame implements ActionListener {
    JLabel tieude,txt1,txt2;
    JTextField user,pass;
    JButton submit,reset;

    public DangNhap() throws HeadlessException {
        super("Đăng nhập tài khoản");
        GUI();
    }
    public void GUI(){
        tieude=new JLabel("INFORMATION LOGIN");
        txt1=new JLabel("Username:");
        txt2=new JLabel("Password:");
        user=new JTextField(20);
        pass=new JTextField(20);
        submit=new JButton("Submit");
        reset=new JButton("Reset");
        submit.addActionListener(this);
        reset.addActionListener(this);
        JPanel pn1=new JPanel();
        JPanel pn2=new JPanel(new FlowLayout(FlowLayout.LEFT,20,20));
        JPanel pn3=new JPanel(new FlowLayout(FlowLayout.RIGHT,20,20));
        JPanel pn=new JPanel(new BorderLayout());
        pn1.add(tieude);
        pn2.add(txt1);
        pn2.add(user);
        pn2.add(txt2);
        pn2.add(pass);
        pn3.add(submit);
        pn3.add(reset);
        pn.add(pn1,BorderLayout.NORTH);
        pn.add(pn2,BorderLayout.CENTER);
        pn.add(pn3,BorderLayout.SOUTH);
        add(pn);
        setSize(360,220);
        show();
    }
    @Override
    public void actionPerformed(ActionEvent ae) {
        if(ae.getSource()==submit){
            String url = "net.sourceforge.jtds.jdbc.Driver";
            try {
              
               Class.forName(url);
            conn = DriverManager.getConnection("jdbc:jtds:sqlserver://KnLap:1433/QLKHACHSAN_CK");
            } catch (ClassNotFoundException ex) {
                Logger.getLogger(DangNhap.class.getName()).log(Level.SEVERE, null, ex);
            } catch (SQLException ex) {
                Logger.getLogger(DangNhap.class.getName()).log(Level.SEVERE, null, ex);
            }
            try {
                Statement sttm=conn.createStatement();
                ResultSet rs=sttm.executeQuery("select * from taikhoan where username='"+user.getText()+"' and password='"+pass.getText()+"'");
                if(rs.next()){
                    new GPT();
                    System.out.println("Thành công");
                }
                else
                    JOptionPane.showMessageDialog(this, "Tên đăng nhập hoặc tài khoản không hợp lệ");
            } catch (SQLException ex) {
                Logger.getLogger(DangNhap.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
        if(ae.getSource()==reset){
            user.setText("");
            pass.setText("");
        }
    }
    
}
