package mypackage;

import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import java.awt.event.*;
import java.awt.*;
public class Main {
    public void addorder() {

    }

    private static JDialog d;

    public static void main(String[] args) {
        // import library from jar
        try {
            NativeUtils.loadLibraryFromJar("/share.so");
        } catch (Exception temp){
            System.out.println(temp.getLocalizedMessage());
        }
        // new panels
        JPanel search = new JPanel(true);
        JPanel f = new JPanel();// creating instance of JFrame
        JPanel k = new JPanel();
        // layout for ordering panel
        GroupLayout group = new GroupLayout(k);
        group.setAutoCreateGaps(true);
        group.setAutoCreateContainerGaps(true);
        k.setLayout(group);
        // new layout for adding panel
        GroupLayout gr = new GroupLayout(f);
        gr.setAutoCreateContainerGaps(true);
        gr.setAutoCreateGaps(true);
        f.setLayout(gr);
        // new layout for searching
        GroupLayout se = new GroupLayout(search);
        se.setAutoCreateContainerGaps(true);
        se.setAutoCreateGaps(true);
        // mother frame
        JFrame t = new JFrame("Connection Parts Inventory");
        t.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        // constructing new connection
        Connection C = new Connection();
        
        // add a part panel
        JLabel l = new JLabel("Please enter new part information");
        JLabel num = new JLabel("Part #");
        JLabel cnt = new JLabel("Count");
        JLabel nme = new JLabel("Part Name");
        JLabel descrip = new JLabel("Description");
        JLabel o = new JLabel();

        // textFields
        JTextField n = new JTextField(10);
        JTextField countT = new JTextField(10);
        JTextField nameT = new JTextField(10);
        JTextField descripT = new JTextField(10);
        
        // buttons
        JButton b = new JButton("Add Part");
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
                          
                            boolean y = C.addPart(partNum, count, nameT.getText(), descripT.getText());
                        
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
                        
                        boolean y = C.addPart(partNum, count, nameT.getText(), descripT.getText());
                        
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
                n.setText("");
                countT.setText("");
                nameT.setText("");
                descripT.setText("");
            }
        });
        // ordering panel/dialogs
        JButton print = new JButton("Order");
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
                if(nameT.getText() == "") nameT.setText("Name");
                if(descripT.getText() == "") descripT.setText("Description");
                boolean y = C.addPart(partNum, count, nameT.getText(), descripT.getText());
                if (y) {
                    JOptionPane.showMessageDialog(k, "Added Successfully");
                } else
                    System.out.println("Yikes");
                d.setVisible(false);

                countT.setText("");
                nameT.setText("");
                descripT.setText("");
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
                boolean y = C.orderPart(h, c, nameT.getText(), descripT.getText(), 1);
                if (y) {
                    JOptionPane.showMessageDialog(k, "Added Order Successfully");
                } else
                    System.out.println("Yikes");
                Main.d.setVisible(false);
                ordering.setText("");
                countT.setText("");
                nameT.setText("");
                descripT.setText("");
            }
        });
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
                        
                        d.add(high);
                        d.setSize(300, 300);
                        d.setVisible(true);
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
                }

            }
        });

        // search panel
        JButton query = new JButton("Search");
        JLabel status = new JLabel("");
        JTextField searching = new JTextField(10);        
        query.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent re){
                String Number = searching.getText();
                int u = 0;
                JTable jt = new JTable(new DefaultTableModel(new Object[]{"Part Number","Part Name","# in inventory","Description"},0));
                jt.setBounds(20,20,450,70);
                try {
                    u = Integer.parseInt(Number);
                } catch (Exception poll) {
                    System.out.println(poll.getLocalizedMessage());
                }
                Part h = C.searchPart(u);
                if(h!= null){
                    status.setText("Part Found!");
                    String count = Integer.toString(h.getCount());
                    String name = h.getName().getStr();
                    String description = h.getDescription().getStr();
                   
                    
                    JPanel uriel = new JPanel();
                    DefaultTableModel model = (DefaultTableModel) jt.getModel();
                    model.addRow(new Object[]{"Part Number","Part Name","# in inventory","Description"});
                    model.addRow(new Object[]{Number,name,count,description});
                    jt.setPreferredSize(new Dimension(500, 100));
                    uriel.add(jt);
                    UIManager.put("OptionPane.minimumSize",new Dimension(600, 120));  
                    JOptionPane.showMessageDialog(search, uriel, "Part Found", JOptionPane.INFORMATION_MESSAGE);
                    // jt.addColumn(column);
                    searching.setText("");
                }
                if(h==null){
                    status.setText("Part not Found");
                    Component test[] = query.getComponents();
                    boolean eh = false;
                    for(int i=0;i<test.length;i++){
                        if(test[i] instanceof JTable){
                            
                            eh = true;
                            break;
                        }
                    }
                    if(eh){
                        System.out.println("Testing");
                        query.remove(jt);
                        query.revalidate();
                        query.repaint();
                    }
                    eh = false;
                    
                }
                searching.setText("");
            }
        });

        
        //setting grouplayouts
        gr.setHorizontalGroup(gr.createSequentialGroup().addComponent(l).addComponent(num).addComponent(n)
                .addComponent(cnt).addComponent(countT).addComponent(nme).addComponent(nameT).addComponent(descrip)
                .addComponent(descripT).addComponent(b)

        );
        gr.setVerticalGroup(gr.createParallelGroup(GroupLayout.Alignment.BASELINE).addComponent(l).addComponent(num)
                .addComponent(n).addComponent(cnt).addComponent(countT).addComponent(nme).addComponent(nameT)
                .addComponent(descrip).addComponent(descripT).addComponent(b));
    
        f.add(o);
        JLabel two = new JLabel("Enter a Part Number");
        se.setHorizontalGroup(se.createSequentialGroup().addComponent(two).addComponent(searching).addComponent(query).addComponent(status));
        se.setVerticalGroup(se.createParallelGroup().addComponent(two).addComponent(searching).addComponent(query).addComponent(status));
        
        // order a part panel
        JLabel order = new JLabel("Place an order: Please enter a part number");
        group.setHorizontalGroup(
                group.createSequentialGroup().addComponent(order).addComponent(ordering).addComponent(print));
        group.setVerticalGroup(group.createParallelGroup(GroupLayout.Alignment.BASELINE).addComponent(order)
                .addComponent(ordering).addComponent(print));
        

        
        // adding to mother frame
        JTabbedPane tp = new JTabbedPane();
        tp.setBounds(0, 0, 1000, 1000);
        tp.add("Add a Part", f);
        tp.add("Order a Part", k);
        tp.add("Search for a Part",search);
        t.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        t.add(tp);
        t.setSize(1000, 400);// 400
                              // width
                              // and
                              // 500
                              // height
        t.setLayout(null);// using no layout managers
        
        t.setVisible(true);// making the frame visible
    }
}