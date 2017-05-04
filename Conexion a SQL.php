<!DOCTYPE html>
<html>
<head>
	<title>Conexion a MySQL</title>
</head>
<body>
	<?php
		$servername = "localhost";
		$username = "root";
		$password = "";
		

		//Crear Conexion
		$conn = new mysqli($servername, $username, $password);

		//Comprobar conexion
		if($conn->connect_error)
		{
			die("Conexion fallida: " . $conn->connect_error);
		}
		else
		{
			echo "Conexion creada correctamente";
			echo "<br>";
		}

		//crear database
		$sql = "CREATE DATABASE Musica";
		if($conn->query($sql) === TRUE)
		{
			echo "Database creada con exito";
			echo "<br>";
		}
		else
		{
			echo "Error al crear la database" . $conn->error;
			echo "<br>";
		}

		$sql = "USE Musica";
		if(!$conn->query($sql)===TRUE)
		{
			die("Error,no existe la base de datos");
		}

		//crear tabla
		$sql = "CREATE TABLE Grupos(
			Nombre VARCHAR(50),
			Genero VARCHAR(50)
		)";

		if($conn->query($sql)===TRUE)
		{
			echo "Tabla Grupos creada correctamente";
			echo "<br>";
		} 
		else
		{
			echo "Error al crear la tabla" . $conn->error;
			echo "<br>";
		}

		//Introducir datos en una tabla
		$sql = "INSERT INTO Grupos (Nombre,Genero) VALUES 
		('Dream Theater','Metal Progresivo'),
		('ACDC','Rock'),
		('Metallica','Trash Metal'),
		('A day to remember','Hard Rock'),
		('Sleeping with sirens','Hard Rock'),
		('Downplay','Hard Rock')";

		if($conn->multi_query($sql)===TRUE)
		{
			echo "Nuevos datos introducidos correctamente";
		}
		else
		{
			echo "Error: " . $sql . "<br>" . $conn->error;
		}

		//Crear consulta
		$sql = "SELECT * FROM grupos WHERE Genero='Hard Rock'";
		$result = $conn->query($sql);

		if ($result->num_rows > 0) 
		{
			echo "<table><tr><th>NOMBRE</th><th>GENERO</th></tr>";
    		while($row = $result->fetch_assoc()) 
    		{
        		echo "<tr><td>" . $row["Nombre"]. "</td><td>" . $row["Genero"]. "</td></tr>";
    		}
		} 
		else 
		{
    		echo "0 results";
		}
		echo "</table>";
		

		$conn->close();
	?>

</body>
</html>
