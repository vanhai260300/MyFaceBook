/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Knjdbc_Odbc;

import java.awt.FlowLayout;
import java.awt.GridLayout;
import java.awt.HeadlessException;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
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
import static javax.swing.JFrame.EXIT_ON_CLOSE;
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
public class KNCSDL_Odbc extends JFrame implements ActionListener {

    JLabel lb1, lb2, lb3;
    JTextField tfUrl, tfSql;
    JTable tb1;
    JButton btSubmit, btReset, btExit;
    JScrollPane jsp;
    JPanel pn1, pn2, pn3, pn4, pn;
    String[] ColumNames = {"Id", "Name", "Address", "Total"};
    private DefaultTableModel tbModel = new DefaultTableModel(ColumNames, 5);

    public void GUI() {
        lb1 = new JLabel("KNCSDL", JLabel.CENTER);
        lb2 = new JLabel("Input", JLabel.CENTER);
        lb3 = new JLabel("SQL", JLabel.CENTER);

        tfUrl = new JTextField(100);
        tfSql = new JTextField();

        tb1 = new JTable(tbModel);
        jsp = new JScrollPane(tb1);

        btSubmit = new JButton("Submit");
        btSubmit.addActionListener(this);

        btReset = new JButton("Reset");
        btReset.addActionListener(this);

        btExit = new JButton("Exit");
        btExit.addActionListener(this);

        pn = new JPanel(new GridLayout(4, 1));
        pn1 = new JPanel(new FlowLayout());
        pn2 = new JPanel(new GridLayout(2, 2));
        pn3 = new JPanel(new FlowLayout());
        pn4 = new JPanel(new FlowLayout());

        pn1.add(lb1, JLabel.CENTER);

        pn2.add(lb2);
        pn2.add(tfUrl);
        pn2.add(lb3);
        pn2.add(tfSql);

        pn3.add(jsp);

        pn4.add(btSubmit);
        pn4.add(btReset);
        pn4.add(btExit);

        pn.add(pn1);
        pn.add(pn2);
        pn.add(pn3);
        pn.add(pn4);

        add(pn);

        setSize(500, 500);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        show();

    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == btSubmit) {
            Connection conn = null;
            Statement stmt = null;
            ResultSet rs = null;
            try {
                
                Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");
                String url = tfUrl.getText();//jdbc:odbc:data
                conn = DriverManager.getConnection(url);
                stmt = conn.createStatement();

                String sql = tfSql.getText();

                rs = stmt.executeQuery(sql);

                Vector data = null;
                tbModel.setRowCount(0);
              
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
                ex.printStackTrace();
            } catch (ClassNotFoundException ex) {
                Logger.getLogger(KNCSDL_Odbc.class.getName()).log(Level.SEVERE, null, ex);
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
        if (e.getSource() == btReset) {
            tfUrl.setText("");
            tfSql.setText("");
            tbModel.setRowCount(0);
        }
        if (e.getSource() == btExit) {
            System.exit(0);
        }
    }

    public KNCSDL_Odbc(String s) {
        super(s);
        GUI();
    }

    public static void main(String[] args) {
        KNCSDL_Odbc KN = new KNCSDL_Odbc("Ket Noi CSDL");
    }
}
