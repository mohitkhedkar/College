import java.net.*;
import java.nio.charset.StandardCharsets;
import java.io.*;  
 
 
public class Server {
 
	public static void main(String args[])throws Exception{  
		DatagramSocket datagramSocket = new DatagramSocket(5555);
 
		byte[] buffer;
		InetAddress receiverAddress = InetAddress.getLocalHost();
	BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	  
	String str="",str2="";  
	while(!str.equals("stop")){  
		byte[] buffer1 = new byte[10];
	DatagramPacket packet1 = new DatagramPacket(buffer1, buffer1.length);
 
		datagramSocket.receive(packet1);
		buffer1 = packet1.getData();
		String str1 = new String(buffer1, StandardCharsets.UTF_8);
		System.out.println("Client says: "+str1);
		str=br.readLine();  
		buffer = str.getBytes();
		DatagramPacket packet = new DatagramPacket(
		        buffer, buffer.length, receiverAddress, 4444);
		datagramSocket.send(packet);
 
	}  
 
	}}  
	
 

