
import java.awt.FlowLayout;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTextField;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author jokey
 */
public class GiuaKy2 extends JFrame implements ActionListener{
    JLabel lb1, lb2, lb;
    JTextField txtm, txtkq;
    JButton btok, btreset, btexit;
    JPanel pn, pn1, pn2, pn3;

    public void GAN() {
        lb = new JLabel("Nhap m in ra cach doc");
        lb1 = new JLabel("Nhap m: ");
        lb2 = new JLabel("Ket qua: ");
        txtm = new JTextField();
        txtkq = new JTextField();
        btok = new JButton("OK");
        btreset = new JButton("Reset");
        btexit = new JButton("Exit");
        btok.addActionListener(this);
        btreset.addActionListener(this);
        btexit.addActionListener(this);
        pn = new JPanel(new GridLayout(3, 1));
        pn1 = new JPanel(new FlowLayout());
        pn2 = new JPanel(new GridLayout(2, 2));
        pn3 = new JPanel(new FlowLayout());
        pn1.add(lb);
        pn2.add(lb1);
        pn2.add(txtm);
        pn2.add(lb2);
        pn2.add(txtkq);
        pn3.add(btok);
        pn3.add(btreset);
        pn3.add(btexit);
        pn.add(pn1);
        pn.add(pn2);
        pn.add(pn3);
        add(pn);
        setSize(400, 200);
        show();
    }

    public GiuaKy2(String st) {
        super(st);
        GAN();
    }
    @Override
    public void actionPerformed(ActionEvent ae) {
        if(ae.getSource()==btok){
            try{
            String chuoi = "";
            int n = Integer.parseInt(txtm.getText());
            int tram=n/100;
            int chuc=n/10%10;
            int dv=n%10;
            if(n>=0){
            switch(tram){
                case 1 : chuoi = chuoi+"mot";
                break;
                case 2 : chuoi = chuoi+"hai";
                break;
                case 3 : chuoi = chuoi+"ba";
                break;
                case 4 : chuoi = chuoi+"bon";
                break;
                case 5 : chuoi = chuoi+"nam";
                break;
                case 6 : chuoi = chuoi+"sau";
                break;
                case 7 : chuoi = chuoi+"bay";
                break;
                case 8 : chuoi = chuoi+"tam";
                break;
                case 9 : chuoi = chuoi+"chin";
                break;
                case 10 : chuoi = chuoi+"muoi";
                break;
            }
            switch(chuc){
                case 0 : if(dv==0 || txtm.getText().length() == 1) chuoi = chuoi+" ";
                else chuoi = chuoi+" le";
                break;
                case 1 : chuoi=chuoi+" muoi";break;
                case 2 : chuoi=chuoi+" hai";break;
                case 3 : chuoi=chuoi+" ba";break;
                case 4 : chuoi=chuoi+" bon";break;
                case 5 : chuoi=chuoi+" nam";break;
                case 6 : chuoi=chuoi+" sau";break;
                case 7 : chuoi=chuoi+" bay";break;
                case 8 : chuoi=chuoi+" tam";break;
                case 9 : chuoi=chuoi+" chin";break;
            }
            switch(dv){
		case 0 : chuoi=chuoi+" mươi";break;
                case 1 : chuoi=chuoi+" mot";break;
                case 2 : chuoi=chuoi+" hai";break;
                case 3 : chuoi=chuoi+" ba";break;
                case 4 : chuoi=chuoi+" bon";break;
                case 5 : chuoi=chuoi+" nam";break;
                case 6 : chuoi=chuoi+" sau";break;
                case 7 : chuoi=chuoi+" bay";break;
                case 8 : chuoi=chuoi+" tam";break;
                case 9 : chuoi=chuoi+" chin";break;
            }
            txtkq.setText(chuoi);
        }
        else
            JOptionPane.showMessageDialog(null,"Nhập sai, nhập lại !!");
        }    
        catch(Exception ex){
            JOptionPane.showMessageDialog(null,"Nhập sai, nhập lại !!");
        }    
        }    
        if(ae.getSource()==btreset){
            txtm.setText("");
            txtkq.setText("");
        }
        if(ae.getSource()==btexit){
            System.exit(0);
        }
    }
    public static void main(String[] args){
        new GiuaKy2("test");
    }   
}
