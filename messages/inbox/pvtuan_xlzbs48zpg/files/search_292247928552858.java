/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package KnTimKiemThongTin;

import java.awt.Checkbox;
import java.awt.CheckboxGroup;
import java.awt.FlowLayout;
import java.awt.GridLayout;
import java.awt.HeadlessException;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.Vector;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTable;
import javax.swing.JTextField;
import javax.swing.table.DefaultTableModel;

/**
 *
 * @author PVTuan
 */
public final class search extends JFrame implements ActionListener,ItemListener {

    JLabel lb1,lb2;
    JTextField tfSearch;
    JButton btsearch,btReset,btExit;
    CheckboxGroup cbgr ;
    Checkbox cbId,cbName,cbAddress,cbTotal;
    JTable tb1;
    JScrollPane jsp;
    JPanel pn1,pn2,pn3,pn4,pn;
    String [] c= {"Id","Name","Address","Total"}; 
    String sql;
    private final DefaultTableModel tbModel = new DefaultTableModel(c,5);
    
    public void GUI(){
        JLabel l1 = new JLabel("Tim kiếm thông tin");
        JLabel l2 = new JLabel("Input");
        
        btsearch = new JButton("Search");
        btsearch.addActionListener(this);
        
        tfSearch = new JTextField(10);
        
        btReset = new JButton("Reset");
        btReset.addActionListener(this);
        
        btExit = new JButton("Exit");
        btExit.addActionListener(this);
        
        cbgr = new CheckboxGroup();
        
        cbId = new Checkbox("Id",cbgr,false);
        cbId.addItemListener(this);
        
        cbName = new Checkbox("Name",cbgr,false);
        cbName.addItemListener(this);
        
        cbAddress = new Checkbox("Address",cbgr,false);
        cbAddress.addItemListener(this);
        
        cbTotal = new Checkbox("Total",cbgr,false);
        cbTotal.addItemListener(this);
        
        tb1= new JTable(tbModel);
        jsp = new JScrollPane(tb1);
        
        pn = new JPanel(new GridLayout(4,1));
        pn1 = new JPanel(new FlowLayout());
        pn2 = new JPanel(new FlowLayout());
        pn3 = new JPanel(new FlowLayout());
        pn4 = new JPanel(new FlowLayout());
        
        pn1.add(l1);
        
        pn2.add(l2);
        pn2.add(tfSearch);
        pn2.add(btsearch);
        pn2.add(btReset);
        pn2.add(btExit);
        
        pn3.add(cbId);
        pn3.add(cbName);
        pn3.add(cbAddress);
        pn3.add(cbTotal);
        
        pn4.add(jsp);
        
        pn.add(pn1);
        pn.add(pn2);
        pn.add(pn3);
        pn.add(pn4);
        
        add(pn);
        setSize(500,500);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        show();
    }
    @Override
    public void actionPerformed(ActionEvent e) {
        
        if(e.getSource()==btsearch )
        {
            Connection conn = null;
            Statement stmt = null;
            ResultSet rs = null;
            try {
                Class.forName("com.microsoft.sqlserver.jdbc.SQLServerDriver");
            } catch (ClassNotFoundException ex) {
                Logger.getLogger(search.class.getName()).log(Level.SEVERE, null, ex);
            }
            try {
            String url= "jdbc:sqlserver://localhost:1433;databaseName=DATA";
            conn = DriverManager.getConnection(url,"sa","15421542");
            stmt = conn.createStatement();
                
                if(cbId.getState() || cbName.getState() || cbAddress.getState() || cbTotal.getState())
                    sql= "select *from Table1 ";
                else 
                    JOptionPane.showMessageDialog(this, "Chon checkBox di !");
                
                if(cbId.getState()){
                sql = sql+" where Id like '%" + tfSearch.getText() + "%' " ;
                  }
                if(cbName.getState()){
                    sql = sql+" where Name like '%" + tfSearch.getText() + "%' " ;
                 }
                if(cbAddress.getState()){
                    sql = sql+" where Address like '%" + tfSearch.getText() + "%' " ;
                }
                if(cbTotal.getState()){
                    sql = sql+" where Total like '%" + tfSearch.getText() + "%' " ;
                }

                try {
                    rs= stmt.executeQuery(sql);
                } catch (Exception ea) {
                }
            
            
            Vector data = null;
            tbModel.setRowCount(0);
            // Nếu sách không tồn tại
            if (rs.isBeforeFirst() == false) {
             JOptionPane.showMessageDialog(this, "The book is not available!");
             return;
            }

            // Trong khi chưa hết dữ liệu
            while (rs.next()) {
              data = new Vector();
              data.add(rs.getInt("Id"));
              data.add(rs.getString("Name"));
              data.add(rs.getString("Address"));
              data.add(rs.getString("Total"));
              // Thêm một dòng vào table model
              tbModel.addRow(data);
            }

            tb1.setModel(tbModel); // Thêm dữ liệu vào table
            
           } catch (HeadlessException | SQLException ex) {
            } finally {
             try {
               if (conn != null) {
                 conn.close();
               }
               if (stmt != null) {
                stmt.close();
               }
               if (rs != null) {
                rs.close();
               }
              } catch (SQLException ex) {
              }
           }
        }
        if(e.getSource()==btReset){
            tfSearch.setText("");
            tbModel.setRowCount(0);
        }
        if(e.getSource()==btExit){
            System.exit(0);
        }
    }
    
    
    @Override
    public void itemStateChanged(ItemEvent ie) {
        
    }
    
    public search(String s){
        super(s);
        GUI();
    }
    
    public static void main(String[] args) {
        search s= new search("Tìm kiếm thông tin");
    }

    
}
