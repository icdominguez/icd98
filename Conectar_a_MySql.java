import java.awt.BorderLayout;
import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JTextField;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.beans.Statement;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.awt.event.ActionEvent;

public class Alta extends JFrame {

	private JPanel contentPane;
	private JTextField textNombre;
	private JTextField textField_1;
	private JTextField textField_2;
	private JTextField textField_3;
	private JTextField textField_4;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					Alta frame = new Alta();
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
	public Alta() {
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 450, 300);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JLabel lblAltasMascotasEn = new JLabel("ALTAS MASCOTAS EN PET");
		lblAltasMascotasEn.setBounds(145, 22, 230, 14);
		contentPane.add(lblAltasMascotasEn);
		
		JLabel lblNombre = new JLabel("Nombre");
		lblNombre.setBounds(130, 62, 46, 14);
		contentPane.add(lblNombre);
		
		JLabel lblEspecie = new JLabel("Especie");
		lblEspecie.setBounds(130, 87, 46, 14);
		contentPane.add(lblEspecie);
		
		JLabel lblSexo = new JLabel("Sexo");
		lblSexo.setBounds(130, 112, 46, 14);
		contentPane.add(lblSexo);
		
		JLabel lblNacimiento = new JLabel("Nacimiento");
		lblNacimiento.setBounds(130, 137, 67, 14);
		contentPane.add(lblNacimiento);
		
		JLabel lblMuerto = new JLabel("Muerto");
		lblMuerto.setBounds(130, 162, 46, 14);
		contentPane.add(lblMuerto);
		
		textNombre = new JTextField();
		textNombre.setBounds(207, 59, 86, 20);
		contentPane.add(textNombre);
		textNombre.setColumns(10);
		
		textField_1 = new JTextField();
		textField_1.setBounds(207, 84, 86, 20);
		contentPane.add(textField_1);
		textField_1.setColumns(10);
		
		textField_2 = new JTextField();
		textField_2.setBounds(207, 109, 86, 20);
		contentPane.add(textField_2);
		textField_2.setColumns(10);
		
		textField_3 = new JTextField();
		textField_3.setBounds(207, 134, 86, 20);
		contentPane.add(textField_3);
		textField_3.setColumns(10);
		
		textField_4 = new JTextField();
		textField_4.setBounds(207, 159, 86, 20);
		contentPane.add(textField_4);
		textField_4.setColumns(10);
		
		JButton btnEnviar = new JButton("ENVIAR");
		btnEnviar.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) 
			{
				Connection conexion;
				try{
					conexion=DriverManager.getConnection("jdbc:mysql://localhost/menagerie","root","");
					Statement comando = (Statement) conexion.createStatement();
					String sql ="INSERT INTO 'pet' VALUES('";
					
					//Nombre
					if(!lblNombre.getText().isEmpty())
						sql=sql + lblNombre.getText()+"',";
					else
						sql=sql+"'";
					
					//Especie
					if(!lblEspecie.getText().isEmpty())
						sql=sql + lblEspecie.getText()+"',";
					else
						sql=sql+"'";
					
					//Nacimiento
					if(!lblNacimiento.getText().isEmpty())
						sql=sql + lblNacimiento.getText()+"',";
					else
						sql=sql+"'";
					
					//Sexo
					if(!lblSexo.getText().isEmpty())
						sql=sql + lblSexo.getText()+"',";
					else
						sql=sql+"'";
					
					//Muerto
					if(!lblMuerto.getText().isEmpty())
						sql=sql + lblMuerto.getText()+"',";
					else
						sql=sql+"'";
					JOptionPane.showConfirmDialog(Alta.this, "El registro ha sido insertado correctamente");
				}catch(SQLException ex){
					JOptionPane.showConfirmDialog(Alta.this, "El registro ha sido insertado correctamente");
					ex.printStackTrace();
				}
			}
			
		});
		btnEnviar.setBounds(164, 208, 89, 23);
		contentPane.add(btnEnviar);
	}
}
