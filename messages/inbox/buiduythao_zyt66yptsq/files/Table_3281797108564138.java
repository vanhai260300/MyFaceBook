
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.Vector;
import javax.naming.spi.DirStateFactory.Result;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JScrollPane;
import javax.swing.JTable;
import javax.swing.table.DefaultTableModel;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Banme.com
 */
public class Table extends JFrame{
    JTable table1;
    DefaultTableModel tableModel;
    Vector data;
    JButton bt1,bt2;
    
    public Table() throws ClassNotFoundException, SQLException {
        create();
    }
    public void create() throws ClassNotFoundException, SQLException
    {
        bt1=new JButton("Search");
        tableModel =new DefaultTableModel(); 
        String cot [] = { "Mã Tác Giả" , "Tên Tác Giả"  };         
        JTable table1 = new JTable();
        tableModel.setColumnIdentifiers(cot);
        table1.setModel(tableModel);
        JScrollPane sp = new  JScrollPane (table1);    
        add (sp);    
        setSize ( 400 , 200 );    
        show();
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setLocationRelativeTo(null);
        ketnoi();
    }
    public void ketnoi() throws ClassNotFoundException, SQLException
    {
        Class.forName("com.microsoft.sqlserver.jdbc.SQLServerDriver");
            String url="jdbc:sqlserver://BUIDUYTHAO18T4\\SQLEXPRESS:1433;databaseName=KetNoiVB";
            Connection conn = DriverManager.getConnection(url,"sa","ngan2103");
            Statement stmt=conn.createStatement();
            String sql="select * from TacGia";
            ResultSet rs=stmt.executeQuery(sql);
            while(rs.next())
            {
                data=new Vector();
                data.add(rs.getString(1));
                data.add(rs.getString(2));
                tableModel.addRow(data);
            }
    }
    public static void main(String[] args) throws ClassNotFoundException, SQLException {
        new Table();
    }
}
