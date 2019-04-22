package mypackage;

import javax.swing.*;
import javax.swing.event.ListSelectionListener;
import javax.swing.event.ListSelectionEvent;
import javax.swing.table.DefaultTableModel;
import java.awt.*;
import java.awt.event.*;
import java.util.*;

// import java.util.*;

public class Main {
    public void addorder() {

    }

    private static JDialog d;

    public static void main(String[] args) {
        // mother frame
        JFrame t = new JFrame("Connection Parts Inventory");
        t.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        // import library from jar
        try {
            NativeUtils.loadLibraryFromJar("/share.so");
        } catch (Exception temp) {
            System.out.println(temp.getLocalizedMessage());
            JOptionPane.showMessageDialog(t, "Library failure", "Error", JOptionPane.ERROR_MESSAGE);
        }
        // new panels
        JPanel search = new JPanel(true);
        JPanel f = new JPanel();// creating instance of JFrame
        JPanel k = new JPanel();
        JPanel searchName = new JPanel();
        JPanel replacement = new JPanel();
        JPanel view = new JPanel();
        JPanel viewOrder = new JPanel();
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
        search.setLayout(se);
        // new layout for searching by name
        GroupLayout searchin = new GroupLayout(searchName);
        searchin.setAutoCreateContainerGaps(true);
        searchin.setAutoCreateGaps(true);
        searchName.setLayout(searchin);
        // grouplayout for replacement
        GroupLayout replace = new GroupLayout(replacement);
        replace.setAutoCreateContainerGaps(true);
        replace.setAutoCreateGaps(true);
        replacement.setLayout(replace);
        // viewing panel
        GroupLayout viewing = new GroupLayout(view);
        viewing.setAutoCreateContainerGaps(true);
        viewing.setAutoCreateGaps(true);
        view.setLayout(viewing);
        // fulfill screen
        GroupLayout fulfill = new GroupLayout(viewOrder);
        fulfill.setAutoCreateContainerGaps(true);
        fulfill.setAutoCreateGaps(true);
        viewOrder.setLayout(fulfill);

        // constructing new connection
        Connection C = new Connection();
        wordSearch wordTree = new wordSearch();
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
        JButton editPart = new JButton("Add Part");
        JButton b = new JButton("Add Part");
        b.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                int partNum = 0;
                int count = 0;
                try {
                    partNum = Integer.parseInt(n.getText());
                } catch (Exception z) {
                    JOptionPane.showMessageDialog(t, "Input failure", "Error", JOptionPane.ERROR_MESSAGE);
                    System.out.println(z.getLocalizedMessage());
                }
                try {
                    count = Integer.parseInt(countT.getText());
                } catch (Exception f) {
                    System.out.println(f.getLocalizedMessage());
                    JOptionPane.showMessageDialog(t, "Input failure", "Error", JOptionPane.ERROR_MESSAGE);
                }
                if (partNum != 0 && count != 0) {
                    // Part r = new Part();
                    Part r = C.searchPart(partNum);
                    if (r != null) {
                        int b = JOptionPane.showConfirmDialog(k,
                                "Part is already in inventory, would you like to edit it?");
                        if (b == JOptionPane.YES_OPTION) {
                            d = new JDialog(t, "Editing part " + nameT.getText() + " to inventory", true);

                            d.setLayout(new FlowLayout());
                            d.add(cnt);
                            d.add(countT);
                            d.add(nme);
                            d.add(nameT);
                            d.add(descrip);
                            d.add(descripT);

                            d.add(editPart);
                            d.setSize(300, 300);
                            d.setVisible(true);

                        }
                    } else {

                        Part y = C.addPart(partNum, count, nameT.getText(), descripT.getText());
                        wordTree.addPart(y);
                        y = C.searchPart(partNum);
                        if (y != null)
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
        JButton button = new JButton("Place Order");
        // ordering panel/dialogs
        JButton print = new JButton("Order");
        JTextField ordering = new JTextField(10);
        JButton high = new JButton("Add Part");

        high.addActionListener(new ActionListener() {

            @Override
            public void actionPerformed(ActionEvent action1) {
                int count = 0;
                int partNum = 0;
                boolean error = false;
                try {
                    partNum = Integer.parseInt(ordering.getText());
                } catch (Exception z) {
                    JOptionPane.showMessageDialog(t, "Input failure", "Error", JOptionPane.ERROR_MESSAGE);
                    System.out.println(z.getLocalizedMessage());
                    error = true;
                }
                try {
                    count = Integer.parseInt(countT.getText());
                } catch (Exception f) {
                    System.out.println(f.getLocalizedMessage());
                    JOptionPane.showMessageDialog(t, "Input failure", "Error", JOptionPane.ERROR_MESSAGE);
                    error = true;
                }
                if (nameT.getText() == "")
                    nameT.setText("Name");
                if (descripT.getText() == "")
                    descripT.setText("Description");
                Part temp = C.searchPart(partNum);
                Part vex = null;
                if (temp != null) {
                    int b = JOptionPane.showConfirmDialog(k, "Part is not in inventory, would you like to add it?");
                    if (b == JOptionPane.YES_OPTION) {
                        d = new JDialog(t, "Adding part " + nameT.getText() + " to inventory", true);

                        d.setLayout(new FlowLayout());
                        d.add(cnt);
                        d.add(countT);
                        d.add(nme);
                        d.add(nameT);
                        d.add(descrip);
                        d.add(descripT);

                        d.add(editPart);
                        d.setSize(300, 300);
                        d.setVisible(true);

                    }
                } else {
                    vex = C.addPart(partNum, count, nameT.getText(), descripT.getText());
                    wordTree.addPart(vex);
                }
                if (vex != null && !error) {
                    JOptionPane.showMessageDialog(k, "Added Successfully");
                } else {
                    JOptionPane.showMessageDialog(k, "Failure");
                    System.out.println("Yikes");
                }
                d.setVisible(false);

                countT.setText("");
                nameT.setText("");
                descripT.setText("");
            }
        });

        editPart.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                int partNum = 0;
                int count = 0;
                boolean error = false;
                try {
                    partNum = Integer.parseInt(nameT.getText());
                } catch (Exception z) {

                    System.out.println(z.getLocalizedMessage());
                    JOptionPane.showMessageDialog(t, "Input failure", "Error", JOptionPane.ERROR_MESSAGE);
                    error = true;
                }
                try {
                    count = Integer.parseInt(countT.getText());
                } catch (Exception f) {
                    System.out.println(f.getLocalizedMessage());
                    JOptionPane.showMessageDialog(t, "Input failure", "Error", JOptionPane.ERROR_MESSAGE);
                    error = true;
                }
                Part y = C.searchPart(partNum);
                C.editPart(y, count, nameT.getText(), descripT.getText());
                d.setVisible(false);
            }
        });
        button.addActionListener(new ActionListener() {

            @Override
            public void actionPerformed(ActionEvent e) {
                int c = 0;
                boolean error = false;
                String partName = ordering.getText();
                int u = 0;
                try {
                    c = Integer.parseInt(countT.getText());
                    JOptionPane.showMessageDialog(t, "Input failure", "Error", JOptionPane.ERROR_MESSAGE);
                } catch (Exception l) {
                    error = true;
                    System.out.println(l.getLocalizedMessage());
                    JOptionPane.showMessageDialog(t, "Input failure", "Error", JOptionPane.ERROR_MESSAGE);
                }
                try {
                    u = Integer.parseInt(partName);
                } catch (Exception poll) {
                    error = true;
                    System.out.println(poll.getLocalizedMessage());
                }
                Part h = C.searchPart(u);
                boolean y = C.orderPart(h, c, nameT.getText(), descripT.getText(), 1);
                if (y && !error) {
                    JOptionPane.showMessageDialog(k, "Added Order Successfully");
                } else {
                    System.out.println("Yikes");
                    JOptionPane.showMessageDialog(k, "Failure");
                }
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
                boolean error = false;
                try {
                    u = Integer.parseInt(partName);
                } catch (Exception poll) {
                    System.out.println(poll.getLocalizedMessage());
                    JOptionPane.showMessageDialog(t, "Input failure", "Error", JOptionPane.ERROR_MESSAGE);
                    error = true;
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
                        d.add(new JLabel("Part found! there are " + cont + " in the inventory"));
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
                } else {
                    Part asd = C.searchPart(u);
                    int cont = 0;
                    cont += asd.getCount();
                    strmod you = asd.getName();
                    String your = you.getStr();
                    d = new JDialog(t, "Ordering " + your, true);
                    d.setLayout(new FlowLayout());
                    d.add(new JLabel("Part found! there are " + cont + " in the inventory"));
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
        });

        // search panel
        JButton query = new JButton("Search");
        JLabel status = new JLabel("");
        JTextField searching = new JTextField(10);
        query.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent re) {
                String Number = searching.getText();
                int u = 0;
                JTable jt = new JTable(new DefaultTableModel(
                        new Object[] { "Part Number", "Part Name", "# in inventory", "Description" }, 0));
                jt.setBounds(20, 20, 450, 70);
                try {
                    u = Integer.parseInt(Number);
                } catch (Exception poll) {
                    System.out.println(poll.getLocalizedMessage());
                }
                Part h = C.searchPart(u);
                if (h != null) {
                    status.setText("Part Found!");
                    String count = Integer.toString(h.getCount());
                    String name = h.getName().getStr();
                    String description = h.getDescription().getStr();

                    JPanel uriel = new JPanel();
                    DefaultTableModel model = (DefaultTableModel) jt.getModel();
                    model.addRow(new Object[] { Number, name, count, description });
                    jt.setPreferredSize(new Dimension(500, 100));
                    uriel.add(jt);
                    UIManager.put("OptionPane.minimumSize", new Dimension(600, 120));
                    JOptionPane.showMessageDialog(search, uriel, "Part Found", JOptionPane.INFORMATION_MESSAGE);
                    // jt.addColumn(column);
                    searching.setText("");
                }
                if (h == null) {
                    JOptionPane.showMessageDialog(search, "Part not found", "Error", JOptionPane.ERROR_MESSAGE);

                }
                searching.setText("");
            }
        });

        // search by name stuff
        JLabel sName = new JLabel("Enter a Part Name");
        JTextField field = new JTextField(10);
        JButton huawei = new JButton("Search");
        huawei.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                PartPVector commonParts = new PartPVector();
                wordTree.searchPart(field.getText(), commonParts);
                JPanel uriel = new JPanel();
                JTable jt = new JTable(new DefaultTableModel(
                        new Object[] { "Part Number", "Part Name", "# in inventory", "Description" }, 0));
                jt.setBounds(20, 20, 450, 70);
                DefaultTableModel model = (DefaultTableModel) jt.getModel();
                if (commonParts.size() != 0) {
                    for (int i = 0; i < commonParts.size(); i++) {
                        status.setText("Part Found!");
                        Part h = commonParts.get(i);
                        int Number = h.getPartNum();
                        String count = Integer.toString(h.getCount());
                        String name = h.getName().getStr();
                        String description = h.getDescription().getStr();
                        model.addRow(new Object[] { Number, name, count, description });
                    }
                    jt.setPreferredSize(new Dimension(500, 100));
                    JScrollPane pane = new JScrollPane(jt);
                    uriel.add(pane);
                    UIManager.put("OptionPane.minimumSize", new Dimension(600, 120));
                    JOptionPane.showMessageDialog(search, uriel, "Part Found", JOptionPane.INFORMATION_MESSAGE);
                    searching.setText("");
                } else {
                    JOptionPane.showMessageDialog(searchName, "Part not found", "Error", JOptionPane.ERROR_MESSAGE);
                }
            }
        });

        // Replacement screen

        JLabel numo = new JLabel("Part #");
        JLabel machine = new JLabel("Machine #");
        JTextField entry = new JTextField(10);
        JTextField numOff = new JTextField(10);
        JTextField no = new JTextField(10);
        JTextField countTo = new JTextField(10);
        JTextField nameTo = new JTextField(10);
        JTextField descripTo = new JTextField(10);
        JButton queryy = new JButton("Make Replacement");
        queryy.addActionListener(new ActionListener() {

            @Override
            public void actionPerformed(ActionEvent e) {
                int number = 0;
                int count = 0;
                String mechanic = nameTo.getText();
                String notes = descripTo.getText();
                int numberOn = 0;
                int numberOff = 0;
                try {
                    number = Integer.parseInt(no.getText());
                } catch (Exception poll) {
                    System.out.println(poll.getLocalizedMessage());
                    JOptionPane.showMessageDialog(t, "Input failure", "Error", JOptionPane.ERROR_MESSAGE);
                }
                try {
                    count = Integer.parseInt(countTo.getText());
                } catch (Exception p) {
                    System.out.println(p.getLocalizedMessage());
                    JOptionPane.showMessageDialog(t, "Input failure", "Error", JOptionPane.ERROR_MESSAGE);
                }
                try {
                    numberOn = Integer.parseInt(entry.getText());
                } catch (Exception o) {
                    System.out.println(o.getLocalizedMessage());
                    JOptionPane.showMessageDialog(t, "Input failure", "Error", JOptionPane.ERROR_MESSAGE);
                }
                try {
                    numberOff = Integer.parseInt(numOff.getText());
                } catch (Exception l) {
                    System.out.println(l.getLocalizedMessage());
                    JOptionPane.showMessageDialog(t, "Input failure", "Error", JOptionPane.ERROR_MESSAGE);
                }
                boolean y = C.addReplacement(count, number, numberOff, numberOn, mechanic, notes);
                if (y) {
                    System.out.println("Success");
                } else {
                    System.out.println("Yikes");
                }
                n.setText("");
                entry.setText("");
                numOff.setText("");
                countT.setText("");
                nameT.setText("");
                descripT.setText("");
            }
        });

        // viewing screen

        // JLabel label = new JLabel("Make Replacement");
        JButton viewReplacements = new JButton("View Replacements");
        JButton viewInventory = new JButton("View Inventory");
        JTextField text = new JTextField(10);
        JTextField texter = new JTextField(10);
        ActionListener viewer = new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                int number = 0;
                int machine = 0;
                try {
                    number = Integer.parseInt(text.getText());
                } catch (Exception poll) {
                    System.out.println(poll.getLocalizedMessage());
                    JOptionPane.showMessageDialog(t, "Input failure", "Error", JOptionPane.ERROR_MESSAGE);

                }
                try {
                    machine = Integer.parseInt(texter.getText());
                } catch (Exception po) {
                    System.out.println(po.getLocalizedMessage());
                    JOptionPane.showMessageDialog(t, "Input failure", "Error", JOptionPane.ERROR_MESSAGE);
                }
                ReplacementPVector commonParts = new ReplacementPVector();
                Part g = C.searchPart(number);
                C.getReplacements(g, number, machine, commonParts);
                JPanel uriel = new JPanel();
                JTable jt = new JTable(new DefaultTableModel(new Object[] { "Part Number", "Mechanic", "Notes",
                        "Number of part removed", "Number of part added", "Date of replacement" }, 0));
                jt.setBounds(20, 20, 450, 70);
                DefaultTableModel model = (DefaultTableModel) jt.getModel();
                for (int i = 0; i < commonParts.size(); i++) {
                    status.setText("Part Found!");
                    Replacement h = commonParts.get(i);
                    int Number = g.getPartNum();
                    String count = Integer.toString(h.getNumOff());
                    String mechanic = h.getMechanic().getStr();
                    String notes = h.getNotes().getStr();
                    String removed = Integer.toString(h.getNumOn());
                    Date time = new java.util.Date((long) h.getDate() * 1000);
                    model.addRow(new Object[] { Number, mechanic, notes, count, removed, time });
                }
                jt.setPreferredSize(new Dimension(500, 100));
                JScrollPane pane = new JScrollPane(jt);
                uriel.add(pane);
                UIManager.put("OptionPane.minimumSize", new Dimension(600, 120));
                JOptionPane.showMessageDialog(search, uriel, "Part Inventory", JOptionPane.INFORMATION_MESSAGE);
                searching.setText("");

            }
        };
        ActionListener viewingReplacements = new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                PartPVector commonParts = new PartPVector();
                C.getAllParts(commonParts);
                JPanel uriel = new JPanel();
                JTable jt = new JTable(new DefaultTableModel(
                        new Object[] { "Part Number", "Part Name", "# in inventory", "Description" }, 0));
                jt.setBounds(20, 20, 450, 70);
                DefaultTableModel model = (DefaultTableModel) jt.getModel();
                for (int i = 0; i < commonParts.size(); i++) {
                    status.setText("Part Found!");
                    Part h = commonParts.get(i);
                    int Number = h.getPartNum();
                    String count = Integer.toString(h.getCount());
                    String name = h.getName().getStr();
                    String description = h.getDescription().getStr();
                    model.addRow(new Object[] { Number, name, count, description });
                }
                jt.setPreferredSize(new Dimension(500, 100));
                JScrollPane pane = new JScrollPane(jt);
                uriel.add(pane);
                UIManager.put("OptionPane.minimumSize", new Dimension(600, 120));
                JOptionPane.showMessageDialog(search, uriel, "Part Inventory", JOptionPane.INFORMATION_MESSAGE);
                searching.setText("");

            }
        };

        viewInventory.addActionListener(viewingReplacements);
        viewReplacements.addActionListener(viewer);

        // order fulfillment screen
        // show orders, place and fulfill orders
        JButton reveal = new JButton("Show Orders");
        JDialog show = new JDialog();
        show.setSize(600, 300);
        reveal.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                RequestPVector commonParts = new RequestPVector();
                C.getRequests(commonParts);
                JPanel uriel = new JPanel();
                JTable jt = new JTable(new DefaultTableModel(
                        new Object[] { "Part Number", "Mechanic Name", "# requested", "Notes", "Date Requested" }, 0));
                jt.setBounds(20, 20, 650, 70);
                DefaultTableModel model = (DefaultTableModel) jt.getModel();
                for (int i = 0; i < commonParts.size(); i++) {
                    status.setText("Part Found!");
                    Request h = commonParts.get(i);
                    String Number = Integer.toString(h.getPartNumber());
                    String count = Integer.toString(h.getCount());
                    String name = h.getMechanic().getStr();
                    String description = h.getNotes().getStr();
                    Date time = new java.util.Date((long) h.getDateOrdered() * 1000);
                    model.addRow(new Object[] { Number, name, count, description, time });
                }
                jt.setPreferredSize(new Dimension(800, 100));
                ListSelectionModel select = jt.getSelectionModel();
                select.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
                select.addListSelectionListener(new ListSelectionListener() {
                    public void valueChanged(ListSelectionEvent list) {
                        uriel.setVisible(false);
                        search.setVisible(false);
                        show.setVisible(false);
                        d.setVisible(false);
                        int[] row = jt.getSelectedRows();
                        System.out.println(row.length);
                        Request r = commonParts.get(row.length - 1);
                        Date time = new java.util.Date((long) r.getDateOrdered() * 1000);
                        d = new JDialog(t, "Order by " + (r.getMechanic().getStr()) + " for part " + r.getPartNumber());
                        d.setLayout(new BorderLayout());
                        d.add(new JLabel("Order Notes: " + r.getNotes().getStr()));
                        d.add(new JLabel("Date Ordered " + time));
                        JButton place = new JButton("Place Order");
                        place.addActionListener(new ActionListener() {

                            @Override
                            public void actionPerformed(ActionEvent e) {
                                Date date = new Date();
                                long rough = date.getTime() / 1000;
                                r.setDateOrdered((int) rough);
                                uriel.add(new JLabel("Order Placed!"));
                                JOptionPane.showMessageDialog(viewOrder, uriel, "Order Updated!",
                                        JOptionPane.INFORMATION_MESSAGE);
                                d.setVisible(false);
                            }
                        });
                        JButton fulfillment = new JButton("Fulfill Order");
                        fulfillment.addActionListener(new ActionListener() {

                            @Override
                            public void actionPerformed(ActionEvent e) {
                                Date date = new Date();
                                long rough = date.getTime() / 1000;
                                r.setDateFulfilled((int) rough);
                                C.closeRequest(r);
                                uriel.add(new JLabel("Order Fulfilled!"));
                                JOptionPane.showMessageDialog(viewOrder, uriel, "Order Updated!",
                                        JOptionPane.INFORMATION_MESSAGE);
                                d.setVisible(false);
                            }
                        });
                        d.add(place, BorderLayout.PAGE_START);
                        d.add(fulfillment, BorderLayout.PAGE_END);
                        d.setSize(600, 300);
                        d.setVisible(true);
                    }
                });
                JScrollPane pane = new JScrollPane(jt);
                uriel.add(pane);
                UIManager.put("OptionPane.minimumSize", new Dimension(600, 120));
                show.add(uriel);
                show.setVisible(true);
                searching.setText("");
            }
        });

        // setting grouplayouts
        gr.setHorizontalGroup(gr.createSequentialGroup().addComponent(l).addComponent(num).addComponent(n)
                .addComponent(cnt).addComponent(countT).addComponent(nme).addComponent(nameT).addComponent(descrip)
                .addComponent(descripT).addComponent(b).addComponent(o));
        gr.setVerticalGroup(gr.createParallelGroup(GroupLayout.Alignment.BASELINE).addComponent(l).addComponent(num)
                .addComponent(n).addComponent(cnt).addComponent(countT).addComponent(nme).addComponent(nameT)
                .addComponent(descrip).addComponent(descripT).addComponent(b).addComponent(o));

        // f.add(o);
        JLabel two = new JLabel("Enter a Part Number");
        se.setHorizontalGroup(se.createSequentialGroup().addComponent(two).addComponent(searching).addComponent(query)
                .addComponent(status));
        se.setVerticalGroup(se.createParallelGroup(GroupLayout.Alignment.BASELINE).addComponent(two)
                .addComponent(searching).addComponent(query).addComponent(status));

        // order a part panel
        JLabel order = new JLabel("Place an order: Please enter a part number");
        group.setHorizontalGroup(
                group.createSequentialGroup().addComponent(order).addComponent(ordering).addComponent(print));
        group.setVerticalGroup(group.createParallelGroup(GroupLayout.Alignment.BASELINE).addComponent(order)
                .addComponent(ordering).addComponent(print));
        // searching by name grouplayout
        searchin.setHorizontalGroup(
                searchin.createSequentialGroup().addComponent(sName).addComponent(field).addComponent(huawei));
        searchin.setVerticalGroup(searchin.createParallelGroup(GroupLayout.Alignment.BASELINE).addComponent(sName)
                .addComponent(field).addComponent(huawei));
        // replacement grouplayout
        JLabel mechName = new JLabel("Mechanic's Name");
        JLabel partsRemoved = new JLabel("Number of parts that are being removed");
        JLabel partsAdded = new JLabel("Number of parts that are being added");
        JLabel notesAF = new JLabel("Any notes");
        replace.setHorizontalGroup(replace.createSequentialGroup()
                .addGroup(replace.createParallelGroup(GroupLayout.Alignment.LEADING).addComponent(machine)
                        .addComponent(partsRemoved))
                .addGroup(replace.createParallelGroup(GroupLayout.Alignment.LEADING).addComponent(countTo)
                        .addComponent(numOff))
                .addGroup(replace.createParallelGroup(GroupLayout.Alignment.LEADING).addComponent(numo)
                        .addComponent(partsAdded))
                .addGroup(
                        replace.createParallelGroup(GroupLayout.Alignment.LEADING).addComponent(no).addComponent(entry))
                .addGroup(replace.createParallelGroup(GroupLayout.Alignment.LEADING).addComponent(mechName)
                        .addComponent(queryy))
                .addComponent(nameTo).addComponent(notesAF).addComponent(descripTo));
        replace.setVerticalGroup(replace.createSequentialGroup()
                .addGroup(replace.createParallelGroup(GroupLayout.Alignment.BASELINE).addComponent(machine)
                        .addComponent(countTo).addComponent(numo).addComponent(no).addComponent(mechName)
                        .addComponent(nameTo).addComponent(notesAF).addComponent(descripTo))
                .addGroup(replace.createParallelGroup(GroupLayout.Alignment.BASELINE).addComponent(partsRemoved)
                        .addComponent(numOff).addComponent(partsAdded).addComponent(entry).addComponent(queryy)));
        // viewing pane
        JLabel machineNum = new JLabel("Enter Machine #");
        JLabel partNum = new JLabel("Enter Part #");
        viewing.setHorizontalGroup(
                viewing.createSequentialGroup().addComponent(partNum).addComponent(text).addComponent(machineNum)
                        .addComponent(texter).addComponent(viewReplacements).addComponent(viewInventory));
        viewing.setVerticalGroup(viewing.createParallelGroup(GroupLayout.Alignment.BASELINE).addComponent(partNum)
                .addComponent(text).addComponent(machineNum).addComponent(texter).addComponent(viewReplacements)
                .addComponent(viewInventory));
        // view order pane
        fulfill.setHorizontalGroup(fulfill.createSequentialGroup().addComponent(reveal));
        fulfill.setVerticalGroup(fulfill.createParallelGroup(GroupLayout.Alignment.BASELINE).addComponent(reveal));
        // adding to mother frame
        JTabbedPane tp = new JTabbedPane();
        // Container tp = t.getContentPane();
        tp.setBounds(0, 0, 1500, 1000);

        tp.add("Add a Part", f);
        tp.add("Order a Part", k);
        tp.add("Search by part #", search);
        tp.add("Search by name", searchName);
        tp.add("Replace a part", replacement);
        tp.add("View Inventory", view);
        tp.add("View Orders", viewOrder);

        t.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        t.add(tp);
        t.setSize(1500, 400);// 400
                             // width
                             // and
                             // 500
                             // height

        t.setLayout(null);// using no layout managers

        t.setVisible(true);// making the frame visible
    }
}