//----SERVER SIDE----
 
import java.io.*; 
import java.net.*; 
 
public class Server 
{ 
  public static void main(String args[]) throws IOException 
  { 
	 DatagramSocket ss = null; 
	 //ServerSocket serversocket = null; Socket socket =null; 
			 
	 ss = new DatagramSocket(9001);  
	 //serversocket = new ServerSocket(8000); 
		  
	 byte[] receiveData = new byte[512]; 
	byte[] receiveData2 = new byte[512]; 
	   //DataInputStream istream = new DataInputStream(socket.getInputStream()); 
	 byte[] sendData  = new byte[512]; 
	 
      //DataOutputStream ostream = new DataOutputStream(socket.getOutputStream()); 
	 BufferedReader br = new BufferedReader(new InputStreamReader(System.in));   
     System.out.println("UDP Server socket is created and waiting for client....."); 
		 
       while(true) 
       { 
  		  
   DatagramPacket receivePacket =new DatagramPacket(receiveData, receiveData.length); 
  
	  ss.receive(receivePacket); 
DatagramPacket receivePacket2 =new DatagramPacket(receiveData2, receiveData2.length); 
  
	  ss.receive(receivePacket2); 
  
String message = new String(receivePacket.getData(),
						 0, receivePacket.getLength()); 
String message2 = new String(receivePacket2.getData(),
						 0, receivePacket2.getLength()); 
	 //myoperation = istream.readUTF(); 
	  
	 System.out.print(""+message); 
	 System.out.print(":-"+message2); 
	  if(message.equals("end") ) 
		{ 
			break; 
		}	 
	  // To read from console 
	 System.out.println(); 
	  System.out.print("Enter Server Message:"); 
	  message = br.readLine(); 
		  
	  InetAddress IPAddress = receivePacket.getAddress(); 
  
	  int port = receivePacket.getPort(); 
		  
	  sendData = message.getBytes(); 
  
  DatagramPacket sendPacket = new DatagramPacket(sendData,
					 sendData.length, IPAddress,port); 
  
	  ss.send(sendPacket); 
	  //ostream.writeUTF(myoperation); 
		 	 } 	 
    ss.close(); 
    System.out.println("Server Stopped by User program"); 
  } 
} 

