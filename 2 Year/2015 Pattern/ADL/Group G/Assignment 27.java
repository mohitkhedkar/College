// Write a Java program which will demonstrate aconcept of Interfaces and packages: In this assignment design and use of customized interfaces and packages for a specific application are expected.

// Author: Mohit Khedkar.

import java.util.*;
import sum.*;

interface Area
{
  final static float pi=3.14F;
  float compute(float x,float y);
}

class rectangle implements Area
{
  public  float compute (float x, float y)
  {
    return(x*y);
  }
}

class circle implements Area
{
 public float compute(float x , float y)
 {
   return(pi*x*x);
 }
}

class interpack
{

public static void main (String args[])
 {
  rectangle rect = new rectangle();
  circle cir = new circle();
  pack p=new pack();
  
  p.add(10,20);
 
  Area X;   
  X=rect;
  System.out.println("Area of rectangle:" + X.compute(10,20));

  X= cir;
  System.out.println("Area of circle:" + X.compute(10,0));
  }
}