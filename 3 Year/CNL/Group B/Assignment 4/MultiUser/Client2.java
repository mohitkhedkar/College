//----CLIENT SIDE 2----
 
import java.io.*; 
import java.net.*; 
 
public class Client2 
{ 
 public static void main(String args[]) throws IOException 
 { 
	 String message = null; 
	 
	 DatagramSocket cs = null; 
		 			 
	 cs = new DatagramSocket();  
		  
	 byte[] receiveData = new byte[512];   
	 byte[] sendData  = new byte[512]; 
	byte[] sendData2  = new byte[512]; 
 
     BufferedReader br = new BufferedReader(new InputStreamReader(System.in));  
     System.out.println(" UDP Client socket is created and waiting for server"); 
		 
     InetAddress IPAddress = InetAddress.getByName("localhost"); 
  
	 int port = 9001; 
		  
	 while(true) 
	 { 
		System.out.println("Client-2:"); 
		String message2="client-2";				 
		message = br.readLine();	 
		 
		if(message.equals("end")) 
		{ 
		break; 
		} 
			 
		sendData = message.getBytes(); 
		sendData2 = message2.getBytes(); 
		  
 
     DatagramPacket sendPacket2 = new DatagramPacket(sendData2, 
					sendData2.length, IPAddress,port); 
	DatagramPacket sendPacket = new DatagramPacket(sendData,
					 sendData.length, IPAddress,port); 
		 
  		 
		cs.send(sendPacket2); 
		cs.send(sendPacket);  
  		 
	DatagramPacket receivePacket =new DatagramPacket(receiveData,
						receiveData.length); 
  
		cs.receive(receivePacket); 
  
	message = new String(receivePacket.getData(), 0,
						 receivePacket.getLength()); 
		 //myoperation = istream.readUTF(); 
 
		System.out.println("Server Says: "+message); 
			 
		 
			 
	  } 
 
	 
			   
	} 
}

