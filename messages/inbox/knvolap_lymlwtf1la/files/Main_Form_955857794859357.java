/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package GPTB2;

import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.*;

/**
 *
 * @author Admin
 */
public class Main_Form extends JFrame implements ActionListener {
    JLabel hoten;
    MenuBar mb=new MenuBar();
    public Main_Form() throws HeadlessException {
        super("Đặng Minh Hiếu - 18T1");
        GUI();
    }
    public void GUI(){
        hoten=new JLabel("Đặng Minh Hiếu - 1811505310109");
        Menu mn=new Menu("File");
        MenuItem login=new MenuItem("Đăng nhập");
        login.addActionListener(this);
        mn.add(login);
        mb.add(mn);
        //đưa label hiển thị ra chính giữa Frame
        hoten.setHorizontalAlignment(0);
        hoten.setVerticalAlignment(0);
        add(hoten);
        setMenuBar(mb);
        setSize(300,200);
        show();
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
    @Override
    public void actionPerformed(ActionEvent ae) {
        if(ae.getActionCommand()=="Đăng nhập"){
            new DangNhap();
        }
    }
    public static void main(String str[]){
        new Main_Form();
    }
}
