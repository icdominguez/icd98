import java.awt.BorderLayout;
import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JPasswordField;
import javax.swing.border.EmptyBorder;
import javax.swing.JLabel;
import javax.swing.JOptionPane;

import java.awt.Font;
import javax.swing.JTextField;
import javax.swing.JButton;
import java.awt.Color;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class Login extends JFrame {

	private JPanel contentPane;
	private JTextField txtUsuario;
	private JPasswordField txtPass;
	private final static String USER="Ismael";
	private final static String PASS="2196";

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					Login frame = new Login();
					frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the frame.
	 */
	public Login() {
		setForeground(Color.BLACK);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 450, 300);
		contentPane = new JPanel();
		contentPane.setForeground(Color.WHITE);
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JLabel lblUsuario = new JLabel("Usuario:");
		lblUsuario.setFont(new Font("Tahoma", Font.BOLD, 22));
		lblUsuario.setBounds(69, 48, 165, 20);
		contentPane.add(lblUsuario);
		
		txtUsuario = new JTextField();
		txtUsuario.setBounds(217, 48, 152, 25);
		contentPane.add(txtUsuario);
		txtUsuario.setColumns(10);
		
		JLabel lblContrasea = new JLabel("Contrase\u00F1a:");
		lblContrasea.setFont(new Font("Tahoma", Font.BOLD, 22));
		lblContrasea.setBounds(69, 110, 165, 20);
		contentPane.add(lblContrasea);
		
		txtPass = new JPasswordField();
		txtPass.setColumns(10);
		txtPass.setBounds(217, 105, 152, 25);
		contentPane.add(txtPass);
		
		JButton btnEnviar = new JButton("Enviar");
		btnEnviar.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				String vUser = txtUsuario.getText().toString();
				String vPass = txtPass.getText().toString();
				
				if(vUser.equals(USER))
				{
					if(vPass.equals(PASS))
					{
						Menú miMenú = new Menú();
						miMenú.setVisible(true);
					}
					else{
						JOptionPane.showMessageDialog(null, "Usuario y/o contraseña no validos", "Error Login", 0);
					}
				}
				else{
					JOptionPane.showMessageDialog(null, "Usuario y/o contraseña no validos", "Error Login", 0);
				}
			}
		});
		btnEnviar.setBounds(146, 168, 141, 52);
		contentPane.add(btnEnviar);
	}
}
