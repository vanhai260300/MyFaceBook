/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ThiCuoiKi;

import java.awt.FlowLayout;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JDialog;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;

/**
 *
 * @author Admin
 */
public class CourseManagement extends JFrame implements ActionListener {
    
    JLabel lbhead;
    JButton btnadd, btndisplay, btnsearch, btnexit;
    JPanel pn, pn1, pn2, pn3, pn4,pn5, pn6;
    
    public void GUI()
    {
       lbhead = new JLabel("COURSE MANAGEMENT");
      
      btnadd = new JButton("Add a new Course");
      btndisplay = new JButton("Display all course");
      btnsearch = new JButton("Search Course by Course Code");
      btnexit = new JButton("Exit Application");
      
      btnadd.addActionListener(this);
      btndisplay.addActionListener(this);
      btnsearch.addActionListener(this);
      btnexit.addActionListener(this);
      
      pn = new JPanel();
      pn1 = new JPanel(new FlowLayout(FlowLayout.CENTER,10,10));
      pn2 = new JPanel(new FlowLayout(FlowLayout.CENTER,10,10));
      pn3 = new JPanel(new FlowLayout(FlowLayout.CENTER,10,10));
      pn4 = new JPanel(new FlowLayout(FlowLayout.CENTER,10,10));
      pn5 = new JPanel(new FlowLayout(FlowLayout.CENTER,10,10));
      pn6 = new JPanel(new GridLayout(5,1));
      pn1.add(lbhead);
      pn2.add(btnadd);
      pn3.add(btndisplay);
      pn4.add(btnsearch);
      pn5.add(btnexit);
      pn6.add(pn1);
      pn6.add(pn2);
      pn6.add(pn3);
      pn6.add(pn4);
      pn6.add(pn5);
      pn.add(pn6);
      add(pn);
      setDefaultCloseOperation(EXIT_ON_CLOSE);
      setSize(400,400);
      show();
    }
    
    @Override
    public void actionPerformed(ActionEvent e) {
        if(e.getSource()==btndisplay){
            new ListCourse();
    }
        if(e.getSource()==btnexit){
            System.exit(0);
        }
        if(e.getSource()==btnsearch)
            new SearchCourse();
    }
    public CourseManagement(String st){
     super(st);
     GUI();
    }
    public static void main(String[] arg){
        new CourseManagement("hello");
}
}
