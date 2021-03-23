/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package GPTB2;

import java.awt.BorderLayout;
import java.awt.FlowLayout;
import java.awt.HeadlessException;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.*;

/**
 *
 * @author Admin
 */
public class GPT extends JFrame implements ActionListener {
    JLabel tieude,nhapA,nhapB,nhapC;
    JTextField a,b,c;
    JButton reset,submit;

    public GPT() throws HeadlessException {
        super("Giải phương trình bậc 2");
        GUI();
    }
    public void GUI(){
        tieude=new JLabel("Giải phương trình bậc 2");
        nhapA=new JLabel("Nhập a:");
        nhapB=new JLabel("Nhập b:");
        nhapC=new JLabel("Nhập c:");
        a=new JTextField(5);
        b=new JTextField(5);
        c=new JTextField(5);
        reset=new JButton("Reset");
        submit=new JButton("Submit");
        reset.addActionListener(this);
        submit.addActionListener(this);
        JPanel pn1=new JPanel(new FlowLayout(FlowLayout.CENTER,40,20));
        JPanel pn2=new JPanel(new FlowLayout(FlowLayout.LEFT,40,20));
        JPanel pn3=new JPanel(new FlowLayout(FlowLayout.CENTER,40,20));
        JPanel pn=new JPanel(new BorderLayout());
        pn1.add(tieude);
        pn2.add(nhapA);
        pn2.add(a);
        pn2.add(nhapB);
        pn2.add(b);
        pn2.add(nhapC);
        pn2.add(c);
        pn3.add(submit);
        pn3.add(reset);
        pn.add(pn1,BorderLayout.NORTH);
        pn.add(pn2,BorderLayout.CENTER);
        pn.add(pn3,BorderLayout.SOUTH);
        add(pn);
        setSize(250,310);
        show();
    }
    @Override
    public void actionPerformed(ActionEvent ae) {
        if(ae.getSource()==submit){
            try {
                Double x=Double.parseDouble(a.getText().trim());
                Double y=Double.parseDouble(b.getText().trim());
                Double z=Double.parseDouble(c.getText().trim());
                if(x==0){
                    if(y==0){
                        if(z==0){
                            JOptionPane.showMessageDialog(this,"Phương trình vô số no");
                        }
                        else{
                            JOptionPane.showMessageDialog(this,"Phương trình vô no");
                        }
                    }
                    else{
                        JOptionPane.showMessageDialog(this,"Phương có 1 no, x="+Double.toString(-z/y));
                    }
                }
                else{
                    Double delta=(y*y-4*x*z);
                    if(delta<0){
                        JOptionPane.showMessageDialog(this,"Phương trình vô no");
                    }
                    else{
                        if(delta==0){
                            Double no=-y/2*x;
                            JOptionPane.showMessageDialog(this,"Phương trình có no kép, x="+Double.toString(no));
                        }
                        else{
                            Double x1=(-y+Math.sqrt(delta))/2*x;
                            Double x2=(-y-Math.sqrt(delta))/2*x;
                            String kq="Phương có 2 nghiệm phân biệt:\nX1="+x1+",   X2="+x2;
                            JOptionPane.showMessageDialog(this,kq);
                        }
                    }
                }
            } catch (Exception e) {
                JOptionPane.showMessageDialog(this, "a, b, c bạn vừa nhập không hợp lệ");
            }
        }
        if(ae.getSource()==reset){
            a.setText("");
            b.setText("");
            c.setText("");
        }
    }
    
}
