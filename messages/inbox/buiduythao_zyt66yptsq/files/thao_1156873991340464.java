
import java.awt.BorderLayout;
import java.awt.FlowLayout;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Banme.com
 */
public class thao extends JFrame implements ActionListener{
    JTextField tb1,tb2,tb3;
    JButton bt1,bt2,bt3;
    JLabel lb1,lb2,lb3,kq;
    JPanel pn,pn1,pn2,pn3;
    public thao() {
        CreateAndShow();
    }
    public void CreateAndShow()
    {
        tb1=new JTextField();
        tb2=new JTextField();
        tb3=new JTextField();
        bt1=new JButton("FIFO");
        bt1.addActionListener(this);
        bt2=new JButton("Tìm ucln");
        bt2.addActionListener(this);
        bt3=new JButton("Tìm Bcnn");
        bt3.addActionListener(this);
        lb1=new JLabel("Nhập n");
        lb2=new JLabel("Nhập a");
        lb3=new JLabel("Nhập b");
        kq=new JLabel("");
        pn=new JPanel(new GridLayout(3,1));
        pn2=new JPanel(new BorderLayout());
        pn1=new JPanel(new GridLayout(3,2));
        pn3=new JPanel(new FlowLayout());
        pn1.add(lb1);
        pn1.add(tb1);
        pn1.add(lb2);
        pn1.add(tb2);
        pn1.add(lb3);
        pn1.add(tb3);
        pn2.add(kq,BorderLayout.CENTER);
        pn3.add(bt1);
        pn3.add(bt2);
        pn3.add(bt3);
        pn.add(pn1);
        pn.add(pn2);
        pn.add(pn3);
        this.add(pn);
        setSize(500,400);
        this.setLocationRelativeTo(null);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        show();
    }
    public int ucln(int a,int b)
    {
        int r;
        while(a%b!=0)
        {
            r=a%b;
            a=b;
            b=r;
        }
        return b;
    }
    public int bcnn(int a,int b)
    {
        return (a*b)/ucln(a,b);
    }
    public void fifo(int n)
    {
        int T=0;
        int S=1;
        int i,tt,d=0;
        for(i=1;d<n;i++)
        {
            kq.setText(kq.getText()+T+",");
            tt=T+S;
            T=S;
            S=tt;
            d++;
        }
    }
    public static void main(String[] args) {
        new thao();
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if(e.getSource()==bt1)
        {
            
            fifo(Integer.parseInt(tb1.getText()));
        }
        if(e.getSource()==bt2)
        {
            kq.setText("");
            kq.setText(kq.getText()+ucln(Integer.parseInt(tb2.getText()),Integer.parseInt(tb3.getText())));
        }
        if(e.getSource()==bt3)
        {
            kq.setText("");
            kq.setText(kq.getText()+bcnn(Integer.parseInt(tb2.getText()),Integer.parseInt(tb3.getText())));
        }
    }
}
