package gui;
import java.awt.EventQueue;
import java.sql.*;

public class ConnexionBDD{

    public void enregistrerScore(String pseudo, int score) {
        EventQueue.invokeLater(new Runnable() {
            public void run() {

                String url = "jdbc:mysql://172.16.23.115:3306/tpjavaimds5A";
                String user = "IMDS5A";
                String passwd = "Polytech";

                try {
                    Class.forName("com.mysql.cj.jdbc.Driver");
                    Connection conn = DriverManager.getConnection(url, user, passwd);
                    System.out.println("Connecter");
                    Statement statement = conn.createStatement();

                    statement.executeUpdate("INSERT INTO Scores(pseudo,score) VALUES(\"" + pseudo + "\"," + String.valueOf(score) + ")");
                    ResultSet resultSet = statement.executeQuery("SELECT * from scores");

                    while (resultSet.next()){
                        System.out.println("id: "+resultSet.getInt("idScores"));
                        System.out.println("nom: "+resultSet.getString("pseudo"));
                        System.out.println("nom: "+resultSet.getInt("score"));
                    }

                } catch (Exception e){
                    e.printStackTrace();
                    System.out.println("Erreur");
                    System.exit(0);
                }
            }
        });
    }

}