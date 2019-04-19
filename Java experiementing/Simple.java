import javax.swing.*;
import java.awt.event.*; 
public class Simple {
    JFrame f;
    public native void displayHelloWorld();
    Simple() {
        System.load("/mnt/5932357A1CFE5229/OneDrive - University of Colorado at Boulder Office 365/OneDrive - UCB-O365/2019/CSCI 2270/Project/CSCI_2270_Project/Java experiementing/test.so");
        f = new JFrame();// creating instance of JFrame
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        JButton b = new JButton("click");// creating instance of JButton
        b.setBounds(130, 100, 100, 40);
        b.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){  
                new Simple().displayHelloWorld();
            }  
        }); 
        f.add(b);// adding button in JFrame

        f.setSize(400, 500);// 400 width and 500 height
        f.setLayout(null);// using no layout managers
        f.setVisible(true);// making the frame visible
    }

    public static void main(String[] args) {
        new Simple();
    }
}