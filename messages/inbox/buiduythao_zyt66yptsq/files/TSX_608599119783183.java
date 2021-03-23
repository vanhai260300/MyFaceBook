
import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
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
import javax.swing.table.TableModel;
import static jdk.nashorn.internal.objects.NativeString.trim;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Banme.com
 */
public class TSX extends JFrame implements ActionListener{
    JLabel lb1,lb2;
    JTextField tb1,tb2;
    JButton bt1,bt2,bt3,bt4,bt5;
    JPanel pn,pn1,pn2,pn3,pn4;
    JTable table;
    DefaultTableModel model;
    JScrollPane sr;
    Vector data;
    private int i=-5;
    private String ma;
    public TSX() {
        create();
    }
  
    public void create()
    {
        lb1=new JLabel("Mã tác giả  :    ");
        lb2=new JLabel("Tên tác giả :    ");
        tb1=new JTextField(20);
        tb2=new JTextField(20);
        bt1=new JButton("Thêm");
        bt1.addActionListener(this);
        bt2=new JButton("Lưu");
        bt2.addActionListener(this);
        bt2.setEnabled(false);
        bt3=new JButton("Sửa");
        bt3.addActionListener(this);
        bt4=new JButton("Xóa");
        bt4.addActionListener(this);
        bt5=new JButton("Thoát");
        bt5.addActionListener(this);
        table=new JTable();
        table.addMouseListener(new MouseAdapter(){
        
            @Override
            public void mouseClicked(MouseEvent e)
            {
                
                 int i=table.getSelectedRow();
                 ma=model.getValueAt(i, 0).toString();
                 tb1.setText(model.getValueAt(i,0).toString());
                 tb2.setText(model.getValueAt(i, 1).toString());
                  bt4.setEnabled(true);
                  bt3.setEnabled(true);
            }
        });
        String cot[]={"Mã Tác Giả","Tên Tác Giả"};
        model=new DefaultTableModel();
        model.setColumnIdentifiers(cot);
        table.setModel(model);
        sr=new JScrollPane(table);
        pn=new JPanel(new FlowLayout());
        pn1=new JPanel(new FlowLayout());
        pn2=new JPanel(new FlowLayout());
        pn3=new JPanel(new FlowLayout());
        pn4=new JPanel(new FlowLayout());
        pn1.add(lb1);
        pn1.add(tb1);
        pn2.add(lb2);
        pn2.add(tb2);
        pn3.add(bt1);
        pn3.add(bt2);
        pn3.add(bt3);
        pn3.add(bt4);
        pn3.add(bt5);
        pn4.add(sr);
        pn.add(pn1);
        pn.add(pn2);
        pn.add(pn3);
        pn.add(pn4);
        add(pn);
        setSize(500,400);
        show();
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setLocationRelativeTo(null);
        bt4.setEnabled(false);
        bt3.setEnabled(false);
    }
   public void hien()
   {
       tb1.setText(model.getValueAt(0,0).toString());
       tb2.setText(model.getValueAt(0, 1).toString());
   }
    public static void main(String[] args) throws ClassNotFoundException, SQLException {
        TSX dt=new TSX();
        dt.Ketnoi("select * from TacGia",0);
        dt.hien();
    }
    @Override
    public void actionPerformed(ActionEvent e) {
       if(e.getSource()==bt1)
       {
           tb1.setText("");
           tb2.setText("");
           bt1.setEnabled(false);
           bt2.setEnabled(true);
          
       }
       if(e.getSource()==bt2)
       {
           int n=JOptionPane.showConfirmDialog(this, "Bạn có muốn thêm không !!","Lựa chọn",JOptionPane.YES_NO_OPTION);
           if(n==JOptionPane.YES_OPTION)
           {
           String sql="insert into TacGia(MaTacGia,TenTacGia) values('"+tb1.getText()+"',N'"+tb2.getText()+"')";
           try {
               Ketnoi(sql,1);
               JOptionPane.showMessageDialog(this,"Thêm thành công !!");
               model.setRowCount(0);
               sql="select * from Tacgia";
               Ketnoi(sql,0);
               hien();
               bt1.setEnabled(true);
               bt2.setEnabled(false);
           } catch (ClassNotFoundException ex) {
               Logger.getLogger(TSX.class.getName()).log(Level.SEVERE, null, ex);
           } catch (SQLException ex) {
               Logger.getLogger(TSX.class.getName()).log(Level.SEVERE, null, ex);
               JOptionPane.showMessageDialog(this,"Lỗi nhập dữ liệu sai");
               model.setRowCount(0);
               sql="select * from Tacgia";
               try {
                   Ketnoi(sql,0);
               } catch (ClassNotFoundException ex1) {
                   Logger.getLogger(TSX.class.getName()).log(Level.SEVERE, null, ex1);
               } catch (SQLException ex1) {
                   Logger.getLogger(TSX.class.getName()).log(Level.SEVERE, null, ex1);
               }
               hien();
               bt1.setEnabled(true);
               bt2.setEnabled(false);
           }
           }
           else
           {
               model.setRowCount(0);
                String sql="select * from Tacgia";
               try {
                   Ketnoi(sql,0);
               } catch (ClassNotFoundException ex) {
                   Logger.getLogger(TSX.class.getName()).log(Level.SEVERE, null, ex);
               } catch (SQLException ex) {
                   Logger.getLogger(TSX.class.getName()).log(Level.SEVERE, null, ex);
               }
               hien();
               bt1.setEnabled(true);
               bt2.setEnabled(false);
           }
           
       }
       if(e.getSource()==bt3)
       {
           int n=JOptionPane.showConfirmDialog(this, "Bạn có chắc chắn cập nhật không !!","Lựa chọn",JOptionPane.YES_NO_OPTION);
           if(n==JOptionPane.YES_OPTION)
           {
               String sql="Update TacGia set MaTacGia='"+tb1.getText()+"',TenTacGia=N'"+tb2.getText()+"' where MaTacGia='"+trim(ma)+"'";
               try {
                   Ketnoi(sql,1);
                   JOptionPane.showMessageDialog(this,"Bạn đã cập nhật thành công");
                   bt3.setEnabled(false);
                   bt4.setEnabled(false);
                   model.setRowCount(0);
                   sql="select * from TacGia";
                   Ketnoi(sql,0);
                   hien();
               } catch (ClassNotFoundException ex) {
                   Logger.getLogger(TSX.class.getName()).log(Level.SEVERE, null, ex);
               } catch (SQLException ex) {
                   Logger.getLogger(TSX.class.getName()).log(Level.SEVERE, null, ex);
                   JOptionPane.showMessageDialog(this,"Lỗi sửa dữ liệu  !!");
                   bt3.setEnabled(false);
                   bt4.setEnabled(false);
                   model.setRowCount(0);
                   sql="select * from TacGia";
                   try {
                       Ketnoi(sql,0);
                   } catch (ClassNotFoundException ex1) {
                       Logger.getLogger(TSX.class.getName()).log(Level.SEVERE, null, ex1);
                   } catch (SQLException ex1) {
                       Logger.getLogger(TSX.class.getName()).log(Level.SEVERE, null, ex1);
                   }
                   hien();
               }
           }
           else
           {
                   bt3.setEnabled(false);
                   bt4.setEnabled(false);
                   model.setRowCount(0);
                   String sql="select * from TacGia";
               try {
                   Ketnoi(sql,0);
               } catch (ClassNotFoundException ex) {
                   Logger.getLogger(TSX.class.getName()).log(Level.SEVERE, null, ex);
               } catch (SQLException ex) {
                   Logger.getLogger(TSX.class.getName()).log(Level.SEVERE, null, ex);
               }
                   hien(); 
           }
       }
       if(e.getSource()==bt4)
       {
           int n=JOptionPane.showConfirmDialog(this,"Bạn có chắc chắn xóa dòng này ko ??","Thống báo !!",JOptionPane.YES_NO_OPTION);
           if(n==JOptionPane.YES_OPTION)
           {
               String sql="Delete from Tacgia where MaTacGia='"+trim(ma)+"'";
               try {
                   Ketnoi(sql,1);
                   JOptionPane.showMessageDialog(this,"Xóa thành công !!");
                   bt4.setEnabled(false);
                   bt3.setEnabled(false);
                   model.setRowCount(0);
                   sql="select * from Tacgia";
                   Ketnoi(sql,0);
                   hien();
               } catch (ClassNotFoundException ex) {
                   Logger.getLogger(TSX.class.getName()).log(Level.SEVERE, null, ex);
               } catch (SQLException ex) {
                   Logger.getLogger(TSX.class.getName()).log(Level.SEVERE, null, ex);
               }
           }
           else
           {
                   bt3.setEnabled(false);
                   bt4.setEnabled(false);
                   model.setRowCount(0);
                    String sql="select * from TacGia";
               try {
                   Ketnoi(sql,0);
               } catch (ClassNotFoundException ex) {
                   Logger.getLogger(TSX.class.getName()).log(Level.SEVERE, null, ex);
               } catch (SQLException ex) {
                   Logger.getLogger(TSX.class.getName()).log(Level.SEVERE, null, ex);
               }
                   hien();
           }
       }
       if(e.getSource()==bt5)
       {
           int n=JOptionPane.showConfirmDialog(this,"Bạn thực sự muốn thoát!!","Thông Báo",JOptionPane.YES_NO_OPTION);
           if(n==JOptionPane.YES_OPTION)
                System.exit(0);
       }
    }
    public void Ketnoi(String sql,int a) throws ClassNotFoundException, SQLException
    {
        Class.forName("com.microsoft.sqlserver.jdbc.SQLServerDriver");
        String url="jdbc:sqlserver://BUIDUYTHAO18T4\\SQLEXPRESS:1433;databaseName=QLTVVB";
        Connection conn=DriverManager.getConnection(url,"sa","ngan2103");
        Statement stmt=conn.createStatement();
        if(a==0)
        {
            ResultSet rs=stmt.executeQuery(sql);
            while(rs.next())
            {
                data=new Vector();
                data.add(rs.getString(1));
                data.add(rs.getString(2));
                model.addRow(data);
            }
        }
        else
            stmt.executeUpdate(sql);
    }
}
