
// javahpackage JNI;
import java.awt.*;
import java.awt.event.*;
// import java.util.concurrent.TimeUnit;

import javax.swing.*;

public class SwingListenerDemo {
   static{
      System.loadLibrary("a.out");
   }
   private JFrame mainFrame;
   private JLabel headerLabel;
   private JLabel statusLabel;
   // private JLabel closeLabel;
   private JPanel controlPanel;

   public SwingListenerDemo() {
      prepareGUI();
   }

   public static void main(String[] args) {
      SwingListenerDemo swingListenerDemo = new SwingListenerDemo();
      swingListenerDemo.showActionListenerDemo();
   }

   private void prepareGUI() {
      mainFrame = new JFrame("Java SWING Examples");
      mainFrame.setSize(400, 400);
      mainFrame.setLayout(new GridLayout(3, 1));

      headerLabel = new JLabel("", JLabel.CENTER);
      statusLabel = new JLabel("", JLabel.CENTER);
      statusLabel.setSize(350, 100);
      // closeLabel = new JLabel("",JLabel.CENTER);
      // closeLabel.setSize(350,100);

      mainFrame.addWindowListener(new WindowAdapter() {
         public void windowClosing(WindowEvent windowEvent) {
            // closeLabel.setText("Would you like to save");
            System.exit(0);
         }
      });
      controlPanel = new JPanel();
      controlPanel.setLayout(new FlowLayout());

      mainFrame.add(headerLabel);
      mainFrame.add(controlPanel);
      mainFrame.add(statusLabel);
      // mainFrame.add(closeLabel);
      mainFrame.setVisible(true);
   }

   private void showActionListenerDemo() {
      headerLabel.setText("Listener in action: ActionListener");

      JPanel panel = new JPanel();
      panel.setBackground(Color.magenta);
      JButton okButton = new JButton("OK");
      JButton nokButton = new JButton("Not OK");
      okButton.addActionListener(new CustomActionListener());
      nokButton.addActionListener(new CustomActionListener1());
      panel.add(okButton);
      panel.add(nokButton);
      controlPanel.add(panel);
      mainFrame.setVisible(true);
   }

   class CustomActionListener implements ActionListener {
      public void actionPerformed(ActionEvent e) {
         statusLabel.setText("Ok Button Clicked.");
      }
   }

   class CustomActionListener1 implements ActionListener {
      public void actionPerformed(ActionEvent e) {
         statusLabel.setText("Not ok Button Clicked");
      }
   }
}