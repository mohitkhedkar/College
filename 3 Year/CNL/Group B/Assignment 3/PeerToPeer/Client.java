//----CLIENT SIDE----
 
//To execute on two machines write ip address of server in the
 //code of client then compile n execute
import java.net.*;
import java.io.*;  
 
public class Client {
 
	public static void main(String args[])throws Exception{  
		Socket s=new Socket("192.168.1.104",8080);  
		DataInputStream din=new DataInputStream(s.getInputStream());  
		DataOutputStream dout=new DataOutputStream(s.getOutputStream());  
	BufferedReader br=new BufferedReader(new InputStreamReader(System.in));  
		  
		String str="",str2="";  
		while(!str.equals("stop")){  
			str=br.readLine();  
			dout.writeUTF(str);  
			dout.flush();  
			str2=din.readUTF();  
			System.out.println("Server says: "+str2);  
		}  
	  
		dout.close();  
		s.close();  
	}}


