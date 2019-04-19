package mypackage;

import javax.swing.*;
import java.awt.event.*;

public class Main {    
    public static void main(String[] args) {
        System.load("/mnt/5932357A1CFE5229/OneDrive - University of Colorado at Boulder Office 365/OneDrive - UCB-O365/2019/CSCI 2270/Project/CSCI_2270_Project/Java experiementing/mypackage/sources/share.so");
        JFrame f = new JFrame("Adding a Part");// creating instance of JFrame
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        // new UI().constructConnection();
        Connection C = new Connection();
        // labels
        JLabel l = new JLabel("Please enter new part information");
        l.setBounds(365, 60, 200, 40);
        JLabel num = new JLabel("Part #");
        num.setBounds(120,100,100,40);
        JLabel cnt = new JLabel("Count");
        cnt.setBounds(320,100,100,40);
        JLabel nme = new JLabel("Part Name");
        nme.setBounds(520,100,100,40);
        JLabel descrip = new JLabel("Description");
        descrip.setBounds(720,100,100,40);
        JLabel o = new JLabel();
        o.setBounds(10, 300, 100, 40);
        // textFields
        JTextField n = new JTextField();
        n.setBounds(120,125,100,40);
        JTextField countT = new JTextField();
        countT.setBounds(320,125,100,40);
        JTextField nameT = new JTextField();
        nameT.setBounds(520,125,100,40);
        JTextField descripT = new JTextField();
        descripT.setBounds(720,125,100,40);
        // buttons
        JButton b = new JButton("Add Part");// creating instance of JButton
        b.setBounds(450, 200, 200, 40);
        b.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                boolean y = C.addPart(Integer.parseInt(n.getText()), Integer.parseInt(countT.getText()), nameT.getText(), descripT.getText());
                if (y)
                    o.setText("Success!");
                else
                    o.setText("Failed to add Part");
            }
        });
        // labels
        f.add(l);
        f.add(cnt);
        f.add(nme);
        f.add(descrip);
        f.add(num);
        f.add(o);
        // buttons
        f.add(b);// adding button in JFrame
        // textFields
        f.add(descripT);
        f.add(n);
        f.add(countT);
        f.add(nameT);

        f.setSize(1000, 400);// 400 width and 500 height
        f.setLayout(null);// using no layout managers
        f.setVisible(true);// making the frame visible
    }
}