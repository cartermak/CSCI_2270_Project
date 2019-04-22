import javax.swing.*;
import java.awt.event.*;

public class Simple {

    public native int displayHelloWorld(String c);

    Simple() {

    }

    public static void main(String[] args) {
        System.load(
                "/mnt/5932357A1CFE5229/OneDrive - University of Colorado at Boulder Office 365/OneDrive - UCB-O365/2019/CSCI 2270/Project/CSCI_2270_Project/Java experiementing/test.so");
        JFrame f = new JFrame("Multiplier");// creating instance of JFrame
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        JLabel l = new JLabel("INPUT");
        JLabel o = new JLabel("");
        o.setBounds(175, 200, 100, 40);
        l.setBounds(175, 60, 100, 40);
        JTextField tf1 = new JTextField();
        tf1.setBounds(150, 100, 100, 40);
        JButton b = new JButton("Multiply input by 5");// creating instance of JButton
        b.setBounds(130, 140, 200, 40);
        b.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                int y = new Simple().displayHelloWorld(tf1.getText());
                System.out.println(y);
                o.setText(Integer.toString(y));
            }
        });
        f.add(b);// adding button in JFrame
        f.add(tf1);
        f.add(l);
        f.add(o);
        f.setSize(400, 500);// 400 width and 500 height
        f.setLayout(null);// using no layout managers
        f.setVisible(true);// making the frame visible
        new Simple();
    }
}