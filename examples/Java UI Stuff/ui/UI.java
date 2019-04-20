
// package ui;
import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
public class UI {

    public static void main(String[] args) {
        // // System.load(
        // "/mnt/5932357A1CFE5229/OneDrive - University of Colorado at Boulder Office
        // 365/OneDrive - UCB-O365/2019/CSCI 2270/Project/CSCI_2270_Project/Java
        // experimenting/mypackage/sources/share.so");

        JFrame t = new JFrame("Connection Parts Inventory");// creating instance of JFrame
        // BoxLayout q = new BoxLayout(t, BoxLayout.Y_AXIS);
        JPanel f = new JPanel();
        f.setLayout(new BoxLayout(f, BoxLayout.PAGE_AXIS));
        JLabel l = new JLabel("Please enter new part information");
        l.setBounds(365, 60, 200, 40);
        JLabel num = new JLabel("Part #");
        num.setBounds(120, 100, 100, 40);
        JLabel cnt = new JLabel("Count");
        cnt.setBounds(320, 100, 100, 40);
        JLabel nme = new JLabel("Part Name");
        nme.setBounds(520, 100, 100, 40);
        JLabel descrip = new JLabel("Description");
        descrip.setBounds(720, 100, 100, 40);
        JLabel o = new JLabel();
        o.setBounds(10, 300, 100, 40);
        // textFields
        JTextField n = new JTextField();
        n.setBounds(120, 125, 100, 40);
        JTextField countT = new JTextField();
        countT.setBounds(320, 125, 100, 40);
        JTextField nameT = new JTextField();
        nameT.setBounds(520, 125, 100, 40);
        JTextField descripT = new JTextField();
        descripT.setBounds(720, 125, 100, 40);
        // buttons
        JButton b = new JButton("Add Part");// creating instance of JButton
        b.setBounds(450, 200, 200, 40);
        b.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                int partNum = 0;
                int count = 0;
                try {
                    partNum = Integer.parseInt(n.getText());
                } catch (Exception d) {

                    System.out.println(d.getLocalizedMessage());
                }
                try {
                    count = Integer.parseInt(countT.getText());
                } catch (Exception f) {
                    System.out.println(f.getLocalizedMessage());
                }
                if (partNum != 0 && count != 0) {
                    // boolean y = C.addPart(partNum, count, nameT.getText(), descripT.getText());
                    System.out.println("adding part");
                    // if (y)
                    // o.setText("Success!");
                    // else
                    // o.setText("Failed to add Part");
                }
            }
        });
        // labels
        f.add(l);
        f.add(num);
        f.add(n);
        f.add(cnt);
        f.add(countT);
        f.add(nme);
        f.add(nameT);
        f.add(descrip);
        f.add(descripT);
        f.add(o);
        // buttons
        f.add(b);// adding button in JFrame
        JPanel k = new JPanel();
        JTabbedPane tp = new JTabbedPane();
        tp.setBounds(0, 0, 1000, 400);
        tp.add("Add a Part", f);
        tp.add("Order a Part", k);
        t.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);        
        t.add(tp);
        t.setSize(1000, 1000);// 400 width and 500 height
        t.setLayout(null);// using no layout managers
        t.setVisible(true);// making the frame visible
    }
}