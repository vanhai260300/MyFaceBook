
import java.util.Scanner;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author E6410
 */
public class Validation {
    private final static Scanner in=new Scanner(System.in);
    public static int checkInputLimit(int min,int max){
        while(true)
        {
            try{
                int result=Integer.parseInt(in.nextLine().trim());
                if(result<min||result>max)
                    throw new NumberFormatException();
                return result;
            }catch (NumberFormatException e){
                System.err.println("Chi duoc nhap trong khoang [ "+min+" den "+max+" ]");
                System.out.println("Moi nhap lai : ");
            }
        }
    }
    public static String checkInputString(){
        while(true){
            String result=in.nextLine().trim();
            if(result.isEmpty())
            {
                System.err.println("Not Empty !");
                System.out.println("Enter again : ");
            }
            else
                return result;
        }
    }
    public static int checkInputInt(){
        while(true)
        {
            try{
                int result=Integer.parseInt(in.nextLine().trim());
                return result;
                }catch (NumberFormatException e){
                    System.err.println("Đau vao phai la so nguyen : ");
                    System.out.println("Moi nhap lai : ");
                }
        }
    }
    public static double checkInputDouble(){
        while(true)
        {
            try{
                double result=Double.parseDouble(in.nextLine());
                return result;        
            }catch (NumberFormatException e){
                System.err.println("Dau vao phai la so thuc !");
                System.out.println("Moi nhap lai : ");
            }
        }
    }
    public static boolean checkInputYN(){
        while(true)
        {
            String result=checkInputString();
            if(result.equalsIgnoreCase("Y"))
                return true;
            if(result.equalsIgnoreCase("N"))
                return false;
            System.err.println("Please input y/Y or n/N.");
            System.out.println("Enter again: ");
        }
    }
}
