import java.util.*;
import java.io.*;
class twopass
{
static int lc=0,index=0;
static String litrl[][]=new String[10][4]; //assumning 10 literals
static int base_table[][]=new int[10][2]; //assuming 10 entries
public static void main(String args[])
{
pass1();
pass2();
}
static void pass1()
{
try
{
int val=0,potflag=0,i;
String inpt,strng=null,mot;
String lit[]=new String[1];
BufferedReader inp = new BufferedReader(new FileReader("input.txt"));
File syt = new File("symbol_table.txt");
if (!syt.exists())
syt.createNewFile();
BufferedWriter sy = new BufferedWriter(new FileWriter(syt.getAbsoluteFile()));
File ltt = new File("literal_table.txt");
if (!ltt.exists())
ltt.createNewFile();
BufferedWriter lt = new BufferedWriter(new FileWriter(ltt.getAbsoluteFile()));
File p1op = new File("pass1output.txt");
if (!p1op.exists())
p1op.createNewFile();
BufferedWriter op = new BufferedWriter(new FileWriter(p1op.getAbsoluteFile()));
for(;(inpt=inp.readLine())!=null;val=potflag=0)
{
StringTokenizer st=new StringTokenizer(inpt);
String str[]=new String[st.countTokens()];
for(i=0;i<str.length;i++)
str[i]=st.nextToken();
if(str.length==3)
val=1;
if(str.length!=1)
{
StringTokenizer stkn=new StringTokenizer(str[val+1],","); //delimiter is comma
lit=new String[stkn.countTokens()];
for(i=0;i<lit.length;i++)
lit[i]=stkn.nextToken();
}
if(str[val].equalsIgnoreCase("DS") || str[val].equalsIgnoreCase("DC")) //checking whether it is in pot
{
int l=0;
if (val==1)
strng=str[0]+" "+lc+" 4 R";
if(lit[0].indexOf("F")!=0)
{
l=Integer.parseInt(lit[0].substring(0,lit[0].length()-1));
l*=4;
}
else
for(i=0;i<lit.length;i++)
l+=4;
lc+=l;
}
else
{
if(str[val].equalsIgnoreCase("EQU"))
{
if(str[2].equals("*"))
strng=str[0]+" "+lc+" 1 R";
else
strng=str[0]+" " +str[2]+" 1 A";
}
else
{
if(str[val].equalsIgnoreCase("START"))
strng=str[0]+" "+str[2]+" 1 R";
else
{
if(str[val].equalsIgnoreCase("LTORG"))
ltorg(true);
else
{
if(str[val].equalsIgnoreCase("END"))
ltorg(false);
else potflag=1;
}
}
}
}
if(potflag==1) //mot search
{
if(str.length!=1)
{
for(i=0;i<lit.length;i++)
if(lit[i].charAt(0)=='=')
{
litrl[index][0]=lit[i].substring(1,lit[i].length());
litrl[index][1]="-1";
litrl[index][2]="4";
litrl[index++][3]="R";
}
}
BufferedReader mt = new BufferedReader(new FileReader("mot.txt"));
while((mot=mt.readLine())!=null)
{
StringTokenizer stk=new StringTokenizer(mot);
String s[]=new String[stk.countTokens()];
for(i=0;i<s.length;i++)
s[i]=stk.nextToken();
if(str[val].equalsIgnoreCase(s[0]))
{
if(val==1)
strng=str[0]+" "+lc+" "+s[2]+" R"; //formation of symbol table
lc+=Integer.parseInt(s[2]);
break;
}
}
mt.close();
op.write(inpt); //input to pass 2
op.newLine();
}
if(val==1)
{
sy.write(strng);
sy.newLine();
}
}
for(i=0;i<index;i++)
{
lt.write(litrl[i][0]+" "+litrl[i][1]+" "+litrl[i][2]+" "+litrl[i][3]);
lt.newLine();
}
inp.close();
sy.close();
lt.close();
op.close();
}
catch(FileNotFoundException ex)
{
System.out.println("Unable to find file ");
}
catch(IOException e)
{
e.printStackTrace();
}
}
static void pass2()
{
int first=0,val=0,i,temp,mask;
String s,s0="",str[],output,mot;
int value[]=new int[2];
index=0;
try
{
BufferedReader p1o = new BufferedReader(new FileReader("pass1output.txt"));
File p2 = new File("pass2output.txt");
if (!p2.exists())
p2.createNewFile();
BufferedWriter op = new BufferedWriter(new FileWriter(p2.getAbsoluteFile()));
for(;(s=p1o.readLine())!=null;s0=str[val],val=0)
{
StringTokenizer st=new StringTokenizer(s);
str=new String[st.countTokens()];
for(i=0;i<str.length;i++)
str[i]=st.nextToken();
if(str.length==3)
val=1;
st=new StringTokenizer(str[val+1],","); //delimiter is comma
String lit[]=new String[st.countTokens()];
for(i=0;i<lit.length;i++)
lit[i]=st.nextToken();
if(str[val].equalsIgnoreCase("USING")) //dealing with pot
{
if(lit[0].equals("*"))
{
if(first==0)
value[0]=0;
else
value[0]=getValue(s0,0); //0=symbol table & 1=literal table value
value[1]=Integer.parseInt(lit[1]);
first=1;
}
else
{
for(i=0;i<lit.length;i++)
{
value[i]=getValue(lit[i],0);
if(value[i]==-1)
value[i]=Integer.parseInt(lit[i]);
}
}
base_table[index][0]=value[1];
base_table[index++][1]=value[0];
}
else //dealing with mot
{
if(str[val].equalsIgnoreCase("BNE"))
output="BC "+7;
else
if(str[val].equalsIgnoreCase("BR"))
output="BCR "+15+",";
else
output=str[val]+" ";
BufferedReader mt = new BufferedReader(new FileReader("mot.txt"));
while((mot=mt.readLine())!=null)
{
st=new StringTokenizer(mot);
String mts[]=new String[st.countTokens()];
for(i=0;i<mts.length;i++)
mts[i]=st.nextToken();
if(str[val].equals(mts[0]))
{
if(mts[3].equals("RR"))
{
for(i=0;i<lit.length;i++)
{
if(i!=0)
output+=",";
temp=getValue(lit[i],0);
if(temp!=-1)
output+=temp;
else
output+=lit[i];
}
}
else
{
if(lit.length==1)
output+=offset(lit[0]);
else
{
temp=getValue(lit[0],0);
if(temp!=-1)
output+=temp;
else
output+=lit[0];
output+=offset(lit[1]);
}
}
break;
}
}
op.write(output);
op.newLine();
}
}
op.close();
}
catch(FileNotFoundException ex)
{
System.out.println("Unable to find file ");
}
catch(IOException e)
{
e.printStackTrace();
}
}
static void ltorg(boolean flag)
{
int i,l=0;
if(flag)
{
l=lc+8;
lc=l-(l%8);
}
for(i=0;i<index;i++)
if(litrl[i][1].equals("-1"))
{
litrl[i][1]=""+lc;
lc+=4;
}
}
static String offset(String s)
{
int value,indx,i,ind=0,offst,new_offst,indx_reg=0;
String string=s;
if(s.charAt(0)=='=')
value=getValue(s.substring(1,s.length()),1); //0=symbol table & 1=literal table value
else
{
indx=s.indexOf("(");
if(indx!=-1)
{
s=s.substring(0,indx);
indx_reg=getValue(string.substring(string.indexOf("(")+1,string.indexOf(")")),0);
}
value=getValue(s,0);
}
offst=Math.abs(value - base_table[ind][1]);
for(i=1 ; i<index ; i++)
{
new_offst = Math.abs(value - base_table[i][1]);
if(new_offst < offst)
{
offst = new_offst;
ind = i;
}
}
String result = ","+offst + "(" + indx_reg + ", " + base_table[ind][0] + ")";
return result;
}
static int getValue(String s,int flag)
{
try
{
String sym,file_name;
if(flag==0)
file_name="symbol_table.txt";
else
file_name="literal_table.txt";
BufferedReader br = new BufferedReader(new FileReader(file_name));
while((sym=br.readLine())!=null)
{
StringTokenizer st=new StringTokenizer(sym);
String str[]=new String[st.countTokens()];
for(int i=0;i<str.length;i++)
str[i]=st.nextToken();
if(str[0].equalsIgnoreCase(s))
return Integer.parseInt(str[1]);
}
}
catch(FileNotFoundException ex)
{
System.out.println("Unable to find file ");
}
catch(IOException e)
{
e.printStackTrace();
}
return -1;
}
}
