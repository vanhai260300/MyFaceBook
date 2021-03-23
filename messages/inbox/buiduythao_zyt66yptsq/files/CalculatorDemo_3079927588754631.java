
import java.awt.Button;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JFrame;
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
public class CalculatorDemo extends JFrame implements ActionListener{
    JButton bt1,bt2,bt3,bt4,bt5,bt6,bt7,bt8,bt9,bt10,bt11,bt12,bt13,bt14,bt15,bt16,bt17,bt18;
    JTextField tb;
    public CalculatorDemo(){
        CreateAndShow();
    }
    private int a=0;
    private int b=0;
    private int c=0;
    private int d=0;
    private int g=-1;
    public void CreateAndShow(){
        tb=new JTextField();
        tb.setBounds(40,10,330,40);
        bt1=new JButton("0");
        bt1.setBounds(40, 80, 50, 50);
        bt1.addActionListener(this);
        bt2=new JButton("1");
        bt2.setBounds(110, 80, 50, 50);
        bt2.addActionListener(this);
        bt3=new JButton("2");
        bt3.setBounds(180, 80, 50, 50);
        bt3.addActionListener(this);
        bt4=new JButton("3");
        bt4.setBounds(250, 80, 50, 50);
        bt4.addActionListener(this);
        bt5=new JButton("4");
        bt5.setBounds(320, 80, 50, 50);
        bt5.addActionListener(this);
        bt6=new JButton("5");
        bt6.setBounds(40, 150, 50, 50);
        bt6.addActionListener(this);
        bt7=new JButton("6");
        bt7.setBounds(110, 150, 50, 50);
        bt7.addActionListener(this);
        bt8=new JButton("7");
        bt8.setBounds(180, 150, 50, 50);
        bt8.addActionListener(this);
        bt9=new JButton("8");
        bt9.setBounds(250, 150, 50, 50);
        bt9.addActionListener(this);
        bt10=new JButton("9");
        bt10.setBounds(320, 150, 50, 50);
        bt10.addActionListener(this);
        bt11=new JButton("+");
        bt11.setBounds(40, 220, 50, 50);
        bt11.addActionListener(this);
        bt12=new JButton("-");
        bt12.setBounds(110, 220, 50, 50);
        bt12.addActionListener(this);
        bt13=new JButton("*");
        bt13.setBounds(180, 220, 50, 50);
        bt13.addActionListener(this);
        bt14=new JButton("/");
        bt14.setBounds(250, 220, 50, 50);
        bt14.addActionListener(this);
        bt15=new JButton("%");
        bt15.setBounds(320, 220, 50, 50);
        bt15.addActionListener(this);
        bt16=new JButton("=");
        bt16.setBounds(40, 290, 50, 50);
        bt16.addActionListener(this);
        bt17=new JButton("C");
        bt17.setBounds(110, 290, 50, 50);
        bt17.addActionListener(this);
        bt18=new JButton("AC");
        bt18.setBounds(180, 290, 50, 50);
        bt18.addActionListener(this);
        this.setSize(420,400);
        this.setLocationRelativeTo(null);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        this.add(tb);
        this.add(bt1);
        this.add(bt2);
        this.add(bt3);
        this.add(bt4);
        this.add(bt5);
        this.add(bt6);
        this.add(bt7);
        this.add(bt8);
        this.add(bt9);
        this.add(bt10);
        this.add(bt11);
        this.add(bt12);
        this.add(bt13);
        this.add(bt14);
        this.add(bt15);
        this.add(bt16);
        this.add(bt17);
        this.add(bt18);
        
        this.setLayout(null);
        this.setVisible(true);
        
    }
    public static void main(String[] args) {
        new CalculatorDemo();
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if(e.getSource()==bt1)
            tb.setText(tb.getText()+"0");
        if(e.getSource()==bt2)
            tb.setText(tb.getText()+"1");
        if(e.getSource()==bt3)
            tb.setText(tb.getText()+"2");
        if(e.getSource()==bt4)
            tb.setText(tb.getText()+"3");
        if(e.getSource()==bt5)
            tb.setText(tb.getText()+"4");
        if(e.getSource()==bt6)
            tb.setText(tb.getText()+"5");
        if(e.getSource()==bt7)
            tb.setText(tb.getText()+"6");
        if(e.getSource()==bt8)
            tb.setText(tb.getText()+"7");
        if(e.getSource()==bt9)
            tb.setText(tb.getText()+"8");
        if(e.getSource()==bt10)
            tb.setText(tb.getText()+"9");
        if(e.getSource()==bt11)
        {
            a=Integer.parseInt(tb.getText());
            tb.setText("");
            c=1;
        }
         if(e.getSource()==bt12)
        {
            a=Integer.parseInt(tb.getText());
            tb.setText("");
            c=2;
        }
          if(e.getSource()==bt13)
        {
            a=Integer.parseInt(tb.getText());
            tb.setText("");
            c=3;
        }
           if(e.getSource()==bt14)
        {
            a=Integer.parseInt(tb.getText());
            tb.setText("");
            c=4;
        }
            if(e.getSource()==bt15)
        {
            if(tb.getText()!="")
            {
                tb.setText(tb.getText()+"%");
            }
        }
         if(e.getSource()==bt16)
         {
             int i;
             for(i=0;i<=tb.getText().length()-1;i++)
             {
                 if (tb.getText().substring(i,i+1).equalsIgnoreCase("%"))
                 {
                     g=i;
                     break;
                 }
             }
             if(g!=-1)
                 tb.setText(new Double(Integer.parseInt(tb.getText().substring(0,g))*0.01).toString());
             else
             {
                  b=Integer.parseInt(tb.getText());
                switch(c)
                {
                    case 1:
                        d=a+b;
                        break;
                    case 2:
                        d=a-b;
                        break;
                    case 3:
                        d=a*b;
                        break;
                    case 4:
                        d=a/b;
                        break;
                    default:d=0;
                }
                tb.setText(new Integer(d).toString());
             }
         }
         if(e.getSource()==bt17)
         {
            String s=tb.getText();
            tb.setText("");
            for(int i=0;i<s.length()-1;i++){
                tb.setText(tb.getText()+s.charAt(i));
         }
         if(e.getSource()==bt18)
         {
             tb.setText("");
         }
    }
    }
}
