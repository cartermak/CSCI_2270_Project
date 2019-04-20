package mypackage;

import javax.swing.*;
import java.awt.event.*;
import java.awt.*;

public class Main {
    public void addorder() {

    }

    private static JDialog d;

    public static void main(String[] args) {
        System.load(
                "/mnt/5932357A1CFE5229/OneDrive - University of Colorado at Boulder Office 365/OneDrive - UCB-O365/2019/CSCI 2270/Project/CSCI_2270_Project/Java experimenting/mypackage/sources/share.so");
        JPanel f = new JPanel();// creating instance of JFrame
        f.setLayout(new BoxLayout(f, BoxLayout.PAGE_AXIS));
        JPanel k = new JPanel();
        k.setLayout(new FlowLayout());
        JFrame t = new JFrame("Connection Parts Inventory");
        t.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        Connection C = new Connection();
        int partNumberfortest = 0;
        // add a part panel
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
        JTextField n = new JTextField(10);
        n.setBounds(120, 125, 100, 40);
        JTextField countT = new JTextField(10);
        countT.setBounds(320, 125, 100, 40);
        JTextField nameT = new JTextField(10);
        nameT.setBounds(520, 125, 100, 40);
        JTextField descripT = new JTextField(10);
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
                } catch (Exception z) {

                    System.out.println(z.getLocalizedMessage());
                }
                try {
                    count = Integer.parseInt(countT.getText());
                } catch (Exception f) {
                    System.out.println(f.getLocalizedMessage());
                }
                if (partNum != 0 && count != 0) {
                    Part r = new Part();
                    r = C.searchPart(partNum);
                    if (r != null) {
                        int a = JOptionPane.showConfirmDialog(f,
                                "Part already in inventory, would you like to increment its count?");
                        if (a == JOptionPane.YES_OPTION) {
                            System.out.println("HECK YEAH");
                            final int partNumberfortest = partNum;
                            boolean y = C.addPart(partNum, count, nameT.getText(), descripT.getText());
                            // String yes = w.getStr();
                            try {

                            } catch (Exception c) {
                                System.out.println(c.getLocalizedMessage());
                            }

                            if (y)
                                o.setText("Success!");
                            else
                                o.setText("Failed to add Part");
                        }
                    } else {
                        final int partNumberfortest = partNum;
                        boolean y = C.addPart(partNum, count, nameT.getText(), descripT.getText());
                        // String yes = w.getStr();
                        try {

                        } catch (Exception c) {
                            System.out.println(c.getLocalizedMessage());
                        }

                        if (y)
                            o.setText("Success!");
                        else
                            o.setText("Failed to add Part");
                    }

                }

            }
        });
        JButton print = new JButton("Test");
        JTextField ordering = new JTextField(10);
        JButton high = new JButton("Add Part");
        high.addActionListener(new ActionListener() {

            @Override
            public void actionPerformed(ActionEvent action1) {
                int count = 0;
                int partNum = 0;
                try {
                    partNum = Integer.parseInt(ordering.getText());
                } catch (Exception z) {

                    System.out.println(z.getLocalizedMessage());
                }
                try {
                    count = Integer.parseInt(countT.getText());
                } catch (Exception f) {
                    System.out.println(f.getLocalizedMessage());
                }
                boolean y = C.addPart(partNum, count, nameT.getText(), descripT.getText());
                if (y) {
                    JOptionPane.showMessageDialog(k, "Added Successfully");
                } else
                    System.out.println("Yikes");
                d.setVisible(false);
            }
        });
        JButton button = new JButton("Place Order");
        button.addActionListener(new ActionListener() {

            @Override
            public void actionPerformed(ActionEvent e) {
                int c = 0;

                String partName = ordering.getText();
                int u = 0;
                try {
                    c = Integer.parseInt(countT.getText());
                } catch (Exception l) {

                    System.out.println(l.getLocalizedMessage());
                }
                try {
                    u = Integer.parseInt(partName);
                } catch (Exception poll) {
                    System.out.println(poll.getLocalizedMessage());
                }
                Part h = C.searchPart(u);
                boolean y = C.orderPart(h, c, nameT.getText(), descripT.getText(), 0);
                if (y) {
                    JOptionPane.showMessageDialog(k, "Added Successfully");
                } else
                    System.out.println("Yikes");
                Main.d.setVisible(false);
            }
        });
        print.setBounds(160, 850, 100, 40);
        print.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent action) {
                String partName = ordering.getText();
                int u = 0;
                try {
                    u = Integer.parseInt(partName);
                } catch (Exception poll) {
                    System.out.println(poll.getLocalizedMessage());
                }

                Part h = C.searchPart(u);
                if (h == null) {
                    int b = JOptionPane.showConfirmDialog(k, "Part is not in inventory, would you like to add it?");
                    if (b == JOptionPane.YES_OPTION) {
                        d = new JDialog(t, "Adding part " + partName + " to inventory", true);

                        d.setLayout(new FlowLayout());
                        d.add(cnt);
                        d.add(countT);
                        d.add(nme);
                        d.add(nameT);
                        d.add(descrip);
                        d.add(descripT);
                        // d.add(print);
                        d.add(high);
                        d.setSize(300, 300);
                        d.setVisible(true);
                    }
                }
                Part asd = C.searchPart(u);
                int cont = 0;
                cont += asd.getCount();
                strmod you = asd.getName();
                String your = you.getStr();
                d = new JDialog(t, "Ordering " + your, true);
                d.setLayout(new FlowLayout());
                d.add(new JLabel("Part found! there are " + cont + "in the inventory"));
                d.add(new JLabel("Number to be ordered"));
                d.add(countT);
                d.add(new JLabel("Mechanic's Name"));
                d.add(nameT);
                d.add(new JLabel("Any notes"));
                d.add(descripT);
                d.add(button);
                d.setSize(300, 300);
                d.setVisible(true);

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

        // buttons
        f.add(b);// adding button in JFrame
        f.add(o);

        // order a part panel
        JLabel order = new JLabel("Place an order: Please enter a part number");
        k.add(order);
        k.add(ordering);
        k.add(print);

        JRadioButton r1 = new JRadioButton("Yes");
        JRadioButton r2 = new JRadioButton("No");
        ButtonGroup bg = new ButtonGroup();
        bg.add(r1);
        bg.add(r2);

        JTabbedPane tp = new JTabbedPane();
        tp.setBounds(0, 0, 1000, 400);
        tp.add("Add a Part", f);
        tp.add("Order a Part", k);
        t.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        t.add(tp);
        t.setSize(1000, 1000);// 400
                              // width
                              // and
                              // 500
                              // height
        t.setLayout(null);// using no layout managers
        t.setVisible(true);// making the frame visible
    }
}